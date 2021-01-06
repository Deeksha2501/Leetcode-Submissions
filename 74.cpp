#include<bits/stdc++.h>
#include<string.h>
#include<vector>

using namespace std;

typedef signed long long int ull;

bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int c = m-1;
        int r = 0;
        while((0<=c)&&(r<n)){
        	cout<<"\nr = "<<r;
        	cout<<"\nc = "<<c;
            int curr = mat[r][c];
            if(target == curr){
                return true;
            }
            if(target > curr){
                r++;
            }else{
                c--;
            }
        }
        return false;
    }

int main(){
	
	vector<vector<int> >mat{{1,3,5,7} , {10,11,16,20} , {23,30,34,50}};
	int t = 13;
	cout<<searchMatrix(mat , t);

return 0;
}

