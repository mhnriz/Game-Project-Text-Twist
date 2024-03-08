#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void menu();
void play_game();
void game_set();
void wordlist(int *check, char guess[15]);
int check_guess(int check, char guess[15], int *counter);
void help();
void flush();
void ended(int points);

//MAIN

int main(){

	menu();

	return 0;
}

//FUNCTIONS

void menu(){
	
	int choice = 0;
	
	do{
		system("clear");
		printf("Welcome to TEXT TWIST!\n\n");
		printf("1. New game\n2. Help\n3. Exit\n");
		printf("Please choose your option (1~3): ");
		scanf("%d", &choice);
	
		if(choice == 1) play_game();
		else if(choice == 2) help();
		else if(choice == 3) printf("Thanks for playing!!\nExiting...\n");
		else if(choice <= 0 || choice >= 4) flush();
		else printf("Invalid input! Try again.\n");
		 
	}while(choice != 3);
}

void play_game(){
	
	char guess[15];
	int check, counter = 0, i = 0, j, guessed, points = 0;
	char correct_guess[25][10];
	
	system("clear");
	printf("Here is your puzzle:\n\n");
	
	do{
		game_set();
		printf("Guess a word or END to quit: ");
		scanf("%s", guess);
	
		if(strcmp(guess,"END") == 0) break;
		check = 0;
		guessed = 0;
		wordlist(&check, guess);
	
		for(j = i;j >= 0; j--){
			if (strcmp(correct_guess[j],guess) == 0){	
				printf("You have already guessed it!\n");
				printf("-----------------------------------------------\n");
				guessed = 1;
				break;
			}		
		}
	
		if(guessed == 0) check_guess(check, guess, &counter);
	
		if(check == 1 && guessed == 0){
			strcpy(correct_guess[counter-1],guess);
			points += 2*strlen(guess);
		}
	
		if(counter > 0){
			printf("You made the following words so far: ");
			i=0;
			while(i < counter){
				printf("%s ",correct_guess[i]);
				i++;
			}
			printf("\n");	
		}
	}while(counter < 20);
	
	ended(points);
}

void game_set(){
	int x = 1;		// for choosing gameset 1~3
	char line[10];
	
	FILE *fp;
	fp = fopen("GameSets.txt","r");
	
	while(x > 0){
		fgets(line,10,fp);
		x--;
	}
	
	fclose(fp);
	printf("%s\n", line);
}

void wordlist(int *check, char guess[15]){
	char string[10];
	FILE *fp;
	
	fp = fopen("wordlist_Game1.txt","r");
	while(fgets(string,10,fp)!=NULL){
		string[strcspn(string, "\n")] = '\0';		// read string till '\n' and replace it with '\0'
		if(strcmp(string,guess) == 0) *check = 1;
	}
	
	fclose(fp);
}
int check_guess(int check, char guess[15], int *counter){
	
	if(check){
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
	printf("\nInstruction on How To Play.\n\n");
	printf("You will be given a word.\nYou may guess using only the letter the word has.\nThe longer the word you guessed.\nThe more points you will achieve.\nGOODLUCK :)\n\n");	
	printf("Press ENTER to go back");
	
	flush();
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
	
	printf("\nGoodjob! You have managed to get %d points\n\n", points);
	printf("Here's a list of all the words that could be found\n");
	printf("----------------------------------------------------\n");
	
	FILE *fp;
	fp = fopen("wordlist_Game1.txt", "r");
	while(fgets(string,10,fp) !=NULL)
	{
		printf("%s",string);
	}
	
	fclose(fp);
	printf("\nThank you for playing!!\n\n");
	printf("Press ENTER to go back");
	flush();
}
