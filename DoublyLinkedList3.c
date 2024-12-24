// INSERTION IN DOUBLY LINKED LIST: INSERT A NODE AT ANY POSITION.

    #include<stdio.h>
    #include<stdlib.h>

    typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
    } Node;

    Node* head = NULL, * tail, * newnode, * current;

    void createList (Node** head, Node** tail) {
    int choice = 1;
    while (choice)
    {
        newnode = (Node*)malloc(sizeof(Node));
        if (newnode == NULL) {
            printf("Memory allocation failed!!!");
            exit(1);
        }
        else
        {
            printf("\nEnter data: ");
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


    void insertAtAnyPosition(Node** head) {
    int pos, data;
    printf("\nEnter position at which node has to be added in the list: ");
    scanf("%d", &pos);

    if (pos <= 0)
    {
        printf("Invalid position! Position should be greater than 0.\n");
        return;
    }

    newnode = (Node*) malloc(sizeof(Node));
    if(newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    if (pos == 1)
    {
        newnode->prev = NULL;
        newnode->next = *head;
        if (*head != NULL)
        {
            (*head)->prev = newnode;
        }
        *head = newnode;
        return;
    }
    else
    {
        current = *head;
        int i = 1;
        while (i < pos - 1)
        {
            current = current->next;
            i++;
        }

    // Insert at the end if we reached the last node
        if (current->next == NULL)
        {
            newnode->prev = current;
            newnode->next = NULL;
            current->next = newnode;
        }

        else
        {
        // Insert in between
            newnode->prev = current;
            newnode->next = current->next;
            current->next->prev = newnode;
            current->next = newnode;
        }
    }
    }

    int main()
{
    createList(&head, &tail);
    printf("\nOriginal list:\n");
    displayList(head);

    insertAtAnyPosition(&head);
    displayList(head);

    if (tail->next == NULL)
    printf("\n\nTail's next is NULL, indicating the end of the list.");
    printf("\n----------------------------------");
    return 0;
}