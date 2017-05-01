/**
 * @Author: wayne
 * @Date:   26-04-2017
 * @Project: Expression Evaluation
 * @Filename: exp_eval.h
 * @Last modified by:   wayne
 * @Last modified time: 30-04-2017
 */



#ifndef EXP_EVAL_H_
#define EXP_EVAL_H_

/*Including Header to the Project Header file*/
#include "mymath.h"
#include "data_structures.h"

/*OPERATOR STACK FUNCTIONS*/

extern int operator_priority(char op);

/*EXPRESSION EVALUATION*/

extern int exp_eval(char *filename);

#endif
