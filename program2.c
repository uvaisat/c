//Stack operation
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int stk[SIZE];
int sp=-1;
void main(){
void push(int);
int pop();
void display();
int opt,item;
do{
printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
printf("Enter your choice: ");
scanf("%d",&opt);
switch(opt){
case 1:printf("Enter item:");
scanf("%d",&item);
push(item);
break;
case 2:item=pop();
if (item!=-9)
printf("popped value=%d\n",item);
break;
case 3:
display();
break;
case 4:
exit(0);
}
}
while(1);
}
//function to push an item to stack
void push(int x)
{
if(sp==SIZE-1){
printf("Stack is full");
return;
}else
stk[++sp]=x;
return;
}
//function to pop an item from stack
int pop(){
if(sp==-1){
printf("empty stack...");
return -9;
}else
{
return stk[sp--];
}
}
//function to display the stack
void display()
{
int i;
if (sp == -1)
{
printf("Stack is empty!\n");
return;
}
printf("Stack elements are:\n");
for(i = sp; i >= 0; i--)
{
printf("%d\n", stk[i]);
}
}
