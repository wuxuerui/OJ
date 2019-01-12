#include "pch.h"
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	long a, b;
	cin >> a >> b;
	long c = a + b;
	int num[20];
	int k = 0;
	bool sign = true;
	if (c < 0)
	{
		c = -c;
		sign = false;
	}
	while (c > 0)
	{
		num[k++] = c % 10;
		c /= 10;
	}
	if (!sign)
		cout << "-";
	if (k != 0)
	{
		for (int i = k - 1; i >= 0; --i)
		{
			printf("%d", num[i]);
			if (i % 3 == 0 && i != 0)
			{
				printf(",");
			}
		}
	}
	else
	{
		printf("0");
	}
	printf("\n");
	return 0;

}