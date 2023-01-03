#include <stdio.h>
#include <stdlib.h>

char* inputString()
{
	char* str;
	int ch;
	int len_max = 5;
	int len = 0;

	str = (char*)malloc(sizeof(char) * len_max);
	if (!str)
	{
		return str;
	}

	while ((ch = getchar()) != '\n' && ch != EOF)
	{
		str[len++] = ch;

		if (len == len_max)
		{
			str = (char*)realloc(str, sizeof(char) * (len_max += len));
			if (!str)
			{
				return str;
			}
		}
	}

	str[len++] = '\0';
	str = (char*)realloc(str, sizeof(char) * len);

	return str;
}

int main(void)
{
	printf("Input a string : ");
	char* str1 = inputString();
	printf("\n\nOutput string  : %s\n", str1);

	free(str1);
	return 0;
}