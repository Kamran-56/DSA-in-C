// LINKED LIST: REVERSE A SINGLY LINKED LIST

    #include<stdio.h>
    #include<stdlib.h>

    typedef struct node {
    int data;
    struct node *next;
    }Node;
    struct node *head = NULL, *newnode;

    void CreateList(Node** head) {
        int choice = 1;
        Node *current;
        
        while(choice)
        {
        newnode = (Node*) malloc(sizeof(Node));

        if(newnode == NULL)
        {
            printf("memory allocation failed!!!");
            exit(1);
        }

        printf("Enter data:\t");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if(*head == NULL)
            current = *head = newnode;
        else
        {
            current->next = newnode;
            newnode->next = NULL;
            current = newnode;
        }
        printf("\nDo you want to add any other data? (1 for YES / 0 for NO)");
        scanf("%d", &choice);
        }
    }

    void DisplayList(Node* head) {
        Node *current = head;
        while(current != NULL)
        {
            printf("%d->", current->data);
            current = current->next;
        }
        printf("NULL");
    }

    void ReverseList(Node** head) {
    Node* prevnode = NULL, *currentnode, *nextnode;
    currentnode = nextnode = *head;
    while(nextnode != NULL)
    {
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    *head = prevnode;
   }


    int main()
{
    CreateList(&head);
    printf("\nOriginal list:\t");
    DisplayList(head);

    ReverseList(&head);
    printf("\n\nList After reversing:\t");
    DisplayList(head);

    printf("\n-----------------------");
}
