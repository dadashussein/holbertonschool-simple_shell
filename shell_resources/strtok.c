#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *str = "This is a separated word by spaces";
	char *stc = malloc(sizeof(char) * (strlen(str) + 1));
	char delim[5] = " ";
	char *trunks;
	int i;

	strcpy(stc, str);
	trunks = strtok(stc, delim);

	while (trunks != NULL)
	{
		printf("%s\n", trunks);
		trunks = strtok(NULL, delim);
	}

	for (i = 0; i < 35; i++)
	{
		if (stc[i] == '\0')
			printf("\\0");
		else
		printf("%c", stc[i]);
	}
	
	free(stc);
	return (0);
}
