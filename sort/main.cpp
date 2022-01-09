#include"Sort.h"
#include"DataGenerator.h"
#include<string>
#include<time.h>
using namespace std;

string _a = "-a";
string _c = "-c";
string _time = "-time";
string _comp = "-comp";
string _both = "-both";

void copy(int* a, int* b, int n){
    for (int i = 0; i < n; i++)
        b[i] = a[i];
}

bool isNumber(char* c) {
    for (int i = 0; i < sizeof(c); i++)
        if (!isalnum(c[i]))
            return false;
    return true;
}

void input(int* a, int& n, fstream& fi) {
    fi >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
        fi >> a[i];
}

void output(int* a, int n, fstream& fo) {
    fo << n << endl;
    for (int i = 0; i < n; i++)
        fo << a[i] << " ";
}

double Sort_time(int* a, int n, string st) {

    clock_t s, e;
    double time = 0;
    // Selection sort
    if (!st.compare("selection-sort")) {
        s = clock();
        SelectionSort(a, n);
        e = clock();
        time = ((double)(e - s)) / CLOCKS_PER_SEC;

    }
    //Insertion sort
    else if (!st.compare("insertion-sort")) {
        s = clock();
        InsertionSort(a, n);
        e = clock();
        time = ((double)(e - s)) / CLOCKS_PER_SEC;

    }
    // Bubble sort
    else if (!st.compare("bubble-sort")) {
        s = clock();
        BubbleSort(a, n);
        e = clock();
        time = ((double)(e - s)) / CLOCKS_PER_SEC;

    }
    // shaker-sort
    else if (!st.compare("shaker-sort")) {
        s = clock();
        shakerSort(a, n);
        e = clock();
        time = ((double)(e - s)) / CLOCKS_PER_SEC;

    }
    // shell sort
    else if (!st.compare("shell-sort")) {
        s = clock();
        shellSort(a, n);
        e = clock();
        time = ((double)(e - s)) / CLOCKS_PER_SEC;

    }
    // heap sort
    else if (!st.compare("heap-sort")) {
        s = clock();
        HeapSort(a, n);
        e = clock();
        time = ((double)(e - s)) / CLOCKS_PER_SEC;

    }
    // merge sort
    else if (!st.compare("merge-sort")) {
        s = clock();
        mergeSort(a, 0, n - 1);
        e = clock();
        time = ((double)(e - s)) / CLOCKS_PER_SEC;

    }
    //quick sort
    else if (!st.compare("quick-sort")) {
        s = clock();
        QuickSort(a, 0, n - 1);
        e = clock();
        time = ((double)(e - s)) / CLOCKS_PER_SEC;

    }
    // counting sort
    else if (!st.compare("counting-sort")) {
        s = clock();
        CountingSort(a, n);
        e = clock();
        time = ((double)(e - s)) / CLOCKS_PER_SEC;

    }
    // radix sort
    else if (!st.compare("radix-sort")) {
        s = clock();
        radixSort(a, n);
        e = clock();
        time = ((double)(e - s)) / CLOCKS_PER_SEC;

    }
    // flash sort
    else if (!st.compare("flash-sort")) {
        s = clock();
        FlashSort(a, n);
        e = clock();
        time = ((double)(e - s)) / CLOCKS_PER_SEC;

    }
    return time;
}

