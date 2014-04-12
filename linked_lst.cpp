#include<iostream>
#include<stdlib.h>
using namespace std;

struct linked_lst {
    int data;
    struct linked_lst *next;
};

typedef struct linked_lst ll;

//NOTE : malloc always return void pointer to allocated heap slab
//We have to explictly point to the memory location.
// 0 == NULL
void create_node(ll **head, int data) {
    ll *ll_node = (ll *) malloc(sizeof(ll));
    ll_node->data = data;
    ll_node->next = 0;
    if (*head == 0) {
        *head = ll_node;
    }else{
      ll_node->next = *head;
      *head = ll_node;
    }

}

void insert_node_ll() {

}

void delete_node_ll() {
}

void traverse_ll (ll *head) {
    cout << "traversing the element" << endl;
    while (head != 0)  {
        cout << head->data << " "; 
        head = head->next;
    }
    cout << endl;
}

void reverse_ll () {

}

void create_linked_lst() {

}

int main () {
    ll *head = 0;
    create_node (&head,12);
    create_node (&head,14);
    traverse_ll(head);
}


