#include<iostream>
#include<vector>
using namespace std;

int binarySearch(int a[], int left, int right, int x){
    while(left <= right){
        int mid = (left + right) / 2;
        if (x == a[mid]) return mid;
        else if (x < a[mid]) right = mid -1;
        else if (x > a[mid]) left = mid + 1;
    }
    return -1;
}

int binarysearchRec(int a[], int left, int right, int x){
    if (left <= right){
        int mid = left + (right - left) / 2;
        if (a[mid] == x) return mid;
        if (a[mid] > x) 
            return binarysearchRec(a, left, mid -1, x);
        return binarysearchRec(a, mid + 1, right, x);
    }
    return -1;
}

int bsfirst(int a[], int left, int right, int x){
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if ((mid == left || x > a[mid -1]) && a[mid] == x) return mid;
        else if (x > a[mid]) return bsfirst(a, (mid + 1), right, x);
        else
            return bsfirst(a, left, mid -1, x);
    }
    return -1;
}

int bslast(int a[], int left, int right, int x){
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if ((mid == right || x < a[mid + 1]) && a[mid] == x) return mid;
        else if (x >= a[mid]) return bslast(a, (mid + 1), right, x);
        else
            return bslast(a, left, mid -1, x);
    }
    return -1;
}

int interpolationSearch(int arr[], int n, int x)
{
    // Find indexes of two corners
    int lo = 0, hi = (n - 1);
 
    // Since array is sorted, an element present
    // in array must be in range defined by corner
    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        if (lo == hi)
        {
            if (arr[lo] == x) return lo;
            return -1;
        }
        // Probing the position with keeping
        // uniform distribution in mind.
        int pos = lo + (((double)(hi - lo) /
            (arr[hi] - arr[lo])) * (x - arr[lo]));
 
        // Condition of target found
        if (arr[pos] == x)
            return pos;
 
        // If x is larger, x is in upper part
        if (arr[pos] < x)
            lo = pos + 1;
 
        // If x is smaller, x is in the lower part
        else
            hi = pos - 1;
    }
    return -1;
}