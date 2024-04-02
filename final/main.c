/******************************************************************** 
	Group Name			:		C.Code 
	1st Member Name		:       Yeong Ya Zing  
	1st Matric Number	:       22008891 
	2nd  Member Name	:       Muhammad Hariz Naim bin Muhammad Jamali 
	2nd Matric  Number  :       22008354 
	Semester            :       Jan 2024 

Compiling command:

gcc main.c gfx_element.c gfx.c -o main.o -lX11 -lm -lpulse-simple -lpulse -pthread
*********************************************************************/

//required libraries: libpulse-dev

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <pulse/simple.h>
#include <pthread.h>
#include <X11/Xlib.h>
#include "gfx.h"
#include "gfx_element.h"

void menu();
void play_game();
void game_set(char set[10], int *set_no);
void wordlist(char set[10], int y, int *max_guess, char string_list[35][10], int *longest);
int check_guess(int *check, char guess[10], int *counter, int max_guess, char string_list[35][10], int longest);
void help();
void flush();
void ended(int points);
char gfx_getKey();
void *bgm();
void tap();
void *animation(void *args);
void *cloud_animation();

//MAIN
int main(){
	XInitThreads();
	gfx_open(1300,650,"Text Twist by C.Code");

	pthread_t bgm_thread;
	pthread_create(&bgm_thread, NULL, bgm, NULL);
	
	menu();
	return 0;
}

//Start screen
void menu(){
	start:
	int kb_key = 1, choice = 0, x, loop = 0;			
	gfx_clear_color(1, 11, 19);
	gfx_clear();

	pthread_t cloud_animation_thread;
	pthread_create(&cloud_animation_thread, NULL, cloud_animation, NULL);

	while(1){
		if(kb_key == 1 || loop == 1){
			loop = 0;

			house(10,403);
			for (x=0;x<1300;x+=48){
				grass(x,608);
			}

			gfx_color(255,255,255);
			gfx_text("C.Code", 1230, 590, 1);
			gfx_text("Welcome to TEXT TWIST", 530, 200, 2);
			
			nav_button(550, 290, 200, 50,"PLAY");
			nav_button(550, 390, 200, 50,"HELP");
			nav_button(550, 490, 200, 50, "EXIT");
			
			if((gfx_xpos() >= 545 && gfx_xpos() <= 755) && (gfx_ypos() >= 290 && gfx_ypos() <= 340)){
				nav_button_clicked(550,290, 200, 50,"PLAY");
				tap();
				pthread_cancel(cloud_animation_thread);
				play_game();
				goto start;

			}
			else if((gfx_xpos() >= 545 && gfx_xpos() <= 755) && (gfx_ypos() >= 390 && gfx_ypos() <= 440)){
				nav_button_clicked(550,390,200, 50,"HELP");
				tap();
				help();
				loop = 1;
				
			}
			else if((gfx_xpos() >= 545 && gfx_xpos() <= 755) && (gfx_ypos() >= 490 && gfx_ypos() <= 540)){
				nav_button_clicked(550,490, 200, 50, "EXIT");
				tap();
				exit(0);
			}
			
		}
		kb_key = gfx_getKey();
	}
}

