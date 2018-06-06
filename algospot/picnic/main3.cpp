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
        int m_friendCnt;
        int m_ret;
        int m_findCnt;

    public:
        FindFriend(void) {
            // init table
            memset(&m_friendTable, 0, sizeof(int)*10*10);
            memset(&m_visitTable, 0, sizeof(int)*10);
            m_visitTable[0] = 1;
            m_ret = 0;
            m_findCnt = 1;
        }

        void inputData(void) {
            cin>> m_stdCnt;
            cin>> m_friendCnt;
            for(int i=0; i<m_friendCnt; ++i)
            {
                int friend1, friend2;
                cin>> friend1;
                cin>> friend2;
                m_friendTable[friend1][friend2] = 1;
                m_friendTable[friend2][friend1] = 1;
            }
        }

        void findFriendCnt(int here = 0) {
            for (int there=0; there<m_stdCnt; ++there) {
                if (m_friendTable[here][there] == 1	&& m_visitTable[there] == 0) {
                    m_findCnt++;

                    if (m_findCnt%2 == 0 && here > there) {
                        m_findCnt--;
                        break;
                    }

                    m_visitTable[there] = 1;
                    m_friendTable[here][there] = 0;
                    m_friendTable[there][here] = 0;
                    findFriendCnt(there);
                    m_friendTable[here][there] = 1;
                    m_friendTable[there][here] = 1;
                }
            }

            if (m_findCnt == m_stdCnt)
                m_ret++;

            m_visitTable[here] = 0;
            m_findCnt--;
        }

        void printRet(void) {
            cout<< m_ret<< endl;
        }
};

int main(void)
{
    int testCase = 0;
    // cin>> testCase;

    // while(testCase--) {
        FindFriend findFriend;
        findFriend.inputData();
        findFriend.findFriendCnt(0);
        findFriend.printRet();
    // }

    return 0;
}
