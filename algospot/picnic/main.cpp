// https://algospot.com/judge/problem/read/PICNIC

#include <iostream>
#include <utility>
#include <vector>
#include <string.h>

using namespace std;

class FindFriend{
	private:
		// first:isFriend, second:isVisit
		int m_friendTable[10][10];
		int m_edgeTable[10][10];
		int m_visitTable[10];
		int m_stdCnt;
		int m_friendCnt;
		int m_findCnt;
		int m_ret;

	public:
		FindFriend(void) {
			// init table
			memset(&m_friendTable, 0, sizeof(int)*10*10);
			memset(&m_edgeTable, 0, sizeof(int)*10*10);
			memset(&m_visitTable, 0, sizeof(int)*10);
			m_visitTable[0] = 1;
			m_findCnt = 1;
			m_ret = 0;

			// input table data
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
			for (int i=0; i<m_friendCnt; ++i) {
				int nextThere = 0;

				cout<< here<< " -> ";
				for (int there=0; there<m_friendCnt; ++there) {
					if (m_friendTable[here][there] == 1
							&& m_edgeTable[here][there] == 0
							&& m_visitTable[there] == 0) {
						nextThere = there;
						m_findCnt++;
						m_edgeTable[here][there] = 1;
						m_edgeTable[there][here] = 1;
						m_visitTable[there] = 1;
						findFriendCnt(there);
					}
				}

				if (m_findCnt == m_stdCnt) {
					cout<< "jjaem"<< endl;
					m_ret++;
					m_findCnt = 1;
					memset(&m_visitTable, 0, sizeof(int)*10);
					m_visitTable[0] = 1;
					m_friendTable[here][nextThere] = 0;
					m_friendTable[nextThere][here] = 0;
					memset(&m_edgeTable, 0, sizeof(int)*10*10);
					cout<< endl;
				}
			}
		}

		void printData(void) {
			cout<< endl;
			cout<< "ret : "<<  m_ret<< endl;
		}

		void debug(void) {
			for (int i=0; i<10; ++i) {
				for (int j=0; j<10; ++j){
					cout<< m_friendTable[i][j]<< " ";
				}
				cout<< endl;
			}
		}

};

int main(void)
{

	FindFriend findFriend;
	findFriend.findFriendCnt(0);
	findFriend.printData();

	return 0;
}