//Game logic
void play_game(){ 
	int x, y, c = 1, i, j, k, l, proceed = 1, count, x_center, twist = 0, longest;
	int set_no, max_guess, guess_index = 0, guess_count = 0, counter = 0, points = 0;
	char set[10], temp_set[10], guess[10], score[10], ch, chr[2], chs[10] = "", no_string[10];
	char guess_list[35][10], correct_guess[35][10];

	//*use blank fillrectangle in place of gfx_clear();

	//setting game up
	game_set(set,&set_no);
	wordlist(set, set_no, &max_guess, guess_list, &longest);

	
	pthread_t animation_thread;
	int *peashooter_shoot;
	int *end;
	void *args[] = {(void *)&peashooter_shoot,(void *)&end};
	pthread_create(&animation_thread, NULL, animation, (void *)args);
	
	gfx_clear();
	usleep(10000); //give time for graphics to load and prevent artifacts
	
	//stars
	srand(time(NULL));
	for(i = 0; i < 100; i++){
		gfx_color(255,255,255);
		x = rand()%1300;
		y = rand()&450;
		gfx_fillrectangle(x,y,2,2);
	}

	i = 0;
	while(1){

		if(c == 1){		
			
			start:
			int go = 0, guessed = 0, check = 0;

			house(10,403);
			gfx_color(1, 11, 19);
			gfx_fillrectangle(200,310, 160,25);
			gfx_fillrectangle(89,340, 295,40);

			//center x;
			x_center = ((1300-((50*strlen(set)+(30 * (strlen(set)-1)))))/2);
		
			//Counts repeated letter in set[10]
			if(proceed){
				for(j = 0; j < strlen(set); j++){
					count = 0;
					for(k = 0; k < strlen(set); k++ ){
						if(set[j] == set[k]) count++;
					}
					no_string[j] = count;
				}
			}

			k = 0;
			//Puzzle letters inputs
			printf("x: %d\n", gfx_xpos());
			while((gfx_xpos() >= x_center && gfx_xpos() <= x_center+((strlen(set)-1)*100)) && (gfx_ypos() >= 375 && gfx_ypos() <= 425)){
				
				if(gfx_xpos() >= x_center+(k*100) && gfx_xpos() <= x_center+(k*100)+50){
					ch = set[k];
					proceed = 0;
					tap();
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
						guess_count++;
						guess_index++;
					}
					
				}
				k++;
				if(k > strlen(set)) break;	
			}
			proceed = 0;
			strcpy(guess, chs);
			printf("guess %s\n", chs);

			if((gfx_xpos() >= 1000 && gfx_xpos() <= 1100) && (gfx_ypos() >= 300 && gfx_ypos() <= 350)){
				button_clicked(1000,300,100,50,"Enter", 0);
				tap();
				usleep(10000);
				button(1000,300,100,50,"Enter", 0);
				go = 1;
			}

			//guess evaluation
			if(go){ 
				for(j = 0;j >= 0; j--){
					if (strcmp(correct_guess[j],guess) == 0){

						gfx_color(255,255,255);	
						printf("test\n");
						gfx_text("You have already guessed it!",100, 350,1);
						printf("You have already guessed it!\n");
						printf("-----------------------------------------------\n");
						guessed = 1;
					}
				}
			
				if(guessed == 0){
					gfx_color(1, 11, 19);
					check_guess(&check, guess, &counter, max_guess, guess_list, longest);
				}

				if(check == 1){
					strcpy(correct_guess[counter-1],guess);
					points += 2*strlen(guess);
					peashooter_shoot = (int *)1;
					 
				}

				//reset value
				strcpy(chs," ");
				char no_string[10];
				go = 0;
				proceed = 1;
				guess_count = 0;
				guess_index = 0;	

				if(counter == max_guess) break;
			}
			
			if((gfx_xpos() >= 1230 && gfx_xpos() <= 1330) && (gfx_ypos() >= 15 && gfx_ypos() <= 55)){
				button_clicked(1230,15,100,40,"END?", -20);
				tap();
				goto end;
			}


			if((gfx_xpos() >= 1230 && gfx_xpos() <= 1330) && (gfx_ypos() >= 135 && gfx_ypos() <= 175)){
				button_clicked(1230,135,100,40,"TWIST", -20);
				tap();
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
				proceed = 1;
				guess_index = 0;
				strcpy(guess," ");
				printf("twist value: %d\n", twist);\
				

			}
			
			if((gfx_xpos() >= 1000 && gfx_xpos() <= 1100) && (gfx_ypos() >= 370 && gfx_ypos() <= 420)){
				button_clicked(1000,370,100,50,"Delete", 0);
				tap();
				strcpy(guess," ");
				proceed = 1;
				guess_index = 0;
				guess_count = 0;
			}
	
			sprintf(score,"%d", points);

			//buttons
			button(1230,15,100,40,"END?", -20);
			button(1230,75,100,40,score, -20);
			button(1230,135,100,40,"TWIST", -20);
			button(1000,300,100,50,"Enter", 0);
			button(1000,370,100,50,"Delete", 0);

			//Puzzle letter
			puzzle_letter(x_center, 375, set);
			input_box(x_center, 300, guess, set, guess_count);
			//Guess board
			guess_board(-20, 1300, max_guess, counter, guess_list, correct_guess);
			guess_board_letter(1300, max_guess, counter, guess_list, correct_guess);

		}//max_guess if(c == 1);

		c = gfx_getKey();
	}
	end:
	pthread_cancel(animation_thread);
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
	if(fp == NULL) {
		printf("FILE NOT FOUND\n");
		exit(1);
	}
	while(x > 0){
		fgets(set,10,fp);
		x--;
		
	}
	fclose(fp);
}

//Pull respective gameset's wordlist and store in a array[][].
void wordlist(char set[10], int y, int *max_guess, char string_list[35][10], int *longest){
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

	*max_guess = 0; i = 0; j = 0; k = 0;
	while(fgets(string,10,fp)!=NULL){
		*max_guess += 1;
		string[strcspn(string, "\n")] = '\0';		// read string till '\n' and replace it with '\0'
		strcpy(temp_list[i],string);
		i++;
	}

	//Duplicate handling
	for(i=0;i < *max_guess; i++){
		proceed = 1;
		strcpy(temp,temp_list[i]);

		for(j = 0;j < *max_guess;j++)
			if(strcmp(temp,string_list[j]) == 0){
				proceed=0;
		}

		if(proceed){
			strcpy(string_list[k],temp);
			
			k++;
		}
	}
	*max_guess = k;
	
	//longest string
	for(i = 0; i < *max_guess; i++){
		for(k = 0;k <*max_guess;k++){
			if(strlen(string_list[i])> strlen(string_list[k])){
				*longest = strlen(string_list[i]);
			}
		}
	}
    printf("longest string: %d", *longest);
	printf("file lines %d\n", *max_guess);
	fclose(fp);
}

