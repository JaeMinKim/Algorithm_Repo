#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 1000

int main()
{
	int i = 0, j = 0;
	char inputStr[MAX_STR_LEN + 1] = {'\0', };
	char buffCh;
	int cnt;

	scanf("%d", &cnt);

	while(cnt--)
	{	
		scanf("%s", inputStr);

		for (i=0; i<strlen(inputStr); i+=2)
		{
			for (j=i+2; j<strlen(inputStr); j+=2)
			{
				if (inputStr[i] > inputStr[j])
				{
					buffCh = inputStr[j];
					inputStr[j] = inputStr[i];
					inputStr[i] = buffCh;

					buffCh = inputStr[j+1];
					inputStr[j+1] = inputStr[i+1];
					inputStr[i+1] = buffCh;
				}
				else if(inputStr[i] == inputStr[j])
				{
					if (inputStr[i+1] > inputStr[j+1])
					{
						buffCh = inputStr[j+1];
						inputStr[j+1] = inputStr[i+1];
						inputStr[i+1] = buffCh;
					}
				}
			}
		}

		printf("%s\n", inputStr);
	}
	return 0;
}
