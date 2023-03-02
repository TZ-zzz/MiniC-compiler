void foo(int a) {}
void foo(
bool a); 
// Definition of function "foo()" with different parameter type at position 0! 
// (2, 0)

void foo(int a) {}
// Redefinition of function "foo()"! (7, 0)

void bar(int a,
int a);
// No errors should be reported here. Take a look @199

int ha() {}
// The function "ha()" need to return a value at its end! (14, 0)

void hee() {
return 1;
}
// Function has void return type, but the return statement has a returned expression!
// (18, 0)

int wow() {
return true;
}
// Function has return type "int", but the returned expression has type "bool"!
// (24, 0)

void wut(int a) {
if (1) {}  
// Conditional expression in if statement has non-bool type! (30, 4)

for (;
1; 
) {}
// Conditional expression in for statement has non-bool type! (34, 0)

while (1) {}
// Conditional expression in while statement has non-bool type! (38, 7)

- true; 
// Negate "-" opcode must have int operand! (41, 0)

! 1;
// Not "!" opcode must have bool operand! (44, 0)

true &&
1;
// "&&"/"||" opcode must have bool operand! (47, 0)

1 >
true;
// ">" opcode must have int type operand! (51, 0)

a[true];
// Array index expressions must have int operand! (55, 2)
// Indexing an non-array variable! (55, 0)

a = true;
// Variable and the assignment expression do not have the same type!
// (59, 0)

- 4294967297;  // Note that this is 2^32 + 1
// Integer literal must be inside the range of int! (63, 0)

1 + 
true;
// "+" opcode must have int type operand! (66, 0)

foo(true);
// Function foo() does not match the type of the call argument at position 0!
// (70, 0)
}