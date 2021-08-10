#include<bits/stdc++.h>
#include<string.h>
#include<vector>

using namespace std;

int maxElement(vector<int> arr){
    int n = arr.size();
    if(n == 0)return 0;
    int leader = arr[n-1];
    int res=1;
    for(int i=n-2 ; i>=0 ; i--){
        if(arr[i] > leader){
            res++;
            leader = arr[i];
        }
    }
    return res;
}

int main(){
    vector<int> v{7,9,5,2,8,7};
    cout<<maxElement(v);

   return 0;
}