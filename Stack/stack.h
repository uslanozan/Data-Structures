#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // bool, true, false kullanımı için

// Stack veri yapısı
//! Sor. ben top'a default değer vermek istiyorsam ne yapmalıyım
typedef struct {
    int *data;  //Her bir int değerini gösteren pointer
    int top ;  //Stack'in en üstünü gösteren değer. -1 ise boştur
    int capacity; //Stackin türüne göre tüm elemanları içerecek
} Stack;

// Fonksiyon prototipleri
Stack* createStack(int capacity);  //? bitti
void push(Stack* stack, int item);  //? bitti
int pop(Stack* stack);  //? bitti
bool isEmpty(Stack* stack);  //? bitti
bool search(Stack* stack, int item);  //? bitti
void deleteItem(Stack* stack, int item);  //? bitti
void clearStack(Stack* stack);  //? bitti
void displayStack(Stack* stack);  //? bitti
Stack* expandStack(Stack* stack, int extraCapacity);  //? bitti
Stack* reverseStack(Stack* stack);  //? bitti
int peek(Stack* stack);  //? bitti
int size(Stack* stack);  //? bitti
Stack* copyStack(Stack* stack);  //? bitti
Stack* mergeStacks(Stack* stack1, Stack* stack2);  //? bitti
void shrinkStack(Stack* stack);  //? bitti
Stack* sortStack(Stack* stack);  //todo: tekrar bakılacak
void deleteStack(Stack** stack);

#endif // STACK_H
