#include <stdio.h>

void help();
void play_game();

// MAIN
int main()
{
    int choice;
    printf("Welcome to Text Twist!\n\n");
    printf("1. New game\n2. Help\n3. Exit\nPlease choose your option (1~3): ");
    do
    {
        scanf("%d", choice);
        if (choice == 1)
            play_game();
        else if (choice == 2)
            help();

    } while (0);

    return 0;
}

// FUNCTIONS
void play_game()
{
}

void help()
{

    printf("Instruction on How To Play.\n\n");
    /*
        INSERT INSTRUCTION
    */
    printf("Press ENTER to go back");
    getc(stdin);
}