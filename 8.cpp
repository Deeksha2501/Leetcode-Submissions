#include<bits/stdc++.h>
#include<string.h>
#include<vector>

using namespace std;

int myAtoi(string s) {
    int i=0;
    int n = s.length();
    while(i<n && s[i] == ' '){
        i++;
    }
    char sign = '+';
    if(i<n && s[i] == '+' || s[i] == '-'){
        sign = s[i];
        i++;
    }
    
    //when words are in starting
    if(isalpha(s[i]) || s[i] == ' ' || s[i]=='+' || s[i] == '-'){
        return 0;
    }
    
    //when digits are in starting
    int nn = i;
    while(nn<n && s[nn] != '.' && 
            s[nn] !='+' && s[nn]  != '-' && 
            s[nn] != ' ' && isdigit(s[nn])){
        nn++;
    }
    
    
    
    long double num = 0, p=0;
    bool flag=false;
    int j=nn-1;
    for(j=nn-1 ; j>=i ; j--){
        // if(s[j] == '.'){
        //     flag = true;
        //     break;
        // }
        num += (s[j]-'0')*pow(10,p);
        p++;
        
    }
    // j--;
    
    // cout<<"num = "<<num;
    
//         if(flag){
//             num = num/pow(10,p);
//             // cout<<"num = "<<num;
//             long double num2 = 0, p2 = 0;
//             for(int k=j ; j>=i ; j--){
//                 // cout<<"s[k] = "<<s[k];
//                 num2 += (s[k]-'0')*pow(10,p2);
//                 p2++;
//             }
//             // cout<<"num2 = "<<num2;
//             num = num + num2;
//         }
    
    if(sign == '-'){
        num = -num;
    }
    
    if(num > INT_MAX){
        num = INT_MAX;
    }else if(num < INT_MIN){
        num = INT_MIN;
    }
    
    

    return num;
}

int main(){

    cout<<myAtoi("-42");

   return 0;
}