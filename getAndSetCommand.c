#include <stdio.h>
#include "def.h"

int formatFlag = 0;
int numEnd = WIDTH;
int numBegin = 1;
int cntDeleteChar;

void strCopy(char *s1, char *s2);

int getAndSetCommand(char *cmd)
{
	int i = 0;
    int tmp;
	char *start;
	int offset;
	offset = 0;
	start = cmd;
	cmd++;
	if(*(cmd))
	{
		switch(*cmd)
		{
		case 'f':
			cmd++;
			if(*(cmd))
			{
				switch(*cmd)
				{
				case 'n':
					formatFlag = 0;
					break;
				case 'l':
					formatFlag = 1;
					break;
				case 'r':
					formatFlag = 2;
					break;
				case 'b':
					formatFlag = 3;
					break;
				case 'c':
					formatFlag = 4;
					break;
				default:
					return 0;
					break;
				}
				if(*cmd)
				{
					cmd++;
					strCopy(start,cmd);
				}
			}else return 0;
			break;
		case 'b':
			cmd++;
			if(sscanf(cmd,"%d%n",&numBegin,&offset))
			{
				tmp = 0;
				sscanf(cmd,"%*d%*[']%n",&tmp);
				offset += tmp?1:0;
				strCopy(start,cmd+offset);
			}
			else
				return 0;
			break;
		case 'e':
			cmd++;
			if(sscanf(cmd,"%d%n",&numEnd,&offset))	
			{
				tmp = 0;
				sscanf(cmd,"%*d%*[']%n",&tmp);
				offset += tmp?1:0;
				strCopy(start,cmd+offset);
			}
			else
				return 0;
			break;
		default:
			return 0;
			break;
		}
	}
	else return 0;

	cntDeleteChar += cmd + offset - start;

	return 1;
}