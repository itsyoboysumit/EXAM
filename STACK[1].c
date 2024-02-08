#include <stdio.h>
#define MAX 10
int stack[MAX];
int top;
int item;
void push(int item);
int pop();
void display();
int main()
{
    top = -1;
    int k, n;
    do
    {
        printf("\n************\nPRESS 1 for PUSH\nPRESS 2 for POP\nPRESS 3 for DISPLAY\nPRESS 4 for EXIT\n**********\n");
        printf("Enter choice:");
        scanf("%d", &k);
        switch (k)
        {
        case 1:
            printf("Enter the item to be pushed:");
            scanf("%d", &n);
            push(n);
            break;
        case 2:
            printf("%d deleted\n", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exited");
            break;
        default:
            printf("Wrong input!");
            break;
        }
    } while (k != 4);
    return 0;
}
void push(int item)
{
    if (top == MAX - 1)
    {
        printf("Overflow");
    }
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}
int pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        item = stack[top];
        top = top - 1;
    }
    return (item);
}
void display()
{
    for (int i = 0; i <= top; i++)
    printf("%d ", stack[i]);
}