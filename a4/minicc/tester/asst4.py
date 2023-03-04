#!/usr/bin/python3
#
# Assignment 4 Private tester
#
# Tests a program path and against an expected output
#

import tester
import os, sys
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
# Change path to minicc here
exec_path = [SCRIPT_DIR + '/../build/src/minicc']

test_cases = [
    ['public_tests/var.c', b'', 1],
    ['public_tests/bool_fail.c', b'Redefinition of variable/parameter "z" in the same scope! (4:5)\nVariable and the assignment expression do not have the same type! (9:4)\n"+" opcode must have int type operand! (11:4)\n"&&"/"||" opcode must have bool operand! (13:8)\nFunction has return type "bool", but the returned expression has type "int"! (14:8)\nConditional expression in if statement has non-bool type! (13:8)\n', 2],
    ['public_tests/index_fail.c', b'Indexing an non-array variable! (7:4)\nBreak statement must appear inside a for/while statement! (12:8)\nThe function "main()" need to return a value at its end! (6:0)\n', 2],

    ['private_tests/easy.c', b'', 2],
    ['private_tests/easy_fail.c', b'Negate "-" opcode must have int operand! (9:4)\nNot "!" opcode must have bool operand! (10:4)\n', 1],
    ['private_tests/pizza_fail1.c', b'Function has return type "int", but the returned expression has type "bool"! (27:8)\n', 1],
    ['private_tests/pizza_fail2.c',b'Integer literal must be inside the range of int! (33:8)\nFunction has return type "int", but the returned expression has type "bool"! (35:4)\n', 2],
    ['private_tests/pizza_fail3.c', b'Function has return type "int", but the returned expression has type "bool"! (29:8)\n', 1],
    ['private_tests/pizza_fail4.c', b'Function whichTop() is declared with 1 parameters but called with 0 arguments! (30:4)\n', 1],
    ['private_tests/counting_fail1.c', b'Conditional expression in for statement has non-bool type! (12:11)\n', 1],
    ['private_tests/counting_fail2.c', b'Function dummy() does not match the type of the call argument at position 0! (28:4)\nFunction dumy() is not declared before use! (25:4)\nRedefinition of function "main()"! (33:0)\nConditional expression in while statement has non-bool type! (20:11)', 2],
    ['private_tests/ops_fail1.c', b'">" opcode must have int type operand! (15:4)\n"=="/"!=" opcode must have same primitive type operand! (11:4)\n"=="/"!=" opcode must have same primitive type operand! (9:4)\n"+" opcode must have int type operand! (7:4)\n"<" opcode must have int type operand! (13:4)\n">=" opcode must have int type operand! (19:4)\n"<=" opcode must have int type operand! (17:4)', 1],
    ['private_tests/ops_fail2.c', b'"*" opcode must have int type operand! (9:12)\nVariable gamma is not declared before use! (7:4)\n"+" opcode must have int type operand! (9:4)\n"/" opcode must have int type operand! (11:4)', 1],
    ['private_tests/definition_fail.c', b'Redefinition of function "countDigits()"! (25:0)\nRedefinition of function "reverse()"! (41:0)\nRedefinition of function "factorial()"! (6:0)\nDefinition of function "countDigits()" with different number of parameters! (25:0)\nDefinition of function "reverse()" with different parameter type at position 0! (41:0)\nDefinition of function "factorial()" with different return type! (6:0)', 1],
    ['private_tests/function_fail.c', b'Function has void return type, but the return statement has a returned expression! (16:3)\nFunction has void return type, but the return statement has a returned expression! (10:7)\nFunction has return type "bool", but the returned expression has type "int"! (46:3)\nFunction has non-void return type, but the return statement has no returned expression! (30:3)', 1],
]


tmp_files = ['output.bc']

def convert_bytes_to_set(b):
    s = b.decode("utf-8") 
    ss = s.split('\n')
    ss = set(ss)
    if '' in ss:
        ss.remove('')
    return ss

def main():
    test = tester.Core('Assignment 4 Public Tester', 20)

    # Public tests
    for case in test_cases:
        test_path = exec_path + [case[0]]
        # Supply the executable and test program path
        test.start_test(test_path)
        # Check the program output against a string and assign a mark
        test.actual = convert_bytes_to_set(test.actual)
        test.check_output(convert_bytes_to_set(case[1]), case[2])
        test.clean_up(tmp_files)

if __name__ == '__main__':
    main()