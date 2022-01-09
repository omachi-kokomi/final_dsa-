#include "minheap.h"
void input(vector<obj> &h)
{
    fstream fi;
    fi.open("input.txt", ios::in);
    int n;
    fi >> n;
    for (int i = 0; i < n; i++)
    {
        obj a;
        fi.ignore();
        fi >> a.ID;
        fi >> a.order;
        fi >> a.priority;
        h.push_back(a);
    }
    fi.close();
}

int main()
{
    cout << "Read from file input.txt!\n";
    vector<obj> a;
    input(a);
    buildHeap(a);
    cout << "min heap: \n";
    print(a);
    cout << "Insert object with ID '200', order = 6, priority = 1: \n";
    obj n;
    n.ID = "200";
    n.order = 6;
    n.priority = 1;
    Insert(a, n);
    print(a);
    cout << "Remove ID '124': \n";
    remove(a, "124");
    print(a);
    cout << "Change priority of '126' to 1: \n";
    changePriority(a, "126", 1);
    print(a);
    
    return 0;
}