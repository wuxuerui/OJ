#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
using namespace std;
int main()
{
	map<int, string> grade;
	string name, ID;
	int total;
	cin >> total;
	int stugrade;
	for (int i = 0; i < total; i++)
	{
		cin >> name;
		cin >> ID;
		cin >> stugrade;
		name = name + " " + ID;

		grade.insert(pair<int, string>(stugrade, name));
	}
	int low, high;
	cin >> low;
	cin >> high;
	map<int, string>::reverse_iterator iter;
	bool has = false;
	for (iter = grade.rbegin(); iter != grade.rend(); iter++)
	{
		if (iter->first >= low && iter->first <= high)
		{
			has = true;
			cout << iter->second;
			cout << "\n";
		}
	}
	if (!has)
	{
		cout << "NONE";
	}
	return 0;
}