#include <stdio.h>
#include <stdlib.h>
#include <pulse/simple.h>
#include <pulse/error.h>

#define SAMPLE_RATE 44100
#define CHANNELS 2
#define FORMAT PA_SAMPLE_S16LE
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <audio_file>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "rb");
    if (!f) {
        perror("Failed to open audio file");
        return 1;
    }

    // PulseAudio main loop
    pa_simple *pa_handle = NULL;
    pa_sample_spec pa_spec;
    pa_spec.format = FORMAT;
    pa_spec.channels = CHANNELS;
    pa_spec.rate = SAMPLE_RATE;
    int error;
    if (!(pa_handle = pa_simple_new(NULL, "play_audio", PA_STREAM_PLAYBACK, NULL, "playback", &pa_spec, NULL, NULL, &error))) {
        fprintf(stderr, "pa_simple_new() failed: %s\n", pa_strerror(error));
        return 1;
    }

    char buffer[BUFFER_SIZE];
    size_t read_count;
    while ((read_count = fread(buffer, sizeof(char), BUFFER_SIZE, f)) > 0) {
        if (pa_simple_write(pa_handle, buffer, read_count, &error) < 0) {
            fprintf(stderr, "pa_simple_write() failed: %s\n", pa_strerror(error));
            return 1;
        }
    }

    // Close PulseAudio handle
    if (pa_simple_drain(pa_handle, &error) < 0) {
        fprintf(stderr, "pa_simple_drain() failed: %s\n", pa_strerror(error));
        return 1;
    }
    pa_simple_free(pa_handle);
    
    fclose(f);

    return 0;
}

