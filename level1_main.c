#include <stdio.h>
#include <stdlib.h>

void help();
void play_game();
void menu();
void game_set();

// MAIN
int main()
{
    menu();
    return 0;
}

// FUNCTIONS
void play_game()
{
    system("clear");
    printf("Here is your puzzle:\n\n");
    game_set();
}

void help()
{
    printf("Instruction on How To Play.\n\n");
    /*
        INSERT INSTRUCTION
    */
    printf("Press ENTER to go back");
    //int c;
    //while ((c = getchar()) != '\n' && c != EOF); //loop getchar() till no input buffer
    getchar();
    getchar();
}

void game_set()
{
    char line[10];
    FILE *file;
    file = fopen("GameSets.txt", "r");
    fgets(line, 10, file);
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
        if (choice == 3)
        {
            printf("Thanks for playing!");
            printf("\nExiting...\n");

        }
    } while (choice != 3);
}
