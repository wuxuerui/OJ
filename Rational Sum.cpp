#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
long numerator = 0;
long denominator = 0;
long denominatortemp = 0;
long numeratortemp = 0;
long numeratorout = 0;
long denominatorout = 0;
long intout = 0;
bool num = true;
bool deno = true;
void countnum()
{
	denominatorout = denominator * denominatortemp;
	numeratorout = numerator * denominatortemp + numeratortemp * denominator;
	denominator = denominatorout;
	numerator = numeratorout;
	//printf("%d.%d\n", numerator, denominator);
}
long fraction(long a, long b)
{
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;
	while (b != 0)
	{
		long temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
void removefraction()
{
	//È¡ÕýÊý
	if (denominator < 0)
	{	
		denominator = -denominator;
		numerator = -numerator;
	}
	int fractionnum;
	fractionnum = fraction(numerator, denominator);
	numerator = numerator / fractionnum;
	denominator = denominator / fractionnum;

		
}

int main()
{
	int total;
	cin >> total;
	cin >> numerator;
	getchar();
	cin >> denominator;
	for (int i = 0; i < total - 1; i++)
	{
		cin >> numeratortemp;
		getchar();
		cin >> denominatortemp;
		countnum();
		if (numerator >= denominator || numerator <= -denominator)
		{
			intout = intout + numerator / denominator;
			numerator = numerator % denominator;
		}
		removefraction();
	}
	//printf("%d %d %d", intout, numerator, denominator);
	if (intout != 0)
	{
		printf("%d ", intout);
	}
	if (numerator != 0)
	{
		printf("%d/%d", numerator, denominator);
	}
	else
	{
		if (intout == 0)
		{
			printf("0");
			//printf("%d ", intout);
		}
		
	}
	//printf("\n");
	return 0;
}