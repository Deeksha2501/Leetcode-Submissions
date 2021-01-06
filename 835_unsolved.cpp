#include<bits/stdc++.h>
#include<string.h>
#include<vector>

using namespace std;

typedef signed long long int ull;

int calcCount (vector<vector<int>>& A, vector<vector<int>>& B , int i , int j){
		int na = A.size();
        int ma = A[0].size();
        int nb = B.size();
        int mb = B[0].size();
        int max_count = 0;
	int count = 0;
	for(int s1=1 ; s1<=i ; s1++){
        for(int s2=1 ; s2<=j ; s2++){
            cout<<"\n s1s2 = "<<s1-1<<" "<<s2-1;
            cout<<"\n effective "<<(nb-i)+s1-1<<" "<<(mb-j)+s2-1;
            if(A[s1-1][s2-1] == 1 && B[(nb-i)+s1-1][(mb-j)+s2-1] == 1){
                count++;
                max_count = max(count , max_count);
			}
		}
	}
	cout<"abc\n\n\n";
	count =0;
	for(int s1=i ; s1<na ; s1++){
		for(int s2=j ; s2<nb ; s2++){
			cout<<"\n\ncoy knke\n\n";
			cout<<"\n s1s2 = "<<s1<<" "<<s2;
            cout<<"\n effective "<<s1-i<<" "<<s2-j;
			if(A[s1][s2]==1 && B[s1-i][s2-j]==1){
				count++;
				max_count = max(count , max_count);
			}
		}
	}
	cout<<"\n\n\n";
	return max_count;
}

int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
		int na = A.size();
        int ma = A[0].size();
        int nb = B.size();
        int mb = B[0].size();
        int max_count = 0;
        cout<<na<<" "<<nb<<" "<<ma<<" "<<mb;
        for(int i=1 ; i<=na ; i++){
            for(int j=1 ; j<=ma ; j++){
                cout<<"square formed with coodinates = 0 0 "<<i<<" "<<j;
                int count=calcCount(A , B , i , j);
                max_count = max(count , max_count);
				cout<<"count = "<<count;
                cout<<endl;
            }
            
        }
        
//        for(int i=na ; i>0 ; i--){
//            for(int j=ma ; j>0 ; j--){
//                cout<<"square formed with coodinates = 0 0 "<<i<<" "<<j;
//                int count=calcCount(A , B , i , j);
//                max_count = max(count , max_count);
//				cout<<"count = "<<count;
//                cout<<endl;
//            }
//            
//        }
        return max_count;
             
}

int main(){
//	[[0,0,0,0,0],[0,1,0,0,0],[0,0,1,0,0],[0,0,0,0,1],[0,1,0,0,1]]
//[[1,0,1,1,1],[1,1,1,1,1],[1,1,1,1,1],[0,1,1,1,1],[1,0,1,1,1]]
	vector<vector<int> > a{ {0,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,0,1},{0,1,0,0,1}};
	vector<vector<int> > b{ {1,0,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{0,1,1,1,1},{1,0,1,1,1}};
    cout<<largestOverlap(a , b);

return 0;
}

