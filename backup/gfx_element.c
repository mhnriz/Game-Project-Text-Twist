#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "gfx.h"
//4px = 1px;
int button(int x, int y, int width, int height, char text[10]){

    //int x = (900-width)/2;
    //int y = b;
    gfx_color(34, 40, 49);
    gfx_fillrectangle(x+(width/12.5)/2,y-4,(width*0.93),4);
    gfx_fillrectangle(x-4,y+(height*0.18),4,height*0.6);
    gfx_fillrectangle(x,y,width,height); //center box 200, 50
    gfx_fillrectangle(x+(width/12.5)/2,y+height,(width*0.93),4);
    gfx_fillrectangle(x+width,y+(height*0.18),4,height*0.6);
    gfx_color(255,255,255);
    gfx_text(text,x+(width/2)-(10*strlen(text)/2),y+((height/2)-10),1);
    
}

void button_clicked(int x, int y, int width, int height, char text[10]){

    gfx_color(24, 30, 39);
    gfx_fillrectangle(x+(width/12.5)/2,y-4,(width*0.93),4);
    gfx_fillrectangle(x-4,y+(height*0.18),4,height*0.6);
    gfx_fillrectangle(x,y,width,height); //center box 200, 50
    gfx_fillrectangle(x+(width/12.5)/2,y+height,(width*0.93),4);
    gfx_fillrectangle(x+width,y+(height*0.18),4,height*0.6);
    gfx_color(255,255,255);
    gfx_text(text,x+(width/2)-(10*strlen(text)/2),y+((height/2)-10),1);
    
    
}

void input_box(int x, int y, int width, int height, char input[10], int *redo){
    int c, i = 0, a, b;
    char text[10] = "";
	gfx_color(34, 40, 49);
    gfx_rectangle(x,y,width,height);
    

    while(1){
        c = gfx_wait(); 
        if(c == 0x20){
            strcpy(input,text);
            input[strlen(input)]='\0';
            printf("%s\n", input);
            *redo = 0;
            break;
        }
        else if(c == 0x08){
            *redo = 1;
            break;
        }
        else if(c == 0x01){
            *redo = 1;
            break;
        }
        else if(isgraph((char)c)){
            if(i <=10) text[i]=toupper((char)c);
            printf("%s\n", text);
            gfx_color(34, 40, 49);
            //gfx_rectangle(x,y,100,50);
            gfx_text(text,x+15,y+10,2);
            i++;
        }

    }
}

