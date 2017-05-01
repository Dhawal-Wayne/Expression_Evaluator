/**
 * @Author: wayne
 * @Date:   26-04-2017
 * @Project: Expression Evaluation
 * @Filename: exp_eval.c
 * @Last modified by:   wayne
 * @Last modified time: 02-05-2017
 */



#include "stdafx.h"

#include "exp_eval.h"

/*Opearor Priority Checker*/

int operator_priority(char op)
{
	switch (op)
	{
		case ADD:
			return 1;
		case SUB:
			return 2;
		case MUL:
			return 3;
		case DIV:
			return 4;
		case POW:
			return 5;
	}
	return -1;
}

/*Expression Evaluation Functions*/

int exp_eval(char *filename)
{

	FILE *in_file;

	FILE *out_file;

	char *line, *dummy;

	/*Temporary line length declaration*/
	size_t line_length = 1000;
	line = (char*)calloc(line_length, sizeof(char));

	/*Temporaries*/
	double temp_nums;
	char temp_ops;
	double operator_1, operator_2;


	OPSTACK opstack;

	VALSTACK valstack;

	/*Return Values and Errors*/
	int ret,error;

	/*Opening file*/

	if ((in_file = fopen(filename, "r")) == NULL)
	{
		ret = -1;
		perror("EXP_EVAL:File Not Found");
	}

	else
	{
		out_file = fopen("./.tempfile.txt", "w");
		while (fgets(line, 1000, in_file))
		{
			/*Initialization*/
			valstack.top = opstack.top = -1;
			dummy = line;
			error = 0;

			while (*dummy)
			{
				/*Number Readers*/
				if (*dummy >= '0' && *dummy <= '9')
				{
					temp_nums = (double)strtol(dummy, &dummy, 10);
					value_push(temp_nums, &valstack);
				}


				else
				{
					if (*dummy == MUL && *(dummy + 1) == MUL)
					{
						 *dummy++;
						 operator_push(POW, &opstack);
					}
					else if (*dummy == MUL || *dummy == ADD || *dummy == SUB || *dummy == DIV  || *dummy == POW)
					{

						if (opstack.top == -1)
						{
							operator_push(*dummy, &opstack);
						}
						else if (operator_priority(opstack.operator_stack[opstack.top]) > operator_priority(*dummy))
						{
							while (operator_priority(opstack.operator_stack[opstack.top]) > operator_priority(*dummy))
							{
								if (valstack.top < 1)
								{
									error = 1;
									break;
								}
								temp_ops = operator_pop(&opstack);
								operator_1 = value_pop(&valstack);
								operator_2 = value_pop(&valstack);
								switch (temp_ops)
									{
										case ADD:
											value_push(add(operator_1, operator_2), &valstack);
											break;
										case SUB:
											value_push(sub(operator_1, operator_2), &valstack);
											break;
										case DIV:
											value_push(div1(operator_1, operator_2), &valstack);
											break;
										case MUL:
											value_push(mul(operator_1, operator_2), &valstack);
											break;
										case POW:
											value_push(pow1(operator_1, operator_2), &valstack);
											break;
									}
							}
							operator_push(*dummy, &opstack);
						}

						else
						{
							operator_push(*dummy, &opstack);
						}
					}
					dummy++;
				}
			}
			while (opstack.top >= 0)
			{
				if (valstack.top < 1)
				{
					error = 1;
					break;
				}
				temp_ops = operator_pop(&opstack);
				operator_1 = value_pop(&valstack);
				operator_2 = value_pop(&valstack);

				switch (temp_ops)
				{
					case ADD:
					value_push(add(operator_1, operator_2), &valstack);
					break;
					case SUB:
					value_push(sub(operator_1, operator_2), &valstack);
					break;
					case DIV:
					value_push(div1(operator_1, operator_2), &valstack);
					break;
					case MUL:
					value_push(mul(operator_1, operator_2), &valstack);
					break;
					case POW:
					value_push(pow1(operator_1, operator_2), &valstack);
					break;
				}
			}

			/*Error Handling*/
			if (error != 0)
			{
				/*
				fgets gets line+'\n' character
				inorder to add another remove '\n' character
				we have dummy pointing to end of line line pointing to start
				difference would be the line length (including the '\n')
				BUT LAST LINE DOESNOT HAVE '\n' hence this condition ;)
				*/
				if (line[dummy - line - 1] == '\n')
				{
					line[dummy - line - 1] = '\0';
				}
				perror("\nInvalid Expression");
				printf("Final line is %s=INVALID\n", line);
				fprintf(out_file, "%s=INVALID\n", line);
			}
			else
			{
				/*
				fgets gets line+'\n' character
				inorder to add another remove '\n' character
				we have dummy pointing to end of line line pointing to start
				difference would be the line length (including the '\n')
				BUT LAST LINE DOESNOT HAVE '\n' hence this condition ;)
				*/
				if (line[dummy - line - 1] == '\n')
				{
					line[dummy - line - 1] = '\0';
				}
				printf("\nFinal line is %s=%f\n", line, valstack.value_stack[valstack.top]);
				fprintf(out_file, "%s=%f\n", line, valstack.value_stack[valstack.top]);
			}
		}

		fclose(in_file);
		fclose(out_file);
		remove(filename);
		int rename1=rename("./.tempfile.txt",filename);
		/*
		  //To check wheather a file is altered or not
		if (rename1 == 0)
			printf("Succeded\n");
		else
			printf("Failed");
		*/
		ret = 0;
	}

	return ret;
}
