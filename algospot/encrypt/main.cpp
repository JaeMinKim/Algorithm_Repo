#include <stdio.h>

#define MAX_STR_LEN		100
#define MAX_INPUT_CNT	10

int main()
{
	int i, j;
	char inputStr[MAX_INPUT_CNT+1][MAX_STR_LEN + 1] = {{'\0', }, };
	int cnt = 0;

	scanf("%d", &cnt);
	for (i=0; i<cnt; i++)
		scanf("%s", inputStr[i]);

	i = 0;
	while(cnt--)
	{
		j = 0;
		while(inputStr[i][j] != '\0')
		{
			if (j % 2 == 0)	printf("%c", inputStr[i][j]);
			j++;
		}

		j = 0;
		while(inputStr[i][j] != '\0')
		{
			if (j % 2 != 0)	printf("%c", inputStr[i][j]);
			j++;
		}

		printf("\n");
		i++;
	}

	return 0;
}
