#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void display() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void createsll() {
    struct node *newnode, *temp;
    int choice;

    while (1) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("If you want to continue, press 1; to break, press 0: ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }
    }
}

void insertatpos(int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct node *newnode, *temp, *prev;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (position == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;
    int current_pos = 1;
    prev = NULL;

    while (temp != NULL && current_pos < position) {
        prev = temp;
        temp = temp->next;
        current_pos++;
    }

    if (temp == NULL && current_pos < position) {
        printf("Position out of range.\n");
        free(newnode);
        return;
    }

    prev->next = newnode;
    newnode->next = temp;
}

void insertatbeg() {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data at the beginning: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}

void insertatend() {
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data at the End: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void delete_end() {
    if (head == NULL) {
        printf("List is empty, cannot delete from the end.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    free(temp);
    prev->next = NULL;
}

void delete_beg() {
    if (head == NULL) {
        printf("List is empty, cannot delete from the beginning.\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);
}

int main() {
    int ch, pos;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Create list\n");
        printf("2. Create at the beginning of the list\n");
        printf("3. Create at the end of the list\n");
        printf("4. Delete at the end of the list\n");
        printf("5. Delete at the beginning of the list\n");
        printf("6. Insert at a specific position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                createsll();
                break;

            case 2:
                insertatbeg();
                break;

            case 3:
                insertatend();
                break;

            case 4:
                delete_end();
                break;

            case 5:
                delete_beg();
                break;

            case 6:
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                insertatpos(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
