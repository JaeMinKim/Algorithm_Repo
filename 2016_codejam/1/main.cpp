#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Node
{
	private:
		double parent;
		double child;

	public:
		Node (double p, double c) : parent(p), child(c) {}
		double get_child(void) { return child; }
		double get_parent(void) { return parent; }
};

class NodeList
{
	private:
		vector<Node*> node_list;
		vector<double> curr_gen_list;
		vector<double> prev_gen_list;
		double child_sum;
		double people_cnt;
		double gen;

	public:
		NodeList (double p_cnt) : people_cnt(p_cnt), child_sum(0), gen(0)
		{
			node_list.clear(); curr_gen_list.clear();
		};

		void add_node(Node* node) { node_list.push_back(node); child_sum += node->get_child(); }
		double find_1st_parent(void);
		double find_child(double _parent);
		double get_gen_cnt() { return gen; } 

};

double NodeList::find_1st_parent(void)
{
	double t_child_sum = 0;

	for (int i=0; i<people_cnt; i++)
	{
		t_child_sum += (i + 1);
	}

	return (child_sum - t_child_sum);
}

double NodeList::find_child(double _parent)
{
	for (int i=0; i<node_list.size(); i++)
	{
		if( node_list[i]->get_parent() == _parent)
		{
			curr_gen_list.push_;
		}
	}
}

int main(int argc, char* argv[])
{
	ifstream input_file; //(argv[1], ios::in | ios::binary);
	ofstream output_file;
	double case_cnt = 0;
	double people_cnt = 0;
	double tmp_p = 0;
	double tmp_c = 0;
	string file_name = argv[1];

	// file i/o setting
	input_file.open(file_name);
	file_name = file_name.substr( 0, file_name.find(".") ) + ".out";
	output_file.open(file_name);

	// insert node
	input_file>> case_cnt;
	while(case_cnt--)
	{
		input_file>> people_cnt;

		NodeList nodes(people_cnt);
		while(--people_cnt)
		{
			input_file>> tmp_p;
			input_file>> tmp_c;

			Node* tmp_node = new Node(tmp_p, tmp_c);
			nodes.add_node(tmp_node);
		}
		cout<< nodes.get_gen_cnt()<< endl;
	}

	// close file
	input_file.close();
	output_file.close();

	return 0;
}
