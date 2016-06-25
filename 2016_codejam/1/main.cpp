#include <iostream>
#include <vector>

using namespace std;

class Node
{
	private:
		static vector<Node*> _node_list;
		double _parent;
		double _child;

	public:
		Node (double p, double c) : _parent(p), _child(c)
		{
			_node_list.push_back(this);
		}
		double find_parent(vector<Node*> _list);
		double find_child(vector<Node*> _list);
};
vector<Node*> Node::_node_list;

int main()
{
	double case_cnt = 0;
	double people_cnt = 0;
	double tmp_p = 0;
	double tmp_c = 0;

	cin>> case_cnt;
	while(case_cnt--)
	{
		cin>> people_cnt;
		while(people_cnt--)
		{
			cin>> tmp_p;
			cin>> tmp_c;

			Node* tmp_node = new Node(tmp_p, tmp_c);
		}
	}

	return 0;
}
