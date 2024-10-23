#include <stdio.h>
#include <unistd.h>
#include "gfx.h"

void cloud(int x, int y);

int main(){
        gfx_open(1300,650,"haha");
        gfx_clear_color (1,19,25);
        gfx_clear();
        int c, frame = 1, x = 1255;
        //house(100,400);
        while (1){
            gfx_color(1,19,25);
            gfx_fillrectangle(150,150,1300,150);
            cloud(300,300);
            
            gfx_flush();
           usleep(500000);
            
            // c=gfx_wait();
            // if (c == 'q'){
            //     break;
            // }
        }
}

