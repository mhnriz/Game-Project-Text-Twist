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
	gfx_open(1300,650,"Text Twist by C.Code");
	gfx_flush();
	menu();

	return 0;
}

//Start screen
void menu(){
	int kb_key, choice = 0, x = 0, y = 0;
	while(1){
		gfx_clear_color(238, 238, 238);
		gfx_clear();
		
		char text[] = "thisisatest";
		gfx_color(34, 40, 49);
		gfx_text("C.Code", 1230, 630, 1);
		gfx_text("Welcome to TEXT TWIST", 530, 200, 2);
		
		//centering formula: x = (window.size - width)/2
		nav_button(550, 290, 200, 50,"PLAY");
		nav_button(550, 390, 200, 50,"HELP");
		nav_button(550, 490, 200, 50, "EXIT");
		
		if((gfx_xpos() >= 545 && gfx_xpos() <= 755) && (gfx_ypos() >= 290 && gfx_ypos() <= 340)){
			nav_button_clicked(550,290, 200, 50,"PLAY");
			usleep(25000); // 1s = 1*10^6
			play_game();

		}
        else if((gfx_xpos() >= 545 && gfx_xpos() <= 755) && (gfx_ypos() >= 390 && gfx_ypos() <= 440)){
			nav_button_clicked(550,390,200, 50,"HELP");
			usleep(25000); 
			printf("testing");
			help();
		}
		else if((gfx_xpos() >= 545 && gfx_xpos() <= 755) && (gfx_ypos() >= 490 && gfx_ypos() <= 540)){
			nav_button_clicked(550,490, 200, 50, "EXIT");
			usleep(25000);
			exit(0);
		}
		else
			gfx_wait();
	}
}

