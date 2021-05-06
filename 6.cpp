#include<bits/stdc++.h>
#include<string.h>
#include<vector>

using namespace std;

string convert(string st, int num) {
        
    int n = st.length();
    string res = "";
    
    for(int i=0 ; i<num ; i++){
        set<int> s;
        set<int>::iterator itr;
        int j=i;
        // cout<<"in row "<<i<<endl;
        while(j<n){
            s.insert(j);
            // cout<<"inserting 1st = "<<j<<endl;
            int v1 = 2*num -2 + j;
            if(v1<n && v1>0){
                s.insert(v1);
                // cout<<"inserting 2nd = "<<v1<<endl;
            }
            int v2 = 2*num -2*i - 2 + j;
            if(v2<n && v2>0){
                s.insert(v2);
                // cout<<"inserting 3rd = "<<v2<<endl;
            }
            j = v1;
        }
        for (itr = s.begin(); itr != s.end(); itr++)
        {
            res += st[*itr];
        }
        
    }
    return res;
    
}

int main(){

    cout<<convert("PAYPALISHIRING" , 4);

   return 0;
}


// PAHNAPLSIIGYIR
// PAHNAPLSIIGYIR

PINALSIGYAHRPI
PINALSIGYAHRPI