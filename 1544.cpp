#include<bits/stdc++.h>
#include<string.h>
#include<vector>

using namespace std;

bool isGood(string s){
    for(int i=0 ; i<s.length()-1 ; i++){
        if(abs(s[i]-s[i+1]) == 32){
            return false;
        }
    }
    return true;
}

string makeGood(string s) {
    while(isGood(s) == false){
        // cout<<"s.length() = "<<s.length()<<"\n";
        for(int i=0 ; i<s.length()-1 ; i++){
            if(abs(s[i]-s[i+1]) == 32){
                cout<<"i = "<<i<<endl;
                s.erase(s.begin()+i , s.begin()+i+2);
                if(s.length() == 0)return s;
            }
        }
    }
    return s;
}

int main(){
    cout<<makeGood("abBAcC");

   return 0;
}