#include <stdio.h>

#define MAX_INPUT_CNT	1000
#define MAX_STR_LEN		80

int main()
{
	int i = 0;
	int cnt = 0, idx = 0;
	char strArr[MAX_INPUT_CNT][MAX_STR_LEN + 1] = {{'\0', }, };
	int delIdxArr[MAX_INPUT_CNT] = {0, };
	char tmpCh;

	scanf("%d", &cnt);
	for (i=0; i<cnt; i++)
		scanf("%d %s", &delIdxArr[i], strArr[i]);

	for (i=0; i<cnt; i++)
	{
		idx = delIdxArr[i];
		tmpCh = strArr[i][idx];
		while(tmpCh != '\0')
		{
			strArr[i][idx - 1] = tmpCh;
			tmpCh = strArr[i][++idx];
		}
		strArr[i][--idx] = '\0';

		printf("%d %s\n", i + 1, strArr[i]);
	}

	return 0;
}
