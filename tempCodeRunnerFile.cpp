#include<bits/stdc++.h>
#include<string.h>
#include<vector>

using namespace std;

int getnext(int digits){
    string s="";
    s += '1';
    for(int i=1 ; i<digits ; i++){
        s += (to_string(digits-1));
    }
    int num = stoi(s);
    return num;
}

int main(){

    cout<<getnext(9);

   return 0;
}