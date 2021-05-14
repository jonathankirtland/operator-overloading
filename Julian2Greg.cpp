#include "Julian2Greg.h"

/**
updates a day month and year with a julian date
@param JD the updated julian date
@param m referenced month
@param d referenced d
@param y referenced year
*/
void Julian2Greg(int JD, int& m, int& d, int& y)
{
	int L, N, I, J, K;
	L = JD + 68569;
	N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	J = 80 * L / 2447;
	K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;
	

	//update the date

	y = I;
	m = J;
	d = K;

}
