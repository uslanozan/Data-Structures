#include "stack.h"

// Create an integer Stack
Stack* createStack(int capacity) {
    //? Ne öğrendik: Stack için ayrı içerideki değerler için ayrı alan açmak gerekiyormuş

    Stack* stack = (Stack*)malloc(sizeof(Stack)); //Stack Structunu istediğimiz boyuta göre yer ayırıyor
    if (!stack)
    {
        printf("Memory allocation failed!\n");
        exit(1); // Programı durdur
    }

    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int*)malloc(capacity * sizeof(int));
    if (!stack->data) { // data dizisi için de kontrol yapmalısın
        printf("Memory allocation for stack data failed!\n");
        free(stack);
        exit(1);
    }

    return stack;
}

// Add item
void push(Stack* stack, int item) {

    if (stack == NULL)
    {
        printf("Stack is NULL!\n");
        return;
    }


    if (stack->top == stack->capacity - 1) { // Stack dolu mu?
        printf("Stack is full! Use 'Expand' to increase size of the stack\n");
        return;
    }

    // sayı zaten eklenmişse
    if (search(stack, item))
    {
        printf("%d item is already added to stack.\n", item);
        return;
    }


    stack->top++;   // Yeni eleman için top'u artır
    stack->data[stack->top] = item; // Elemanı ekle
    printf("%d is added to stack\n", item);
}

// Remove and return last item of stack (FILO)
int pop(Stack* stack) {
    //? Ne öğrendik int pointerı yerine NULL koyamam 

    if (stack == NULL)
    {
        printf("Stack is NULL!\n");
        return -1;
    }

    if (isEmpty(stack)) { // Stack boş mu?
        printf("Stack is empty! Use 'push' to add item\n");
        return -1; // Hata kodu döndür
    }

    int lastItem = stack->data[stack->top];
    stack->data[stack->top] = 0;  //! Sor. free yapmak gerekmez miydi ya da NULL kulanamaz mıyız.
    stack->top--;

    return lastItem;
}

// Check is stack true
bool isEmpty(Stack* stack) {

    if (stack == NULL)
    {
        printf("Stack is NULL!\n");
        return false;
    }

    if (stack->top == -1)
    {
        return true;
    }
    else {
        return false;
    }
}

// Check an item is in stack
bool search(Stack* stack, int item) {

    if (stack == NULL)
    {
        printf("Stack is NULL!\n");
        return false;
    }

    if (isEmpty(stack))
    {
        return false;
    }

    for (int index = 0; index <= stack->top; index++)
    {
        if (stack->data[index] == item)
        {
            return true;
        }
    }

    return false;
}

// Remove a specific item from stack
void deleteItem(Stack* stack, int item) {

    if (stack == NULL)
    {
        printf("Stack is NULL!\n");
        return;
    }

    if (isEmpty(stack))
    {
        printf("Stack is empty!\n");
        return;
    }

    int itemIndex;
    int gap;


    if (search(stack, item))
    {
        // Iterating over stack
        for (int i = 0; i < stack->top; i++)
        {
            if (stack->data[i] == item)
            {
                itemIndex = i;
                break;
            }
        }

        gap = (stack->top - itemIndex);
        printf("%d", gap);
        Stack* tempStack = createStack(gap);
        tempStack->capacity = gap;
        tempStack->top = -1;


        // Up-to-Down (because of FILO)
        for (int i = stack->top; itemIndex < i; i--)
        {
            // Çıkarılacak hariç hepsi stack'e eklendi
            push(tempStack, pop(stack));
        }

        // Çıkarılacak olan çıktı ama geçici stack'e eklenmedi.
        pop(stack);

        for (int i = tempStack->top; i >= 0; i--)
        {
            push(stack, pop(tempStack));
        }

        deleteStack(&tempStack);


    }
    else {
        printf("There is no item %d", item);
        return;
    }
}

// Clear stack
void clearStack(Stack* stack) {

    if (stack == NULL)
    {
        printf("Stack is NULL!\n");
        return;
    }

    if (isEmpty(stack))
    {
        printf("Stack is empty!\n");
        return;
    }

    for (int i = stack->top; 0 <= i; i--)
    {
        pop(stack);
    }
}

