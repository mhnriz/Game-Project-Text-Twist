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

void background_brick(int x, int y){
    gfx_color(18,21,27);
    gfx_fillrectangle(x,y,80,36);
    gfx_color(27,30,35);
    gfx_fillrectangle(x,y+4,80,4);
    gfx_color(10,12,19);
    gfx_fillrectangle(x,y,80,4);    //top
    gfx_fillrectangle(x,y,4,36);    
    gfx_fillrectangle(x-4,y+4,12,4);
    gfx_fillrectangle(x,y+32,80,4);    //bottom
    gfx_fillrectangle(x-4,y+28,12,4);
    gfx_fillrectangle(x+76,y,4,36);
    //gfx_line(10,20,90,56);
} //y = 36

void background(int x, int y){
    for(x = 0; x <= 900;x+=76){
		printf("%d\n", x);	
		if(x == 836){
		    background_brick(x,y);
		    x = -38;
		    y += 36;
		}
		else if(x == 874){	
			background_brick(x,y);
			x = 0;
			y += 36;
		}
		else if(y > 899) break;
		    background_brick(x,y);
    }
}

void foreground_brick(int x, int y){
    gfx_color(34,38,45);
    gfx_fillrectangle(x,y,80,36);
    gfx_color(48,52,57);
    gfx_fillrectangle(x,y+4,80,4);
    gfx_color(21,24,31);
    gfx_fillrectangle(x,y,80,4);    //top
    gfx_fillrectangle(x,y,4,36);    
    gfx_fillrectangle(x-4,y+4,12,4);
    gfx_fillrectangle(x,y+32,80,4);    //bottom
    gfx_fillrectangle(x-4,y+28,12,4);
    gfx_fillrectangle(x+76,y,4,36);
    //gfx_line(10,20,90,56);
} //y = 36

void foreground(int x, int y){
    for(x = 0; x <= 900;x+=76){
		printf("%d\n", x);	
		if(x == 836){
		    foreground_brick(x,y);
		    x = -38;
		    y += 36;
		}
		else if(x == 874){	
			foreground_brick(x,y);
			x = 0;
			y += 36;
		}
		else if(y > 899) break;
		    foreground_brick(x,y);
    }
}

void input_box(int x, int y, char input[10]){
    int c, i = 0;
    char text[10] = "";
    gfx_color(71, 80, 87);
    gfx_rectangle(x,y,100,50);
    while(c != 0x20){
        c = gfx_wait(); 
        if(c == 0x20){
            strcpy(input,text);
            input[strlen(input)]='\0';
            printf("%s\n", input);
        }
        else if(isgraph((char)c)){
            text[i]=toupper((char)c);
            printf("%s\n", text);
            gfx_rectangle(x,y,100,50);
            gfx_text(text,x,y,2);
            i++;
           
            
        }
    
    }
}