long long Sort_count(int* a, int n, string st) {
    long long count = 0;
    // Selection sort
    if (!st.compare("selection-sort")) {
        SelectionSortCount(a, n, count);
    }
    //Insertion sort
    else if (!st.compare("insertion-sort")) {
        InsertionSortCount(a, n, count);
    }
    // Bubble sort
    else if (!st.compare("bubble-sort")) {
        BubbleSortCount(a, n, count);
    }
    // shaker-sort
    else if (!st.compare("shaker-sort")) {
        shakerSortCount(a, n, count);
    }
    // shell sort
    else if (!st.compare("shell-sort")) {
        shellSortCount(a, n, count);
    }
    // heap sort
    else if (!st.compare("heap-sort")) {
        HeapSortCount(a, n, count);
    }
    // merge sort
    else if (!st.compare("merge-sort")) {
        mergeSortCount(a, 0, n - 1, count);
    }
    //quick sort
    else if (!st.compare("quick-sort")) {
        QuickSortCount(a, 0, n - 1, count);
    }
    // counting sort
    else if (!st.compare("counting-sort")) {
        CountingSortCount(a, n, count);
    }
    // radix sort
    else if (!st.compare("radix-sort")) {
        radixSortCount(a, n, count);
    }
    // flash sort
    else if (!st.compare("flash-sort")) {
        FlashSortCount(a, n, count);
    }
    return count;
}

void command_1(char* input_file, char* algorithm, char* output_parameter) {
    fstream fi, fo;
    fi.open(input_file, ios::in);
    fo.open("output.txt", ios::out);
    int n = 0;
    int* a = nullptr;
    
    input(a, n, fi);
    int* b = new int[n];
    copy(a, b, n);
    string algo(algorithm);
    cout << "ALGORITHM MODE\nAlgorithm: " << algo;
    cout << "\nInput file: " << input_file;
    cout << "\nInput size: " << n;
    cout << "\n-----------------------------\n";
    // command -time or -both
    if (!_time.compare(output_parameter) || !_both.compare(output_parameter))
    {
        double time = Sort_time(a, n, algo);
        cout << "Running time: " << time << endl;
    }
    // command -comp
    if (!_comp.compare(output_parameter) || !_both.compare(output_parameter)) {
        long long count = Sort_count(b, n, algo);
        cout << "Comparisons: " << count << endl;
    }
    output(a, n, fo);
    fi.close();
    fo.close();
    delete[]a;
    delete[]b;
}

void command_2(char* _algo, char* input_size, char* input_order, char* output_param) {
    string algo(_algo);
    int n = atoi(input_size);
    int* a = new int[n];
    int* b = new int[n];
    string order(input_order);
    cout << "ALGORITHM MODE\nAlgorithm: " << algo;
    cout << "\nInput size: " << n;
    cout << "\nInput order: ";
    if (order == "-rand") { GenerateRandomData(a, n); cout << "Randomize"; }
    else if (order == "-nsorted") { GenerateNearlySortedData(a, n); cout << "Nearly Sorted"; }
    else if (order == "-sorted") { GenerateSortedData(a, n); cout << "Sorted"; }
    else { GenerateReverseData(a, n); cout << "Reversed"; }
    fstream fo;
    copy(a, b, n);
    fo.open("input.txt", ios::out);
    output(a, n, fo);
    fo.close();
    cout << "\n---------------------------------\n";
    if (!_time.compare(output_param) || !_both.compare(output_param)) {
        double time = Sort_time(a, n, algo);
        cout << "Running time: " << time << endl;
    }
    if (!_comp.compare(output_param) || !_both.compare(output_param)) {
        
        long long count = Sort_count(b, n, algo);
        cout << "Comparisons: " << count << endl;
    }
    fo.open("output.txt", ios::out);
    output(a, n, fo);
    fo.close();
    delete[]a;
}

void command_3(char* algorithm, char* input_size, char* output_param) {
    int n = atoi(input_size);
    int* a = new int[n];
    int* b = new int[n];
    string algo(algorithm);
    cout << "ALGORITHM MODE\nAlgorithm: " << algo;
    cout << "\nInput size: " << n << "\n\n";

    for (int i = 0; i < 4; i++) {
        cout << "Input order: ";
        if (i == 0) cout << "Randomize";
        else if (i == 3) cout << "Nearly Sorted";
        else if (i == 1) cout << "Sorted";
        else cout << "Reversed";
        cout << "\n----------------------------------\n";
        GenerateData(a, n, i);
        copy(a, b, n);
        if (!_time.compare(output_param) || !_both.compare(output_param)) {
            double time = Sort_time(a, n, algo);
            cout << "Running time: " << time << endl;
        }
        if (!_comp.compare(output_param) || !_both.compare(output_param)) {
            long long count = Sort_count(b, n, algo);
            cout << "Comparisons: " << count << endl;
        }
        cout << endl;
    }
    delete[]a;
    delete[]b;
}

