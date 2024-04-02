#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "gfx.h"

void zombie(int x, int y);
void zombie2(int x,int y);
int main(){
        gfx_open(1300,650,"haha");
        gfx_clear_color (255,255,255);
        gfx_clear();
        int c, frame = 1, x = 1255;
        int ball_x = 10, zombie_alive =1;
        srand(time(NULL));
        //house(100,400);
        while (1){
            gfx_color(255,255,255);
            gfx_fillrectangle(0,150,1300,150);
            if(zombie_alive = 1){
                if(frame == 2) frame = 1;
                if(frame == 1){
                    zombie(x,200);
                    frame = 0;
                    x -= 20;
                }
                else if(frame == 0){
                    zombie2(x,200);
                    frame = 1;
                    x -= 20;
                }
                if(ball_x >= x){
                    zombie_alive = 0;
                    frame = 2;
                    x = 1255;
                    ball_x = 10;
                }
            }
            gfx_circle(255,0,0);
            gfx_fillcircle(ball_x,250,15);
            ball_x += 50;
            gfx_flush();
            usleep(500000);
           
            if(zombie_alive != 1){
                
                zombie_alive = rand()%2;
            }
printf("zombie_alive: %d", zombie_alive);
            // c=gfx_wait();
            // if (c == 'q'){
            //     break;
            // }
        }
}

void zombie(int x, int y){
    gfx_color(55,82,41);
    //head
    gfx_fillrectangle(x,y,16,20);
    gfx_color(35,50,27);
    gfx_fillrectangle(x+16,y,8,16);
    gfx_fillrectangle(x+16,y+16,4,4);
    //eyes
    gfx_color(196,177,52);
    gfx_fillrectangle(x,y+8,4,4);
    gfx_fillrectangle(x+12,y+8,4,4);
    //mouth
    gfx_color(118,31,20);
    gfx_fillrectangle(x+4,y+16,8,4);
    //cloth
    gfx_color(61,38,20);
    gfx_fillrectangle(x+20,y+16,8,28);
    gfx_fillrectangle(x+4,y+20,16,8);
    gfx_fillrectangle(x,y+24,20,8);
    gfx_fillrectangle(x-4,y+28,28,8);
    gfx_fillrectangle(x+4,y+36,24,12);
    gfx_fillrectangle(x+4,y+48,8,8);
    gfx_fillrectangle(x+20,y+48,8,8);

    //ligament
    gfx_color(55,82,41);
    gfx_fillrectangle(x-8,y+32,4,8);
    gfx_fillrectangle(x+8,y+32,4,8);
    //stomach
    gfx_fillrectangle(x+4,y+36,16,4);
    //leg
    gfx_fillrectangle(x+4,y+56,4,16);
    gfx_fillrectangle(x+24,y+56,4,16);
    //cloth2
    gfx_color(84,57,32);
    gfx_fillrectangle(x+16,y+20,4,4);
    gfx_fillrectangle(x+4,y+24,12,4);
    gfx_fillrectangle(x-8,y+26,8,8);
    gfx_fillrectangle(x+4,y+26,8,4);
    gfx_fillrectangle(x+4,y+30,4,8);
    gfx_fillrectangle(x+16,y+30,4,4);
    gfx_fillrectangle(x+12,y+34,8,4);
    gfx_fillrectangle(x+4,y+42,4,12);
    gfx_fillrectangle(x+16,y+42,4,12);
}

void zombie2(int x,int y){
    gfx_color(55,82,41);
    //head
    gfx_fillrectangle(x,y,16,20);
    gfx_color(35,50,27);
    gfx_fillrectangle(x+16,y,8,16);
    gfx_fillrectangle(x+16,y+16,4,4);
    //eyes
    gfx_color(196,177,52);
    gfx_fillrectangle(x,y+8,4,4);
    gfx_fillrectangle(x+12,y+8,4,4);
    //mouth
    gfx_color(118,31,20);
    gfx_fillrectangle(x+4,y+16,8,4);
    //cloth
    gfx_color(61,38,20);
    gfx_fillrectangle(x+20,y+16,8,28);
    gfx_fillrectangle(x+4,y+20,16,8);
    gfx_fillrectangle(x,y+24,20,8);
    gfx_fillrectangle(x-4,y+28,28,8);
    gfx_fillrectangle(x+4,y+36,24,12);
    gfx_fillrectangle(x+4,y+48,8,8);
    gfx_fillrectangle(x+20,y+48,8,8);

    //ligament
    gfx_color(55,82,41);
    gfx_fillrectangle(x-8,y+32,4,8);
    gfx_fillrectangle(x+8,y+32,4,8);
    //stomach
    gfx_fillrectangle(x+4,y+36,16,4);
    //leftleg
     gfx_fillrectangle(x+4,y+56,4,4);
     gfx_fillrectangle(x+4,y+60,4,4);
     gfx_fillrectangle(x+8,y+64,4,4);
     gfx_fillrectangle(x+8,y+68,4,4);
     gfx_fillrectangle(x+8,y+72,4,4);
    //rightleg
    gfx_fillrectangle(x+24,y+56,4,4);
    gfx_fillrectangle(x+24,y+60,4,4);
    gfx_fillrectangle(x+20,y+64,4,4);
    gfx_fillrectangle(x+20,y+68,4,4);
    gfx_fillrectangle(x+20,y+72,4,4);
    //cloth2
    gfx_color(84,57,32);
    gfx_fillrectangle(x+16,y+20,4,4);
    gfx_fillrectangle(x+4,y+24,12,4);
    gfx_fillrectangle(x-8,y+26,8,8);
    gfx_fillrectangle(x+4,y+26,8,4);
    gfx_fillrectangle(x+4,y+30,4,8);
    gfx_fillrectangle(x+16,y+30,4,4);
    gfx_fillrectangle(x+12,y+34,8,4);
    gfx_fillrectangle(x+4,y+42,4,12);
    gfx_fillrectangle(x+16,y+42,4,12);

}
