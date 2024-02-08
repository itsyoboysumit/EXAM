/*Write down a program to insert tree data structure*/

#include <stdio.h>
#include <stdlib.h>

struct abc
{
    int data;
    struct abc *lc;
    struct abc *rc;
};
typedef struct abc node;

node *creation(node *root, int item);
void insertion();
void inOrderTraversal(node *root);
// void traversing();
// void deletion();
// void searching();

int main()
{
    int n, item;
    node *root = NULL;
    do
    {
        printf("\n\tPRESS\n***********************\n1. for creation \n2. for insertion\n3. for traversing\n4. for deletion\n5. for searching\n6. for exit\n***************************\n");
        printf("Enter choice:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter the number:");
            scanf("%d", &item);
            root = creation(root, item);
            break;
        case 2:
            // insertion();
            break;
        case 3:

            printf("In-order Traversal: ");
            inOrderTraversal(root);
            printf("\n");
            break;

            break;
        case 4:
            // deletion();
            break;
        case 5:
            // searching();
            break;
        case 6:
            printf("PROGRAM EXITED");
            break;
        default:
            printf("Wrong input!Try again.");
            break;
        }
    } while (n != 6);
    return 0;
}

node *creation(node *root, int item)
{
    char ch;
    if (root == NULL)
    {
        root = (node *)malloc(sizeof(node));
        root->data = item;
        root->lc = NULL;
        root->rc = NULL;
        return (root);
    }
    printf("Current value=%d", root->data);
    printf("\nIn which direction you want to insert item ('L' or 'R'):");
    scanf(" %c", &ch);
    if (ch == 'L')
    {
        root->lc = creation(root->lc, item);
    }
    else
    {
        root->rc = creation(root->rc, item);
    }
    return (root);
}


void inOrderTraversal(node *root) {
    if (root != NULL) {
        inOrderTraversal(root->lc); // Traverse left subtree
        printf("%d ", root->data); // Print current node's data
        inOrderTraversal(root->rc); // Traverse right subtree
    }
}
