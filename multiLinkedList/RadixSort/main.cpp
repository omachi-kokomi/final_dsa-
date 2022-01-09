#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct node
{
    int key;
    node *next;
};

struct bucket
{
    int id;
    node *head, *tail;
    bucket *next;
};

node *CreateNode(int x)
{
    node *p = new node;
    p->key = x;
    p->next = NULL;
}

bucket *CreateBucket(int id)
{
    bucket *b = new bucket;
    b->id = id;
    b->head = NULL;
    b->tail = NULL;
    b->next = NULL;
    return b;
}

void removeLL(node *&h, node *&t)
{
    while (h)
    {
        node *p = h;
        h = h->next;
        delete p;
    }
}

void insert(bucket *&b, int id, int x)
{
    if (b == NULL)
    {
        b = CreateBucket(id);
        node *p = CreateNode(x);
        b->head = p;
        b->tail = p;
        return;
    }
    else
    {
        bucket *cur = b;
        bucket *prev = NULL;
        while (cur)
        {
            if (cur->id == id)
            { // co bucket
                // them x vao bucket
                node *cur_node = cur->head;
                node *prev_node = NULL;
                // tim vi tri chen bucket
                while (cur_node)
                {
                    if (cur_node->key > x)
                        break;
                    prev_node = cur_node;
                    cur_node = cur_node->next;
                }
                node *p = CreateNode(x);
                if (cur_node)
                    p->next = cur_node;
                else
                    cur->tail = p;
                if (prev_node)
                    prev_node->next = p;
                else
                    cur->head = p;
                return;
            }
            if (cur->id > id)
            { // tim vi tri tao them bucket
                break;
            }
            prev = cur;
            cur = cur->next;
        }
        bucket *new_bucket = CreateBucket(id);
        node *p = CreateNode(x);
        new_bucket->head = p;
        new_bucket->tail = p;
        if (cur)
            new_bucket->next = cur;
        if (prev)
            prev->next = new_bucket;
        else
            b = new_bucket;
    }
}

void extract(node *&h, node *&t, bucket *&b)
{
    while (b)
    {
        node *cur = b->head;
        while (cur)
        {
            node *p = CreateNode(cur->key);
            if (h == NULL)
            {
                h = p;
                t = p;
            }
            else
            {
                t->next = p;
                t = p;
            }
            // delete cur
            node *d = cur;
            cur = cur->next;
            delete d;
        }
        // delete bucket
        bucket *a = b;
        b = b->next;
        delete a;
    }
}

int countDigit(int a)
{
    int count = 0;
    while (a > 0)
    {
        count += 1;
        a /= 10;
    }
    return count;
}
int getdigit(int x, int k)
{
    int count = 1;
    while (count < k)
    {
        x /= 10;
        count += 1;
    }
    return x % 10;
}

void radixSort(node *&h, node *&t, int max, int k)
{
    int n = countDigit(max);
    int count = 1;
    while (count <= n)
    {
        bucket *b = NULL;
        node *cur = h;
        while (cur)
        {
            insert(b, getdigit(cur->key, count), cur->key);
            cur = cur->next;
        }
        removeLL(h, t);
        extract(h, t, b);
        count +=1;
    }
}

void print(node *h, node *t, fstream &fo)
{
    node *cur = h;
    while (cur)
    {
        fo << cur->key << " ";
        cur = cur->next;
    }
}

int main()
{
    node *h = NULL;
    node *t = NULL;
    bucket *b = NULL;
    fstream fi, fo;
    fi.open("input.txt", ios::in);
    int k;
    int n;
    fi >> k >> n;
    int a;
    int max = -1e9;
    for (int i = 0; i < n; i++)
    {
        fi >> a;
        node *p = CreateNode(a);
        if (h == NULL)
        {
            h = p;
            t = p;
        }
        else
        {
            t->next = p;
            t = p;
        }
        if (max < a)
            max = a;

    }
    radixSort(h, t, max, k);
    fi.close();
    fo.open("output.txt", ios::out);
    print(h, t, fo);
    fo.close();
    return 0;
}