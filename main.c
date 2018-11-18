#include <stdio.h>
#include <stdlib.h>
#include "define.h"

void proccesingLine(char *line);
char *bildFinalyLine(char *line);
FILE *fin;

int main(void)
{
	char line[WIDTH+2];
	char *l;
	if(!(fin = fopen("input.txt","r")))
		return 1;
	while(l = fgets(line,sizeof(line),fin))
	{
		proccesingLine(line);
		l = bildFinalyLine(line);
		printf("%s\n",l);
	}
	system("pause");
	return 0;
}
