#include "Greg2Julian.h"
/**
converts a gregorian date to julian
@param m the month 
@param d the day
@param y the year
@return the julian date of the date passed
*/
int Greg2Julian(int m, int d, int y)
{
	int jd; 
	jd = d - 32075 + 1461 * (y + 4800 + (m - 14) / 12) / 4 + 367 * (m - 2 - (m - 14) / 12 * 12) / 12 - 3 * ((y + 4900 + (m - 14) / 12) / 100) / 4;
	return jd; 
}