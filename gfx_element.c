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

void grass(int x, int y){
	
	//lightbrown
	gfx_color(136,69,0);	
	gfx_fillrectangle(x,y+36,48,8);
	//darkbrown
	gfx_color(113,55,0);
	gfx_fillrectangle(x,y+40,48,4);
	
	
	//brown 
	gfx_color(199,121,3);
	gfx_fillrectangle(x,y+16,48,8);
	gfx_fillrectangle(x+8,y+16,4,4);
	
	//yellow
	gfx_color(238,181,55);
	gfx_fillrectangle(x,y+20,48,12);
	gfx_fillrectangle(x+8,y+20,4,12);
	//darkbrown
	gfx_color(113,55,0);	
	gfx_fillrectangle(x,y+28,48,8);
	//morebrown
	gfx_color(199,121,3);
	gfx_fillrectangle(x+8,y+20,4,4);
	gfx_fillrectangle(x+20,y+20,12,4);
	
	//darkgreen
	gfx_color(3,136,0);
	gfx_fillrectangle(x,y+8,48,8);
	gfx_fillrectangle(x+8,y+16,4,4);
	gfx_fillrectangle(x+20,y+16,8,4);
	
	//lightgreen
	gfx_color(102,200,66);
	gfx_fillrectangle(x,y,48,8);
	gfx_fillrectangle(x+8,y+8,4,4);
	gfx_fillrectangle(x+20,y+8,8,4);
	
}

