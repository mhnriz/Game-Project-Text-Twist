#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void help();
void play_game();
void menu();
void game_set();
void flush();
void guesses(int *check, int *point, char guess[10], int *end);
void existed(char found[]);

// MAIN
int main()
{
    menu();
    return 0;
}

// FUNCTIONS
void play_game()
{	
	int check = 0, points = 0, i = -1, j, end = 0;
	char guess[16];
	char guessed[25][10];
    
    system("clear");
    printf("Here is your puzzle:\n\n");
    
    do{
    	game_set();	
    	
    	if(check){
    		i++;
    		strcpy(guessed[i], guess);
    	}
    	
    	if(i >= 0)
    	{
    		printf("points so far: %d\n", points);
    		printf("You have made the following words so far: \n");
    	}
    	
    	for(j = 0; j <= i; j++)
    		printf("%s ", guessed[j]);
    	
    	if(i>=0)
    		printf("\n\n");
    	
    	printf("Guess a word or END to quit: ");
    	scanf("%s",guess);
    	guesses(&check,&points, guess, &end);
    	
    }while (strcmp(guess,"END") != 0 || i == end);		//strcmp: string comparison; if true returnn 0
}

void help()
{
    printf("Instruction on How To Play.\n\n");
    /*
        INSERT INSTRUCTION
    */
    printf("Press ENTER to go back");
    getchar();
    flush();
}

void game_set()
{
    char line[10];
    int x = 1;		// no. for gameset
    FILE *set;
    set = fopen("GameSets.txt", "r");
    while (0 < x)
    {
    	fgets(line, 10, set);
    	x--;
    }
    printf("%s\n", line);
}

void menu()
{
	int choice = 0;
	do{
    	system("clear");
    	printf("Welcome to TEXT TWIST!\n\n");
    	printf("1. New game\n2. Help\n3. Exit\nPlease choose your option (1~3): ");
        scanf("%d", &choice);
        if(choice == 1)
        	play_game();
        else if(choice == 2)
        	help();
        else if(choice == 3)
        	printf("Thanks for playing!!\nExiting...\n");
    	else
    		printf("Invalid input! Try again.\n");
    }while (choice != 3);
}

void flush()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
	{
		printf("Unwanted input detected! Press ENTER to go back");
		while((c = getchar()) != '\n' && c != EOF);
	}
}

void guesses(int *check, int *points, char guess[10], int *end)
{
	int i = 0, j;
	char string[10];
	FILE *list;
	list = fopen("wordlist_Game1.txt", "r");
	while(fgets(string,10,list)){
		string[strcspn(string,"\n")]= '\0';		//strcspn() read string till '\n' and replace with '\0'.	
		if(strcmp(string,guess)==0)
			j = 1;
	}
	
	if(j == 1)
	{
		printf("%s: VALID WORD\n", guess);
		printf("----------------------------------------------\n");
		*points += 2*strlen(guess);
		*check = 1;
		}
	else
	{
		printf("%s: INVALID WORD\n", guess);
		printf("----------------------------------------------\n");
		*check = 0;
		}	
	while(fgets(string,10,list))
		*end += 1;
	fclose(list);
	
}

void existed(char found[]){
			
	}

