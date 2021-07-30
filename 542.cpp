class Solution {
public:

    int n,m;
    vector<vector<int>> res;
    
    bool check(int i , int j){
        if(i >= 0 && i < n && j>=0 && j<m && res[i][j] == -1)return true;
        return false;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n=mat.size() , m = mat[0].size();
        res = vector<vector<int>>(n , vector<int>(m , -1));
        queue<pair<int, int>> q;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(mat[i][j] == 0){
                    q.push(make_pair(i , j));
                }
            }
        }
        int cnt=0;
        while(q.size()>0){
            int n = q.size();
            for(int i=0 ; i<n ; i++){
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                // cout<<"i";
                if(res[x][y] == -1)res[x][y] = cnt;
                if(check(x+1 , y))q.push(make_pair(x+1 , y));
                if(check(x , y+1))q.push(make_pair(x , y+1));
                if(check(x-1 , y))q.push(make_pair(x-1 , y));
                if(check(x , y-1))q.push(make_pair(x , y-1));
            }
            cnt++;
        }
        return res;
    }
};
