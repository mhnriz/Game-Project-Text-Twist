#include <stdio.h>
#include <string.h>

int main(){

	char string[][10]= {"bob","mike","angela"};
	int i;
	while(string[i] != '\0'){
		printf("%s",string[i]); 
	 	i++;
	 }
	printf("test\n");
}
