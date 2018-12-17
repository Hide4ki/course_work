#include <stdio.h>
#include <stdlib.h>
#include "format.h"
#include "def.h"

extern int formatFlag;
extern int numEnd;
extern int numBegin;
extern int cntCharacter;

void strCopyN(char *s1,char *s2, int num);

char *bildFinalyLine(char *line)
{
	static char finalyLine[WIDTH+1];

	numBegin--;
	if(numEnd-numBegin > WIDTH)
	{
		printf("Error, format place very far");
		exit(2);
	}
	fprintf(stdout,"%*s",numBegin,"");
	sprintf(finalyLine,"%*s",sizeof(finalyLine)-1,"");
	format(finalyLine, line);

	finalyLine[numEnd] ='\0';

	numBegin = 1;
	numEnd = WIDTH;
	cntCharacter = 0;

	return finalyLine;
}
