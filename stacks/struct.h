//This is the header file for stack.c

#ifndef STRUCT_H //Header guard
#define STRUCT_H //Header guard

struct Stack {
        int* nums;
        int CUR_SIZE;
        int MAX_SIZE;
};
void init(struct Stack** stk);
bool isEmpty(struct Stack** stk);
void push(struct Stack** stk, int n);
void pop(struct Stack** stk);
int top(struct Stack** stk);

#endif //Header guard
