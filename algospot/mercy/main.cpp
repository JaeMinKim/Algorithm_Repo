#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0;
	int cnt = 0;
	char* printStr = "Hello Algospot!";

	scanf("%d", &cnt);

	for (i=0; i<cnt; i++)
	{
		printf("%s\n", printStr);
	}

	return 0;
}
