#include <stdio.h>
#include "define.h"
#include "format.h"

extern int formatFlag;
extern int numEnd;
extern int numBegin;
extern int cntCharacter;

void strCopyN(char *s1,char *s2, int num);

char *bildFinalyLine(char *line)
{
	static char finalyLine[WIDTH+1];

	numBegin--;
	sprintf(finalyLine,"%*s",numBegin,"");

	switch(formatFlag)
	{
	case 0:
		strCopyN(finalyLine+numBegin,line,numEnd-numBegin);
		break;

	case 1:
		formatLeft(finalyLine + numBegin, line);
		break;

	case 2:
		formatRight(finalyLine + numBegin, line);
		break;

	case 3:
		formatCenter(finalyLine + numBegin, line);
		break;

	case 4:
		formatLeftAndRight(finalyLine + numBegin, line);
		break;
	}

	finalyLine[numEnd] ='\0';

	numBegin = 1;
	numEnd = WIDTH;
	cntCharacter = 0;

	return finalyLine;
}
