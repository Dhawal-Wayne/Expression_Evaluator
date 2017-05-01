/**
 * @Author: wayne
 * @Date:   26-04-2017
 * @Project: Expression Evaluation
 * @Filename: data_structures.h
 * @Last modified by:   wayne
 * @Last modified time: 02-05-2017
 */

#ifndef DATA_STRUCTURES_H_
#define DATA_STRUCTURES_H_

#define MUL '*'
#define POW '^'
#define ADD '+'
#define DIV '/'
#define SUB '-'

#define MAX_VAL_STACK 999
#define MAX_OP_STACK 999

typedef struct VALSTACK {
	double value_stack[100];
	int top;
}VALSTACK;

typedef struct OPSTACK {
	char operator_stack[100];
	int top;
}OPSTACK;

/*Function Declarations*/

extern void stack_contents(OPSTACK *opstack, VALSTACK *valstack);

/*VALUE STACK FUNCTIONS*/

extern void value_push(double val, VALSTACK *valstack);

extern double value_pop(VALSTACK *valstack);

/*OPERATOR STACK FUNCTIONS*/

extern void operator_push(char op, OPSTACK *opstack);

extern char operator_pop(OPSTACK *opstack);


#endif // !DATA_STRUCTURES_H_
