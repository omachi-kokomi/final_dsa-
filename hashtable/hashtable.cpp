#include<string>
#include<iostream>
#include<vector>
using namespace std;

const int TABLE_SIZE = 2000;
struct node{
    string key;
    node* next;
};

struct HashTable{
    node* head = NULL;
    int count = 0;
};

HashTable* hashTable;

node* createNode(string key){
    node* newNode = new node();
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}
// hash function
int Hash(string key){
    int hashValue = 1315423911;
    int a = 5;
    int b = 2;
    for (int i = 0; i < key.size(); i++){
        int x = hashValue << a;
        int y = hashValue >> b;
        hashValue ^= (x + key[i] + y);
    }
    return hashValue & 0x7FFFFFFF;
}

// separate chaining (bam dong dung danh sach lien ket)
void insertKey(string key){
    int index = Hash(key) % TABLE_SIZE;
    node* newNode = createNode(key);
    if (!hashTable[index].head){
        hashTable[index].head = newNode;
        hashTable[index].count = 1;
        return;
    }
    newNode->next = hashTable[index].head;
    hashTable[index].head = newNode;
    hashTable[index].count++;
}

bool searchKey(string key){
    int index = Hash(key) %TABLE_SIZE;
    node* myNode = hashTable[index].head;
    while(myNode != NULL){
        if (myNode->key == key) return true;
        myNode = myNode->next;
    }
    return false;
}

bool deleteKey(string key){
    int index = Hash(key) % TABLE_SIZE;
    node* myNode = hashTable[index].head;
    if (!myNode) return false;
    node* temp = myNode;
    while(myNode){
        if (myNode->key == key){
            if (myNode == hashTable[index].head)
                hashTable[index].head = myNode->next;
            else{
                temp->next = myNode->next;
            }
            hashTable[index].count --;
            delete myNode;
            return true;
        }
        temp = myNode;
        myNode = myNode->next;
    }
    return false;
}
//linear probing (cong index them 1 cho den khi vi tri do trong)
struct Node{
    string key;
    int marker;
};
int current_size;
Node* hTable;
bool insertKeyLinear(string key){
    unsigned int index = Hash(key) % TABLE_SIZE;
    if (current_size >= TABLE_SIZE) return false;
    while(hTable[index].marker == 1) index = (index + 1) %TABLE_SIZE;
    hTable[index].key = key;
    hTable[index].marker = 1;
    current_size++;
    return true;
}

int searchKeyLinear(string key){
    int index = Hash(key) %TABLE_SIZE;
    int count = 0;
    if (current_size == 0) return -1;
    while(hTable[index].marker != 0 && count << TABLE_SIZE){
        if (hTable[index].key == key){
            if (hTable[index].marker == 1) return index;
            return -1; // found, but deleted
        }
        index = (index + 1) % TABLE_SIZE;
        count ++;
    }
    return -1;
}

bool deleteKeyLinear(string key){
    int index = searchKeyLinear(key);
    if (index == -1) return false;
    current_size--;
    hTable[index].marker = -1;
    return true;
}

// binary probing(do nhi phan)
// di chuyen den index con trong ke tiep bang cach dung XOR
// oo buoc i dem index hien tai XOR voi i mod table_size
int searchKeyBinary(string key){
    int index = Hash(key) % TABLE_SIZE;
    int count = 0;
    if(current_size == 0) return -1;
    int i = 1;
    while(hTable[index].marker != 0 && count <= TABLE_SIZE){
        if (hTable[index].key == key){
            if (hTable[index].marker == 1) return index;
            return -1; //found but deleted
        }
        index = (index ^ 1) % TABLE_SIZE;
        count ++;
        i++;
    }
    return -1;
}
// tuong tu linear
bool deleteKeyBinary(string key);


// quadratic probing(do bac 2)
// timf gtnn i sao cho (index + i^2) % table_size

bool insertKeyQua(string key){
    int index = Hash(key) %TABLE_SIZE;
    if (current_size >= TABLE_SIZE) return false;
    for (int i = 1; i < TABLE_SIZE; i++){
        if (hTable[index].marker == 0){
            hTable[index].key = key;
            hTable[index].marker = 1;
            current_size++;
            return true;
        }
        index = (index + (1LL * i * i) %TABLE_SIZE) %TABLE_SIZE;

    }
    return false;
}

int searchKeyQua(string key){
    int index = Hash(key) %TABLE_SIZE;
    int count = 0;
    if (current_size == 0) return -1;
    int i = 1;
    while(hTable[index].marker != 0 && count <= TABLE_SIZE){
        if (hTable[index].key == key){
            if (hTable[index].marker == 1) return index;
            return -1;
        }
        index = (index + (1LL * i * i) %TABLE_SIZE) % TABLE_SIZE;
        count++;
        i++;
    }
    return -1;
}
// tuong tu linear
bool deleteKeyQua(string key){

}

// double hashing(bam kep)
// index = (index + i * index_second) % table_size
// tim i nho nhat tu 1-> table_size cho den khi index trong
bool insertKeyDouble(string key){
    int index = Hash(key) % TABLE_SIZE;
    int index_second = Hash(key) + TABLE_SIZE;  // hash khac dong tren
    if (current_size >= TABLE_SIZE) return false;
    for(int i = 1; i < TABLE_SIZE;i++)
    {
        if (hTable[index].marker == 0){
            hTable[index].key = key;
            hTable[index].marker = 1;
            current_size++;
            return true;
        }
        index = (index + i * index_second) % TABLE_SIZE;
    }
    return false;
}

int searchkey(string key){
    int index = Hash(key) % TABLE_SIZE;
    int index_second = Hash(key) % TABLE_SIZE;
    int count = 0;
    if (current_size == 0) return -1;
    int i = 1;
    while (hTable[index].marker != 0 && count <= TABLE_SIZE){
        if (hTable[index].key == key){
            if (hTable[index].marker == 1) return index;
            return -1; // found, but deleted
        }
        index = (index + i * index_second) % TABLE_SIZE;
        count++;
        i++;
    }
    return -1;
}
