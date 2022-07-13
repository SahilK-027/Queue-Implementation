#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *next;
};

typedef struct LinkedQueue
{
    struct node *start;
}LinkedQueue;

LinkedQueue * createQueue()
{
    LinkedQueue* Qptr;
    Qptr=(LinkedQueue*)malloc(sizeof(LinkedQueue));
    Qptr->start=NULL;
    return Qptr;
}
void insertion(LinkedQueue *Qptr, int data)
{
    struct node *s2;
    s2=(struct node*)malloc(sizeof(struct node));
    s2->value=data;
    s2->next=NULL;
    if(Qptr->start==NULL)
    {
        Qptr->start=s2;
    }
    else
    {
        struct node *temp;
        temp=Qptr->start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=s2;
    }
    printf("\n✅Data succesfully inserted✅\n\n");
}

void deletion(LinkedQueue *Qptr)
{
    if(Qptr->start==NULL)
    {
        printf("⚠️Queue is Empty⚠️\n\n");
    }
    else
    {
        struct node *temp;
        temp=Qptr->start;
        temp=temp->next;
        Qptr->start=temp;
        free(temp);
        printf("\n✅Data succesfully deleted✅\n\n");
    }
}

void getItem(LinkedQueue *Qptr)
{
    struct node *temp;
    temp=Qptr->start;
    if(Qptr->start!=NULL)
    {
        printf("The front item in your queue is %d ", Qptr->start->value);
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        printf("The rear item in your queue is %d ", temp->value);
    }
    else
    {
        printf("⚠️Queue is Empty⚠️\n");
    }
    printf("\n");
}

int main()
{
    LinkedQueue * NewQueue;
    int flag=1,ch,value;
    printf("You are going to create a new queue Queue\n");
    NewQueue=createQueue();
    while(flag==1)
    {
        printf("\nEnter your choice:");
        printf("\n1. Insert\n2. Delete\n3. Get first and last item\n4. Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nYOU ARE GOING TO INSERT AN ELEMENT INTO QUEUE\n");
                printf("Enter Value: ");
                scanf("%d",&value);
                insertion(NewQueue,value);
                break;
            case 2:
                printf("\nYOU ARE GOING TO DELETE AN ELEMENT FROM QUEUE\n");
                deletion(NewQueue);
                break;
            case 3:
                getItem(NewQueue);
                break;
            case 4:
                flag=0;
                break;
            default:
                printf("\n🚫Incorrect choice Re-Enter🚫\n\n");
        }
    }
    return 0;
}
