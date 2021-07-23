#include<bits/stdc++.h>
using namespace std;


    bool check(int i , int j ,int k ,string s1 , string s2 , string s3){
        
        int n1 = s1.length();
        int n2 = s3.length();
        int n3 = s3.length();

        
        if(i>=n1 && j>=n2 && k>=n3){
            cout<<i<<" "<<j<<" "<<k<<endl;
            return true;
        }
        // if(k>=n3)return false;
        
        bool f1 = false,f2 = false;

        
        if(i<n1 && s3[k] == s1[i]){
            f1 = check(i+1 , j , k+1 , s1 , s2 , s3);
        }
        
        if(j<n2 && s3[k] == s2[j]){
            f2 = check(i , j+1 , k+1 , s1 , s2 , s3);
        }
        // if(i<n1 && j<n2 && s3[k] != s1[i] && s3[k] != s2[j]){
        //     return false;
        // }
        
        return f1 || f2;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1+s2 == s3)return true;
        if(s1.length() + s2.length() != s3.length())return false;
        
        return check(0,0,0,s1,s2,s3);
        
    }


int main(){
    cout<<isInterleave("aa","ab","aaba")<<endl;
}