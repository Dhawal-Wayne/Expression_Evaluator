/**
 * @Author: wayne
 * @Date:   26-04-2017
 * @Project: Expression Evaluation
 * @Filename: mymath.c
 * @Last modified by:   wayne
 * @Last modified time: 30-04-2017
 */



#include "stdafx.h"

#include "mymath.h"

double pow1(long int power, double base)
{
	double temp;

	if (power == 0)
	{
		return 1;
	}

	if (power % 2 == 0)
	{
		temp = pow1(power / 2, base);
		return temp*temp;
	}

	else
	{
		return base*pow1(power - 1, base);
	}
}

double add(double val1, double val2)
{
	return val1 + val2;
}

double sub(double val1, double val2)
{
	/*Pop is done in reverse hence 2nd-1st */
	return val2 - val1;
}

double mul(double val1, double val2)
{
	return val1*val2;
}

double div1(double down, double up)
{
	/* Pop is done in reverse hence 2nd/1st */
	return up / down;
}
