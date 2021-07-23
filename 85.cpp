class Solution {
public:
    int longestHistogram(vector<int> arr){
        stack<int> s;
        s.push(0);
        int res = 0;
        int n = arr.size();
        for(int i=1 ; i<n ; i++){
            while(s.empty() == false && arr[s.top()] >= arr[i]){
                int tp = s.top();
                s.pop();
                int curr = arr[tp]*(s.empty() ? i : (i-s.top()-1));
                res = max(curr , res);
                
            }
            s.push(i);   
        }
        while(s.empty() == false){
            int tp =  s.top();
            s.pop();
            int curr = arr[tp]*(s.empty() ? n : (n-s.top()-1));
            res = max(curr , res);
        }
        return res;
    }
    
    vector<int> sumArray(vector<int> a, vector<int> b){

        for(int i=0 ; i<a.size() ; i++){
            if(b[i] == 0){
                a[i] = 0;
            }else{
                a[i]++;
            }
            // a[i] = a[i] + b[i];
        }

        return a;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int res=0;
        vector<vector<int> > mat;

        if(n==0)return 0;
        for(int i=0 ; i<n ; i++){
            vector<int> v1(matrix[i].size());
            for(int j=0 ; j<matrix[i].size() ; j++){
                if(matrix[i][j] == '1'){
                    v1[j] = 1;
                }
                else v1[j] = 0;
            }
            mat.push_back(v1);
        }
        
        // for(int i=0 ; i<2 ; i++){
        //     for(int j=0 ; j<2 ; j++){
        //         cout<<mat[i][j]<<" ";
        //     }
        // }
        // cout<<endl;
        
        
        for(int i=0 ; i<n-1 ; i++){
            int curr = longestHistogram(mat[i]);
            mat[i+1] = sumArray(mat[i] , mat[i+1]);
            res = max(res,curr);
        }
        int curr = longestHistogram(mat[n-1]);
        res = max(res,curr);
        return res;
    }   
};