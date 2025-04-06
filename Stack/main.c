#include "stack.h"


int main()
{
    Stack* stack = createStack(3);
    push(stack,1);
    push(stack,5);
    push(stack,2);
    push(stack,3);
    stack = expandStack(stack,4);
    push(stack,8);
    
    Stack* stack2 = createStack(3);
    push(stack,123);
    push(stack,98);
    push(stack,000);
    

    Stack* stackMerged = mergeStacks(stack,stack2);
    displayStack(stackMerged);
    shrinkStack(stackMerged);
    displayStack(stackMerged);
    stackMerged = sortStack(stackMerged);
    displayStack(stackMerged);
    deleteStack(&stackMerged);
    displayStack(stackMerged);

}
