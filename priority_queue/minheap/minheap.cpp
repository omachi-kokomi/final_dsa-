#include"PQ_min_heap.h"

bool isEmpty(vector<obj> heap){
    if (heap.size() != 0) return false;
    return true;
}

void minHeapify(vector<obj>& heap, int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < heap.size() && heap[left].priority < heap[smallest].priority)
        smallest = left;
    if (right < heap.size() && heap[right].priority < heap[smallest].priority)
        smallest = right;
    if (smallest != i){
        swap(heap[i], heap[smallest]);
        minHeapify(heap, smallest);
    }
}

void Insert(vector<obj>& h, obj value){
    h.push_back(value);
    int i = h.size() - 1;
    while(i != 0 && h[(i-1) / 2].priority > h[i].priority){
        swap(h[i], h[(i-1) / 2]);
        i = (i - 1) / 2;
    }
}

void remove(vector<obj>& h, string ID){
    int index = -1;
    for (int i = 0; i < h.size(); i++)
        if (h[i].ID == ID) index = i;
    if (index == -1) cout << "Object with ID does not exist!\n";
    else{
        h[index] = h[h.size() - 1];
        h.pop_back();
        minHeapify(h, index);
    }

}

void changePriority(vector<obj>& h, string ID, int priority){
    vector<obj> saved;  
    int length = h.size();
    if (h.size() == 0) return;
    while (!isEmpty(h) && h[0].ID != ID){
        saved.push_back(h[0]);
        h[0] = h[--length];
        h.pop_back();
        minHeapify(h, 0);
    }
    // remove obj with ID and change priority
    if (!isEmpty(h)){
        obj new_obj = h[0];
        new_obj.priority = priority;
        saved.push_back(new_obj);
        h[0] = h[--length];
        h.pop_back();
        minHeapify(h, 0);
    }
    else cout << "Object with ID does not exist!\n";
    for (int i = 0; i < saved.size(); i++){
        Insert(h, saved[i]);
    }
}

void Extract(vector<obj>& h){
    int length = h.size();
    if (length == 0) return;
    h[0] = h[length - 1];
    h.pop_back();
    minHeapify(h, 0);
}

void print(vector<obj> a){
    for (int i = 0; i < a.size(); i++){
        cout << a[i].ID << " " << a[i].order << " " << a[i].priority << endl;
    }
}

void buildHeap(vector<obj>& h){
    for (int i = h.size() / 2 - 1; i >= 0; i--)
        minHeapify(h, i);
}