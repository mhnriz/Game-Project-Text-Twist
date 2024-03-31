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
char gfx_getKey();

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
			nav_button(550,290, 200, 50,"PLAY");
			usleep(25000); // 1s = 1*10^6
			play_game();

		}
        else if((gfx_xpos() >= 545 && gfx_xpos() <= 755) && (gfx_ypos() >= 390 && gfx_ypos() <= 440)){
			nav_button(550,390,200, 50,"HELP");
			usleep(25000); 
			printf("testing");
			help();
		}
		else if((gfx_xpos() >= 545 && gfx_xpos() <= 755) && (gfx_ypos() >= 490 && gfx_ypos() <= 540)){
			nav_button(550,490, 200, 50, "EXIT");
			usleep(25000);
			exit(0);
		}
		else
			gfx_wait();
	}
}

//Game logic
void play_game(){
	int x, y, i, j, k, l, proceed = 1, count, twist = 0, go = 0, key;
	int set_no, max_guess, counter = 0, points, guess_index = 0, guess_count = 0;
	char set[10], temp_set[10], guess[10], no_string[10], chs[10], ch, chr[2];
	char guess_list[35][10], correct_guess[35][10];

	//animation / graphics variable
	int pea_head_mov = 0, pea_head, re_head_mov = 0, re_head, ice_head_mov = 0, ice_head;
	int bullet_mov=160, shoot = 0, shoot_mov = 0;
	
	game_set(set,&set_no);
	wordlist(set, set_no, &max_guess,guess_list);

	gfx_clear();

	while(1){

		//game_logic
		printf("x %d y %d\n", gfx_xpos(), gfx_ypos());
		printf("outside test\n");
		if(key == 1){
			printf("test key: %d\n", key);
			int guessed = 0, check = 0;
			int key = gfx_getKey();
			

			int x_center = (1300-((50*strlen(set)+(30 * (strlen(set)-1)))))/2;

			//per-char set[] counter
			if(proceed){
				for(j = 0; j < strlen(set); j++){
					count = 0;
					for(k = 0; k < strlen(set); k++ ){
						if(set[j] == set[k]) count++;
					}
					no_string[j] = count;
				}
			}
			
			k=0;
			while((gfx_xpos() >= x_center && gfx_xpos() <= x_center+((strlen(set)-1)*100)) && (gfx_ypos() >= 375 && gfx_ypos() <= 425)){
				
				if(gfx_xpos() >= x_center+(k*100) && gfx_xpos() <= x_center+(k*100)+50){
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
						chs[guess_index] = ch;
						chs[guess_index+1] = '\0';
						sprintf(chr,"%c", ch);
						//gfx_text(chr, x+(j*100)+5, 305,1);
						guess_count++;
						guess_index++;
					}
					
				}
				k++;
				if(k > strlen(set)) break;
				
			}
			proceed = 0;
			strcpy(guess,chs);
			printf("guess %s\n", chs);

			if((gfx_xpos() >= 1000 && gfx_xpos() <= 1100) && (gfx_ypos() >= 300 && gfx_ypos() <= 350)){
				button_clicked(1000,300,100,50,"Enter", 0);
				go = 1;
			}

			if(go){
				GO:
				for(j = 0;j >= 0; j--){
					if (strcmp(correct_guess[j],guess) == 0){

						gfx_color(34, 40, 49);	
						printf("test\n");
						gfx_text("You have already guessed it!",200, 400,1);
						printf("You have already guessed it!\n");
						printf("-----------------------------------------------\n");
						guessed = 1;
					}
				}
			
				if(guessed == 0) check_guess(&check, guess, &counter,max_guess, guess_list);
			
				if(check == 1 && guessed == 0){
					strcpy(correct_guess[counter-1],guess);
					points += 2*strlen(guess);
					shoot = 1;
				}
				strcpy(chs,"er");
				char no_string[10];
				go = 0;
				proceed = 1;
				guess_count = 0;
				guess_index = 0;
				if(counter == max_guess) break;
			}

			x = gfx_xpos();
			y = gfx_ypos();

			//buttons
			if((gfx_xpos() >= 1230 && gfx_xpos() <= 1330) && (gfx_ypos() >= 15 && gfx_ypos() <= 55)){
				button_clicked(1230,15,100,40,"END?", -20);
				usleep(25000);
				goto end;
			}

			if((gfx_xpos() >= 1230 && gfx_xpos() <= 1330) && (gfx_ypos() >= 75 && gfx_ypos() <= 115)){
				button_clicked(1230,75,100,40,"HELP",-20);
				usleep(25000);
				do{
					help();
				}while(gfx_wait() != 0x01);
				gfx_clear();
			}

			if((gfx_xpos() >= 1230 && gfx_xpos() <= 1330) && (gfx_ypos() >= 135 && gfx_ypos() <= 175)){
			button_clicked(1230,135,100,40,"TWIST", -20);
			usleep(25000);
			strcpy(temp_set,set);
			if(twist == 0){
				for(k = 0, l = strlen(temp_set)-1; k < strlen(temp_set)-1;k++, l--){
						set[l] = temp_set[k];
						
				}
				twist = 1;
			}
			else{
				for(k = 1, l = strlen(temp_set)-1; k < strlen(temp_set)-1;k++, l--){
						set[l] = temp_set[k];
						
				}
				twist = 0;
			}
			printf("twist value: %d", twist);
			proceed = 1;
			guess_index = 0;
			char guess[10], no_string[10];
			}
			
			if((gfx_xpos() >= 1000 && gfx_xpos() <= 1100) && (gfx_ypos() >= 370 && gfx_ypos() <= 420)){
				button_clicked(1000,370,100,50,"Delete", 0);
				usleep(25000);
				strcpy(guess,"er");
				proceed = 1;
				guess_index = 0;
				guess_count = 0;
			}
			


			printf(" x %d\ny %d\n", x,y);
		}

		//animations / graphics
		else{
			gfx_color(238,238,238);
			//gfx_color(238,0,0);
			gfx_fillrectangle(0,470, 1300,180);
			
			printf("shoot %d\n", shoot);
			if(shoot == 1) {
				shoot_mov = 1;
				shoot = 0;
			}
			if(shoot_mov == 1){
				gfx_color(230,0,0);
				gfx_fillcircle(bullet_mov,575,20);
				bullet_mov += 100;
				if(bullet_mov >= 1280) shoot_mov = 0;
			}
			
			//peashooter animation
			if(pea_head_mov){
				pea_head = 108;
				pea_head_mov = 0;
			}
			else{
				pea_head = 100;
				pea_head_mov = 1;
			}
			peashooter_head(pea_head,550);
			peashooter(100,550);
			
			if(re_head_mov){
				re_head = 28;
				re_head_mov = 0;
			}
			else{
				re_head = 20;
				re_head_mov = 1;
			}
			repeater_head(re_head,550);
			peashooter(20,550);

			if(ice_head_mov){
				ice_head = 188;
				ice_head_mov = 0;
			}
			else{
				ice_head = 180;
				ice_head_mov = 1;
			}
			iceshooter_head(ice_head,550);
			peashooter(180,550);
			
			
			gfx_fillrectangle(1280,525,75,50);

			int x_center = (1300-((50*strlen(set)+(30 * (strlen(set)-1)))))/2;
			//Guess board
			guess_board(-20, 1300, max_guess, counter, guess_list, correct_guess);
			guess_board_letter(1300, max_guess, counter, guess_list, correct_guess);
			//Puzzle letter
			puzzle_letter(x_center, 375, set);
			input_box(x_center, 300, guess, set, guess_count);
			
			button(1230,15,100,40,"END?", -20);
			button(1230,75,100,40,"Help", -20);
			button(1230,135,100,40,"TWIST", -20);
			button(1000,300,100,50,"Enter", 0);
			button(1000,370,100,50,"Delete", 0);
			gfx_flush();
			usleep(500000);	
			//gfx_clear();
		}
		
		key = gfx_getKey();
	}
	end:
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
		gfx_text("VALID WORD!",600,510,2);
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
				gfx_text("TOO SHORT!",600,510,2);
				printf("TOO SHORT\n");
				printf("-----------------------------------------------\n");
				return 0;
			}
			else if(isdigit(guess[i]) || !isalnum(guess[i])){
				gfx_text("INVALID SYMBOL/NUMBER",600,510,2);
				printf("INVALID SYMBOL/NUMBER %c\n",guess[i]);
				printf("-----------------------------------------------\n");
				return 0;
			}
			i++;
		}while(i < strlen(guess));
		gfx_text("INVALID WORD!",600,510,2);
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
	do{
		int x = 200, y = 250, i = 0, c;
		gfx_clear();
		gfx_color(34, 40, 49);
		gfx_text("Goodjob! Points you've managed to achieve:", 200,150,2);
		gfx_text("Here's a list of all the words that could be found", 200,200,2);
		//use gfx_line (); printf("----------------------------------------------------\n");
		
		FILE *fp;
		fp = fopen("wordlist_Game1.txt", "r");
		while(fgets(string,10,fp) !=NULL){
			string[strcspn(string, "\n")] = '\0';
			if(i%10 == 0){
				y = 250;
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

char gfx_getKey(){
	if(gfx_event_waiting()){
		char key = gfx_wait();
		while(gfx_event_waiting()) {gfx_wait();}
		return key;
	}
}