//Guess evaluation
int check_guess(int *check, char guess[10], int *counter,int max_guess, char string_list[35][10], int longest){
   
   int i = 0, bingo = 0;
	while(i < max_guess){
		printf("string check_guess %s\n", string_list[i]);
		if(strcmp(string_list[i],guess) == 0){
			*check = 1;
			if(strlen(string_list[i]) == longest) bingo = 1;
			break;
		}
		i++;
	}
	gfx_color(255,255,255);
	if(*check && bingo){
		gfx_text("BINGO!",200,310,2);
		printf("%s: BINGO!\n", guess);	
		printf("-----------------------------------------------\n");
		*counter = *counter + 1;
		return 0;
	}
	else if(*check){
		gfx_text("VALID WORD!",200,310,2);
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
				gfx_text("TOO SHORT!",200,310,2);
				printf("TOO SHORT\n");
				printf("-----------------------------------------------\n");
				return 0;
			}
			else if(isdigit(guess[i]) || !isalnum(guess[i])){
				gfx_text("INVALID SYMBOL/NUMBER",200,310,2);
				printf("INVALID SYMBOL/NUMBER %c\n",guess[i]);
				printf("-----------------------------------------------\n");
				return 0;
			}
			i++;
		}while(i < strlen(guess));
		gfx_text("INVALID WORD!",200,310,2);
		printf("INVALID WORD\n");
		printf("-----------------------------------------------\n");
		
		return 0;
	}
}

//Help message
void help(){
	gfx_color(1, 11, 19);
	gfx_fillrectangle(500,200,400,400);
	
	gfx_color(255,255,255);
	gfx_text("Instruction on How To Play.", 400,250,1);			
	gfx_text("You will be given a word.",400,270,1);	
	gfx_text("You may guess using only the letter the word has", 400, 290,1);
	gfx_text("The longer the word you guessed",400,310,1);
	gfx_text("The more points you will achieve. GOODLUCK :)",400,330,1);
	gfx_text("Press anywhere to go back", 400, 350,1);
	gfx_wait();
	gfx_color(1, 11, 19);
	gfx_fillrectangle(300,200,600,400);

}

//Flush leftover inputs
void flush(){
	getchar();
	
	while(getchar() != '\n'){
		printf("Unwanted input detected! Press ENTER to go back");
		while(getchar() != '\n');
	}
}

//End screen
void ended(int points){
	char string[10];
	do{
		int x = 200, y = 250, i = 0, c;
		char score[10];
		gfx_color(1, 11, 19);
		gfx_fillrectangle(0,0,1300,420);
		gfx_fillrectangle(200,0,1300,520);
		gfx_color(255,255,255);
		gfx_text("Goodjob! Points you've managed to achieve:", 200,150,2);
		sprintf(score,"%d",points);
		gfx_text(score, 730,150,2);
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

		gfx_text("Thank you for playing!!", 650, 310, 2);
		gfx_text("Press ANYWHERE to go back", 650, 350, 2);
	}while(gfx_wait() != 0x01);
	
	
	//flush();
}

// gfx_wait() but without the waiting
char gfx_getKey(){
	if(gfx_event_waiting()){
		char key = gfx_wait();
		while(gfx_event_waiting()) {gfx_wait();}
		return key;
	}
}

//Background music
void *bgm(){

    FILE *fp = fopen("bgm.wav", "rb");
	if(fp == NULL) {
		printf("FILE NOT FOUND\n");
		exit(1);
	}

    pa_simple *pa_handle;
    pa_sample_spec pa_spec;
    pa_spec.format = PA_SAMPLE_S16LE;
    pa_spec.channels = 2;
    pa_spec.rate = 44100;

    pa_handle = pa_simple_new(NULL, "play_audio", PA_STREAM_PLAYBACK, NULL, "playback", &pa_spec, NULL, NULL, NULL);
    
    char buffer[4096];
    size_t read_count;
	while(1){
		while((read_count = fread(buffer, sizeof(char), 4096, fp)) > 0){
			pa_simple_write(pa_handle, buffer, read_count, NULL);
		}
	}
    pa_simple_drain(pa_handle, NULL);
    pa_simple_free(pa_handle);

    fclose(fp);
	pthread_exit(NULL);
    
}

