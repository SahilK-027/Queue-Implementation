#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;
typedef struct LinkedQueue{
    int front, rear;
    int capacity;
    Node *start;
}LinkedQueue;
LinkedQueue* createQueue(int cap){
    LinkedQueue *Qptr;
    Qptr=(LinkedQueue*)malloc(sizeof(LinkedQueue));
    Qptr->capacity=cap;
    Qptr->front=-1;
    Qptr->rear=-1;
    Qptr->start=NULL;
    return Qptr;
}
void insert(LinkedQueue*Qptr,int item){
    Node *n1;
    n1=(Node*)malloc(sizeof(Node));
    n1->data=item;
    n1->next=NULL;
    if(Qptr->rear==Qptr->capacity-1){
        printf("\n⚠️Queue is full ""OVERFLOW""⚠️\n");
    }
    else{
        if(Qptr->start==NULL){
            Qptr->front=0;
            Qptr->rear=0;
            Qptr->start=n1;
        }
        else{
            Qptr->rear++;
            Node *temp;
            temp=Qptr->start;
            while (temp->next!=NULL) {
                temp=temp->next;
            }
            temp->next=n1;
        }
    }
   
}
void delete(LinkedQueue*Qptr){
    if(Qptr->start==NULL){
        printf("⚠️Queue is Empty cannot delete⚠️\n\n");
    }
    else{
        Qptr->rear--;
        Node *temp;
        temp=Qptr->start;
        temp=temp->next;
        Qptr->start=temp;
        free(temp);
        printf("\n✅Data succesfully deleted✅\n\n");
    }
}
void getitem(LinkedQueue*Qptr){
    Node *temp;
    temp=Qptr->start;
    if(temp!=NULL){
        printf("The front item in your queue is %d ", temp->data);
        while (temp->next!=NULL) {
            temp=temp->next;
        }
        printf("The rear item in your queue is %d ", temp->data);
    }
    else{
        printf("⚠️Queue is Empty no data found⚠️\n");
    }
    printf("\n");
}
int main(){
    LinkedQueue *NewQueue;
    int cap,flag=1,ch,value;
    printf("Enter the capacity of Queue\n");
    scanf("%d",&cap);
    NewQueue=createQueue(cap);
    while(flag==1){
        printf("\nEnter your choice:");
        printf("\n1. INSERT new element\n2. DELETE element\n3. Get Front and Rare \n4. Exit\n");
        scanf("%d",&ch);
        switch(ch){
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
                getitem(NewQueue);
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
