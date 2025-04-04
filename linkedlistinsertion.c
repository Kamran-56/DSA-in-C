#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* head;

struct node* create(struct node * head,int data){
    
    struct node * temp = malloc(sizeof(struct node));
    if (temp==NULL)
    {
        printf("Memory allocation failed");
    }
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else{
        struct node* p = head;
        while (p->next!=NULL)
        {
            p = p->next;
        }
        p->next = temp;
        
    }
    
    
    
    return head;



}
void display() {
    struct node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
   head = NULL;
    int nodes;
    printf("Enter number of elements : ");
    scanf("%d",&nodes);
    int data;
    for (int i = 0; i < nodes; i++)
    {
        printf("Enter data: ");
        scanf("%d",&data);
        head = create(head,data);
    }
    display();
   return 0;
}