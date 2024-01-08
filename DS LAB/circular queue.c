#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int CQ[SIZE];
int front=-1;
int rear=-1,ch;
int IsCQ_Full();
int IsCQ_Empty();
void CQ_Insert(int);
void CQ_Delete();
void CQ_Display();
void main()
{
    printf("1.insert\n2.delete\n3.display\n4.exit\n");
    while(1)
    {
        int ele;
        printf("enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:if(IsCQ_Full())
            printf("circular queue overflow\n");
            else
            {
                printf("enter the element to be inserted\n");
                scanf("%d",&ele);CQ_Insert(ele);
            }
            break;
            case 2:if(IsCQ_Empty())
            printf("circular queue underflow\n");
            else
            CQ_Delete();
            break;
            case 3:if(IsCQ_Empty())
            printf("circular queue underflow\n");
            else
            CQ_Display();
            break;
            case 4: exit(0);
            
            }
            
        }
        
    }
    void CQ_Insert(int item)
    {
        if(front==-1)
        front++;
        rear=(rear+1)%SIZE;
        CQ[rear]=item;
        
    }
    void CQ_Delete()
    {
        int item;
        item=CQ[front];
        printf("Deleted element is:%d",item);
        front=(front+1)%SIZE;
        
    }
    void CQ_Display()
    {
        int i;
        if(front==-1)
        printf("circular queue is empty\n");
        else{
            printf("element of the circular queue are..\n");
            for(i=front;i!=rear;i=((i+1)%SIZE))
            {
                printf("%d\t",CQ[i]);
            }
            printf("%d\n",CQ[i]);
            }
            
        }
        int IsCQ_Full()
        {
            if(front==(rear+1)%SIZE)
            return 1;
            return 0;
            
        }
        int IsCQ_Empty()
        {
            if(front==-1)
            return 1;
            else if(front==rear)
            {
                printf("deleted element is:%d",CQ[front]);
                front=-1;
                return 1;
                
            }
            return 0;
            
        }
    

