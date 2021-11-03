#include <bits/stdc++.h>
using namespace std;

int get_max_electricity(vector<int> k,vector<pair<int,int>> v1,int n){
    sort(v1.begin(),v1.end());
    int sum,max_sum=INT_MIN;
    for(int i=1;i<=n;i++) cout << i<< " ";
    cout << endl;
    for(int i=0;i<n;i++){
        vector <bool> p(n,true);
        for(int j=i;j<n+i;j++){
            if(p[j%n]==true){
                for(int k=0;k<2*n-2;k++){
                    if(v1[k].first==j%n){
                        p[v1[k].second] = false; 
                    }
                }    
            }
        }
        for(auto g: p) cout << g << " ";
        cout << endl;
        int sum=0;
        for(int l=0;l<n;l++){
            if(p[l]==true) sum += k[l];
        }
        max_sum = max(sum,max_sum);
    }
    return max_sum;
}

int main(){
    int n = 7;
    vector<int> k = {15,27,42,40,22,30,11};
    vector<pair<int,int>> v1;
    vector<int> arr = {1,1,1,2,3,4};
    vector<int> arr1 ={2,3,4,5,6,5}; 
    for(int i =0;i<n-1;i++){
        v1.push_back(make_pair(arr[i]-1,arr1[i]-1));    
    }
    for(int i =0;i<n-1;i++){
        v1.push_back(make_pair(arr1[i]-1,arr[i]-1));    
    }
    cout << get_max_electricity(k,v1,n);
}