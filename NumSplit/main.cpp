#include <iostream>

using namespace std;

int numSplit(int sumNum, int maxNum)
{
	int cnt = 0;

	if ( sumNum == maxNum)
	{
		cnt ++;
	}
	else if ( sumNum > maxNum )
	{
	}


	return cnt;
}

int main(void)
{
	int sumNum = 0;
	int maxNum = 1;

	cout<< "input(sum max) : ";
	cin>> sumNum>> maxNum;

	cout<< "result : "<< numSplit(sumNum, maxNum)<< endl;

	return 0;
}
