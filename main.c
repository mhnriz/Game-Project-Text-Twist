/******************************************************************** 
	Group Name			:		C.Code 
	1st Member Name		:       Yeong Ya Zing  
	1st Matric Number	:       22008891 
	2nd  Member Name	:       Muhammad Hariz Naim bin Muhammad Jamali 
	2nd Matric  Number  :       22008354 
	Semester            :       Jan 2024 
	Compiling command	:		gcc main.c gfx_element.c gfx.c -o main.o -lX11 -lm
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "gfx.h"
#include "gfx_element.h"

void menu();

//MAIN
int main(){
	gfx_open(900,800,"Text Twist by C.Code");
	menu();

	return 0;
}

void menu(){
	int kb_key, choice = 0;
	
	do{
		gfx_clear_color(49, 54, 63);
		gfx_clear();
		kb_key = gfx_wait();
		gfx_color(0,0,0);
		gfx_text("Welcome to TEXT TWIST", 400, 400, 0);
	}while(kb_key != 0x1B);
}