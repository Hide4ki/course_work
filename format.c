#include <stdio.h>
#include "format.h"
#include "def.h"

void strCopyN(char *s1,char *s2, int num);

extern int formatFlag;
extern int numEnd;
extern int numBegin;
extern int cntCharacter;

void format(char *finalyLine, char *line)
{
	switch(formatFlag)
	{
	case 0:
		strCopyN(finalyLine,line,numEnd-numBegin);
		break;

	case 1:
		formatLeft(finalyLine, line);
		break;

	case 2:
		formatRight(finalyLine, line);
		break;

	case 3:
		formatCenter(finalyLine, line);
		break;

	case 4:
		formatLeftAndRight(finalyLine, line);
		break;
	}
}

void formatLeft(char *finalyLine, char *line)
{
	while(*line && *line == ' ')
		line++;
	strCopyN(finalyLine,line,numEnd-numBegin);
}

void formatRight(char *finalyLine, char *line)
{
	while(*(line+cntCharacter-1)==' ')
		cntCharacter--;
	if(numEnd - numBegin<cntCharacter)
		cntCharacter = numEnd - numBegin + 1;
	sprintf(finalyLine,"%*s",numEnd - numBegin - cntCharacter + 1,"");
	strCopyN(finalyLine + numEnd - numBegin - cntCharacter + 1,line,cntCharacter);
}

void formatCenter(char *finalyLine, char *line)
{
	int cntInterval;
	int offset;
	int numSpaces;
	int numPlaces;
	int space_a_place;
	int extraSpace;
	int tmp;
	char *pStartCharInterval[WIDTH/2+1];
	char *l; 
	char *nowInterval;

	l = line;
	for(cntInterval = 1; cntInterval<WIDTH/2; cntInterval++)
		pStartCharInterval[cntInterval] = l;
	cntInterval = 0; 
	pStartCharInterval[cntInterval] = 0; 
	offset = 0;

	for(;*l;l++)
	{ 
		if(*l==' ') 
			pStartCharInterval[cntInterval] = 0; 
		else 
		{ 
			if(!pStartCharInterval[cntInterval]) pStartCharInterval[cntInterval++] = finalyLine + offset; 
			*(finalyLine + offset++) = *l;
			if(offset>numEnd-numBegin-cntInterval)
				break;
		} 
	}
	numSpaces = numEnd - numBegin - offset; 
	numPlaces = cntInterval - 1; 

	if(numPlaces <= 0) 
	{
		*(finalyLine + offset) = '\0'; 
		return;
	}

	space_a_place = numSpaces / numPlaces; 
	extraSpace = numSpaces % numPlaces; 
	l = finalyLine+numEnd -numBegin-1; 
	pStartCharInterval[cntInterval--] = finalyLine+offset; 
	offset = 0; 

	while(cntInterval>=0) 
	{ 
		offset++; 
		nowInterval = pStartCharInterval[cntInterval+1]-1; 

		while(nowInterval!=pStartCharInterval[cntInterval]) 
			*l-- = *nowInterval--;
		*l-- = *nowInterval--;

		tmp = space_a_place;
		while((tmp-->0) && (numSpaces-->0))
			*l-- = ' ';
		if(extraSpace-->0) 
		{ 
			numSpaces--; 
			*l-- = ' '; 
		} 
		cntInterval--; 
	} 
}

void formatLeftAndRight(char *finalyLine, char *line)
{
	int offset;
	if(numEnd - numBegin>cntCharacter)
		offset = (numEnd - numBegin - cntCharacter + 1)/2;
	else
		offset = 0;
	sprintf(finalyLine,"%*s",offset,"");
	strCopyN(finalyLine + offset,line,cntCharacter);
	sprintf(finalyLine + offset+cntCharacter,"%*s",offset,"");
}