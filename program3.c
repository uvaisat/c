//Queue operation
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int que[SIZE];
int front=0, rear=0;  //Empty queue
void main(){
void enqueue(int);
int dequeue(), item, opt;
void display();
do{
printf("\n1.Insert\n2.delete\n3.Display\n4.Exit\n");
printf("Enter your choice: ");
scanf("%d",&opt);
switch(opt){
case 1:printf("Enter your item:");
scanf("%d",&item);
enqueue(item);
break;
case 2:item= dequeue();
if(item!=-9)
printf("Deleted value= %d",item);
break;
case 3:
display();
break;
case 4:exit(0);
default:printf("Invalid choice");
}
}
while(9);
}
//function to insert an item
void enqueue(int item){
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
if(front==rear){
printf("Queue is empty");
return -9;
}
else{
front=(front+1)%SIZE;
return que[front];
}
}
//Function to display an item
void display(){
int i;
if(front==rear)
printf("No data...");
else{
i=(front+1)%SIZE;
do{
printf("%d ",que[i]);
i=(i+1)%SIZE;
}
while(i!=(rear+1)%SIZE);
}
return;
}
