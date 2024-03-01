#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void help();
void play_game();
void menu();
void game_set();
void flush();
void guesses(int *check, char guess[10], int *end);
void ended(int points);

// MAIN
int main()
{
	menu();
	return 0;
}

// FUNCTIONS
void play_game()
{
	int check = 0, points = 0, i = 0, j, k, end;
	char guess[16];
	char guessed[25][10];

	system("clear");
	printf("Here is your puzzle:\n\n");

	do
	{
		game_set();
		if (check)
		{
			for(j = i;j >= 0; j--)
			{
				if (strcmp(guessed[j],guess) == 0)
				{
					k = 1;
					break;
				}		
			}
			if (k == 1)
				printf("You have already guessed it! \n");
			else
			{
				points += 2 * strlen(guess);
				strcpy(guessed[i], guess);
				i++;
			}
			k = 0;
		}
		if (i >= 1)
		{
			printf("points so far: %d\n", points);
			printf("You have made the following words so far: \n");
			for (j = 0; j <= i; j++)
				printf("%s ", guessed[j-1]);
			printf("\n\n");
		}
		if(i >= end)
			break;
		printf("Guess a word or END to quit: ");
		scanf("%s", guess);
		if(strcmp(guess, "END") == 0)	// strcmp: string comparison; if true return 0
			break;
		guesses(&check, guess, &end);
	} while (1);
	
	ended(points);
}

void help()
{
	printf("\nInstruction on How To Play.\n\n");
	printf("You will be given a word.\nYou may guess using only the letter the word has.\nThe longer the word you guessed.\nThe more points you will achieve.\nGOODLUCK :)\n\n");	
	printf("Press ENTER to go back");
	flush();
}

void game_set()
{
	char line[10];
	int x = 1; // no. for gameset
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
	do
	{
		system("clear");
		printf("Welcome to TEXT TWIST!\n\n");
		printf("1. New game\n2. Help\n3. Exit\nPlease choose your option (1~3): ");
		scanf("%d", &choice);
		if (choice == 1)
			play_game();
		else if (choice == 2)
			help();
		else if (choice == 3)
			printf("Thanks for playing!!\nExiting...\n");
		else
			printf("Invalid input! Try again.\n");
	} while (choice != 3);
}

void flush()
{
	int c;
	getchar();		//not sure why i need to do this separately to make it work
	while ((c = getchar()) != '\n' && c != EOF)		//loop getchar till no input buffer
	{
		printf("Unwanted input detected! Press ENTER to go back");
		while ((c = getchar()) != '\n' && c != EOF);
	}
}

void guesses(int *check, char guess[10], int *end)
{
	int i = 0, j;
	*end = 0;
	char string[10];
	FILE *list;
	list = fopen("wordlist_Game1.txt", "r");
	while (fgets(string, 10, list))
	{
		string[strcspn(string, "\n")] = '\0';		// strcspn() read string till '\n' and replace with '\0'.
		if (strcmp(string, guess) == 0)
			j = 1;
		i++;
	}
	*end = i;
	if (j == 1)
	{
		printf("%s: VALID WORD\n", guess);
		printf("----------------------------------------------\n");

		*check = 1;
	}
	else
	{
		printf("%s: INVALID WORD\n", guess);
		printf("----------------------------------------------\n");
		*check = 0;
	}	
	fclose(list);
}

void ended(int points)
{
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
	
	printf("\nThank you for playing!!\n\n");
	printf("Press ENTER to go back");
	flush();
}
