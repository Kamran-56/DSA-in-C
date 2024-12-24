// INSERTION IN DOUBLY LINKED LIST: INSERT A NODE AT BEGINNING, END.

    #include<stdio.h>
    #include<stdlib.h>

    typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
    } Node;

    Node* head = NULL, *tail = NULL, *newnode = NULL, *current = NULL;

    void createList(Node** head, Node** tail) {
    int choice = 1;
    while(choice)
    {
        newnode = (Node*) malloc(sizeof(Node));
        if (newnode == NULL)
        {
            printf("Memory allocation failed!!!");
            exit(1);
        }
        else
        {
            printf("\nEnter data: \t");
            scanf("%d", &(newnode)->data);  // Corrected scanf

            (newnode)->prev = NULL;
            (newnode)->next = NULL;

            if (*head == NULL) {
                *head = *tail = newnode; // Head and tail both point to the first node
            }
            else
            {
                (*tail)->next = newnode;
                (newnode)->prev = *tail;
                *tail = newnode;
            }

            printf("\nDo you want to add another node? (1 for Yes / 0 for No):\t");
            scanf("%d", &choice);
        }
    }
    }

    void displayList(Node* head) {
    current = head;
    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }

    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

    void insertAtBegining(Node** head, int data) {
        newnode = (Node*) malloc(sizeof(Node));
        newnode->next = *head;
        newnode->data = data;
        newnode->prev = NULL;
        *head = newnode;
        printf("\nlist after inserting node at begining:\n");
    }

    void insertAtEnd(Node** tail, int data) {
        newnode = (Node*) malloc(sizeof(Node));
        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = (*tail);
        if (*tail != NULL)
        {
        (*tail)->next = newnode;
        }
        *tail = newnode;
    }


    int main() {
    createList(&head, &tail);
    printf("\nOriginal list:\n");
    displayList(head);

    insertAtBegining(&head, 23);
    displayList(head);

    printf("\nlist after inserting node at end:\n");
    insertAtEnd(&tail, 99);
    insertAtEnd(&tail, 457);
    insertAtEnd(&tail, 3215292);
    displayList(head);

    if (tail->next == NULL) {
    printf("\n\nTail's next is NULL, indicating the end of the list.");
    }
    printf("\n----------------------------------");
    return 0;
}
