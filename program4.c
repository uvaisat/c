#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *sp=NULL;
struct node *push(struct node *,int);
struct node *pop(struct node *,int *);
void display(struct node *);
int search(struct node *,int);
int main(){
int opt, data, found;
for(;;){
printf("\n1.Push\n2.Pop\n3.Display\n4.Search\n5.Exit\n");
printf("Enter your choice: ");
scanf("%d",&opt);
switch(opt){
case 1:printf("Enter Elements to insert:");
scanf("%d",&data);
sp=push(sp,data);
break;
case 2:
if (sp==NULL){
printf("Stack is empty\n");
}else{
sp=pop(sp, &data);
printf("Popped elements : %d\n",data);
}
break;
case 3:
display(sp);
break;
case 4:
printf("Enter the elements to searched :");
scanf("%d",&data);
found = search(sp,data);
if(found!=0)
printf("The element %d is found\n",data);
else
printf("Data not found");
break;
case 5:
exit(0);
default:
printf("Invalid choice\n;");
}
}
return 0;
}
struct node *push(struct node *sp, int data){   //Function to push an element
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=data;
temp->next=sp;
sp=temp;
return sp;
}
struct node *pop(struct node *sp, int *x){   //Function to remove an element
struct node *temp;
if(sp!=NULL){
temp=sp;
*x=sp->data;
sp=sp->next;
free(temp);
}
return sp;
}
//Function to display the stack
void display(struct node *sp){
if(sp==NULL){
printf("Stack is empty\n");
return;
}
printf("Stack elements:\n");
while(sp!=NULL){
printf("%d  ",sp->data);
sp=sp->next;
}}
//Function to search an element in the stack
int search(struct node *sp, int data){
while(sp !=NULL){
if(sp->data==data)
return 1;
sp=sp->next;
}
return 0;
}
