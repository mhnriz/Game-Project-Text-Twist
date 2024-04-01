#include <stdio.h>
#include <pulse/simple.h>

int main(){

    FILE *fp = fopen("test.wav", "rb");

    pa_simple *pa_handle;
    pa_sample_spec pa_spec;
    pa_spec.format = PA_SAMPLE_S16LE;
    pa_spec.channels = 2;
    pa_spec.rate = 44100;

    pa_handle = pa_simple_new(NULL, "play_audio", PA_STREAM_PLAYBACK, NULL, "playback", &pa_spec, NULL, NULL, NULL);
    
    char buffer[4096];
    size_t read_count;
    while((read_count = fread(buffer, sizeof(char), 4096, fp)) > 0){
        pa_simple_write(pa_handle, buffer, read_count, NULL);
    }

    pa_simple_drain(pa_handle, NULL);
    pa_simple_free(pa_handle);

    fclose(fp);
    
}