#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node *left, *right;
};
struct node *insert(struct node *, int);
struct node *delete(struct node *, int);
struct node *search(struct node *, int);
void display(struct node *);
void main()
{
struct node *list=(struct node *)0;
struct node *start=(struct node *)0;
while(1){
printf("\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Exit\n");
printf("Enter your choice: ");
scanf("%d", &opt);
switch (opt){
case 1:printf("Enter element to insert: ");
scanf("%d", &item);
start=insert(start,item);
break;
case 2:printf("Enter element to delete:");
scanf("%d", &item);
start=delete(start,item);
break;
case 3:display(start);
break;
case 4:printf("Enter element to search: ");
scanf("%d", &item);
if(search(start,item)==(struct node *)0)
printf("Not found\n");
else
printf("Element found\n");
break;
case 5:exit(0);
default:printf("Invalid choice\n");
}
}
}
struct node *insert(struct node *sp, int data){     // Function to push an element
struct node *temp;
temp = (struct node *)malloc(sizeof(struct node));
temp->data = data;
temp->prev = NULL;
temp->next = sp;
if (sp != NULL){
sp->prev = temp;
}
sp = temp;
return sp;
}
struct node *pop(struct node *sp, int *x){    // Function to pop an element
struct node *temp;
if (sp != NULL){
temp = sp;
*x = temp->data;
sp = sp->next;
if (sp != NULL){
sp->prev = NULL;
}
free(temp);
}
return sp;
}
void display(struct node *sp){    // Function to display the stack
if (sp == NULL){
printf("Stack is empty\n");
return;
}
printf("Stack elements:\n");
while (sp != NULL){
printf("%d  ", sp->data);
sp = sp->next;
}
printf("\n");
}
int search(struct node *sp, int data){    // Function to search for an element
while (sp != NULL){
if (sp->data == data)
return 1;
sp = sp->next;
}
return 0;
}
