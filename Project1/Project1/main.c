#include <stdio.h>
int main()
{
	double debt = 200000;
	double rate = 0.0705;
	int year = 25;
	int month = 12;
	double m;
	scanf_s("%lf", &m);
	for (year = 25; year > 0; year--)
	{
		debt *= (1 + rate);
		for (month = 12; month > 0; month--)
		{
			debt -= m;
		}
	}
	printf("\n%lf", debt);
	return 0;
}