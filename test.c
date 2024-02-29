#include <stdio.h>
#include <string.h>
int main()
{
	int i, points =0;
	char guess[10], string[10];
	FILE *list;
	list = fopen("wordlist_Game1.txt", "r");
	
	while(fgets(string,10,list) != NULL){
		printf("%s", string);
		scanf("%s",guess);
		string[strcspn(string,"\n")] = '\0';		//strcspn(); read line till "\n" and replace it with \0.
		if(strcmp(guess,string) == 0)
			printf("yayy");
		}
	/*do{
		fgets(string,10,list);
		if(strcmp(string,guess) ==0
			points += 1;
	}while*/
}       
