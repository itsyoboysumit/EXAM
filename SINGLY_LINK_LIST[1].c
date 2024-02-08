/*Write a menu deriven program to implement single link list and perform the following operation
1.Creation
2.Insertion
    a. after a specific node
    b. before a specific node
3.Searching
4.Traversing
5.Reversing the list
6.Deletion of a particular node
7.Exit*/
 
#include<stdlib.h>
#include<stdio.h>
struct ABC{
    int data;
    struct ABC *next;
};
typedef struct ABC node;
node *head,*lastNode;

void insertion();
void insertAfter();
void insertBefor();
void searching();
void trasversing();
void reversing();
void deletion();

int main(){
    head=NULL,lastNode=NULL;
    int n;
    do {
        printf("\n\tPRESS\n*******************\n1. for Insertion\n2.for insertion after a specific node\n3.for insertion before a specific node\n4. for searching\n5. for transversing\n6. for reversing\n7. for deletion\n8. for exit\n***********************\n");
        printf("Enter choice:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            insertion();
            break;
        case 2:
            insertAfter(); 
            break;
        case 3:
            insertBefor();
            break;
        case 4:
            searching();
            break;
        case 5:
            trasversing();
            break;
        case 6:
            reversing();
            break;
        case 7:
            deletion();
            break;
        case 8:
            break;
        default:
            break;
        }
    }while(n<8);
    return 0;
}

void insertion(){
    node *temp;
    temp= (node*) malloc(sizeof(node));
    printf("Enter data:");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        lastNode=temp;
    }
    else{
        lastNode->next=temp;
        lastNode=temp;
    }

}
void trasversing(){
    node *dh = head;
    printf("\nCurrently listed elements:\n");
    while (dh!=NULL){
        printf("[%d] ",dh->data);
        dh=dh->next;
    }
    printf("\n");
}
void searching(){
    int se, flag=0;
    node *dh=head;
    printf("Enter the element to be searched:");
    scanf("%d",&se);
    while (dh!=NULL){
        if(se==dh->data){
            flag=1;
            break;
        }
        dh=dh->next;
    }
    if(flag==1)
    printf("Got it!");
    else
    printf("Not found.");
}
void insertAfter(){
    int se;
    printf("Enter the element after which you want to insert:");
    scanf("%d",&se);
    node *dh=head;
    node *temp;
    int flag=0;
    while(dh!=NULL){
        if(se == dh->data){
            flag=1;
            break;
        }
        dh=dh->next;
    }
    if(flag==0){
        printf("Element not found.");
        return;
    }
    temp = (node*)malloc(sizeof(node));
    printf("Enter the data:");
    scanf("%d",&temp->data);
    temp->next=dh->next;
    dh->next=temp;
    if(dh->next==NULL){
        lastNode=temp;
    }
}
void insertBefor(){
    node *dh=head;
    node *temp;
    int se;
    printf("Enter the element before which you want to insert:");
    scanf("%d",&se);
    // for head case
    if(head->data==se){
        temp=(node*)malloc(sizeof(node));
        printf("Enter the element to be inserted:");
        scanf("%d",&temp->data);
        temp->next=head;
        head=temp;
        if (temp->next == NULL) {
        lastNode = temp;
        }
        return;
    }
    int flag=0;
    while(dh->next!=NULL){
        if(dh->next->data==se){
            flag=1;
            break;;
        }
        dh=dh->next;
    }
    if(flag==0){
        printf("Element not found.");
        return;
    }
    temp = (node*)malloc(sizeof(node));
    printf("Enter the data:");
    scanf("%d",&temp->data);
    temp->next=dh->next;
    dh->next=temp;
}
void reversing(){
    node *previous=NULL;
    node *current = head;
    node *nextnode=NULL;
    while(current != NULL){
        nextnode=current->next;
        current->next=previous;
        previous=current;
        current=nextnode;
    }
    lastNode=head;
    head=previous;
}
void deletion(){
    node *temp;
    node *dh=head;
    int se;
    printf("Enter the element to be deleted:");
    scanf("%d",&se);
    //HEAD CASE
    if(head->data==se){
        temp=head;
        head=head->next;
        if(head==NULL){
            lastNode=NULL;
        }
        free(temp);
        return;
    }
    //BODY CASE
        //searching
    int flag=0;
    while(dh->next!=NULL){
        if(dh->next->data==se){
            flag=1;
            break;
        }
        dh=dh->next;
    }
    if(flag==0){
        printf("Not found.");
        return;
    }
    temp=dh->next;
    dh->next=temp->next;//dh->next->next
    if(dh->next==NULL){
        lastNode=dh;
    }
    free(temp);
    return;
}