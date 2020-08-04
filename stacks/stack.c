//This code was meant to teach about header files and more about memory allocation.
//It creates a stack in which user user can use the methods push, pop, top, and isEmpty to modify it.
//It relies on the header file struct.h and the c file struct.c.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "struct.h"


/////////////////////////////////////////  PART 1 STARTS HERE /////////////////////////////////////////////////

/////////////////////////////////////////  PART 1 ENDS HERE /////////////////////////////////////////////////


int main() {

        struct Stack* stk = (struct Stack*)malloc(sizeof(struct Stack)); //Dynamic allocation of a Stack struct
        init(&stk); //Initialization of the Stack struct

        push(&stk, 3);
        push(&stk, 1);
        push(&stk, 4);
        assert(top(&stk) == 4);
        pop(&stk);
        assert(top(&stk) == 1);
        assert(!isEmpty(&stk));
        push(&stk, 5);
        push(&stk, 9);
        push(&stk, 20);
        push(&stk, 60);
        push(&stk, 100);
        push(&stk, 18);
        push(&stk, 19);
        push(&stk, 20);
        pop(&stk);
        assert(top(&stk) == 19);
        pop(&stk);
        pop(&stk);
        assert(!isEmpty(&stk));
        assert(top(&stk) == 100);
        pop(&stk);
        pop(&stk);
        pop(&stk);
        pop(&stk);
        assert(top(&stk) == 5);
        pop(&stk);
        pop(&stk);
        assert(top(&stk) == 3);
        pop(&stk);
        assert(isEmpty(&stk));

        free(stk);
        stk = (struct Stack*)malloc(sizeof(struct Stack));
        init(&stk);

        //DO NOT EDIT THIS SECTION IN-BETWEEN PART 1 AND PART 2
        //BEFORE MOVING ONTO PART 2, YOUR CODE SHOULD PASS THESE ASSERTION STATEMENTS
        
/////////////////////////////////////////  PART 2 STARTS HERE /////////////////////////////////////////////////

        printf("Valid commands are push, pop, top, and isEmpty. Push must be followed by a number.\n");

        //Implement the following pseudocode using the functions created in PART 1:
        //For an example on how this section is run, refer to the image in the PDF which covers different commands
        //Auxiliary tools you might use: scanf(), strcmp()

        //USE THE ALREADY CREATED "stk" POINTER FROM THE TESTING CODE FOR YOUR FUNCTIONS

        /*
        Loop Forever:
        get input string
        if string is "push"
                get number
                print "You pushed in [number]"
        else if string is "pop"
                print "There are no items to pop" if empty stack
                otherwise print "You popped the top item"
        else if string is "top"
                print "There are no items on top" if empty stack
                otherwise print "The top item is [number]"
        else if string is "isEmpty"
                print "The stack is empty" if empty stack
                otherwise print "The stack is not empty"
        else
                print "This command is not recognized"
        */
        while(true)
        {
                char inputCommand[100] = "";
                scanf("%s", inputCommand);
                if(strcmp(inputCommand, "push") == 0)
                {
                        int num;
                        scanf("%d", &num);
                        push(&stk, num);
                        printf("You pushed in %d\n", num);
                }
                else if(strcmp(inputCommand, "pop") == 0)
                {
                        if(!isEmpty(&stk))
                        {
                                pop(&stk);
                                printf("You popped the top item\n");
                        }
                        else
                        {
                                printf("There are no items to pop\n");
                        }
                }
                else if(strcmp(inputCommand, "top") == 0)
                {
                        if(!isEmpty(&stk))
                        {
                                printf("The top item is %d\n", top(&stk));
                        }
                        else
                        {
                                printf("There are no items on top\n");
                        }
                }
                else if(strcmp(inputCommand, "isEmpty") == 0)
                {
                        if(isEmpty(&stk))
                        {
                                printf("The stack is empty\n");
                        }
                        else
                        {
                                printf("The stack is not empty\n");
                        }
                }
                else
                {
                        printf("This command is not recognized\n");
                }
        }
        /////////////////////////////////////////  PART 2 ENDS HERE /////////////////////////////////////////////////
}
