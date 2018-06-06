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
        FindFriend(void) {
            // init table
            memset(&m_friendTable, 0, sizeof(int)*10*10);
            memset(&m_visitTable, 0, sizeof(int)*10);
            m_visitTable[0] = 1;
            m_ret = 0;
            m_findCnt = 0;
        }

        void inputData(void) {
            int friendCnt;
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
            findFriendCnt();
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
        findFriend.findFriendCnt();
        findFriend.printRet();
    // }

    return 0;
}
