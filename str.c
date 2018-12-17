void strCopy(char *s1, char *s2)
{
	while(*s1++ = *s2++)
		;
}

void strCopyN(char *s1,char *s2, int num)
{


	while((*s1++ = *s2++) && num--)
		;
}
