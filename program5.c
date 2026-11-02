#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *left, *right;
};
struct node *insert(struct node *, int);
struct node *delete(struct node *, int);
struct node *search(struct node *, int);
void display(struct node *);
void main(){
struct node *start = (struct node *)0;
int opt, item;
while (1) {
printf("\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Exit\n");
printf("Enter your choice: ");
scanf("%d", &opt);
switch (opt) {
case 1:printf("Enter element to insert: ");
scanf("%d", &item);
start = insert(start, item);
break;
case 2:printf("Enter element to delete: ");
scanf("%d", &item);
start = delete(start, item);
break;
case 3:display(start);
break;
case 4:printf("Enter element to search: ");
scanf("%d", &item);
if (search(start, item) == (struct node *)0)
printf("Not found\n");
else
printf("Element found\n");
break;
case 5:exit(0);
default:printf("Invalid choice\n");
}
}
}
struct node *insert(struct node *sp, int data){
struct node *temp;
temp = (struct node *)malloc(sizeof(struct node));
if (temp == NULL) {
printf("Memory allocation failed\n");
return sp;
}
temp->data = data;
temp->left = NULL;
temp->right = sp;
if (sp != NULL)
sp->left = temp;
sp = temp;
return sp;
}
struct node *delete(struct node *sp, int data){
struct node *temp = sp;
while (temp != NULL && temp->data != data)
temp = temp->right;
if (temp == NULL) {
printf("Element not found\n");
return sp;
}
if (temp->left != NULL)
temp->left->right = temp->right;
else
sp = temp->right;
if (temp->right != NULL)
temp->right->left = temp->left;
free(temp);
printf("Element deleted\n");
return sp;
}
void display(struct node *sp){
if (sp == NULL) {
printf("Stack is empty\n");
return;
}
printf("Stack elements:\n");
while (sp != NULL) {
printf("%d  ", sp->data);
sp = sp->right;
}
printf("\n");
}
struct node *search(struct node *sp, int data){
while (sp != NULL) {
if (sp->data == data)
return sp;
sp = sp->right;
}
return NULL;
}
