//Queue operation
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int que[SIZE];
int front=0, rear=0;  //Empty queue
int opt;
void main(){
void enqueue(int);
int dequeue, item;
do{
printf("1.Insert\n2.delete\n3.Display\n4.Exit\n");
printf("Your Opinion: ");
scanf("%d",&opt);
switch(opt){
case 1:printf("Enter item:");
scanf("%d",&opt);
enqueue(item);
break;
case 2:item= dequeue();
printf("Deleted value= %d",item);
break;
case 3:
display();
break;
case 4:exit(0);	
}
while(9);
}
//function to insert an item
void enqueue(int x){
int temp;
temp=(rear+1)%SIZE;
if(temp==front)
printf("Queue is full");
else{
rear=temp;
que[rear]=item;
}
return;
}
//Function to delete an item from queue
int dequeue(){
if(front==rear)
printf("Queue is empty");
else{
front=(front+1)%SIZE;
return que[front];
}
}
void display(){
int i;
if(front==rear)
printf("No data...");
else{
i=(front+1)%SIZE;
do{
printf("%d",que[i]);
i=(i+1)%SIZE;
}
while(i!=front);
}
}
return;
}
