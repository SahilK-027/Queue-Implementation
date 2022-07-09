#include<stdio.h>
#include<stdlib.h>
typedef struct DarrayQueue
{
    int capacity;
    int front, rear;
    int *aptr;
}DarrayQueue;

DarrayQueue* createQueue(int cap)
{
    DarrayQueue *qptr;
    qptr=(DarrayQueue*)malloc(sizeof(DarrayQueue));
    qptr->capacity=cap;
    qptr->front=qptr->rear=-1;
    qptr->aptr=(int *)malloc(sizeof(int)*cap);
    for(int i=0;i<cap;i++)
    {
        qptr->aptr[i]=-1;
    }
    return qptr;
}

DarrayQueue* doubleArray(DarrayQueue* qptr)
{
    int newCap=2*(qptr->capacity);
    int *temp=(int*)malloc(sizeof(int)*newCap);
    for(int i=0;i<qptr->capacity;i++)
    {
        temp[i]=qptr->aptr[i];
    }
    for(int i=qptr->capacity;i<newCap-1;i++)
    {
        temp[i]=-1;
    }
    free(qptr->aptr);
    qptr->aptr=temp;
    qptr->capacity=newCap;
    printf("\nYour queue had reached its maximum capacity so capacity is increased");
    return qptr;
}

DarrayQueue* shrinkArray(DarrayQueue* qptr)
{
    int newCap=(qptr->capacity)/2;
    int *temp=(int*)malloc(sizeof(int)*newCap);
    for(int i=0;i<qptr->capacity;i++)
    {
        temp[i]=qptr->aptr[i];
    }
    free(qptr->aptr);
    qptr->aptr=temp;
    qptr->capacity=newCap;
    printf("Your queue had less items so its capacity is decreased\n");
    return qptr;
}

void insert(DarrayQueue* qptr, int data)
{
    if(qptr->rear==qptr->capacity-1)
    {
        qptr=doubleArray(qptr);
        qptr->rear++;
        qptr->aptr[qptr->rear]=data;
        printf("\n✅ Data successfully inserted ✅\n");
    }
    else
    {
        if(qptr->front==-1)
        {
            qptr->front++;
            qptr->rear++;
            qptr->aptr[qptr->rear]=data;
        }
        else
        {
            qptr->rear++;
            qptr->aptr[qptr->rear]=data;
        }
        printf("\n✅ Data successfully inserted ✅\n");
    }
}

void delete(DarrayQueue* qptr)
{
    if(qptr->front==-1)
    {
        printf("\n⚠️ Queue is empty ""UNDERFLOW""⚠️ \n\n");
    }
    else
    {
        if(qptr->rear==0)
        {
            qptr->aptr[qptr->rear]=-1;
            qptr->front=-1;
            qptr->rear=-1;
            printf("\n✅ Data successfully deleted ✅\n");
        }
        else
        {
            for(int i=0;i<qptr->rear;i++)
            {
                qptr->aptr[i]=qptr->aptr[i+1];
            }
            qptr->aptr[qptr->rear]=-1;
            qptr->rear=qptr->rear-1;
            printf("\n✅ Data successfully deleted ✅\n");
            if((qptr->capacity)%2==0)
            {
                if(qptr->rear<=(qptr->capacity/2)-1)
                {
                    qptr=shrinkArray(qptr);
                }
            }
        }
    }
}
void getFirstItem(DarrayQueue*qptr)
{
    if(qptr->front==-1)
    {
        printf("\n⚠️ Queue is empty ""NO DATA EXISTS""⚠️ \n\n");
    }
    else
    {
        printf("\nTHE FIRST ITEM IN YOUR QUEUE IS %d ",qptr->aptr[qptr->front]);
    }
}

void getLastItem(DarrayQueue*qptr)
{
    if(qptr->rear==-1)
    {}
    else
    {
        printf("\nTHE LAST ITEM IN YOUR QUEUE IS %d ",qptr->aptr[qptr->rear]);
    }
}

void showCapacity(DarrayQueue*qptr)
{
    printf("\nCurrent capacity of your queue is %d\n\n",qptr->capacity);
}

int main()
{
    DarrayQueue * NewQueue;
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
                insert(NewQueue,value);
                break;
            case 2:
                printf("\nYOU ARE GOING TO DELETE AN ELEMENT FROM QUEUE\n");
                delete(NewQueue);
                break;
            case 3:
                getFirstItem(NewQueue);
                getLastItem(NewQueue);
                showCapacity(NewQueue);
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
