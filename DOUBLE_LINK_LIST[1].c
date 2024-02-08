/*Write a menu driven program to implement double link list and perform the following operations
1. Creation
2. Insertion
3. Before a specific node
4. After a specific node
5. Traverse Forward
6. Traverse Backward
7. Searching
8. Reversing the list
9. Deletion of a particular node*/

#include <stdio.h>
#include <stdlib.h>

struct abc
{
    int data;
    struct abc *next;
    struct abc *prev;
};
typedef struct abc node;
node *head, *tail;

void insert(int ele);
void insertBefore();
void insertAfter();
void traverseForward();
void traverseBackward();
void searching();
void deletion();

int main()
{
    head = NULL;
    tail = NULL;
    int ch, item;
    printf("\n\tPRESS\n***********************\n1 for insertion\n2 for before a specific node\n3 for after a specific node\n4 for trasverse forwarde\n5 for traversed backward\n6 for searching\n7 for deletion\n8 for exit\n********************************\n");
    do
    {
        printf("\nEnter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted:");
            scanf("%d", &item);
            insert(item);
            break;
        case 2:
            insertBefore();
            break;
        case 3:
            insertAfter();
            break;
        case 4:
            traverseForward();
            break;
        case 5:
            traverseBackward();
            break;
        case 6:
            searching();
            break;
        case 7:
            deletion();
            break;
        case 8:
            printf("Exited");
            break;
        default:
            break;
        }
    } while (ch < 8);
    return 0;
}
void insert(int ele)
{
    node *temp = (node *)malloc(sizeof(node));
    if (head == NULL)
    {
        temp->data = ele;
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        tail = temp;
        return;
    }
    temp->data = ele;
    temp->next = NULL;
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertBefore()
{
    node *dh = head;
    node *temp;
    int se;
    printf("Enter the element before which you want to insert:");
    scanf("%d", &se);
    // searching
    int flag = 0;
    do
    {
        if (dh->data == se)
        {
            flag = 1;
            break;
        }
        dh = dh->next;
    } while (dh != NULL);

    if (flag == 0)
    {
        printf("Element not found.");
        return;
    }
    temp = (node *)malloc(sizeof(node));
    printf("Enter the element to be inserted:");
    scanf("%d", &temp->data);
    temp->next = dh;
    temp->prev = dh->prev;
    dh->prev = temp;
    if (temp->prev == NULL)
    {
        head = temp;
    }
    else
    {
        temp->prev->next = temp;
    }
}

void insertAfter()
{
    node *dh = head;
    node *temp;
    printf("Enter the element after which you want to insert:");
    int se;
    scanf("%d", &se);
    // searching
    int flag = 0;
    do
    {
        if (se == dh->data)
        {
            flag = 1;
            break;
        }
        dh = dh->next;
    } while (dh != NULL);
    if (flag == 0)
    {
        printf("List is empty.");
        return;
    }
    temp = (node *)malloc(sizeof(node));
    printf("Enter the element to be inserted:");
    scanf("%d", &temp->data);
    temp->next = dh->next;
    temp->prev = dh;
    dh->next = temp;
    if (temp->next == NULL)
    {
        tail = temp;
    }
    else
    {
        temp->next->prev = temp;
    }
}

void traverseForward()
{
    node *dh = head;
    if (dh == NULL)
    {
        printf("List is empty.");
        return;
    }
    do
    {
        printf("[%d] ", dh->data);
        dh = dh->next;
    } while (dh != NULL);
}

void traverseBackward()
{
    node *dh = tail;
    while (dh != NULL)
    {
        printf("[%d] ", dh->data);
        dh = dh->prev;
    }
    printf("\n");
}

void searching()
{
    node *dh = head;
    int se, flag = 0;
    printf("Enter the elment to be searched:");
    scanf("%d", &se);
    do
    {
        if (se == dh->data)
        {
            flag = 1;
        }
        dh = dh->next;
    } while (dh != NULL);
    if (flag == 0)
    {
        printf("Element not found.");
        return;
    }
    printf("Yes, got that element.");
}

void deletion()
{
    node *dh = head;
    int item, flag = 0;
    node *temp;
    printf("Enter the item to be deleted:");
    scanf("%d", &item);
    // searching
    do
    {
        if (item == dh->data)
        {
            flag = 1;
            break;
        }
        dh = dh->next;
    } while (dh != NULL);
    if (flag == 0)
    {
        printf("Element not found.");
        return;
    }
    temp = dh;
    //head case
    if(dh->prev==NULL){
        head=head->next;
        if(head==NULL){
            tail=NULL;
            free(temp);
            return;
        }
        else{
            head->prev=NULL;
        }
    }
    else{
    dh->prev->next = dh->next;
    }
    if(dh->next==NULL){
        tail=tail->prev;
        if(tail==NULL){
            head=NULL;
        }
    }
    else{
        dh->next->prev=dh->prev;
    }
    free(temp);
}
