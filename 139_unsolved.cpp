#include<bits/stdc++.h>
#include<string.h>
#include<vector>

using namespace std;

typedef signed long long int ull;

    bool findWord(string s , vector<string>& wd){
        for(int i=0 ; i<wd.size() ; i++){
            if(s == wd[i]){
                return true;
            }
        }
        return false;
    }    
    
    bool check(string s, int k, vector<string>& wordDict){
    	cout<<"\nentered";
    	cout<<"\nvalue of k = "<<k;
        if(k >= s.length())
            return true;
        string curr = "";
        for(int i=k ; i<s.length() ; i++){
            curr += s[i];
            bool val = findWord(curr , wordDict);
            if(val){
                bool res = check(s , i+1 , wordDict);
                if(res){
                    return true;
                }
//                else{
//                     return false;
//                }
            }
        }
        
        return false;
    }

int main(){
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	vector<string> wordDict{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
//	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<check(s , 0 , wordDict);

return 0;
}

//"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
//["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]

