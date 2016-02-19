#include <iostream>

using namespace std;

int numSplit(int sum, int max)
{
	int result = 0;

	if ( max > sum )
		max = sum;

	cout<< " "<< max;

	if ( max == sum )
	{
		cout<< endl;
		result++;

		if (max > 1)
			max--;
	}

	if ( sum > max )
	{
		result += numSplit( (sum-max), max );
	}

	while ( max > 1 )
		result += numSplit( (sum-max), --max );


	return result;
}

int main(void)
{
	int sum = 0;
	int max = 1;

	cout<< "input(sum max) : ";
	cin>> sum>> max;

	cout<< "result : "<< numSplit(sum, max)<< endl;

	return 0;
}
