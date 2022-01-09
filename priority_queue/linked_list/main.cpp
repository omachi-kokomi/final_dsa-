#include "linkedlist.h"


void input_linked_list(PriorityQueue &pq)
{
    fstream fi;
    fi.open("input.txt", ios::in);
    int n;
    fi >> n;
    for (int i = 0; i < n; i++)
    {
        string ID;
        int order;
        int prior;
        fi.ignore();
        fi >> ID;
        fi >> order;
        fi >> prior;
        Insert(pq, ID, order, prior);
    }
    fi.close();
}

int main()
{
    cout << "Read from file input.txt!\n";
    
    PriorityQueue pq;
    init(pq);
    input_linked_list(pq);
    cout << "priority queue: \n";
    print_linked_list(pq);
    cout << "Change priority of ID '126' to 1 \n";
    changePriority(pq, "126", 1);
    print_linked_list(pq);
    cout << "Remove ID '124':\n";
    Remove(pq, "124");
    print_linked_list(pq);
    removeAll(pq);
    
    return 0;
}