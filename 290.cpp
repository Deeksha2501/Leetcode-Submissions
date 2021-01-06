#include<bits/stdc++.h>
#include<string.h>
#include<vector>

using namespace std;

typedef signed long long int ull;

vector<string> getStrArray(string s){
	vector<string> res;
	string curr_str = "";
	int n = s.length();
	int i=0;
	cout<<"n = "<<n;
	for(int i=0 ; i<n ; i++){
//		cout<<"\nvalue of i= "<<i;
		if(s[i] == ' '){
			res.push_back(curr_str);
			curr_str = "";
		}else{
			curr_str += s[i];
		}
		
	}
	res.push_back(curr_str);
	return res;
}

bool wordPattern(string pattern, string str) {
	vector<string> res;
    res = getStrArray(str);
    cout<<"\n";

	if(pattern.length() != res.size()){
		return false;
	}
	
	string freq[26] = {""};
	for(int i=0 ; i<pattern.length() ; i++){
		cout<<"value at i = "<<i<<" is "<<freq[pattern[i]-'a']<<"\n";
		if(freq[pattern[i]-'a'] == ""){
			for(int k=0 ; k<i ; k++){
				if(freq[pattern[k]-'a'] == res[i]){
					cout<<"value of k and i "<<k<<" "<<i;
					return false;
				}
			}
		freq[pattern[i]-'a'] = res[i];
	}else if(freq[pattern[i]-'a'] != res[i]){
		return false;
	}
		
	}
	
	cout<<endl;
    return true;
}

int main(){
	cout<<wordPattern("abba" , "dog cat cat dog")<<"\n\n\n";
	cout<<wordPattern("abba" , "dog cat cat fish")<<"\n\n\n";
	cout<<wordPattern("aaaa" , "dog cat cat dog")<<"\n\n\n";
	cout<<wordPattern("abba" , "dog dog dog dog")<<"\n\n\n";
	cout<<wordPattern("aaa" , "aa aa aa aa");

return 0;
}

