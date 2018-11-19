#include <stdio.h>
#include "define.h"

char *searchNextCommand(char *line);
int getAndSetCommand(char *cmd);
void strCopy(char *s1, char *s2);

extern int cntDeleteChar;
extern int flagEndLine;
extern FILE *fin;

void proccesingLine(char *line)
{
	char extra[WIDTH];
	cntDeleteChar = 0;
	flagEndLine = 0;
	while(*(line = searchNextCommand(line)))
		if(!getAndSetCommand(line))
			line++;
	if(!flagEndLine && cntDeleteChar)
	{
		fgets(extra,cntDeleteChar+1,fin);
		strCopy(line,extra);
		proccesingLine(extra);
	}
}
