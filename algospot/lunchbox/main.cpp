// https://algospot.com/judge/problem/read/LUNCHBOX

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Box{
    private:
    int mwT;
    int eatT;

    public:
    int  getMwT() { return mwT; }
    void setMwT(int _mwT) { mwT = _mwT; }
    int  getEatT() { return eatT; }
    void setEatT(int _eatT) { eatT = _eatT; }
};

struct BoxCmp {
    bool operator()(Box a, Box b) {
        return a.getEatT() < b.getEatT();
    }
};

int main(void)
{
    priority_queue<Box, vector<Box>, BoxCmp> pq;
    Box boxArr[10000];

    int testCnt = 0;
    cin>> testCnt;

    while (testCnt--)
    {
        int boxCnt = 0;
        cin >> boxCnt;

        for (int i = 0; i < boxCnt; ++i)
        {
            int tmp;
            cin >> tmp;
            boxArr[i].setMwT(tmp);
        }

        for (int i = 0; i < boxCnt; ++i)
        {
            int tmp;
            cin >> tmp;
            boxArr[i].setEatT(tmp);
        }

        for (int i = 0; i < boxCnt; ++i)
            pq.push(boxArr[i]);

        int expLT = 0;
        int totalMwT = 0;
        for (int i = 0; i < boxCnt; ++i)
        {
            Box box = pq.top();
            pq.pop();

            if ((expLT - totalMwT) < (box.getMwT() + box.getEatT()))
                expLT = totalMwT + box.getMwT() + box.getEatT();

            totalMwT += box.getMwT();
        }
        cout << expLT << endl;
    }

    return 0;
}

/*
4
3
2 2 2
2 2 2
3
1 2 3
1 2 1
2
1 100
100 1
2
1 2
4 4
*/