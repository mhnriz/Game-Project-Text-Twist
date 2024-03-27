#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
//#include <string.h>
//#include "gfx_mod.c"
#include "gfx.h"

int main()
{
	char string[10] = "DSSEAN";
	int no_string[10];
	int i, j, count = 0;


	for(i = 0;i<strlen(string);i++){
		count = 0;
		for(j = 0;j<strlen(string);j++){
			if(string[i] == string[j]){
				count++;
			}
		}
		no_string[i] = count;

	}
	for(i = 0;i <;i++){
		printf("%d, ", no_string[i]);
	}

}