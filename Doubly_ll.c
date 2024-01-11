#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
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

void create_dll() {
    struct node *newnode, *temp;
    int choice;

    while (1) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }

        printf("If you want to continue, press 1; to break, press 0: ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }
    }
}

void insert_at_pos(int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct node *newnode, *temp, *prev;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;

    if (position == 1) {
        newnode->next = head;
        head->prev = newnode;
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

    newnode->prev = prev;
    newnode->next = temp;
    if (temp != NULL) {
        temp->prev = newnode;
    }
    if (prev != NULL) {
        prev->next = newnode;
    } else {
        head = newnode;
    }
}

void insert_at_beg() {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data at the beginning: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL) {
        head->prev = newnode;
    }
    head = newnode;
}

void insert_at_end() {
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data at the End: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
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
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
}

void delete_beg() {
    if (head == NULL) {
        printf("List is empty, cannot delete from the beginning.\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
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
                create_dll();
                break;

            case 2:
                insert_at_beg();
                break;

            case 3:
                insert_at_end();
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
                insert_at_pos(pos);
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
