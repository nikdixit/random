#include <stdio.h>
#include <stdlib.h>

typedef struct CList {
    struct Node *head;
    int length;
} CList;


typedef struct Node {
    int data;
    struct Node *next;
} Node;

CList* create_list(){
     CList *list = malloc(sizeof(CList));
    list->head = NULL;
    list->length = 0;
    return list;
}

Node* create_node(int data ){
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->data = data;
    return node;
}

void create_initial_nodes(CList  *list,int count){
    Node *previous=NULL;

    for(int i=0;i<count;i++){
        int x;
        printf("Input the value of node %d: ",i+1);
        scanf("%d",&x);
        Node *node=create_node(x);

        if (list->length == 0) {
            list->head = node;
        }
        else {
            previous->next = node;
        }
    previous=node;
    list->length++;
    }
    previous->next=list->head;
}

int main(){
    int count;
    printf("Enter the number of Elements: ");
    scanf("%d",&count);

    if(count<1){
        printf("Invalid input,\n");
        return 1;
    }

    CList *list=create_list();
    create_initial_nodes(list, count);
    printf("\n");

    // Node *current=list->head;

    Node *node=list->head;
    while(node->next!=node){
        node->next=node->next->next;
        node=node->next;
        list->length--;
    }
    printf("The soilder is: %d",node->data);
}