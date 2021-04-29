#include <stdio.h>
#define MAX 50
int stack[MAX];
int top=-1;

void push(int a)
{
    stack[++top] = a;
}
int pop()
{
    int element = stack[top--];
    return element;
}

int main()
{
    printf("Enter 10 elements: \n");
    int inp;
    for(int i=0; i<10; i++)
    {
        scanf(" %d", &inp);
        push(inp);
    }
    
    inp = pop();
    printf("\nPopped an element from stack. (%d)",inp);
    
    while(top>=0)
    {
        printf("\nPopped an element from stack. (%d)", pop());
    }
    return 0;
}
