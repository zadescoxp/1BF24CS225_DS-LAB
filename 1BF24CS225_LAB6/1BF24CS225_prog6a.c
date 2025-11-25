#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node **head, int value) {
    struct Node *newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void sortList(struct Node *head) {
    if (head == NULL) return;

    struct Node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}


struct Node* reverseList(struct Node *head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct Node* concatenate(struct Node *head1, struct Node *head2) {
    if (head1 == NULL) return head2;
    struct Node *temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}

int main() {
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;

    insertEnd(&list1, 30);
    insertEnd(&list1, 10);
    insertEnd(&list1, 20);

    insertEnd(&list2, 40);
    insertEnd(&list2, 5);

    printf("List1: ");
    display(list1);

    sortList(list1);
    printf("Sorted List1: ");
    display(list1);

    list1 = reverseList(list1);
    printf("Reversed List1: ");
    display(list1);

    printf("List2: ");
    display(list2);

    list1 = concatenate(list1, list2);
    printf("Concatenated List: ");
    display(list1);

    return 0;
}
