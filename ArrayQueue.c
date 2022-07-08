#include<stdio.h>
#include<stdlib.h>
typedef struct ArrayQueue
{
    int capacity;
    int front,rear;
    int *ArrPtr;
}ArrQueue;

ArrQueue * createQueue(int cap)
{
    ArrQueue* Qptr;
    Qptr=(ArrQueue*)malloc(sizeof(ArrQueue));
    Qptr->capacity=cap;
    Qptr->front=-1;
    Qptr->rear=-1;
    Qptr->ArrPtr=(int *)malloc(sizeof(int)*cap);
    for(int i=0;i<cap;i++)
    {
        Qptr->ArrPtr[i]=-1;
    }
    return Qptr;
}

void insertion(ArrQueue*Qptr,int data)
{
    if(Qptr->rear==Qptr->capacity-1)
    {
        printf("\n⚠️ Queue is full ""OVERFLOW"" ⚠️\n\n");
    }
    else
    {
        if(Qptr->front==-1)
        {
            Qptr->front++;
            Qptr->rear++;
            Qptr->ArrPtr[Qptr->rear]=data;
            printf("\n✅ Data successfully inserted ✅\n");
        }
        else
        {
            Qptr->rear++;
            Qptr->ArrPtr[Qptr->rear]=data;
            printf("\n✅ Data successfully inserted ✅\n");
        }
    }
}

void deletion(ArrQueue*Qptr)
{
    if(Qptr->front==-1)
    {
        printf("\n⚠️ Queue is empty ""UNDERFLOW""⚠️ \n\n");
    }
    else
    {
        if(Qptr->rear==0)
        {
            Qptr->ArrPtr[Qptr->rear]=-1;
            Qptr->front=-1;
            Qptr->rear=-1;
            printf("\n✅ Data successfully deleted ✅\n");
        }
        else
        {
            for(int i=0;i<Qptr->rear;i++)
            {
                Qptr->ArrPtr[i]=Qptr->ArrPtr[i+1];
            }
            Qptr->ArrPtr[Qptr->rear]=-1;
            Qptr->rear=Qptr->rear-1;
            printf("\n✅ Data successfully deleted ✅\n");
        }
    }
}

void getFirstItem(ArrQueue*Qptr)
{
    if(Qptr->front==-1)
    {
        printf("\n⚠️ Queue is empty ""NO DATA EXISTS""⚠️ \n\n");
    }
    else
    {
        printf("\nTHE FIRST ITEM IN YOUR QUEUE IS %d ",Qptr->ArrPtr[Qptr->front]);
    }
}

void getLastItem(ArrQueue*Qptr)
{
    if(Qptr->rear==-1)
    {}
    else
    {
        printf("\nTHE LAST ITEM IN YOUR QUEUE IS %d ",Qptr->ArrPtr[Qptr->rear]);
    }
}
int main()
{
    ArrQueue * NewQueue;
    int cap,flag=1,ch,value;
    printf("Enter the capacity of Queue\n");
    scanf("%d",&cap);
    NewQueue=createQueue(cap);
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
                getFirstItem(NewQueue);
                getLastItem(NewQueue);
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
