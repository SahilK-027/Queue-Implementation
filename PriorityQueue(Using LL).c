#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
    int priority;
};
void insert(struct Node** start, int data, int prio)
{
    struct Node* n1=(struct Node*)malloc(sizeof(struct Node));
    n1->data=data;
    n1->priority=prio;
    if(*start==NULL)
    {
        n1->next=NULL;
        *start=n1;
        printf("✅Insertion SUCCESSFULL✅\n\n");
    }
    else
    {
        struct Node *temp1,*temp2;
        int count=0;
        temp2=NULL;
        temp1=*start;
        if(temp1->priority>prio)
        {
            while(temp1->next!=NULL)
            {
                if(temp1->priority>=prio)
                {
                    temp2=temp1;
                    temp1=temp1->next;
                }
                count++;
            }
            if(count)
            {
                if(temp1->priority>=prio && temp1->next==NULL)
                {
                    n1->next=NULL;
                    temp1->next=n1;
                }
                else
                {
                    n1=temp2->next;
                    temp2->next=n1;
                }
            }
            else
            {
                if(temp1->priority>=prio)
                {
                    n1->next=NULL;
                    temp1->next=n1;
                }
                else
                {
                    n1->next=temp1;
                    *start=n1;
                }
            }
        }
        else
        {
            n1->next=temp1;
            *start=n1;
        }
        printf("✅Insertion SUCCESSFULL✅\n\n");
    }
}
void deletion(struct Node** start)
{
    if(*start==NULL)
        printf("\n⚠️Queue is empty cannot pop ""UNDERFLOW""⚠️\n\n");
    else{
        struct Node* temp;
        temp=*start;
        if(temp->next==NULL){
            *start=NULL;
            free(temp);
        }
        else{
            *start=temp->next;
            free(temp);
        }
        printf("\n✅ Data successfully poped from front ✅\n\n");
    }
}
void getdata(struct Node* start)
{
    struct Node* temp;
    temp=start;
    if(temp!=NULL){
        printf("\nTHE FRONT ITEM IN YOUR QUEUE IS %d ", temp->data);
        while(temp->next!=NULL)
            temp=temp->next;
        printf("\nTHE REAR ITEM IN YOUR QUEUE IS %d \n\n", temp->data);
    }
        else
            printf("\n⚠️Queue is empty NO DATA FOUND⚠️\n\n");
}
int main(){
    struct Node *start;
    start= NULL;
    int ch,flag=1, data, priority;
    while(flag){
        printf("MENU\n1. INSERT\n2. DELETE\n3. GET DATA\n4. EXIT\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter data to insert front: ");
                scanf("%d",&data);
                printf("Enter the priority level : ");
                scanf("%d",&priority);
                insert(&start,data,priority);
                break;
            case 2:
                deletion(&start);
                break;
            case 3:
                getdata(start);
                break;
            case 4:
                flag=0;
                break;
            default:
                printf("\n🚫WRONG CHOICE RE-ENTER🚫\n\n");
        }
    }
    return 0;
}
