#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

struct obj{
    string ID;
    int order;
    int priority;
};

bool isEmpty(vector<obj> heap);
void minHeapify(vector<obj>& heap, int i);
void Insert(vector<obj>& h, obj value);
void remove(vector<obj>& h, string ID);
void changePriority(vector<obj>& h, string ID, int priority);
void Extract(vector<obj>& h);
void print(vector<obj> a);
void buildHeap(vector<obj>& h);