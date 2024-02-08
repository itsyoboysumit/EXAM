/*Write a menu driven program to implement Circular Link List and perform the following operations:
1.Creation
2.Insertion
3.After a specific node
4.Before a specific node
5.Searching
6.Trasversing
7.Deletion of a particular node*/

#include<stdio.h>
#include<stdlib.h>

struct abc{
    int data;
    struct abc *next;
};
typedef struct abc node;
node *head,*lastnode;

void insertion();
void insertAfter();
void insertBefore();
void searching();
void trasversing();
void deletion();

int main(){
    head=NULL;
    lastnode=NULL;
    int n;
    do{
        printf("\n\tPRESS\n*************************\n1 for insertion\n2 for insert after\n3 for insert before\n4 for searching\n5 for trasverseing \n6 for deletion\n7 for exit\n*****************************\n");
        printf("Enter choice:");
        scanf("%d",&n);
        switch(n){
            case 1:
                insertion();
                break;
            case 2:
                insertAfter();
                break;
            case 3:
                insertBefore();
                break;
            case 4:
                searching();
                break;
            case 5:
                trasversing();
                break;
            case 6:
                deletion();
                break;
            case 7:
                printf("'EXITED'");
                break;
            default:
                break;
        }
    }while(n<7);
    return 0;
}
void insertion(){
    int item;
    printf("Enter the item to be inserted:");
    scanf("%d",&item);
    node *temp = (node*)malloc(sizeof(node));
    temp->data=item;
    if (head==NULL){
        head=temp;
        lastnode=temp;
        lastnode->next=head;
        return;
    }
    lastnode->next=temp;
    lastnode=temp;
    lastnode->next=head; 
}
void searching(){
    //Empty case 
    if(head==NULL){
        printf("Empty!");
        return;
    }
    node *dh= head;
    int se;
    printf("Enter the item to be searched:");
    scanf("%d",&se);
    int flag=0;
    do{
        if(se==dh->data){
            flag=1;
            break;
        }
        dh=dh->next;
    }while (dh!=head);
    if(flag==0){
        printf("Not found!");
    }
    else{
        printf("Got it!");
    }
}
void trasversing(){
    node *dh= head;
    //Empty case
    if(head==NULL){
        printf("Empty!");
        return;
    }
    printf("Current list is:\n");
    do{
        printf("[%d] ",dh->data);
        dh=dh->next;
    }while(dh!=head);
    printf("\n");
}
void insertAfter(){
    node *dh=head;
    node *temp;
    if(head==NULL){
        printf("List is empty.");
        return;
    }
    int se;
    printf("Enter the element after which you want to insert:");
    scanf("%d",&se);
    int flag=0;
    do{
        if(se==dh->data){
            flag=1;
            break;
        }
        dh=dh->next;
    }while(dh!=head);
    if(flag==0){
        printf("Wrong input! Element not found.");
        return;
    }
    temp=(node*)malloc(sizeof(node));
    printf("Enter the element to be inserted:");
    scanf("%d",&temp->data);
    //BODY CASE
    temp->next=dh->next;
    dh->next=temp;
    // LAST CASE
    if(temp->next==head){
        lastnode=temp;
    }
}
void insertBefore(){
    node *dh=head;
    node *temp;
    if(lastnode==NULL){
        printf("'List is empty!'");
        return;
    }
    int se;
    printf("Enter the element before which you want to insert:");
    scanf("%d",&se);
    if (head->data==se){
        temp=(node*)malloc(sizeof(node));
        printf("Enter the element to be inserted:");
        scanf("%d",&temp->data);
        temp->next=head;
        head=temp;
        lastnode->next=head;
        return;
    }
    int flag=0;
    do{
        if(dh->next->data==se){
            flag=1;
            break;
        }
        dh=dh->next;
    }while(dh!=head);
    if(flag==0){
        printf("Element not found.");
        return;
    }
    temp=(node*)malloc(sizeof(node));
    printf("Enter the element to be inserted:");
    scanf("%d",&temp->data);
    temp->next=dh->next;   
}
void deletion(){
    node *dh=head;
    node *temp;
    if(head==NULL){
        printf("'List is empty!'");
        return;
    }
    int se;
    printf("Enter the element to be deleted:");
    scanf("%d",&se);
    //head case
    if(head->data==se){
        temp=head;
        head=head->next;
        if(head==lastnode){
            head=NULL;
            lastnode=NULL;
        }
        else{
            lastnode->next=head;
        }
        free(temp);
        return;
    }
    //body case
    int flag=0;
    do{
        if(dh->next->data==se){
            flag=1;
            break;
        }
        dh=dh->next;
    }while(dh!=head);
    if(flag==0){
        printf("Element not found.");
        return;
    }
    temp=dh->next;
    dh->next=temp->next;
    //last node
    if(temp->next==head){
        lastnode=dh;
    }
    free(temp);

}