// Print stack with detaisl
void displayStack(Stack* stack) {

    if (stack == NULL)
    {
        printf("Stack is NULL!\n");
        return;
    }


    if (isEmpty(stack))
    {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack includes %d items. %d item(s) can be added to stack\n", stack->top + 1, stack->capacity - (stack->top + 1));

    int i = stack->top;

    while (i >= 0) {
        printf("| %d |\n", stack->data[i]);
        i--;
    }
}

// Reverse stack
Stack* reverseStack(Stack* stack) {

    if (stack == NULL)
    {
        printf("Stack is NULL!\n");
        return NULL;
    }

    if (isEmpty(stack))
    {
        printf("Stack is empty!\n");
        return NULL;
    }

    Stack* newStack = createStack(stack->capacity);
    newStack->capacity = stack->capacity;
    newStack->top = -1;

    for (int i = stack->top; 0 <= i; i--)
    {
        push(newStack, pop(stack));
    }

    return newStack;
}

// Increase capacity of stack
Stack* expandStack(Stack* stack, int extraCapacity) {

    if (stack == NULL)
    {
        printf("Stack is NULL!\n");
        return NULL;
    }


    stack->capacity = stack->capacity + extraCapacity;
    int* p1 = (int*)realloc(stack->data, (stack->capacity) * sizeof(int));
    if (!p1)
    {
        printf("Expand Error");
        return NULL;
    }

    stack->data = p1;

    return stack;
}

// Return top item of the stack
int peek(Stack* stack) {

    if (stack == NULL)
    {
        printf("Stack is NULL!\n");
        return -1;
    }


    if (!isEmpty(stack))
    {
        return stack->data[stack->top];
    }
    else {
        printf("Stack is empty!");
        return -1;
    }
}

// Return item count of stack
int size(Stack* stack) {
    if (stack == NULL)
    {
        printf("Stack is NULL!\n");
        return -1;
    }

    return stack->top + 1;
}

// Copy of stack
Stack* copyStack(Stack* stack) {

    if (stack == NULL)
    {
        printf("Stack is NULL!\n");
        return NULL;
    }


    Stack* newStack = createStack(stack->capacity);
    newStack->capacity = stack->capacity;
    newStack->top = -1;

    for (int i = 0; i <= stack->top; i++)
    {
        push(newStack, stack->data[i]);
    }

    return newStack;
}

// Merge 2 stacks into a stack
Stack* mergeStacks(Stack* stack1, Stack* stack2) {

    if (stack1 == NULL || stack2 == NULL)
    {
        printf("%p or %p is NULL!\n", stack1, stack2);
        return NULL;
    }


    Stack* mergedStack = createStack(stack1->capacity + stack2->capacity);
    mergedStack->capacity = stack1->capacity + stack2->capacity;
    mergedStack->top = -1;

    stack1 = reverseStack(stack1);
    stack2 = reverseStack(stack2);

    for (int i = stack1->top; 0 <= stack1->top; i--)
    {
        push(mergedStack, pop(stack1));
    }


    for (int i = stack2->top; 0 <= stack2->top; i--)
    {
        push(mergedStack, pop(stack2));
    }

    return mergedStack;
}

// Clear empty spaces in stack (Shrink)
void shrinkStack(Stack* stack) {

    if (stack == NULL)
    {
        printf("Stack is NULL!\n");
        return;
    }

    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }

    stack->capacity = stack->top + 1;
    stack->data = (int*)realloc(stack->data, stack->capacity * sizeof(int));
}


// Sort stack
//todo: kopya çekildi tekrar bakılacak
Stack* sortStack(Stack* stack) {

    if (stack == NULL)
    {
        printf("Stack is NULL!\n");
        return NULL;
    }

    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return stack;
    }



    Stack* tempStack = createStack(stack->capacity);
    tempStack->top = -1;
    tempStack->capacity = stack->capacity;
    int tempVal;

    while (!isEmpty(stack))
    {
        tempVal = pop(stack);
        while (!isEmpty(tempStack) && peek(tempStack) > tempVal) {
            push(stack, pop(tempStack));
        }
        push(tempStack, tempVal);
    }

    return tempStack;
}

// Delete stack from memory
//! burayı sor
void deleteStack(Stack** stack) {
    if (*stack != NULL) {
        free((*stack)->data);  // Stack içindeki diziyi boşalt
        free(*stack);          // Stack’in kendisini boşalt
        *stack = NULL;         // Stack’i NULL yaparak kullanılmasını önle
    }

}