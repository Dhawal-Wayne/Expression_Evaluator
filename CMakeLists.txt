cmake_minimum_required( VERSION 3.6 )
#If 3.6 not present mannual set EXP_EVAL PROJECT TO STARTUP PROJECT
cmake_policy(SET CMP0015 NEW)
project(EXP_EVAL)
include_directories(".")
link_directories(".")
configure_file(input.txt input.txt COPYONLY)
add_executable (EXP_EVAL exp_eval.c mymath.c data_structures.c expression_evaluator.c exp_eval.h mymath.h stdafx.h data_structures.h)
set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT "EXP_EVAL" )
