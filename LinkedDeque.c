#include<stdio.h>
#include<stdlib.h>
struct Node{
    int item;
    struct Node* next;
};
void push_front(struct Node **start, int data){
    struct Node* n1;
    n1=(struct Node*)malloc(sizeof(struct Node));
    n1->item=data;
    if(*start==NULL){
        n1->next=NULL;
        *start=n1;
        printf("\n✅ Data successfully pushed at front ✅\n\n");
    }
    else{
        struct Node* temp;
        temp=*start;
        n1->next=temp;
        *start=n1;
        printf("\n✅ Data successfully pushed at front✅\n\n");
    }
}
void push_back(struct Node **start, int data){
    struct Node* n1;
    n1=(struct Node*)malloc(sizeof(struct Node));
    n1->item=data;
    n1->next=NULL;
    if(*start==NULL){
        *start=n1;
        printf("\n✅ Data successfully pushed at back ✅\n\n");
    }
    else{
        struct Node* temp;
        temp=*start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=n1;
        printf("\n✅ Data successfully pushed at back ✅\n\n");
    }
}
void pop_front(struct Node **start){
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
void pop_back(struct Node **start){
    if(*start==NULL)
        printf("\n⚠️Queue is empty cannot pop ""UNDERFLOW""⚠️\n\n");
    else{
        struct Node* temp1,*temp2;
        temp1=*start;
        temp2=NULL;
        if(temp1->next==NULL){
            *start=NULL;
            free(temp1);
        }
        else{
            while(temp1->next!=NULL){
                temp2=temp1;
                temp1=temp1->next;
            }
            temp2->next=NULL;
            free(temp1);
        }
        printf("\n✅ Data successfully poped from back ✅\n\n");
    }
}
void getData(struct Node *start){
    struct Node* temp;
    temp=start;
    if(temp!=NULL){
        printf("\nTHE FRONT ITEM IN YOUR QUEUE IS %d ", temp->item);
        while(temp->next!=NULL)
            temp=temp->next;
        printf("\nTHE REAR ITEM IN YOUR QUEUE IS %d \n\n", temp->item);
    }
        else
            printf("\n⚠️Queue is empty NO DATA FOUND⚠️\n\n");
}
int main(){
    struct Node *start;
    start= NULL;
    int ch,flag=1, data;
    while(flag){
        printf("MENU\n1. push_front\n2. push_back\n3. pop_front\n4. pop_back\n5. Get front and rear\n6. EXIT\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter data to push at front: ");
                scanf("%d",&data);
                push_front(&start,data);
                break;
            case 2:
                printf("\nEnter data to push at back: ");
                scanf("%d",&data);
                push_back(&start,data);
                break;
            case 3:
                pop_front(&start);
                break;
            case 4:
                pop_back(&start);
                break;
            case 5:
                getData(start);
                break;
            case 6:
                flag=0;
                break;
            default:
                printf("\n🚫WRONG CHOICE RE-ENTER🚫\n\n");
        }
    }
    return 0;
}
