#include<bits/stdc++.h>
#include<string.h>
#include<vector>

using namespace std;

int main(){
    int n=10;
    int a,b,c;
    a=0,b=1,c=1;
    while(c<n){
        b = b*c;
        a = a + (b/c);
        c = c+1;
    }
    cout<<a;

   return 0;
}