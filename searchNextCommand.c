int cntCharacter = 0;
int flagEndLine;

char *searchNextCommand(char *line)
{
	line--;
	do
	{
		line++;
		if(*line == '\n')
		{
			flagEndLine = 1;
			*line = '\0';
		}
		if(*line == '%')
				return line;
		cntCharacter++;
	}
	while(*line);
	return line;
}