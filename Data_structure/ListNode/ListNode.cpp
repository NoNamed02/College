// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *link;
}Node;

/*
void insert_f(Node* head, int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = v;
    p->link = head;
    head = p;
}
*/

Node* insert_f(Node* head, int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = v;
    p->link = head;
    head = p;
}


void print(Node* head){
    Node* p;
    for(p=head;p!=NULL;p=p->link)
        printf("%d\n",p->data);
    printf("NULL");
}


Node* _insert(Node* head, int find_data, int v){
    Node* p;
    for(p=head;p!=NULL;p=p->link){
        if(p->data = find_data)
            break;
    }
    Node* p2 = (Node*)malloc(sizeof(Node));
    p2->data = v;
    p2->link = p->link; 
    p->link = p2;
    return head;
}


Node* insert(Node* head, Node* pre, int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = v;
    p->link = pre->link;
    pre->link = p;
    return head;
}

Node* delete_f(Node* head){
    Node* re;
    re = head;
    head = head->link;
    free(re);
    return head;
}

Node* _delete(Node* head, Node* pre){
    Node* re;
    re = pre->link;
    pre->link = re->link;
    free(re);
    return head;
}

int main() {
    Node* A;
    A= (Node*)malloc(sizeof(Node));
    A->data = 10;
    A->link = NULL;
    
    //insert_f(A, 20);
    //insert_f(A, 30);
    //A = insert_f(A, 20);
   // A = insert(A, A->link,30);
    _insert(A,10,50);
    _insert(A,10,60);
    //A = delete_f(A);
    A = delete_f(A);
    //A = _delete(A,A);
    
    //A = delete_f(A);
    
    
    print(A);
    
    return 0;
}
