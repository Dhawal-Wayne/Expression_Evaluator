/**
 * @Author: wayne
 * @Date:   26-04-2017
 * @Project: Expression Evaluation
 * @Filename: expression_evaluator.c
 * @Last modified by:   wayne
 * @Last modified time: 30-04-2017
 */



#include "stdafx.h"

/*Driver C-FIle*/

int main()
{
	int status;
	char filename[10]={'\0'};

	/*Input filename*/

	printf("Enter Input Filename\t");
	scanf("%s",filename);

	status = exp_eval(filename);

	if(status==-1)
	{
		return -1;
	}

	return 0;
}
