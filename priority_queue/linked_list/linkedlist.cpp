#include"linkedlist.h"

void init(PriorityQueue& pq){
    pq.head = NULL;
}

bool isEmpty(PriorityQueue pq){
    if (pq.head == NULL) return true;
    return false;
}

Node* createNode(string ID, int order, int priority){
    Node* p = new Node;
    p->ID = ID;
    p->order = order;
    p->priority = priority;
    p->next = NULL;
}

void Insert(PriorityQueue& pq, string ID, int order, int priority){
    Node* p = createNode(ID, order, priority);
    if (isEmpty(pq)){
        pq.head = p;
        return;
    }
    // insert head
    if (p->priority < pq.head->priority){
        p->next = pq.head;
        pq.head = p;
        return;
    }
    else{
        Node* cur = pq.head;
        while (cur->next){
            if (cur->next->priority > p->priority){
                p->next = cur->next;
                cur->next = p;
                return;
            }
            cur = cur->next;
        }
        // insert tail
        cur->next = p;
    }
}

void Extract(PriorityQueue& pq){
    if (isEmpty(pq)) return;
    Node* p = pq.head;
    pq.head = pq.head->next;
    delete p;
}

void Remove(PriorityQueue& pq, string ID){
    if (isEmpty(pq)) return;
    // remove head
    if (pq.head->ID == ID){
        Extract(pq);
    }
    else{   // ID of head is not the ID needed to be deleted
        Node* cur = pq.head;
        Node* prev = NULL;
        while (cur){
            if (cur->ID == ID){
                Node* p = cur;
                prev->next = cur->next;
                delete p;
                return;
            }
            prev = cur;
            cur = cur->next;
        }
    }
}

void changePriority(PriorityQueue& pq, string ID, int prior){
    if (isEmpty(pq)) return;
    // find node that has ID equal to ID
    Node* cur = pq.head;
    while(cur){
        if (cur->ID == ID)
            break;
        cur = cur->next;
    }
    int order = cur->order;
    Remove(pq, ID);
    Insert(pq, ID, order, prior);
}

void print_linked_list(PriorityQueue pq){
    Node* cur = pq.head;
    while(cur){
        cout << cur->ID << " " << cur->order << " " << cur->priority << endl;
        cur = cur->next;
    }
}

void removeAll(PriorityQueue& pq){
    while (!isEmpty(pq)) Extract(pq);
}