#include<bits/stdc++.h>
#include<string.h>
#include<vector>

using namespace std;

//Compare Version Numbers
//Compare two version numbers version1 and version2.
//If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

vector<string> getString(string str){
	vector<string> s;
	string curr_s = "";
	for(int i=0 ; i<str.length() ; i++){
		if(str[i] != '.'){
		    curr_s += str[i];
	}
		else{
		s.push_back(curr_s);
		curr_s = "";
	}
	}
	s.push_back(curr_s);
	return s;
}

int compareVersion(string v1, string v2) {
	vector<string> s1 = getString(v1);
	vector<string> s2 = getString(v2);
	if(s1.size() >= s2.size()){
		int n = s1.size() - s2.size();
		while(n--){
			s2.push_back("0");
		}
	}
	else{
		int n = s2.size() - s1.size();
		while(n--){
			s1.push_back("0");
		}
	}
	for(int i=0 ; i<s1.size() ; i++){
		int num1 = stoi(s1[i]);
		int num2 = stoi(s2[i]);
		if(num1<num2){
			return -1;
		}else if(num1>num2){
			return 1;
		}
	}
	return 0;
}

int main(){
	string v1 = "1.01" , v2 = "1.001";
	cout<<compareVersion(v1 , v2);

return 0;
}

