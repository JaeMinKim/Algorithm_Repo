#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

#define INF numeric_limits<float>::max()
#define MAX_V 10000

// pair<dest, cost>
vector<pair<int, float> > graph[MAX_V];

// cnt : node cnt
// src : start point
vector<float> dijkstra(int cnt, int src)
{
	// dist : shortist list
	vector<float> dist(cnt, INF);
	// pq : priority queue
	// pair <cost, dest>
	priority_queue< pair<float, int> > pq;

	// init src & pq
	dist[src] = 1;
	pq.push(make_pair(-dist[src], src) );

	// find shortist
	while (!pq.empty())
	{
		float cost = -pq.top().first;
		int currPos = pq.top().second;

		pq.pop();

		if (dist[currPos] < cost) continue;

		for (int i=0; i<graph[currPos].size(); i++)
		{
			float nextCost = cost * graph[currPos][i].second;
			int nextPos = graph[currPos][i].first;

			if (dist[nextPos] > nextCost)
			{
				dist[nextPos] = nextCost;
				pq.push(make_pair(-nextCost, nextPos) );
			}
		}
	}

	return dist;
}

int main(void)
{
	int testCase = 0;
	int nodeCnt = 0;
	int edgeCnt = 0;

	cin>> nodeCnt;
	cin>> edgeCnt;

	for (int i=0; i<edgeCnt; i++)
	{
		int curr = 0;
		int dest = 0;
		float cost = 0;

		cin>> curr;
		cin>> dest;
		cin>> cost;

		graph[curr].push_back( make_pair(dest, cost) );
	}

	cout<< dijkstra(nodeCnt, 0)[nodeCnt-1]<< endl;

	return 0;
}
