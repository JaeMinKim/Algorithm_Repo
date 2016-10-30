#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;


class InputSource
{
	private:
		int startVal, a, b;

	public:
		InputSource(int _startVal, int _a, int _b) : startVal(_startVal), a(_a), b(_b) {}

		int getInput(int idx)
		{
			int ret = startVal;

			for (int i=idx; i>0; i--)
			{
				ret = ( getInput(i-1) * a + b) % 20090711;
			}

			return ret;
		}
};

int runningMedian(int cnt, int _a, int _b)
{
	int ret = 0;
	InputSource inputSrc(1983, _a, _b);
	priority_queue < int, vector<int>, less<int> > maxHeap;
	priority_queue < int, vector<int>, greater<int> > minHeap;


	for(int i=0; i<cnt; i++)
	{
		if (maxHeap.size() == minHeap.size())
			maxHeap.push(inputSrc.getInput(i));
		else
			minHeap.push(inputSrc.getInput(i));

		if ( (!maxHeap.empty() && !minHeap.empty())
				&& (maxHeap.top() > minHeap.top()) )
		{
			int maxTmp = maxHeap.top();
			int minTmp = minHeap.top();

			maxHeap.pop();
			minHeap.pop();

			maxHeap.push(minTmp);
			minHeap.push(maxTmp);
		}

		ret = maxHeap.top();
	}

	return ret;
}

int main(void)
{
	cout<< runningMedian(10, 1, 0)<< endl;
	cout<< runningMedian(10, 1, 1)<< endl;
	cout<< runningMedian(10000, 1273, 4936)<< endl;
}