void house(int x,int y){
	//roofoutline
	gfx_color (0,0,0);
	//higest
	gfx_fillrectangle(x+40,y+20,116,8);
	
	//left 
	gfx_fillrectangle(x+32,y+28,8,8);
	gfx_fillrectangle(x+24,y+36,8,8);
	gfx_fillrectangle(x+16,y+44,8,8);
	gfx_fillrectangle(x+8,y+52,8,8);
	gfx_fillrectangle(x,y+60,8,8);
	gfx_fillrectangle(x-8,y+68,8,8);
	gfx_fillrectangle(x-16,y+76,8,8);
	gfx_fillrectangle(x-24,y+84,8,24);
	gfx_fillrectangle(x-16,y+108,8,8);
	gfx_fillrectangle(x-8,y+116,8,88);
	
	//bottom
	//gfx_fillrectangle(x,y+204,196,8);
	//right
	gfx_fillrectangle(x+156,y+28,8,8);
	gfx_fillrectangle(x+164,y+36,8,8);
	gfx_fillrectangle(x+172,y+44,8,8);
	gfx_fillrectangle(x+180,y+52,8,8);
	gfx_fillrectangle(x+188,y+60,8,8);
	gfx_fillrectangle(x+196,y+68,8,8);
	gfx_fillrectangle(x+204,y+76,8,8);
	gfx_fillrectangle(x+212,y+84,8,8);
	gfx_fillrectangle(x+220,y+92,8,8);
	gfx_fillrectangle(x+212,y+100,8,8);
	gfx_fillrectangle(x+204,y+108,8,8);
	gfx_fillrectangle(x+196,y+116,8,88);
	
	//roof 
	gfx_color (129,26,24);
	gfx_fillrectangle(x+40,y+28,116,8);
	gfx_color(176,37,40);
	gfx_fillrectangle(x+32,y+36,80,8);
	gfx_color (129,26,24);
	gfx_fillrectangle(x+24,y+44,80,8);
	gfx_color(176,37,40);
	gfx_fillrectangle(x+16,y+52,80,8);
	gfx_color (129,26,24);
	gfx_fillrectangle(x+8,y+60,80,8);
	gfx_color(176,37,40);
	gfx_fillrectangle(x,y+68,80,8);
	gfx_color (129,26,24);
	gfx_fillrectangle(x-8,y+76,80,8);
	gfx_color(176,37,40);
	gfx_fillrectangle(x-16,y+84,80,8);
	
	gfx_color(108,16,17);
	gfx_fillrectangle(x+120,y+28,36,8);
	gfx_fillrectangle(x+112,y+36,8,8);
	gfx_fillrectangle(x+104,y+44,8,8);
	gfx_fillrectangle(x+96,y+52,8,8);
	gfx_fillrectangle(x+88,y+60,8,8);
	gfx_fillrectangle(x+80,y+68,8,8);
	gfx_fillrectangle(x+72,y+76,8,8);
	gfx_fillrectangle(x+64,y+84,8,8);
	gfx_fillrectangle(x-16,y+92,88,8);
	
	gfx_color(139,24,27);
	gfx_fillrectangle(x-16,y+100,88,8);
	
	gfx_color(108,16,17);
	gfx_fillrectangle(x-8,y+108,88,8);
	gfx_fillrectangle(x+72,y+100,8,8);
	gfx_fillrectangle(x+128,y+52,28,8);
	gfx_fillrectangle(x+120,y+60,8,8);
	gfx_fillrectangle(x+112,y+68,8,8);
	gfx_fillrectangle(x+104,y+76,8,8);
	gfx_fillrectangle(x+96,y+84,8,8);
	gfx_fillrectangle(x+88,y+92,8,8);
	gfx_fillrectangle(x+80,y+100,8,8);
	
	gfx_fillrectangle(x+156,y+60,8,8);
	gfx_fillrectangle(x+164,y+68,8,8);
	gfx_fillrectangle(x+172,y+76,8,8);
	gfx_fillrectangle(x+180,y+84,8,8);
	gfx_fillrectangle(x+188,y+92,8,8);
	gfx_fillrectangle(x+196,y+100,8,8);
	
	gfx_color(174,38,42);
	gfx_fillrectangle(x+72,y+84,16,16);
	gfx_fillrectangle(x+80,y+76,16,16);
	gfx_fillrectangle(x+88,y+68,16,16);
	gfx_fillrectangle(x+96,y+60,16,16);
	gfx_fillrectangle(x+104,y+52,16,16);
	gfx_fillrectangle(x+112,y+44,16,16);
	gfx_fillrectangle(x+120,y+36,44,16);
	gfx_fillrectangle(x+156,y+44,16,16);
	gfx_fillrectangle(x+164,y+52,16,16);
	gfx_fillrectangle(x+172,y+60,16,16);
	gfx_fillrectangle(x+180,y+68,16,16);
	gfx_fillrectangle(x+188,y+76,16,16);
	gfx_fillrectangle(x+196,y+84,16,16);
	gfx_fillrectangle(x+212,y+92,8,8);
	gfx_fillrectangle(x+204,y+100,8,8);
	
	gfx_color(135,23,20);
	gfx_fillrectangle(x+148,y+60,8,8);
	gfx_fillrectangle(x+156,y+68,8,8);
	gfx_fillrectangle(x+164,y+76,8,8);
	gfx_fillrectangle(x+172,y+84,8,8);
	gfx_fillrectangle(x+180,y+92,8,8);
	gfx_fillrectangle(x+188,y+100,8,8);
	gfx_fillrectangle(x+196,y+108,8,8);
	
	gfx_color(187,128,50);
	gfx_fillrectangle(x+128,y+60,20,8);
	gfx_fillrectangle(x+140,y+68,16,8);
	gfx_fillrectangle(x+148,y+76,16,8);
	gfx_fillrectangle(x+156,y+84,16,8);
	gfx_fillrectangle(x+164,y+92,16,8);
	gfx_fillrectangle(x+172,y+100,16,8);
	gfx_fillrectangle(x+180,y+108,16,8);
	
	gfx_fillrectangle(x,y+116,80, 8);
	
	gfx_color(236,177,77);
	gfx_fillrectangle(x+120,y+68,8,136);
	gfx_fillrectangle(x+112,y+76,8,128);
	gfx_fillrectangle(x+104,y+84,8,120);
	gfx_fillrectangle(x+96,y+92,8,112);
	gfx_fillrectangle(x+88,y+100,8,104);
	
	gfx_fillrectangle(x+128,y+68,12,8);
	gfx_fillrectangle(x+128,y+76,20,128);
	gfx_fillrectangle(x+140,y+84,16,112);
	gfx_fillrectangle(x+148,y+92,16,112);
	gfx_fillrectangle(x+156,y+100,16,104);
	gfx_fillrectangle(x+164,y+108,16,96);
	gfx_fillrectangle(x+172,y+116,16,88);
	gfx_fillrectangle(x+180,y+116,16,88);

	gfx_fillrectangle(x,y+124,80, 80);

	gfx_fillrectangle(x+80,y+108,8,96);
	
	gfx_color(188,130,46);
	gfx_fillrectangle(x,y+172,8,32);
	gfx_fillrectangle(x+8,y+180,8,24);
	gfx_fillrectangle(x+16,y+188,56,16);
	gfx_fillrectangle(x+72,y+180,8,24);
	gfx_fillrectangle(x+80,y+172,8,32);
	
	gfx_fillrectangle(x+96,y+172,8,32);
	gfx_fillrectangle(x+104,y+180,8,24);
	gfx_fillrectangle(x+104,y+188,76,16);
	gfx_fillrectangle(x+180,y+172,8,32);
	gfx_fillrectangle(x+188,y+164,8,40);

	gfx_color(133,92,35);
	gfx_fillrectangle(x+88,y+100,8,104);

	gfx_color(141,130,131);
	gfx_fillrectangle(x+16,y+140,54,32);
	gfx_fillrectangle(x+24,y+132,38,48);
	gfx_color(255,255,255);
	gfx_fillrectangle(x+24,y+140,38,32);
	gfx_color(120,149,221);
	gfx_fillrectangle(x+32,y+148,22,16);

	gfx_color(141,130,131);
	gfx_fillrectangle(x+136,y+116,18,8);
	gfx_fillrectangle(x+128,y+124,34,8);
	gfx_fillrectangle(x+120,y+132,52,8);
	gfx_fillrectangle(x+112,y+140,68,64);

	gfx_color(255,255,255);
	gfx_fillrectangle(x+136,y+124,18,8);
	gfx_fillrectangle(x+128,y+132,36,8);
	gfx_fillrectangle(x+120,y+140,52,64);

	gfx_color(0,0,0);
	gfx_fillrectangle(x+136,y+132,18,8);
	gfx_fillrectangle(x+128,y+140,34,64);

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
     gfx_fillrectangle(x+8,y+72,4,1);
    //rightleg
    gfx_fillrectangle(x+24,y+56,4,4);
    gfx_fillrectangle(x+24,y+60,4,4);
    gfx_fillrectangle(x+20,y+64,4,4);
    gfx_fillrectangle(x+20,y+68,4,4);
    gfx_fillrectangle(x+20,y+72,4,1);
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

void cloud(int x, int y){
    gfx_color(255,255,255);
    gfx_fillrectangle(x+64,y,16,4);
    gfx_fillrectangle(x+48,y+4,48,4);
    gfx_fillrectangle(x+40,y+8,64,4);
    gfx_fillrectangle(x+36,y+12,72,4);
    gfx_fillrectangle(x+32,y+12,80,4);
    gfx_fillrectangle(x+28,y+16,88,8);
    gfx_fillrectangle(x+24,y+20,120,4);
    gfx_fillrectangle(x+24,y+24,124,4);
    gfx_fillrectangle(x+20,y+28,132,4);
    gfx_fillrectangle(x+20,y+32,136,8);
    gfx_fillrectangle(x+16,y+32,144,12);
    gfx_fillrectangle(x+12,y+42,156,8);
    gfx_fillrectangle(x+20,y+46,144,8);
    gfx_fillrectangle(x+28,y+50,100,8);
    gfx_fillrectangle(x+34,y+58,76,4);
    gfx_fillrectangle(x+50,y+60,34,4);
    gfx_fillrectangle(x+64,y+64,24,4);

    
}

void baby_cloud(int x, int y){
    gfx_color(255,255,255);
    gfx_fillrectangle(x+44,y+84,12,4);
    gfx_fillrectangle(x+12,y+88,24,4);
    gfx_fillrectangle(x+40,y+88,24,4);
    gfx_fillrectangle(x+8,y+92,60,4);
    gfx_fillrectangle(x+8,y+96,64,4);
    gfx_fillrectangle(x+8,y+100,68,4);
    gfx_fillrectangle(x+24,y+104,44,4);
    gfx_fillrectangle(x+32,y+104,36,4);
    gfx_fillrectangle(x+44,y+104,24,4);
    gfx_fillrectangle(x+72,y+92,8,8);
}