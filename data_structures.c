/**
 * @Author: wayne
 * @Date:   26-04-2017
 * @Project: Expression Evaluation
 * @Filename: data_structures.c
 * @Last modified by:   wayne
 * @Last modified time: 02-05-2017
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "data_structures.h"

 /*Stack Contents*/
 void stack_contents(OPSTACK *opstack, VALSTACK *valstack)
 {
 	/*Value Stack Contents*/
 	printf("VALSTACK\n");
 	for (int i = 0; i <= valstack->top; i++)
 	{
 		printf("%d-->%f\n", i, valstack->value_stack[i]);
 	}
 	/*Operator Stack Contents*/
 	printf("OPSTACK\n");
 	for (int i = 0; i <= opstack->top; i++)
 	{
 		printf("%d-->%c\n", i, opstack->operator_stack[i]);
 	}
 }

 /*Value Stack Functions*/

 void value_push(double val, VALSTACK *valstack)
 {

 	if (valstack->top<MAX_VAL_STACK && valstack->top >=-1)
 	{
 		/*push to stack top*/
 		valstack->value_stack[++valstack->top] = val;
 	}

 	else if (valstack->top>MAX_VAL_STACK)
 	{
 		perror("Value Stack exceeded");
 		exit(-1);
 	}

 }

 double value_pop(VALSTACK *valstack)
 {
 	double popval = -9999;
 	if (valstack->top >= 0 && valstack->top <= MAX_VAL_STACK)
 	{
 		/*pop from stack*/
 		popval = valstack->value_stack[valstack->top];
 		valstack->value_stack[valstack->top] = 0;
 		valstack->top--;
 	}

 	else if (valstack->top <0)
 	{
 		perror("Invalid Expression:Value Stack Already Empty");
 		//exit(-1);
 	}
 	return popval;
 }

 /*Operator Stack Functions*/

 void operator_push(char op, OPSTACK *opstack)
 {
 	if (opstack->top<MAX_OP_STACK && opstack->top>=-1)
 	{
 		/*push to stack*/
 		opstack->operator_stack[++opstack->top] = op;
 	}

 	else if (opstack->top>MAX_OP_STACK)
 	{
 		perror("Operator Stack exceeded");
 		exit(-1);
 	}

 }

 char operator_pop(OPSTACK *opstack)
 {
 	char pop_op = -1;

 	if (opstack->top >= 0 && opstack->top <= MAX_OP_STACK)
 	{
 		/*pop from stack*/
 		pop_op = opstack->operator_stack[opstack->top];
 		opstack->operator_stack[opstack->top] = '\0';
 		opstack->top--;
 	}

 	else if (opstack->top<0)
 	{
 		perror("Invalid Expression:Operator Stack Already Empty");
 		//exit(-1);
 	}
 	return pop_op;

 }
