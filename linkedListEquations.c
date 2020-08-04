//This code was made while learning about pointers and how to create linked lists using them. 
//I had to create a code which algorithmically solved three different equations using pointers which led to pointers which led to pointers and so on. 

#include <stdio.h>

//In the code, I was not allowed to use any numbers except the three defined below
#define one 1
#define two 2
#define three 3

/* Please put your name in the string */
void printName(){
    char name[30] = "Ayan Chaudhry";
    printf("My Name is: %s\n", name);
}

//I was not allowed to use any mathematical operations unless they were called using these functions.
/*     Math functions (dont modify)     */
void divide(double *operand, double mod){
    *operand = *operand/mod;
}

void multiply(double *operand, double mod){
    *operand = *operand*mod;
}

void add(double *operand, double mod){
    *operand = *operand+mod;
}

void subtract(double *operand, double mod){
    *operand = *operand-mod;
}
/*     End Math functions     */

/* custom datatype to represent a single action  */
//expected solution: 1 line
struct operation {
    double modifier;
    struct operation* next;
    /*pointer to function (accepts any of the math functions above). please name it math*/
    void (*math)(double *a, double b);
};

//expected solution: 3 lines
void constructor(struct operation *op, double value, struct operation* next, void (*math)(double *a, double b)){
    /* assign values of op to the passed in values */
    op->modifier = value;
    op->next = next;
    op->math = math;
}

/*
the operate function will perform the action outlined by a single operation

Quick exmplanation:
Each operation struct has a math type and a modifier value
the operand should be altered by calling the math method
with a modifier defined by the operation

*/

//expected solution: 1 line
void operate(struct operation* op, double* operand){
    /*call op's math function with the a input being the operand*/
    (op->math)(operand, op->modifier);
}

/*
the evaluate function iterates through an entire list of operations

Thinking back to the previous assignment's countlinks function,
evaluate should go from one operation to another using the 'next' field
It should call operate at each step.

*/
//expected solution: 6 lines
double evaluate(double in, struct operation* expression){
    /*     apply the expression to the input     */
    while(expression != NULL)
    {
        operate(expression, &in);
        expression = expression->next;
    }
    return in;
}

/* eqn1 is given as an example */
double eqn1(double test1, double test2, double test3){
    /*     implement expression res = in + 3     */
    struct operation head;
    constructor(&head, three, NULL, add);

    /*   tests, do not modify   */
    double res1 = evaluate(test1, &head);
    double res2 = evaluate(test2, &head);
    double res3 = evaluate(test3, &head);
    double exp1 = test1 + 3;
    double exp2 = test2 + 3;
    double exp3 = test3 + 3;
    printf("test results for eqn1: %f %f %f\n", res1, res2, res3);
    printf("expected results eqn1: %f %f %f\n", exp1, exp2, exp3);
}

double eqn2(double test1, double test2, double test3){
    /*     implement expression res = 2*(in - 1)     */
    struct operation head;
    struct operation tail;
    constructor(&tail, two, NULL, multiply);
    constructor(&head, one, &tail, subtract);

    /*   tests, do not modify   */
    double res1 = evaluate(test1, &head);
    double res2 = evaluate(test2, &head);
    double res3 = evaluate(test3, &head);
    double exp1 = 2*(test1 - 1);
    double exp2 = 2*(test2 - 1);
    double exp3 = 2*(test3 - 1);
    printf("test results for eqn2: %f %f %f\n", res1, res2, res3);
    printf("expected results eqn2: %f %f %f\n", exp1, exp2, exp3);
}

double eqn3(double test1, double test2, double test3){
    /*     implement expression res = (2*(in + 1) - 3)/6     */
    struct operation head;
    struct operation neck;
    struct operation body;
    struct operation tail1;
    struct operation tail2;
    constructor(&tail2, three, NULL, divide);
    constructor(&tail1, two, &tail2, divide);
    constructor(&body, three, &tail1, subtract);
    constructor(&neck, two, &body, multiply);
    constructor(&head, one, &neck, add);

    /*   tests, do not modify   */
    double res1 = evaluate(test1, &head);
    double res2 = evaluate(test2, &head);
    double res3 = evaluate(test3, &head);
double exp1 = (2*(test1 + 1) - 3)/6;
    double exp2 = (2*(test2 + 1) - 3)/6;
    double exp3 = (2*(test3 + 1) - 3)/6;
    printf("test results for eqn3: %f %f %f\n", res1, res2, res3);
    printf("expected results eqn3: %f %f %f\n", exp1, exp2, exp3);
}


/*
 * Feel free to use main to test.
 * We will automatically rename the function and ignore it's code
 * you can type numbers and whatever else you want here
 */
int main(){
    printName();
    eqn1(4, 7, 9);
    eqn2(2, 42, 78);
    eqn3(44, 92, 71);
    return 0;
}
