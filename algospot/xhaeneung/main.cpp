#include <iostream>
#include <string>

using namespace std;

int string2num(string str);
int checkResult(string* calStr);

int main()
{
	int cnt = 0;
	string calStr[4];

	cin>> cnt;

	while(cnt--)
	{
		cin>> calStr[0];
		cin>> calStr[1];
		cin>> calStr[2];
		cin>> calStr[3];
		cin>> calStr[3];

		if (checkResult(calStr)) cout<< "YES"<< endl;
		else                     cout<< "NO"<< endl;
	}

	return 0;
}

int checkResult(string* calStr)
{
	int resultVal = 0;
	char oper = calStr[1].at(0);

	cout<< oper<< endl;

	resultVal = string2num(calStr[0]);

	switch(oper)
	{
		case '+':
			resultVal += string2num(calStr[2]);
			break;
		case '-':
			resultVal -= string2num(calStr[2]);
			break;
		case '*':
			resultVal *= string3num(calStr[2]);
			break;
		case '/':
			resultVal /= string3num(calStr[2]);
			break;
	}

	if (resultVal == string2num(calStr[3]))
			return 1;
	
	return 0;
}

int string2num(string str)
{
	return 0;
}
