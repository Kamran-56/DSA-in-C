// REVERSE A DOUBLY LINKED LIST   
   
    #include <stdio.h>
    #include <stdlib.h>

    struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
    };

    struct Node *head = NULL, *tail = NULL, *current = NULL, *newNode;

    void reverseList(struct Node** head, struct Node** tail) {
    current = *head;
    struct Node* nextNode = NULL;
    while (current != NULL)
    {
        nextNode = current->next;
        current->next = current->prev;
        current->prev = nextNode;
        current = nextNode;
    }
    struct Node *temp;
    temp = *head;
    *head = *tail;
    *tail = temp;
    }

    void displayList(struct Node* head) {
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    }

    int main()
{
    int choice = 1;
    
    while (choice)
    {
        newNode = (struct Node*) malloc(sizeof(struct Node));
        printf("Enter Data: ");
        scanf("%d", &newNode->data);            // Use newNode->data
        newNode->prev = NULL;
        newNode->next = NULL;
        
        if (head == NULL)
        {
            head = tail = current = newNode;
        } else
        {
            /*tail->next = newNode;
            newNode->prev = tail;
            newNode->next = NULL;
            tail = newNode;*/
            current->next = newNode;
            newNode->prev = current;
            newNode->next = NULL;
            current = newNode;
            tail = newNode;
        }
        
        printf("Another input? (press 1 for yes, 0 for no): ");
        scanf("%d", &choice);
    }

    printf("\nOriginal List:\t");
    displayList(head);
    printf("\nhead->data=%d", head->data);

    reverseList(&head, &tail);
    printf("\n\nReversed List:\t");
    displayList(head);
    printf("\nhead->data=%d", head->data);

    if (tail->next == NULL) {
    printf("\n\nTail's next is NULL, indicating the end of the list.");
    }
    printf("\n----------------------------------");
    return 0;
}
