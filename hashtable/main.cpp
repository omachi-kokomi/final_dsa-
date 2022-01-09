#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

struct Company
{
    string name;
    string profit_tax;
    string address;
};

vector<Company> ReadCompanyList(string filename)
{
    fstream fi;
    fi.open(filename, ios::in);
    string s;
    getline(fi, s);
    vector<Company> v;
    while (!fi.eof())
    {
        if (fi.eof())
            break;
        getline(fi, s);
        stringstream line(s);
        vector<string> token;
        Company p;
        string st;
        while (getline(line, st, '|'))
            token.push_back(st);
        p.name = token[0];
        p.profit_tax = token[1];
        p.address = token[2];
        v.push_back(p);
    }
    return v;
}
long long modularExponent(int a, int b, int m){
    long long res = 1;
    a %= m;
    while(b > 0){
        if (b % 2 == 1) res = (res * a) % m;
        b /= 2;
        a = (a * a) % m;
    }
    return res;
}
long long HashString(string company_name)
{
    long long res = 0;
    int p = 31;
    int m = 1e9 + 9;
    int i = company_name.length() - 21 > 0 ? company_name.length() - 21 : 0;
    int j = 0;
    for (i; i < company_name.length(); i++)
    {
        res = ((res % m) + (((long long)((company_name[i] - 'a') % m) * modularExponent(p, j, m)) % m)) % m;
        j += 1;
    }
    return res % m;
}

void insert(Company *HashTable, Company company)
{
    long long res = HashString(company.name) % 2000;
    while (HashTable[res].name != "")
        res = (res + 1) % 2000;
    HashTable[res] = company;
}

Company *CreateHashTable(vector<Company> list_company)
{
    Company *HashTable = new Company[2000];
    for (int i = 0; i < list_company.size(); i++)
    {
        insert(HashTable, list_company[i]);
    }
    return HashTable;
}

Company *Search(Company *HashTable, string company_name)
{
    long long index = HashString(company_name) % 2000;
    int count = 0;
    while (HashTable[index].name != "" && count <= 2000)
    {
        if (HashTable[index].name == company_name)
        {
            return &HashTable[index];
        }
        index = (index + 1) % 2000;
        count++;
    }
    return NULL;
}

/*
delete: search key--> neu co thi danh dau marked = -1
*/

void printInfo(Company *p)
{
    if (p == NULL)
    {
        cout << "Not found!\n";
        return;
    }
    cout << p->name << endl;
    cout << p->profit_tax << endl;
    cout << p->address << endl;
}

int main()
{
    vector<Company> list_company = ReadCompanyList("MST.txt");
    Company *hashTable = CreateHashTable(list_company);
    Company *found = Search(hashTable, "CONG TY TNHH THUONG MAI S.L.D");
    printInfo(found);
    return 0;
}