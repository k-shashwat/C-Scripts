#include <bits/stdc++.h>
using namespace std;

int get_min(vector<int> arr, int i, int min_p){
    if(i==arr.size()) return min_p;
    if(arr[i]<arr[min_p]) min_p = i;
    return get_min(arr,i+1,min_p);
}

void sel_sort(vector<int> &arr, int start){
    if(start == arr.size()) return;
    int min_pos = get_min(arr,start,start);
    swap(arr[start],arr[min_pos]);
    sel_sort(arr,start+1);
}

int main(){
    vector <int> p = {2,3,7,6,4,5,9};
    sel_sort(p,0);
    // sort(p.begin(),p.end());
    for(int i=0;i<p.size();i++) cout << p[i] << " ";
}
