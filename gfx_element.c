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

int button(int x, int y, int width, int height, char text[], int x_offset){

    //int x = (900-width)/2;
    //int y = b;
    gfx_color(34, 40, 49);
    gfx_fillrectangle(x+(width/12.5)/2,y-4,(width*0.93),4);
    gfx_fillrectangle(x-4,y+(height*0.18),4,height*0.6);
    gfx_fillrectangle(x,y,width,height); //center box 200, 50
    gfx_fillrectangle(x+(width/12.5)/2,y+height,(width*0.93),4);
    gfx_fillrectangle(x+width,y+(height*0.18),4,height*0.6);
    gfx_color(255,255,255);
    gfx_text(text,x+(width/2)-(10*strlen(text)/2)+x_offset,y+((height/2)-10),1);
    
    
}

void button_clicked(int x, int y, int width, int height, char text[], int x_offset){

    gfx_color(24, 30, 39);
    gfx_fillrectangle(x+(width/12.5)/2,y-4,(width*0.93),4);
    gfx_fillrectangle(x-4,y+(height*0.18),4,height*0.6);
    gfx_fillrectangle(x,y,width,height); //center box 200, 50
    gfx_fillrectangle(x+(width/12.5)/2,y+height,(width*0.93),4);
    gfx_fillrectangle(x+width,y+(height*0.18)+x_offset,4,height*0.6);
    gfx_color(255,255,255);
    gfx_text(text,x+(width/2)-(10*strlen(text)/2)+x_offset,y+((height/2)-10),1);
   
    
}

