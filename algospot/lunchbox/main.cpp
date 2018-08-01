// https://algospot.com/judge/problem/read/LUNCHBOX

#include <iostream>
#include <string>
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
        double aRate = ( a.getMwT() / a.getEatT() ) * ( a.getEatT() + a.getMwT() );
        double bRate = ( b.getMwT() / b.getEatT() ) * ( b.getEatT() + b.getMwT() );
        return ( aRate < bRate );
    }
};

int main(void)
{
    priority_queue<Box, vector<Box>, BoxCmp> pq;

    int boxCnt = 0;

    cin>> boxCnt;

    Box boxArr[boxCnt];

    for (int i=0; i<boxCnt; ++i) {
        int tmp;
        cin>> tmp;
        boxArr[i].setMwT(tmp);
    }
    
    for (int i=0; i<boxCnt; ++i) {
        int tmp;
        cin>> tmp;
        boxArr[i].setEatT(tmp);
    }

    for (int i=0; i<boxCnt; ++i) {
        pq.push(boxArr[i]);
    }

    for (int i=0; i<boxCnt; ++i) {
        Box box = pq.top();
        pq.pop();
        cout << box.getMwT();
    }
    
    return 0;
}

/*
2
3
2 2 2
2 2 2
3
1 2 3
1 2 1
*/