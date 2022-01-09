#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

typedef struct leader* lref;
typedef struct trailer* tref;
struct leader{
    int key;    // khoa nhan dien
    int count;  //so luong cac phan tu leader dung truoc
    lref next;  // truong lien ket
    tref trail; // quan li cac phan tu leader dung sau no
};
struct trailer{
    lref id;    // chi den phan tu leader dung sau leader dang xet
    tref next;
};

lref addList(lref& head, lref& tail, int w, int& z){
    lref h;
    h = head;
    tail->key = w;
    while(h->key != w)  h = h->next;
    if (h == tail){
        tail = new leader;
        z++;
        h->count = 0;
        h->trail = NULL;
        h->next = tail;
    }
    return h;
}

void print(lref head, lref tail, int& z, fstream& fo){
    fo.open("output.txt", ios::out);
    lref p = head;
    head = NULL;
    while (p!= tail){
        lref q = p;
        p = p->next;
        if (q->count == 0){
            q->next = head;
            head = q;
        }
    }
    lref q = head;
    while (q){
        fo << q->key;
        z--;
        tref t = q->trail;
        q = q->next;
        while(t){
            lref p = t->id;
            p->count--;
            if (p->count == 0){
                p->next = q;
                q = p;
            }
            t = t->next;
        }
    }
}


int main(){
    lref head, tail, p, q;
    tref t;
    int x, y, z;

    head = new leader;
    tail = head;
    z = 0;
    fstream fin, fout;
    fin.open("input.txt", ios::in);
    while (!fin.eof()){
        if (fin.eof())
            break;
        char c;
        fin >> c;   //doc dau (
        fin >> x;   
        fin >> c;   //doc dau ,
        fin >> y;   
        fin >> c;   // doc dau )
        p = addList(head, tail, x, z);
        q = addList(head, tail , y, z);
        t = new trailer;
        t->id = q;
        t->next = p->trail;
        p->trail = t;
        q->count++;
        
    }
    fin.close();
    print(head, tail, z, fout);
    fout.close();
    return 0;
}