void command_4(char* algo_1, char* algo_2, char* input_file) {
    string algo1(algo_1);
    string algo2(algo_2);
    cout << "COMPARE MODE\nAlgorithm: ";
    cout << algo1 << " | " << algo2 << endl;
    cout << "Input file: " << input;
    int* a = nullptr;
    int n;
    fstream fi, fo;
    fi.open(input_file, ios::in);
    fo.open("output.txt", ios::out);
    input(a, n, fi);
    int* a2 = new int[n];
    int* a3 = new int[n];
    int* a4 = new int[n];
    for (int i = 0; i < n; i++)
    {
        a2[i] = a3[i] = a4[i] = a[i];
    }
    cout << "Input size: " << n;
    cout << "\n-----------------------------------\n";
    double time1 = Sort_time(a, n, algo1);
    output(a, n, fo);
    delete[] a;
    double time2 = Sort_time(a2, n, algo2);
    delete[] a2;
    long long count1 = Sort_count(a3, n, algo1);
    delete[] a3;
    long long count2 = Sort_count(a4, n, algo1);
    delete[] a4;
    cout << "Running time: " << time1 << " | " << time2 << endl;
    cout << "Comparisons: " << count1 << " | " << count2 << endl;
    fi.close();
    fo.close();
}

void command_5(char* _algo1, char* _algo2, char* input_size, char* input_order) {
    string algo1(_algo1);
    string algo2(_algo2);
    int n = atoi(input_size);
    int* a = new int[n];
    string order(input_order);
    cout << "COMPARE MODE\nAlgorithm: " << algo1 << " | " << algo2 << endl;
    cout << "Input size: " << n;
    cout << "\nInput order: ";
    if (order == "-rand") { GenerateRandomData(a, n); cout << "Randomize"; }
    else if (order == "-nsorted") { GenerateNearlySortedData(a, n); cout << "Nearly Sorted"; }
    else if (order == "-sorted") { GenerateSortedData(a, n); cout << "Sorted"; }
    else { GenerateReverseData(a, n); cout << "Reversed"; }
    fstream fo;
    fo.open("input.txt", ios::out);
    output(a, n, fo);
    fo.close();

    cout << "\n---------------------------------\n";

    int* a2 = new int[n];
    int* a3 = new int[n];
    int* a4 = new int[n];
    for (int i = 0; i < n; i++)
    {
        a2[i] = a3[i] = a4[i] = a[i];
    }
    double time1 = Sort_time(a, n, algo1);
    delete[] a;
    double time2 = Sort_time(a2, n, algo2);
    delete[] a2;
    long long count1 = Sort_count(a3, n, algo1);
    delete[] a3;
    long long count2 = Sort_count(a4, n, algo1);
    delete[] a4;
    cout << "Running time: " << time1 << " | " << time2 << endl;
    cout << "Comparisons: " << count1 << " | " << count2 << endl;
}

int main(int argc, char* argv[])
{
    if (argc == 5) { // if there are 5 arguments ( command 1, 3, 4)
        if (_a.compare(argv[1]) == 0) { // if mode -a (command 1, 3)
            // command 1
            if (isNumber(argv[3]) == false) command_1(argv[3], argv[2], argv[4]);
            // command 3
            else command_3(argv[2], argv[3], argv[4]);
        }
        // command 4
        else command_4(argv[2], argv[3], argv[4]);
    }
    // command 2, 5
    else {
        if (!_a.compare(argv[1])) {
            // command 2
            command_2(argv[2], argv[3], argv[4], argv[5]);
        }
        // command 5
        else command_5(argv[2], argv[3], argv[4], argv[5]);

    }

    return 0;
}