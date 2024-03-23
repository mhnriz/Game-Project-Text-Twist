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
#include <unistd.h>
#include <time.h>
#include "gfx.h"
#include "gfx_element.h"

void menu();
void play_game();
void game_set(char set[10], int *set_no);
void wordlist(int *check, char guess[10], char set[10], int y);
int check_guess(int check, char guess[10], int *counter);
void help();
void flush();
void ended(int points);

//MAIN
int main(){
	gfx_open(900,800,"Text Twist by C.Code");
	gfx_flush();
	menu();

	return 0;
}

void menu(){
	int kb_key, choice = 0, x = 0, y = 0;
	while(1){
		gfx_clear_color(238, 238, 238);
		gfx_clear();

		gfx_color(34, 40, 49);
		gfx_text("C.Code", 855, 790, 0);
		gfx_text("Welcome to TEXT TWIST", 320, 260, 2);
		
		//centering formula: x = (window.size - width)/2
		button(350,350, 200, 50,"PLAY");
		button(350,450,200, 30,"HELP");
		button(400,550, 100, 50, "EXIT");
		
		if((gfx_xpos() >= 350 && gfx_xpos() <= 550) && (gfx_ypos() >= 350 && gfx_ypos() <= 350+50)){
			button_clicked(350,350, 200, 50,"PLAY");
			usleep(20000); // 1s = 1*10^6
			play_game();

		}
        else if((gfx_xpos() >= 350 && gfx_xpos() <= 550) && (gfx_ypos() >= 450 && gfx_ypos() <= 450+30)){
			button_clicked(350,450,200, 30,"HELP");
			usleep(20000); // 1s = 1*10^6
			help();
		}
		else if((gfx_xpos() >= 400 && gfx_xpos() <= 500) && (gfx_ypos() >= 550 && gfx_ypos() <= 550+50)){
			button_clicked(400,550, 100, 50, "EXIT");
			usleep(20000); // 1s = 1*10^6
			exit(0);
		}
		else{
			kb_key = gfx_wait();
			printf("x %d\n",gfx_xpos());
			printf("y %d\n",gfx_ypos());
			if(kb_key == 0x1B) exit(0); //esc key
			gfx_clear();
		}
	}
}


void play_game(){
	int set_no, c, counter;
	char guess[10];
	char set[10];
	game_set(set,&set_no);
	gfx_clear();
	while(1){
		
		int check = 0;

		gfx_color(34, 40, 49);
		gfx_text("Here is your puzzle:", 150,150,2);
		gfx_text(set, 150,180,2);

		gfx_text("Guess a word: ", 200,300,2);
		input_box(400,250, guess);
		
		wordlist(&check, guess, set, set_no);
		check_guess(check, guess, &counter);
		
		if(c == 0x1B) exit(0); //esc key
		gfx_clear();
		printf("yuh %s", guess);
	}
}	

void game_set(char set[10], int *set_no){
	int x;
	srand(time(NULL));
	x = (rand()%3)+1;
	*set_no = x;		// for choosing gameset 1~3
	char line[10];
	printf("rand %d\n", x);
	FILE *fp;
	fp = fopen("GameSets.txt","r");
	
	while(x > 0){
		fgets(line,10,fp);
		x--;
		
	}
	
	fclose(fp);
	strcpy(set,line);
}

void wordlist(int *check, char guess[10], char set[10], int y){
	char string[10], *text[19];
	FILE *fp;
	printf("%d\n",y);
	printf("guess: %s\n", guess);
	switch(y){
		case 1:
			fp = fopen("wordlist_Game1.txt","r");
			break;
		case 2:
			fp = fopen("wordlist_Game2.txt","r");
			break;
		case 3:
			printf("testing");
			fp = fopen("wordlist_Game3.txt","r");
			break;
		default:
			if( fp == NULL ) {
    			printf( "Couldn't open %s\n",*text);
    			exit(1);
			}
	}
	
	

	while(fgets(string,10,fp)!=NULL){
		string[strcspn(string, "\n")] = '\0';		// read string till '\n' and replace it with '\0'
		if(strcmp(string,guess) == 0) *check = 1;
	}
	fclose(fp);
}


int check_guess(int check, char guess[10], int *counter){

	if(check){
		gfx_text(guess, 600,250,1);
		printf("%s: VALID WORD\n", guess);	
		
		printf("-----------------------------------------------\n");
		*counter = *counter + 1;
		return 0;
	}
	else{
		int i = 0;
		
		printf("%s: ", guess);
		
		do{
			if(strlen(guess)<3){
				printf("TOO SHORT\n");
				printf("-----------------------------------------------\n");
				return 0;
			}
			else if(isdigit(guess[i]) || !isalnum(guess[i])){
				printf("INVALID SYMBOL/NUMBER %c\n",guess[i]);
				printf("-----------------------------------------------\n");
				return 0;
			}
			i++;
		}while(i < strlen(guess));
		
		printf("INVALID WORD\n");
		printf("-----------------------------------------------\n");
		
		return 0;
	}
}

void help(){
	int c;
	do{
	gfx_clear();
	gfx_color(34, 40, 49);
	gfx_text("Instruction on How To Play.", 200,200,1);			
	gfx_text("You will be given a word.",200,220,1);	
	gfx_text("You may guess using only the letter the word has", 200, 240,1);
	gfx_text("The longer the word you guessed",200,260,1);
	gfx_text("The more points you will achieve. GOODLUCK :)",200,280,1);
	gfx_text("Press anywhere to go back", 200, 300,1);
	}while(gfx_wait() != 0x01);
 	//flush();
}

void flush(){
	getchar();
	
	while(getchar() != '\n'){
		printf("Unwanted input detected! Press ENTER to go back");
		while(getchar() != '\n');
	}
}