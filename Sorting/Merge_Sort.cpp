#include <bits/stdc++.h>
using namespace std;

void merger(vector<int> &A, int l, int mid, int r){
    vector<int> temp(A.size(),0);
    int p1=l,p2= mid+1,i=l;
    while(p1<=mid && p2<=r){
        if(A[p2]<A[p1]) temp[i++] = A[p2++];
        else temp[i++] = A[p1++];
    }
    while(p1<=mid) temp[i++] = A[p1++];
    while(p2<=r) temp[i++] = A[p2++];
    for(int j=l;j<=r;j++) A[j] = temp[j];
}

void mergesort(vector<int> &A, int l, int r){

    int mid = (l+r)/2;
    if(l==r) return;
    mergesort(A,l,mid);
    mergesort(A,mid+1,r);
    merger(A,l,mid,r);
}
int main(){
    vector <int> p = {2,3,8,7,4,5,9};
    mergesort(p,0,p.size()-1);
    for(int i=0;i<p.size();i++) cout << p[i] << " ";
}
