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
void wordlist(char set[10], int y, int *end, char string_list[35][10]);
int check_guess(int *check, char guess[10], int *counter, int end, char string_list[35][10]);
void help();
void flush();
void ended(int points);

//MAIN
int main(){
	gfx_open(1200,800,"Text Twist by C.Code");
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
		gfx_text("Welcome to TEXT TWIST", 370, 260, 2);
		
		//centering formula: x = (window.size - width)/2
		button(400, 350, 200, 50,"PLAY");
		button(400, 450, 200, 50,"HELP");
		button(400, 550, 200, 50, "EXIT");
		
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
	int set_no, c, counter = 0, i = 0, j, k, l, points = 0,end=0;
	char guess[10], set[10], correct_guess[35][10], temp[10], chr[10];
	char string_list[35][10];
	game_set(set,&set_no);
	wordlist(set, set_no, &end,string_list);
	gfx_clear();
	while(1){
		int check = 0, guessed = 0,x = 150, y = 525, redo = 1, k = 0, l = 0, proceed = 1;

		gfx_color(34, 40, 49);
		gfx_text("Here is your puzzle:", 150,150,2);
		gfx_text(set, 150,180,2);

		gfx_text("Guess a word: ", 200,300,2);
		input_box(400,300, 100, 50, guess, &redo);
		button(100,700,200,50,"Exit");
		button(100,700,350,50,"Help");

		strcpy(temp,guess);
		if(c == 0x1B) exit(0); //esc key
		gfx_clear();

		
		if(!redo){
			for(j = i;j >= 0; j--){
				if (strcmp(correct_guess[j],guess) == 0){

					gfx_color(34, 40, 49);	
					printf("test\n");
					gfx_text("You have already guessed it!",200, 400,1);
					printf("You have already guessed it!\n");
					printf("-----------------------------------------------\n");
					guessed = 1;
				}
			}
			
			if(guessed == 0) check_guess(&check, guess, &counter,end, string_list);
			
			if(check == 1 && guessed == 0){
				strcpy(correct_guess[counter-1],guess);
				points += 2*strlen(guess);
			}
		}

		if(counter > 0){
			gfx_color(34, 40, 49);
			gfx_text("You made the following words so far: ",200,500,2);
			printf("counter %d\n", counter);
			printf("You made the following words so far: ");
			i=0;
			while(i < counter){
				printf("%s ",correct_guess[i]);
				if(i%10 == 0){
					y = 525;
					x += 100;
					
				}
				gfx_text(correct_guess[i],x,y,2);
				i++;
				y += 25;
			}
			printf("\n");	
		}
		if(counter == end) break;		

	}
	ended(points);
}	

void game_set(char set[10], int *set_no){
	int x;
	srand(time(NULL));
	x = (rand()%3)+1;
	*set_no = x;		// for choosing gameset 1~3
	char line[10];
	printf("file %d\n",*set_no);
	FILE *fp;
	fp = fopen("GameSets.txt","r");
	
	while(x > 0){
		fgets(line,10,fp);
		x--;
		
	}
	
	fclose(fp);
	strcpy(set,line);
}

void wordlist(char set[10], int y, int *end, char string_list[35][10]){
	char string[10], *text[19], temp[10], c[10], temp_list[35][10];
	int i, j, k, proceed;
	FILE *fp;
	switch(y){
		case 1:
			fp = fopen("wordlist_Game1.txt","r");
			break;
		case 2:
			fp = fopen("wordlist_Game2.txt","r");
			break;
		case 3:
			fp = fopen("wordlist_Game3.txt","r");
			break;
		default:
			if( fp == NULL ) {
    			printf( "Couldn't open %s\n",*text);
    			exit(1);
			}
	}

	*end = 0; i = 0; j = 0; k = 0;
	while(fgets(string,10,fp)!=NULL){
		*end += 1;
		string[strcspn(string, "\n")] = '\0';		// read string till '\n' and replace it with '\0'
		strcpy(temp_list[i],string);
		i++;
	}

	//Duplicate handling
	for(i=0;i < *end; i++){
		proceed = 1;
		strcpy(temp,temp_list[i]);
		for(j = 0;j < *end;j++)
			if(strcmp(temp,string_list[j]) == 0){
				proceed=0;
			}
		if(proceed){
			strcpy(string_list[k],temp);
			k++;
		}
	}
	
    
	printf("file lines %d\n", *end);
	fclose(fp);
}


int check_guess(int *check, char guess[10], int *counter,int end, char string_list[35][10]){
   int i = 0;
	while(i < end){
		printf("string check_guess %s\n", string_list[i]);
		if(strcmp(string_list[i],guess) == 0){
			*check = 1;
			break;
		}
		i++;
	}

	if(*check){
		gfx_text("VALID WORD!",600,310,2);
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
				gfx_text("TOO SHORT!",600,310,2);
				printf("TOO SHORT\n");
				printf("-----------------------------------------------\n");
				return 0;
			}
			else if(isdigit(guess[i]) || !isalnum(guess[i])){
				gfx_text("INVALID SYMBOL/NUMBER",600,310,2);
				printf("INVALID SYMBOL/NUMBER %c\n",guess[i]);
				printf("-----------------------------------------------\n");
				return 0;
			}
			i++;
		}while(i < strlen(guess));
		gfx_text("INVALID WORD!",600,310,2);
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

}

void flush(){
	getchar();
	
	while(getchar() != '\n'){
		printf("Unwanted input detected! Press ENTER to go back");
		while(getchar() != '\n');
	}
}

void ended(int points){
	char string[10];
	int x = 160, y = 260, i = 0, c;
	do{
		gfx_clear();
		gfx_color(34, 40, 49);
		gfx_text("Goodjob! Points you've managed to achieve:", 200,200,2);
		gfx_text("Here's a list of all the words that could be found", 200,250,2);
		//use gfx_line (); printf("----------------------------------------------------\n");
		
		FILE *fp;
		fp = fopen("wordlist_Game1.txt", "r");
		while(fgets(string,10,fp) !=NULL){
			string[strcspn(string, "\n")] = '\0';
			if(i%10 == 0){
				y = 260;
				x += 100;				
			}

			gfx_text(string,x,y,2);
			i++;			
			y += 25;
				
		}
		fclose(fp);

	}while(gfx_wait() != 0x01);
	
	gfx_text("Thank you for playing!!", 200, 510, 2);
	gfx_text("Press ANYWHERE to go back", 200, 510, 2);
	//flush();
}