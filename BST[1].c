/*Write down a program in C ti implement Binary Search Tree (BST) and perform the following functions
1. Creation
2. Traversing
3. Searching
4. Count total number of nodes
5. Find height
6. Deletion of element
    Case 1: No child
    Case 2: Only one child (Right)
    Case 3: Only one child (Left)
    Case 4: Two children left and right both side
7. Mirroring*/

#include <stdio.h>
#include <conio.h>

struct abc
{
    int data;
    struct abc *lc;
    struct abc *rc;
};
typedef struct abc node;

node *create(node *root, int item);
void inorder(node *root);
node *search(node *root, int item);
int totalNodes(node *root);
int height(node *root);
void deletion(node *root,int element);
void mirror(node *root);

int main()
{
    node *root = NULL;
    int ch, item;
    do
    {
        printf("\n\tPRESS\n**************************\n1 for creation\n2 for traversing\n3 for searching\n4 for total number of nodes\n5 for height\n6 for deletion\n7 for mirror\n8 for exit\n***************************");
        printf("\nEnter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data:");
            scanf("%d", &item);
            root = create(root, item);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            printf("Enter the element to be searched:");
            int se;
            scanf("%d", &se);
            node *result;
            result = search(root, se);
            if (result == NULL)
                printf("Not found!");
            else
                printf("Found!");
            break;
        case 4:
            printf("Total number of nodes in the tree is %d", totalNodes(root));
            break;
        case 5:
            printf("Height of the node is:%d", height(root));
            break;
        case 6:
            printf("Enter the element to be deleted:");
            int de;
            scanf("%d", &de);
            deletion(root,de);
            break;
        case 7:
            mirror(root);
            break;
        case 8:
            printf("Exited!");
            break;
        default:
            printf("Wrong Input! Please try again...");
            break;
        }
    } while (ch != 8);
}

node *create(node *root, int item)
{
    if (root == NULL)
    {
        root = (node *)malloc(sizeof(node));
        root->data = item;
        root->lc = NULL;
        root->rc = NULL;
        return (root);
    }
    if (item < root->data)
        root->lc = create(root->lc, item);
    else
        root->rc = create(root->rc, item);
    return root;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->lc);
        printf("[%d] ", root->data);
        inorder(root->rc);
    }
}

node *search(node *root, int item)
{
    if (root == NULL)
        return NULL;
    if (root->data == item)
        return (root);
    else if (item < root->data)
        return (search(root->lc, item));
    else
        return (search(root->rc, item));
}

int totalNodes(node *root)
{
    int total, rcount, lcount;
    if (root == NULL)
        return 0;
    else
    {
        lcount = totalNodes(root->lc);
        rcount = totalNodes(root->rc);
        total = lcount + rcount + 1;
        return (total);
    }
}

int height(node *root)
{
    int lcount, rcount, max;
    if (root == NULL)
        return (0);
    else
    {
        lcount = height(root->lc);
        rcount = height(root->rc);
        if (lcount > rcount)
            max = lcount + 1;
        else
            max = rcount + 1;
        return (max);
    }
}

void mirror(node *root){
    node *temp;
    if(root==NULL)
        return;
    mirror(root->lc);
    mirror(root->rc);
    
    temp=root->lc;
    root->lc=root->rc;
    root->rc=temp;
}

void deletion(node *root,int element){
    node *temp, *parent, *tempparent;
    node *droot; int data; int found=0;
    parent=NULL;
    droot=root;
    //searching
    while(droot!=NULL){
        if(droot->data==element){
            found=1;
            break;
        }
        parent=droot;
        if(element<droot->data)
            droot=droot->lc;
        else
            droot=droot->rc;
    }
    if(found==0){
        printf("Element not found");
        return;
    }
    //case 1 (No child (leaf element))
    if(droot->lc==NULL && droot->rc==NULL){
        if(parent==NULL){
            root=NULL;
            free(droot);
            return;
        }
        if(parent->lc==droot)
            parent->lc=NULL;
        else
            parent->rc=NULL;
        free(droot);
    }
    //case 2 (Only Right Child)
    if(droot->lc==NULL && droot->rc!=NULL){
        if(parent==NULL){
            root=droot->rc;
            free(droot);
            return;
        }
        if(parent->lc==droot)
            parent->lc=droot->rc;
        else
            parent->rc=droot->rc;
        free(droot);
    }
    
}