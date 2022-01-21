#include "sorting_header.h"

// STACK DEFINITION
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack -> capacity = capacity;
    stack -> array = (int*) malloc(stack -> capacity * sizeof(int));
    return stack;
}
// STACK END

// DRIVER CODE
int main()
{
    // Initializing Stack
    unsigned nums = 200;
    struct Stack *a;
    a = createStack(nums);
    int n = nums;
    // Generating Random Numbers
    number_assign(a, n);
    // Starting the program
    interface(a, n);
    // Free memory
    delete (a);
    return 0;
}
// DRIVER CODE END