int word_button(int x, int y, int width, int height){

    //int x = (900-width)/2;
    //int y = b;
    gfx_color(24, 30, 39);
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

void input_box(int x, int y, char guess[10], char set[10], int m){
	int i, xpos = x;
    char chr[2], ch;
    gfx_color(34, 40, 49);
    
    for(i = 0; i <strlen(set)-1; i++, xpos += 100){
        gfx_color(34, 40, 49);
        word_button(xpos,y,50,50);
        
    }
    
    xpos = x;
    for(i = 0; i < m; i++, xpos += 100){
        ch = guess[i];
        sprintf(chr,"%c", ch);
        gfx_color(255,255,255);
        gfx_text(chr,xpos+19,y+17,2);
    }
    
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

void puzzle_letter(int x, int y, char set[10]){
    int i;
    char chr[2], ch;
    //(1300-(button.size * strlen + button.gap * strlen-1))/2	//
    
    for(i = 0; i <strlen(set)-1; i++, x += 100){
        gfx_color(34, 40, 49);
        word_button(x,y,50,50);
        gfx_color(255,255,255);
        ch = set[i];
        sprintf(chr,"%c", ch);
        gfx_text(chr,x+19,y+17,2);
    }
}



void guess_board(int y, int xsize, int end, int counter, char guess_list[35][10], char correct_guess[35][10]){
    int i, j, l, x, a = y;
    float round = end/7;
    
    if((round-(int)round) >= 0.5) round = (int)round + 1;
    for(i = 0, l = 0, y = 35; i < end; i++, y += 35){
        x = ((xsize-(round*320))/2) + l;
        for(j = 0; j < strlen(guess_list[i]); j++, x += 45){
            
            gfx_color(34, 40, 49);
            gfx_fillrectangle(x,y+a,30,30);    
            gfx_color(100,100,100);
            
        }
        if(y >= 240){ 
            y = 0;
            l += 230;
        }
    }

}
void guess_board_letter(int xsize, int end, int counter, char guess_list[35][10], char correct_guess[35][10]){
    int i, j, k, l, x, y;
    float round = end/7;
    char temp[10], chs[2];
    if((round-(int)round) >= 0.5) round = (int)round + 1;
    for(i = 0; i < counter; i++){
        y = 35;
        x = ((xsize-(round*320))/2);
        
        for(j = 0; j < end; j++, y += 35){
            if(strcmp(guess_list[j],correct_guess[i]) == 0){
                //printf("test x%d y%d\n", x,y);
                gfx_color(255,255,255);
                strcpy(temp,correct_guess[i]);
                for(k = 0; k < strlen(temp); k++){
                    chs[0] = temp[k];
                    chs[1] = '\0';
                    gfx_text(chs,x+(50*k-(k*5))+10,y-15,1);
                }
                
            } 
            if(y >= 240){    
                y = 0;
                x +=230;
            }
                
            
        }
        
    }
}// do separate loops

//Character sprite

void peashooter(int x, int y){
	gfx_color(0,0,0);
	gfx_fillrectangle(x+20,y+68,44,4);
	gfx_color (0,0,0);
	gfx_fillrectangle(x+16,y+60,52,8);
	gfx_color (66, 129,73);
	gfx_fillrectangle(x+20,y+60,44,8);
	gfx_color (0,0,0);
	gfx_fillrectangle(x+20 ,y+56,44,4);
	gfx_color(0,0,0); 
	gfx_fillrectangle(x+40, y+60,4,8);
	
	gfx_color(0,0,0);
	gfx_fillrectangle(x+36,y+48,4,8);
	gfx_color (114,182,92); 
	gfx_fillrectangle(x+40, y+48,4,8);
	gfx_color (0,0,0);
	gfx_fillrectangle(x+44,y+48,4,8);
}

void peashooter_head(int x,int y){
	//stem
	gfx_color (0,0,0);
	gfx_fillrectangle(x+32,y+40,4,8); 
	gfx_color (114,182,92); 
	gfx_fillrectangle (x+36,y+40,4,8); 
	gfx_color (0,0,0);
	gfx_fillrectangle(x+40,y+40,4,8);
	
	//chin
	gfx_fillrectangle(x+28,y+36,20,4); 
	
	//mouth
	gfx_fillrectangle(x+56 ,y+36,8,4);
	gfx_fillrectangle(x+48,y+32,8,4);
	gfx_fillrectangle(x+64,y+12,4,24);
	gfx_fillrectangle(x+56 ,y+10,8,4);
	
	//back_head
	gfx_fillrectangle(x+20 ,y+32,8,4);
	gfx_fillrectangle(x+16 ,y+16,4,16);
	gfx_fillrectangle(x+24,y+10,4,4);
	gfx_fillrectangle(x+20,y+14,4,4);
	
	//top_head
	gfx_fillrectangle(x+28,y+8,20,4); 
	gfx_fillrectangle(x+48,y+10,4,4);
	gfx_fillrectangle(x+52,y+14,4,4);
	
	//leaf
	gfx_fillrectangle(x+20,y+6,4,4);
	gfx_fillrectangle(x+16,y+2,4,4);
	gfx_fillrectangle(x+12,y-2,4,4);
	gfx_fillrectangle(x+8,y-2,4,4);
	gfx_fillrectangle(x+4,y+2,4,4);
	gfx_fillrectangle(x,y+6,4,4);
	gfx_fillrectangle(x,y+10,24,4);
	gfx_fillrectangle(x+4,y+14,4,4);
	
	//color_leaf
	gfx_color(80,123,95);
	gfx_fillrectangle(x+8,y+2,8,4);
	gfx_fillrectangle(x+4,y+6,16,4);
	
	//color_body
	gfx_color(95,203,65);
	gfx_fillrectangle(x+20,y+18,44,14);
	gfx_fillrectangle(x+28,y+12,20,24);
	gfx_fillrectangle(x+24,y+14,28,4);
	gfx_fillrectangle(x+56,y+14,8,22);
	
	//face
	gfx_color (0,0,0);
	gfx_fillrectangle(x+42,y+16,4,8);
	gfx_fillrectangle(x+34,y+16,4,8);
	gfx_fillrectangle(x+60,y+16,4,18);
}

void repeater_head(int x,int y){
	//stem
	gfx_color (0,0,0);
	gfx_fillrectangle(x+32,y+40,4,8); 
	gfx_color (114,182,92); 
	gfx_fillrectangle (x+36,y+40,4,8); 
	gfx_color (0,0,0);
	gfx_fillrectangle(x+40,y+40,4,8);
	
	//chin
	gfx_fillrectangle(x+28,y+36,20,4); 
	
	//mouth
	gfx_fillrectangle(x+56 ,y+36,8,4);
	gfx_fillrectangle(x+48,y+32,8,4);
	gfx_fillrectangle(x+64,y+12,4,24);
	gfx_fillrectangle(x+56 ,y+10,8,4);
	
	//back_head
	gfx_fillrectangle(x+16,y+32,12,4);
	gfx_fillrectangle(x+16 ,y+16,4,12);
	gfx_fillrectangle(x+24,y+10,4,4);
	gfx_fillrectangle(x+20,y+14,4,4);
	
	//top_head
	gfx_fillrectangle(x+28,y+8,20,4); 
	gfx_fillrectangle(x+48,y+10,4,4);
	gfx_fillrectangle(x+52,y+14,4,4);
	
	//leaf
	gfx_fillrectangle(x+28,y+4,4,4); 
	gfx_fillrectangle(x+20,y,8,4); 
	gfx_fillrectangle(x+16,y+4,4,4); 
	gfx_fillrectangle(x+20,y+8,4,8); 
	
	gfx_fillrectangle(x+8,y,8,4); 
	gfx_fillrectangle(x+4,y+4,4,12);
	gfx_fillrectangle(x+4,y+8,8,4); 
	gfx_fillrectangle(x+12,y+12,4,4);
	
	gfx_fillrectangle(x+8,y+28,8,4);
	gfx_fillrectangle(x+4,y+20,4,8); 
	gfx_fillrectangle(x+4,y+24,12,4); 
	gfx_fillrectangle(x+12,y+20,4,4);
	
	
	//color_leaf
	gfx_color(80,123,95);
	gfx_fillrectangle(x+20,y+4,8,4); 
	gfx_fillrectangle(x+24,y+6,4,4); 
	
	
	gfx_fillrectangle(x+8,y+4,8,4); 
	gfx_fillrectangle(x+12,y+8,8,4); 
	gfx_fillrectangle(x+16,y+12,4,4); 
	
	//color_body
	gfx_color(95,203,65);
	gfx_fillrectangle(x+20,y+18,44,14);
	gfx_fillrectangle(x+28,y+12,20,24);
	gfx_fillrectangle(x+24,y+14,28,4);
	gfx_fillrectangle(x+56,y+14,8,22);
	gfx_fillrectangle(x+16,y+28,4,4); 
	
	//face
	gfx_color (0,0,0);
	gfx_fillrectangle(x+20,y+28,4,4); 
	gfx_fillrectangle(x+42,y+12,4,12);
	gfx_fillrectangle(x+34,y+12,4,12);
	gfx_fillrectangle(x+60,y+16,4,18);
}

void iceshooter_head(int x,int y){
	//stem
	gfx_color (0,0,0);
	gfx_fillrectangle(x+32,y+40,4,8); 
	gfx_color (58,123,156); 
	gfx_fillrectangle (x+36,y+40,4,8); 
	gfx_color (0,0,0);
	gfx_fillrectangle(x+40,y+40,4,8);
	
	//chin
	gfx_fillrectangle(x+28,y+36,20,4); 
	
	//mouth
	gfx_fillrectangle(x+56 ,y+36,8,4);
	gfx_fillrectangle(x+48,y+32,8,4);
	gfx_fillrectangle(x+64,y+12,4,24);
	gfx_fillrectangle(x+56 ,y+10,8,4);
	
	//back_head
	gfx_fillrectangle(x+16,y+32,12,4);
	gfx_fillrectangle(x+16 ,y+16,4,12);
	gfx_fillrectangle(x+24,y+10,4,4);
	gfx_fillrectangle(x+20,y+14,4,4);
	
	//top_head
	gfx_fillrectangle(x+28,y+8,20,4); 
	gfx_fillrectangle(x+48,y+10,4,4);
	gfx_fillrectangle(x+52,y+14,4,4);
	
	//leaf
	gfx_fillrectangle(x+28,y+4,4,4); 
	gfx_fillrectangle(x+24,y,4,4); 
	gfx_fillrectangle(x+20,y+4,4,4); 
	gfx_fillrectangle(x+20,y+8,4,8); 
	
	gfx_fillrectangle(x+12,y,8,4); 
	gfx_fillrectangle(x+8,y,4,12);
	gfx_fillrectangle(x+8,y+8,8,4); 
	gfx_fillrectangle(x+16,y+12,4,4);
	
	gfx_fillrectangle(x,y+8,8,4);
	gfx_fillrectangle(x,y+12,4,4);
	gfx_fillrectangle(x+4,y+16,12,4);
	
	gfx_fillrectangle(x+8,y+20,4,4);
	gfx_fillrectangle(x+4,y+24,4,8); 
	gfx_fillrectangle(x+8,y+28,8,4); 
	
	
	//color_leaf
	gfx_color(81,204,223);
	gfx_fillrectangle(x+24,y+4,4,6); 
	gfx_fillrectangle(x+12,y+4,8,4);
	gfx_fillrectangle(x+16,y+4,4,8);
	gfx_fillrectangle(x+8,y+24,8,4); 
	gfx_fillrectangle(x+12,y+20,4,4); 
	gfx_color(70,141,190);
	gfx_fillrectangle(x+4,y+12,12,4);
	
	//color_body
	gfx_color(42,233,241);
	gfx_fillrectangle(x+20,y+18,44,14);
	gfx_fillrectangle(x+28,y+12,20,24);
	gfx_fillrectangle(x+24,y+14,28,4);
	gfx_fillrectangle(x+56,y+14,8,22);
	gfx_fillrectangle(x+16,y+28,4,4); 
	
	//face
	gfx_color (0,0,0);
	gfx_fillrectangle(x+20,y+28,4,4); 
	gfx_fillrectangle(x+42,y+12,4,12);
	gfx_fillrectangle(x+34,y+12,4,12);
	gfx_fillrectangle(x+60,y+16,4,18);
}
