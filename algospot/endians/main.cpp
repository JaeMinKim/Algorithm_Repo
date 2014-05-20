#include <stdio.h>

#define MASK_DATA 0x000000FF

int main()
{
	unsigned int inputNum = 0;
	int inputCnt = 0;
	unsigned int resultNum  = 0;
	unsigned int numSize = 0;

	scanf("%d", &inputCnt);

	for (int j=0; j<inputCnt; j++)
	{
		inputNum = 0;
		resultNum = 0;
		numSize = 0;

		scanf("%u", &inputNum);
		numSize = sizeof(inputNum);

		resultNum += inputNum & MASK_DATA;

		for (int i=0; i<numSize-1; i++)
		{
			resultNum = resultNum << 8;
			inputNum = inputNum >> 8;

			resultNum += inputNum & MASK_DATA;
		}

		printf("%u\n", resultNum);
	}

	return 0;
}
