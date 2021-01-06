//Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used 
//and each combination should be a unique set of numbers.
//
//Note:
//
//All numbers will be positive integers.
//The solution set must not contain duplicate combinations.

//Input: k = 3, n = 9
//Output: [[1,2,6], [1,3,5], [2,3,4]]


#include<bits/stdc++.h>
#include<string.h>
#include<vector>

using namespace std;

typedef signed long long int ull;

bool checkNums(vector<int> v){
	for(int i=0 ; i<v.size() ; i++){
		if(v[i] >9){
			return false;	
		}
	}
	return true;
}

bool check(vector<int> v){
	for(int i=0 ; i<v.size()-1 ; i++){
		if(v[i+1]<=v[i]){
			return false;	
		}
	}
	return true;
}

void get(vector<int> v , vector<vector<int> > &res , int p){
	int k = v.size();
	vector<int> dup = v;
	while(p<=(k-1)){
	int val=1;
	while(check(dup)){
			int i= k-2;
			int j= p;
			while(j--){
				dup[i] += val;
				dup[k-1] -= val;
				i--;
			}
			for(int i=0 ; i<dup.size() ; i++){
				cout<<dup[i]<<" ";
			}
			if(check(dup) ){
				if(checkNums(dup)){
				bool isPresent = std::find(res.begin(), res.end(), dup) != res.end();
				cout<<"\n\nvalue of isPresent = "<<isPresent;
				if(!isPresent)
					res.push_back(dup);
			}
				get(dup , res , p);
			}
			
		}
		dup=v;
		p++;
		val++;
	}
}

vector<vector<int> > combinationSum3(int k, int n) {
	vector<vector<int> > res;
	int min_limit = k*(k+1)/2;
	int max_limit = k*(19-k)/2;
	if(min_limit > n || max_limit < n){
		return res;
	}
    vector<int> v , dup;
    int i=1;
    int t = k-1;
    int sum = 0;
    while(t--){
    	v.push_back(i);
    	sum += i;
    	i++;
	}
	v.push_back(n-sum);
	for(int i=0 ; i<v.size() ; i++){
		cout<<v[i]<<" ";
	}
	dup = v;
	int p=1 , j=1;
	if(check(v)){
		if(checkNums(v))
		res.push_back(v);
		get(v , res , 1);

}
	
}

int main(){
	vector<vector<int> > res = combinationSum3(4 , 54);
	for(int i=0 ; i<res.size() ; i++){
		for(int j=0 ; j<res[i].size() ; j++){
			cout<<res[i][j]<<" ";
		}
		cout<<"\n";
	}

return 0;
}

