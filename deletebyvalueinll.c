//program to insert element at any position in a linked list 


#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* head;

struct node * delete(struct node *head,int value){
    struct node *p = head;//pointer to head node
    struct node *q = head->next;
    while (q->data!=value && q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if (q->data==value)
    {
        p->next = q->next;
        free(q);
    }
    
    return head;
    

}
void insert(struct node **head,int data, int position){
    int k = 1;
    struct node *p,*q;
    struct node* newdata;
    newdata = (struct node*)malloc(sizeof(struct node));

    newdata->data = data;
    newdata->next = NULL;
    p = *head;
    //insertion at first position 
    if (position==1)
    {
        newdata->next = p;
        *head = newdata;
    }
    else{
        while (p!=NULL && k<position)// using k to reach a specified position 
        {
            k++;
            q=p;//q is set to p to keep the track of previos node
            p=p->next;
        }
        q->next = newdata;
        newdata->next = p;
        
    }
    
}
void display(){
    struct node *temp = head;
    while (temp !=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
}

int main()
{
   head = NULL;
    insert(&head,3,1);
    insert(&head,4,2);
    insert(&head,5,2);//it shifted 4 to position 3
    display();
    head = delete(head,5);
    printf("\n");
    display();

   return 0;
}