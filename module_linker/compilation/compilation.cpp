#include <iostream>

#define VAR 41

#define DIV(a,b) a / b

/*
gcc options for compilation steps
-E Preprocess only; do not compile, assemble or link; .i
-S Compile only; do not assemble or link; .s
-c Compile and assemble, but do not link; .o
*/

void some_function(int a)
{
    std::cout << a;
}

void some_other_function(float)
{
}

int main()
{
    some_function(VAR);
	some_other_function(34.f);

	std::cout << "Hey!" << std::endl;
    std::cout << DIV(25, 3 + 2); //why macros are bad

	return 0;
}