//Game logic
void play_game(){
	int set_no, c, counter = 0, i = 0, j = 0, k, l, y , x, points = 0,end=0, proceed = 1, count;
	char guess[10], set[10], no_string[10], correct_guess[35][10], chs[10], ch, chr[2];
	char guess_list[35][10];
	
	game_set(set,&set_no);
	wordlist(set, set_no, &end,guess_list);
	//strcpy(temp, set);
	gfx_clear();
	while(1){

		start:

		//interactive ui
		int check = 0, guessed = 0, redo = 1, go = 0;

		//Guess board
		guess_board(50, 1300, end, counter, guess_list, correct_guess);
		

			// x = ((xsize-(round*310))/2) + l;
			// for(j = 0; j < end; j++){
			// 	for(k = 0; k < counter;k++){
			// 		if(strcmp(guess_list[j],correct_guess[k]) == 0){
			// 			for(l = j; )
			// 		}
			// 	}
			// }
		//}
		//input_box(400,300, 100, 50, guess, &redo);

		nav_button(10,590,100,50,"END?");
		if((gfx_xpos() >= 10 && gfx_xpos() <= 110) && (gfx_ypos() >= 590 && gfx_ypos() <= 640)){
			nav_button_clicked(10,590,100,50,"END?");
			usleep(25000);
			menu();
		}
		nav_button(160,590,100,50,"Help");
		if((gfx_xpos() >= 160 && gfx_xpos() <= 260) && (gfx_ypos() >= 590 && gfx_ypos() <= 640)){
			nav_button_clicked(160,590,100,50,"END?");
			usleep(25000);
			do{
			help();
			}while(gfx_wait() != 0x01);
			gfx_clear();
			goto start;
		}
		
		nav_button(10,530,100,50,"TWIST");
			if((gfx_xpos() >= 10 && gfx_xpos() <= 110) && (gfx_ypos() >= 530 && gfx_ypos() <= 580)){
				nav_button_clicked(10,530,100,50,"END?");
				usleep(25000);
				
			}

		nav_button(1000,460,100,50,"Enter");
		if((gfx_xpos() >= 1000 && gfx_xpos() <= 1100) && (gfx_ypos() >= 460 && gfx_ypos() <= 510)){
			if(guess != " "){ 
				go = 1;
			}
		}

		// nav_button(1000,530,100,50,"Delete");
		// if((gfx_xpos() >= 200 && gfx_xpos() <= 300) && (gfx_ypos() >= 550 && gfx_ypos() <= 600)){
			
		// }

		//(xsize-(button.size * strlen + button.gap * strlen-1))/2
		int x = (1300-((50*strlen(set)+(30 * (strlen(set)-1)))))/2;
		//Puzzle letter
		puzzle_letter(x, 500, 1300, set);
		
		if(proceed){
			for(k = 0; k < strlen(set); k++){
				count = 0;
				for(l = 0; l < strlen(set); l++ ){
					if(set[k] == set[l]) count++;
				}
				no_string[k] = count;
			}
		}

		
		k=0;
		while((gfx_xpos() >= x && gfx_xpos() <= x+((strlen(set)-1)*100)) && (gfx_ypos() >= 500 && gfx_ypos() <= 550)){
			
			if(gfx_xpos() >= x+(k*100) && gfx_xpos() <= x+(k*100)+50){
				ch = set[k];
				proceed = 0;
				
				for(l = 0; l < strlen(set);l++){
					
					if(ch == set[l] && no_string[l] > 0){
						proceed = 1;
						count = no_string[l];
						printf("no_string[%d] before: %d\n", l, no_string[l]);
						count -= 1;
						no_string[l] = count;
						printf("no_string[%d] after: %d\n\n", l, no_string[l]);
					}

				}
				if(proceed){
					//convert char to string
					chs[j] = ch;
					chs[j+1] = '\0';
					sprintf(chr,"%c", ch);
					gfx_text(chr, x+(j*100), 520,1);
					j++;
				}
				
			}
			k++;
			if(k > strlen(set)) break;
			
		}
		proceed = 0;
		strcpy(guess,chs);
		printf("guess %s\n", chs);
		


		// nav_button(1000,530,100,50,"Delete");
		// if((gfx_xpos() >= 200 && gfx_xpos() <= 300) && (gfx_ypos() >= 550 && gfx_ypos() <= 600)){
			
		// 	}
		
		
		if(go){
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
			
			if(guessed == 0) check_guess(&check, guess, &counter,end, guess_list);
			
			if(check == 1 && guessed == 0){
				strcpy(correct_guess[counter-1],guess);
				points += 2*strlen(guess);
			}
			char guess[10], no_string[10];
			proceed = 1;
			j = 0;
			strcpy(guess, " ");
		

		

			// gfx_color(34, 40, 49);
			// gfx_text("You made the following words so far: ",200,500,2);
			// printf("counter %d\n", counter);
			// printf("You made the following words so far: ");
			// i=0;
			// while(i < counter){
			// 	printf("%s ",correct_guess[i]);
			// 	if(i%10 == 0){
			// 		y = 525;
			// 		x += 100;
					
			// 	}
			// 	gfx_text(correct_guess[i],x,y,2);
			// 	i++;
			// 	y += 25;
			// }
			// printf("\n");	
		}
		if(counter == end) break;
		if(counter > 0){
			guess_board_letter(50, 1300, end, counter, guess_list, correct_guess);
		}
		gfx_wait();
		gfx_clear();
	
	}
	ended(points);
}	
//Setting game by its gameset pulled from file
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
		fgets(set,10,fp);
		x--;
		
	}
	fclose(fp);
}

//Pull respective gameset's wordlist and store in a array[][].
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
	*end = k;
	
    
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
	gfx_color(34, 40, 49);
	if(*check){
		gfx_text("VALID WORD!",600,410,2);
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
				gfx_text("TOO SHORT!",600,410,2);
				printf("TOO SHORT\n");
				printf("-----------------------------------------------\n");
				return 0;
			}
			else if(isdigit(guess[i]) || !isalnum(guess[i])){
				gfx_text("INVALID SYMBOL/NUMBER",600,410,2);
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
	gfx_clear();
	gfx_color(34, 40, 49);
	gfx_text("Instruction on How To Play.", 200,200,1);			
	gfx_text("You will be given a word.",200,220,1);	
	gfx_text("You may guess using only the letter the word has", 200, 240,1);
	gfx_text("The longer the word you guessed",200,260,1);
	gfx_text("The more points you will achieve. GOODLUCK :)",200,280,1);
	gfx_text("Press anywhere to go back", 200, 300,1);
	

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