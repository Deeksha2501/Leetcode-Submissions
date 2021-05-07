#include<bits/stdc++.h>
#include<string.h>
#include<vector>

using namespace std;

int getL(int i , int j, string s1 , string s2 , vector<vector<int> >& mem){
        int n = s1.length();
        int m = s2.length();
        if(mem[i][j] != INT_MIN)return mem[i][j];
        if(i>=n || j>= m){
            return 0;
        }
        
        if(s1[i] == s2[j]){
            mem[i][j] = 1+getL(i+1 , j+1 , s1 , s2,mem);
        }
        else{
         mem[i][j] =  max(getL(i , j+1 , s1 , s2,mem) , getL(i+1 , j , s1 , s2,mem));
        }
        return mem[i][j];
    }
    
    int minDistance(string w1, string w2) {

            int n = w1.length();
            int m = w2.length();
            vector<vector<int> > mem(n+1 , vector<int>(m+1 , INT_MIN));
        
        

            return w1.length()+w2.size() - 2*getL(0 , 0 , w1 , w2 , mem);
    }

int main(){

    string w1 = "dinitrophenylhydrazine";
    string w2  = "acetylphenylhydrazine";
    cout<<minDistance(w1,w2);

   return 0;
}