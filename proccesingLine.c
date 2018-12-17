#include <stdio.h>
#include "def.h"

char *searchNextCommand(char *line);
int getAndSetCommand(char *cmd);
void strCopy(char *s1, char *s2);

extern int cntDeleteChar;
extern int flagEndLine;
extern FILE *fin;

void proccesingLine(char *line)
{
	char extra[WIDTH+1];
	char *tmp;
	char *b;
	char buffer[WIDTH+WIDTH];
	strCopy(buffer,line);
	tmp = buffer;
	b = buffer;
	cntDeleteChar = 0;
	flagEndLine = 0;
	while(*(b = searchNextCommand(b)))
		if(!getAndSetCommand(b))
			b++;
	if(line && !flagEndLine && cntDeleteChar)
	{
		extra[0] = 0;
		fgets(extra,cntDeleteChar+3,fin);
		strCopy(b,extra);
		proccesingLine(tmp);
	}
	strCopy(line,buffer);
}