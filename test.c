#include <stdio.h>
#include <string.h>

void file(char string_list[25][10]);

int main(){
	char string_list[25][10];
	file(string_list);
	printf("string = %s\n", string_list[2]);
}

void file(char string_list[25][10]){
	int i = 0;
	char string[10];
	FILE *fp;
	fp = fopen("wordlist_Game1.txt", "r");
	
	while(fgets(string, 10, fp)!='\0'){
		strcmp(string_list[i],string);
		i++;
	}
}