// https://algospot.com/judge/problem/read/PICNIC

#include <iostream>
#include <string.h>

using namespace std;

class FindFriend{
    private:
        // first:isFriend, second:isVisit
        int m_friendTable[10][10];
        int m_visitTable[10];
        int m_stdCnt;
        int m_ret;
        int m_findCnt;

    public:
        void inputData(void) {
            int friendCnt;

            memset(&m_friendTable, 0, sizeof(int)*10*10);
            memset(&m_visitTable, 0, sizeof(int)*10);
            m_ret = 0;
            m_findCnt = 0;
            
            cin>> m_stdCnt;
            cin>> friendCnt;
            for(int i=0; i<friendCnt; ++i)
            {
                int friend1, friend2;
                cin>> friend1;
                cin>> friend2;
                m_friendTable[friend1][friend2] = 1;
                m_friendTable[friend2][friend1] = 1;
            }
        }

        void findFriendCnt(int here = 0) {
            m_visitTable[here] = 1;

            for (int there = here + 1; there < m_stdCnt; ++there) {
                if (m_friendTable[here][there] == 0 || m_visitTable[there] == 1)
                    continue;

                m_findCnt++;
                m_visitTable[there] = 1;

                for (int nextHere = here; nextHere < m_stdCnt; ++nextHere) {
                    if (m_visitTable[nextHere] == 0)
                        findFriendCnt(nextHere);
                }

                if (m_findCnt == m_stdCnt / 2)
                    m_ret++;

                m_visitTable[there] = 0;
                m_findCnt--;
            }

            m_visitTable[here] = 0;
        }

        void printRet(void) {
            cout<< m_ret<< endl;
        }
};

int main(void)
{
    int testCase = 0;
     cin>> testCase;

    if (testCase == 0)
        cout<< testCase<< endl;

    FindFriend findFriend;
    while(testCase--) {
        findFriend.inputData();
        findFriend.findFriendCnt();
        findFriend.printRet();
    }

    return 0;
}
