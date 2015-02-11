#include <stdio.h>

#define MAX_TIME 9

int main()
{
	int floor = 0;
	int targetW = 0;
	int tmpW = 0;
	int sumW = 0;
	int i = 0;

	scanf("%d", &floor);

	while (floor != 0)
	{
		floor--;

		scanf("%d", &targetW);
		
		for(i=0; i<MAX_TIME; i++)
		{
			scanf("%d", &tmpW);
			sumW += tmpW;
		}

		printf("%s\n", (targetW >= sumW ? "YES" : "NO") );

		sumW = 0;
		tmpW = 0;
	}
	
	return 0;
}
