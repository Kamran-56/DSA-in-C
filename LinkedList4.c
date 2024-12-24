// DELETE A NODE FROM SINGLY LINKED LIST: DELETE FROM BEGINNING, END, FROM ANY POSITION USING FUNCTIONS

    #include<stdio.h>
    #include<stdlib.h>

    typedef struct node {
    int data;
    struct node *next;
    }Node;

    Node *head = NULL, *newnode = NULL;

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
    

    void DeleteFromBeg(Node** head) {
        Node *nextnode, *current;
        if (*head == NULL)
        {
        printf("List is empty, nothing to delete\n");
        return;
        }
        
        current = *head;
        *head = (*head)->next;
        free(current);
    }


    void DeleteFromEnd(Node** head) {

        if (*head == NULL)
        {
            printf("List is empty, nothing to delete\n");
            return;
        }

        Node *current;
        Node *prevnode;
        current = *head;
        if (current->next == NULL)
        {                           // Case when there's only one node
            free(current);
            *head = NULL;
            return;
        }

        while(current->next != NULL)
        {
            prevnode = current;
            current = current->next;
        }
        prevnode->next = NULL;
        free(current);
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


    void DeleteFromPos(Node** head) {

        if(*head == NULL)
        {
            printf("list is empty, Nothing to delete!!");
            return;
        }

        int pos;
        printf("\nEnter postion(>0)of the node you want to delete:\t");
        scanf("%d", &pos);
        Node *current = *head;

        if(pos == 1)
        {
           *head = current->next;
           free(current);
           return;
        }

        else
        {
                int count=0;
                while(current != NULL)
            {
                current = current->next;
                count++;
            }
            if(pos > count)
            {
                printf("\nPosition out of range");
                return;
            }

            current = *head;
            int i = 1;
            while(current != NULL && i < pos-1)
            {
                current = current->next;
                i++;
            }
             // Now, `current` is the node before the node we want to delete

            Node *temp= current->next;
            current->next = current->next->next;
            free(temp);
        }
    }


    int main()
{
    CreateList(&head);

    printf("\noriginal list:\t");
    DisplayList(head);

    DeleteFromBeg(&head);
    printf("\n\nlist after deleting node from begining:\t");
    DisplayList(head);

    DeleteFromEnd(&head);
    printf("\n\nlist after deleting node from end:\t");
    DisplayList(head);

    DeleteFromPos(&head);
    printf("\n\nlist:\t");
    DisplayList(head);

    printf("\n---------------------------");
    return 0;
}