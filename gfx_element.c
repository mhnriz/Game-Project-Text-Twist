#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "gfx.h"
//4px = 1px;
int nav_button(int x, int y, int width, int height, char text[10]){

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

void nav_button_clicked(int x, int y, int width, int height, char text[10]){

    gfx_color(24, 30, 39);
    gfx_fillrectangle(x+(width/12.5)/2,y-4,(width*0.93),4);
    gfx_fillrectangle(x-4,y+(height*0.18),4,height*0.6);
    gfx_fillrectangle(x,y,width,height); //center box 200, 50
    gfx_fillrectangle(x+(width/12.5)/2,y+height,(width*0.93),4);
    gfx_fillrectangle(x+width,y+(height*0.18),4,height*0.6);
    gfx_color(255,255,255);
    gfx_text(text,x+(width/2)-(10*strlen(text)/2),y+((height/2)-10),1);
    
    
}

int word_button(int x, int y, int width, int height){

    //int x = (900-width)/2;
    //int y = b;
    
    gfx_fillrectangle(x+(width/12.5)/2,y-4,(width*0.93),4);
    gfx_fillrectangle(x-4,y+(height*0.18),4,height*0.6);
    gfx_fillrectangle(x,y,width,height); //center box 200, 50
    gfx_fillrectangle(x+(width/12.5)/2,y+height,(width*0.93),4);
    gfx_fillrectangle(x+width,y+(height*0.18),4,height*0.6);
    
    
}

void word_button_clicked(int x, int y, int width, int height){

    gfx_color(24, 30, 39);
    gfx_fillrectangle(x+(width/12.5)/2,y-4,(width*0.93),4);
    gfx_fillrectangle(x-4,y+(height*0.18),4,height*0.6);
    gfx_fillrectangle(x,y,width,height); //center box 200, 50
    gfx_fillrectangle(x+(width/12.5)/2,y+height,(width*0.93),4);
    gfx_fillrectangle(x+width,y+(height*0.18),4,height*0.6);
   
    
}

void input_box(int x, int y, int width, int height, char input[10], int *redo){
    int c, i = 0, a, b;
    char text[10] = "";
	gfx_color(34, 40, 49);
    gfx_rectangle(x,y,width,height);
    

    // while(1){
    //     c = gfx_wait(); 
    //     if(c == 0x20){
    //         strcpy(input,text);
    //         input[strlen(input)]='\0';
    //         printf("%s\n", input);
    //         *redo = 0;
    //         break;
    //     }
    //     else if(c == 0x08){
    //         *redo = 1;
    //         break;
    //     }
    //     else if(c == 0x01){
    //         *redo = 1;
    //         break;
    //     }
    //     else if(isgraph((char)c)){
    //         if(i <=10) text[i]=toupper((char)c);
    //         printf("%s\n", text);
    //         gfx_color(34, 40, 49);
    //         //gfx_rectangle(x,y,100,50);
    //         gfx_text(text,x+15,y+10,2);
    //         i++;
    //     }

    // }
}

void puzzle_letter(int x, int y, int xsize, char set[10]){
    int i;
    char chr[2], ch;
    //(1300-(button.size * strlen + button.gap * strlen-1))/2	//
    
    for(i = 0; i <strlen(set)-1; i++, x += 100){
        gfx_color(34, 40, 49);
        word_button(x,y,50,50);
        gfx_color(255,255,255);
        ch = set[i];
        sprintf(chr,"%c", ch);
        gfx_text(chr,x+(50/2.5),y+(50/2.5),1);
    }
}



void guess_board(int y, int xsize, int end, int counter, char guess_list[35][10], char correct_guess[35][10]){
    int i, j, l, x;
    float round = end/7;
    
    if((round-(int)round) >= 0.5) round = (int)round + 1;
    for(i = 0, l = 0; i < end; i++, y += 50){
        x = ((xsize-(round*310))/2) + l;
        for(j = 0; j < strlen(guess_list[i]); j++, x += 45){
            
            gfx_color(34, 40, 49);
            word_button(x,y,30,30);    
            gfx_color(100,100,100);
            
        }
        if(y >= 350){ 
            y = 0;
            l += 230;
        }
    }

}
void guess_board_letter(int y, int xsize, int end, int counter, char guess_list[35][10], char correct_guess[35][10]){
    int i, j, k, l, x;
    float round = end/7;
    char temp[10], chs[2];
    if((round-(int)round) >= 0.5) round = (int)round + 1;
    for(i = 0; i < counter; i++){
        y = 50;
        x = ((xsize-(round*310))/2);
        
        for(j = 0; j < end; j++, y += 50){
            if(strcmp(guess_list[j],correct_guess[i]) == 0){
                printf("test x%d y%d\n", x,y);
                gfx_color(255,255,255);
                strcpy(temp,correct_guess[i]);
                for(k = 0; k < strlen(temp); k++){
                    chs[0] = temp[k];
                    chs[1] = '\0';
                    gfx_text(chs,x+(50*k-(k*5))+10,y+5,1);
                }
                
                l = 0;
            } 
            if(y >= 350){    
                y = 0;
                x +=230;
            }
                
            
        }
        
    }
}// do separate loops