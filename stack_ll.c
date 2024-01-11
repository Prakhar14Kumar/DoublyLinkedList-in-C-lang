#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *top=NULL;
void push(){
    struct node *newnode = NULL;
    newnode=(struct node *) malloc(sizeof (struct node));
    printf("enter the data at the top");
    scanf("%d",& newnode->data);
    newnode->next=top;
    top=newnode;
}
void pop(){
    if(top=NULL){
        printf("Can't pop ,stack is empty");
    }
    struct node *temp=top;
    top=top->next;
    free(temp);
}
void display(){
    struct node *temp=top;
    while(temp!=NULL) {
        printf("%d\n", temp->data );
        temp = temp->next;
    }
}
int main()
{
    int ch;
    while(1){
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&ch);

        switch (ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
        }
    }
}