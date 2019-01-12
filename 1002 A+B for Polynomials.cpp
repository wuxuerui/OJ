#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

int main()
{
	map<int, float>input;
	int colum[2] = {0};
	int row = 0;
	int i =0 ;
	while (i < 2)
	{
		cin >> colum[i];
		//printf("%d ", colum[i]);
		while (row < colum[i])
		{
			int inttemp = 0;
			double floattemp = 0;
			cin >> inttemp;
			cin >> floattemp;
			//printf("%d,%f\n", inttemp, floattemp);
			if (input.find(inttemp) != input.end())
			{
				input[inttemp] = input[inttemp] + floattemp;
				if (0 == input[inttemp])
				{
					input.erase(inttemp);
				}
			}
			else
			{
				input.insert(pair<int, float>(inttemp, floattemp));
			}
			row++;
		}
		i++;
		row = 0;
	}
	printf("%d", input.size());
	int output1[42];
	double output2[42];
	int count3 = 0;
	for (map<int, float>::iterator iter = input.begin(); iter != input.end(); iter++)
	{
		output2[count3] = iter->second;
		output1[count3++] = iter->first;
	}
	for (int j = count3 - 1; j >= 0; j--)
	{
		printf(" %d ", output1[j]);
		printf("%.1f", output2[j]);
	}
	printf("\n");
	return 0;
}