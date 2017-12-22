//https://algospot.com/judge/problem/read/ALLERGY

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

#define MAX_FOOD_CNT 50

// for test code
static clock_t begin;
static clock_t end;
void start_du(void)
{
	begin = clock();
}
void end_du(void)
{
	end = clock();
	double msec = 1000.0 * (end - begin) / CLOCKS_PER_SEC;
	cout<< "time : "<< msec<< endl;
}

class FoodContainer{
	private:
		int m_size;
		unsigned long long m_eat_table;

	public:
		FoodContainer():m_size(0) {}
		~FoodContainer() {}
		
		void clear();
		int empty();
		int size();
		double begin();
		double end();
		void push_back();
		void pop_back();
		int last_pos();
};

class Allergy{
	private:
		map <int , unsigned long long> *m_food_table;
		unsigned long long m_exp_result;
		vector< pair<int, unsigned long long> > m_select_food;
		int m_total_food_cnt;
	public:
		Allergy(int _total_food_cnt, map <int , unsigned long long> *_food_table, unsigned long long _exp_result):m_total_food_cnt(_total_food_cnt), m_food_table(_food_table), m_exp_result(_exp_result) {}
		~Allergy() {}

		void init_value(void)
		{
			m_total_food_cnt = 0;
			m_exp_result = 0;
			m_select_food.clear();
			m_food_table->clear();
		}

		int check_action(void)
		{
			unsigned long long _check_result = 0;

			if (m_select_food.empty())
				return 0;

			for (vector< pair<int, unsigned long long> >::iterator it = m_select_food.begin(); it != m_select_food.end(); ++it)
				_check_result |= it->second;

			// check
			if (_check_result == m_exp_result)
				return m_select_food.size();

			return 0;
		}

		void add_last_food(map <int, unsigned long long> *_food_tb, int _last_pos)
		{
			_last_pos += 1;
			if ( _last_pos == m_total_food_cnt)
				return ;

			m_select_food.push_back( pair<int, unsigned long long>(_last_pos, _food_tb->at(_last_pos) ) );
		}

		void switch_last_food(map <int, unsigned long long> *_food_tb)
		{
			int _tmp_pos = m_select_food.back().first + 1;

			m_select_food.pop_back();
			if (_tmp_pos != m_total_food_cnt)
				m_select_food.push_back( pair<int, unsigned long long>(_tmp_pos, _food_tb->at(_tmp_pos) ) );
		}

		int check_food(map <int, unsigned long long> *_food_tb, int _food_cn)
		{
			int _ret = 0;

			// init select food vector
			m_select_food.clear();

			// make default vector
			for (int i=0; i<_food_cn; i++)
				m_select_food.push_back( pair<int, unsigned long long>( i, _food_tb->at(i) ) );

			// check action
			_ret = check_action();
			if (_ret != 0)
				return _ret;

			while (!m_select_food.empty())
			{
		start_du();
				if ( m_select_food.back().first == (m_total_food_cnt - 1) )
				{
					int _tmp_pos;

					m_select_food.pop_back();
					if (m_select_food.size() == 0)
						continue;
					_tmp_pos = m_select_food.back().first;
					m_select_food.pop_back();
					add_last_food(_food_tb, _tmp_pos);
					continue;
				}
				else if (m_select_food.size() < _food_cn)
				{
					int _lack_vector_size = _food_cn - m_select_food.size();

					for (int i=0; i<_lack_vector_size; i++)
					{
						int _tmp_pos;
						_tmp_pos = m_select_food.back().first;
						add_last_food(_food_tb, _tmp_pos);
					}
				}
				else
					switch_last_food(_food_tb);

		end_du();
				// check action
				_ret = check_action();
				if (_ret != 0)
					return _ret;
			}

			int _next_food_cn = _food_cn + 1;
			if (_next_food_cn == m_total_food_cnt)
				return m_total_food_cnt;

			return check_food(_food_tb, _next_food_cn);
		}
};

int main()
{
	int tc_count;
	cin>> tc_count;

	while(tc_count--)
	{
		int friend_cnt = 0;
		int food_cnt = 0;
		unsigned long long exp_result = 0;

		// get friend count and food count
		cin>> friend_cnt;
		cin>> food_cnt;

		// make expecte result
		for (int i=0; i<friend_cnt; i++)
			exp_result += 0x01 << i;

		// get friend name
		map <string, int> friend_table;

		for (int i=0; i<friend_cnt; i++)
		{
			string tmp;
			cin>> tmp;
			friend_table[tmp] = i;
		}

		// make food table
		map <int , unsigned long long> food_table;

		for (int i=0; i<food_cnt; i++)
		{
			int tmp;
			cin>> tmp;

			unsigned long long tmp_food = 0;

			while (tmp--)
			{
				string tmp_name;
				cin>> tmp_name;
				tmp_food += (unsigned long long) 0x01<<friend_table[tmp_name];
			}

			food_table[i] = tmp_food;
		}

		// check food
		Allergy allergy(food_cnt, &food_table, exp_result);
		cout<< allergy.check_food(&food_table, 1)<< endl;

		// init value
		allergy.init_value();
	}

	return 0;
}
