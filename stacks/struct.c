//This is a helper file to stack.c. It relies on stack.h.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "struct.h"

// The Stack struct is the struct we will be working with for our expandable Stack
// int* nums should point to a block of integers in our stack
// int CUR_SIZE notes the number of items in the stack
// int MAX_SIZE notes the current maximum capacity of our stack (which can be expanded)
// Do not edit this struct

// We use a function to initialize our Stack struct
// The initial capacity is 0
// The starting maximum capacity is 2

// Inside "Your code goes here", utilize dynamic allocation to allow for MAX_SIZE number of integers in stk->nums
//Hint1: malloc

void init(struct Stack** stk) {
        (*stk)->CUR_SIZE = 0;
        (*stk)->MAX_SIZE = 2;
        (*stk)->nums = (int*)malloc((*stk)->MAX_SIZE * sizeof(int));
}



//The isEmpty function returns true if the stack is empty, false otherwise
//Take out the "return 0" statement and write your own in place, you can do this in one line! :)
//Hint1: examine the variables in your Stack struct

bool isEmpty(struct Stack** stk) {
        if((*stk)->CUR_SIZE == 0){
                return true;
        }
        return false;
}



//The push function pushes the integer n onto the stack
//If the size of your current stack equals the maximum capacity,
//then you must double the maximum capcity by dynamically allocating a new block of memory twice as large

//For this function, you MUST USE a combination of malloc() and free() to accomplish resizing. You cannot use realloc().
//Hint1: Use a temporary pointer such as int* tmp to point to the old region of memory
//Hint2: Use a for loop to manually copy over values
//Hint3: Remember to free older memory!

void push(struct Stack** stk, int n) {
        int* temp = (*stk)->nums;
        if((*stk)->MAX_SIZE == (*stk)->CUR_SIZE)
        {
                (*stk)->MAX_SIZE *= 2;
                (*stk)->nums = (int*)malloc((*stk)->MAX_SIZE * sizeof(int));
                for(int i = 0; i < (*stk)->CUR_SIZE; i++)
                {
                        (*stk)->nums[i] = temp[i];
                }
                free(temp);
        }
        (*stk)->nums[(*stk)->CUR_SIZE] = n;
        (*stk)->CUR_SIZE += 1;
}



//The pop function pops the topmost integer from the stack
//If the size of your current stack equals half the maximum capacity, AND the maximum capacity is greater than 2,
//then you must halve the maximum capcity by dynamically allocating a new block of memory half as large

//For this function, you MUST USE realloc() to accomplish resizing. You cannot use malloc() or free().
//Hint1: Realloc automatically deallocates and does not require the use of free()
//Hint2: Note that you do not need a for loop, which was required for manually copying over values in the push function implementation
//Hint3: Realloc needs two pointers for best practice (refer to slides)

void pop(struct Stack** stk) {
        if((*stk)->CUR_SIZE == (*stk)->MAX_SIZE / 2 && (*stk)->MAX_SIZE > 2)
        {
                (*stk)->MAX_SIZE /= 2;
                int* temp = (int*)realloc((*stk)->nums, (*stk)->MAX_SIZE * sizeof(int));
                (*stk)->nums = temp;

        }
        (*stk)->CUR_SIZE -= 1;
}



//The top function returns the integer on the top layer of the stack
//Take out the "return 0" statement and write your own in place, you can do this in one line! :)

int top(struct Stack** stk) {
        return (*stk)->nums[(*stk)->CUR_SIZE - 1];
}

