#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Node{
    string ID;
    int order;
    int priority;
    Node* next;
};

struct PriorityQueue{
    Node* head;
};

Node* createNode(string ID, int order, int prior);
void init(PriorityQueue& pq);
bool isEmpty(PriorityQueue pq);
void Insert(PriorityQueue& pq, string ID, int order, int priority);
void Extract(PriorityQueue& pq);
void Remove(PriorityQueue& pq, string ID);
void changePriority(PriorityQueue& pq, string ID, int prior);
void print_linked_list(PriorityQueue pq);
void removeAll(PriorityQueue& pq);