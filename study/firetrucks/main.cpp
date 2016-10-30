#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF numeric_limits<int>::max()
#define MAX_V 10000

vector< pair<int, int> > graph[MAX_V];
vector<int> dijkstra(int _v_cnt, int _src)
{
	vector<int> dist(_v_cnt, INF);
	priority_queue< pair<int, int> > pq;

	cout<< "---------------"<< endl;

	dist[_src] = 0;
	pq.push( make_pair(-dist[_src], _src) );

	while (!pq.empty())
	{
		int currCost = -pq.top().first;
		int currPos = pq.top().second;
		
		cout<< "currCost : "<< currCost<< endl;
		cout<< "currPos : "<< currPos<< endl;
		
		pq.pop();

		if (dist[currPos] < currCost)
			continue;

		for (int i=0; i<graph[currPos].size(); i++)
		{
			int nextCost = currCost + graph[currPos][i].second;
			int nextPos = graph[currPos][i].first;

			cout<< "nextCost : "<< nextCost<< endl;
			cout<< "nextPos : "<< nextPos<< endl;
			cout<< "dist : "<< dist[nextPos]<< endl;

			if (dist[nextPos] > nextCost)
			{
				dist[nextPos] = nextCost;
				pq.push( make_pair(-nextCost, nextPos) );
			}
		}
	}

	return dist;
}

int main(void)
{
	int ret = 0;
	int v_cnt = 0;
	int e_cnt = 0;
	int fire_cnt = 0;
	int firestation_cnt = 0;
	vector<int> fireIdx;
	vector<int> stationIdx;

	cin>> v_cnt;
	cin>> e_cnt;
	cin>> fire_cnt;
	cin>> firestation_cnt;

	for (int i=0; i<e_cnt; i++)
	{
		int currPos = 0;
		int nextPos = 0;
		int cost = 0;

		cin>> currPos;
		cin>> nextPos;
		cin>> cost;

		graph[currPos-1].push_back( make_pair(nextPos-1, cost) );
	}

	for (int i=0; i<fire_cnt; i++)
	{
		int fireTmp = 0;
		
		cin>> fireTmp;
		fireIdx.push_back(fireTmp-1);
	}

	for (int i=0; i<firestation_cnt; i++)
	{
		int stationTmp;
		cin>> stationTmp;
		stationIdx.push_back(stationTmp-1);
	}

	for (int i=1; i<firestation_cnt; i++)
	{
		graph[ stationIdx[0] ].push_back( make_pair(stationIdx[i], 0) );
	}

	for (int i=0; i<fire_cnt; i++)
	{
		ret += dijkstra(v_cnt, stationIdx[0])[ fireIdx[i] ];
		//cout<< i<< "["<< fireIdx[i]<< "] : "<<  dijkstra(v_cnt, stationIdx[0])[ fireIdx[i] ]<< endl;
	}
	cout<< ret<< endl;

	return 0;
}