//Tap sound feedback
void tap(){

    FILE *fp = fopen("tap.wav", "rb");
	if(fp == NULL) {
		printf("FILE NOT FOUND\n");
		exit(1);
	}

    pa_simple *pa_handle;
    pa_sample_spec pa_spec;
    pa_spec.format = PA_SAMPLE_S16LE;
    pa_spec.channels = 2;
    pa_spec.rate = 44100;

    pa_handle = pa_simple_new(NULL, "play_audio", PA_STREAM_PLAYBACK, NULL, "playback", &pa_spec, NULL, NULL, NULL);
    
    char buffer[4096];
    size_t read_count;
	while((read_count = fread(buffer, sizeof(char), 4096, fp)) > 0){
		pa_simple_write(pa_handle, buffer, read_count, NULL);
	}
    pa_simple_drain(pa_handle, NULL);
    pa_simple_free(pa_handle);

    fclose(fp);
    
}

//Various sprite animation
void *animation(void *args ){

	int re_head_mov = 0, re_head;
	int ice_head_mov = 0, ice_head;
	int pea_head_mov = 0, pea_head, peashooter_bullet_x= 350, peashooter_shoot_mov = 0;
	int *peashooter_shoot_ptr = ((int **)args)[0];
	int zombie_x = 1270, zombie_frame = 1, zombie_alive = 1;
	int x_grass;
	int i, x, y;
	int *end_ptr = ((int **)args)[1];

	while(1){
	
		gfx_color(1, 11, 19);
		gfx_fillrectangle(242,500, 1103,180);
		
		//peashooter animation
		
		if(*peashooter_shoot_ptr == 1) {
			peashooter_shoot_mov = 1;
			*peashooter_shoot_ptr = 0;
		}
		if(peashooter_shoot_mov == 1){
			gfx_color(230,0,0);
			gfx_fillcircle(peashooter_bullet_x,560,20);
			peashooter_bullet_x += 100;
			if(peashooter_bullet_x >= 1280){
				peashooter_shoot_mov = 0;
				peashooter_bullet_x = 350;
			}
		}
		
		if(pea_head_mov){
			pea_head = 308;
			pea_head_mov = 0;
		}
		else{
			pea_head = 300;
			pea_head_mov = 1;
		}
		peashooter_head(pea_head,536);
		peashooter(300,536);
		
		//repeater animation
		if(re_head_mov){
			re_head = 378;
			re_head_mov = 0;
		}
		else{
			re_head = 370;
			re_head_mov = 1;
		}
		repeater_head(re_head,536);
		peashooter(370,536);

		//iceshooter animation
		if(ice_head_mov){
			ice_head = 248;
			ice_head_mov = 0;
		}
		else{
			ice_head = 240;
			ice_head_mov = 1;
		}
		iceshooter_head(ice_head,536);
		peashooter(240,536);
		
		//grass
		for (x_grass=0;x_grass<1300;x_grass+=48){
			grass(x_grass,608);
		}

		//zombie
		if(!zombie_alive) zombie_alive = rand()%2;

		if(zombie_frame == 1 && zombie_alive){
			
			zombie(zombie_x,534);
			zombie_frame = 0;
			zombie_x -= 30;
		}
		else if(zombie_frame == 0 && zombie_alive){
			zombie2(zombie_x,534);
			zombie_frame = 1;
			zombie_x -= 30;
		}
		
		if(peashooter_bullet_x >= zombie_x){
			zombie_alive = 0;
			peashooter_bullet_x = 350;
			peashooter_shoot_mov = 0;
			zombie_x = 1270;
		}
		if(zombie_x < 200) *end_ptr = 1;
		
		usleep(500000);
	}
}

//cloud animation
void *cloud_animation(){
	int cloud_x = 0, baby_x = 0, pea_head_mov= 1, pea_head = 1108;
		
	while(1){
		gfx_color(1, 11, 19);
		gfx_fillrectangle(0,0, 1300,250);
		gfx_color(255,255,255);
		gfx_text("Welcome to TEXT TWIST", 530, 200, 2);
		zombie(1200,534);
		cloud_x += 1;
		baby_x += 2;
		cloud(cloud_x+500,50);
		baby_cloud(baby_x+500,50);
		cloud(cloud_x+200,100);
		baby_cloud(baby_x+200,100);
		cloud(cloud_x-600,100);
		baby_cloud(baby_x-600,100);
		if(cloud_x > 1300){
			cloud_x = -550;
			baby_x = -550;
		}

		if(pea_head_mov){
			pea_head += 1;
		}
		if(!pea_head_mov){
			pea_head -= 1;
		}
		if(pea_head > 1108){
			pea_head_mov = 0;
		}
		if(pea_head < 1100){
			pea_head_mov = 1;
		}
		peashooter_head(pea_head,536);
		peashooter(1100,536);
		gfx_flush();
		usleep(50000);
	}
}