#include <bits/stdc++.h>
using namespace std;
int Bsearch(const vector <int>&A,int low, int high,int target){
    if(low>high) return -1;
    int mid = (low+high)/2;
    if(A[mid]==target) return mid;
    if(A[mid]>target) return Bsearch(A,low,mid-1,target);
    else return Bsearch(A,mid+1,high,target);
}

int rotate_key(const vector<int>&A,int low,int high){
    int k = A.size();
    int mid = (low+high)/2;
    if(A[mid]>A[mid-1] && A[mid]>A[mid+1]) return mid;
    else if(A[mid]>A[low]) return rotate_key(A,mid+1,high);
    else if(A[mid]<A[low]) return rotate_key(A,low,mid-1);
    return mid;
}


int search(const vector<int> &A, int B) {
    int n = A.size();
    if(A[n-1]>=A[0]) return Bsearch(A, 0, n-1, B);
    int key = rotate_key(A,0,n-1);
    if(B==A[key]) return key;
    if(B>=A[0]) return Bsearch(A,0,key-1,B);
    else return Bsearch(A,key+1,n-1,B);
    
}

int main(){
    const vector<int> A = {192, 194, 197, 198, 199, 200, 201, 203, 204, 2, 3, 4, 7, 9, 10, 11, 14, 15, 16, 17, 20, 
    21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 33, 34, 35, 36, 39, 40, 42, 43, 46, 47, 50, 51, 52, 53, 55, 57, 59, 60,
     64, 66, 68, 70, 71, 72, 75, 76, 78, 85, 86, 87, 91, 92, 94, 95, 96, 99, 102, 105, 106, 107, 109, 111, 113, 114,
      115, 119, 120, 121, 123, 125, 129, 130, 131, 133, 134, 137, 138, 139, 140, 141, 142, 143, 145, 146, 149, 151, 152,
       156, 160, 161, 165, 167, 168, 170, 171, 176, 177, 178, 179, 180, 181, 182, 185, 186, 190};
    int B = 70;
    cout << search(A,B);
}
