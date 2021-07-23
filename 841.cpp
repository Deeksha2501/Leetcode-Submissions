class Solution {
public:
    vector<bool> v;
    vector<vector<int>> r;
    
    void dfs(int i){
        if(v[i] == true)return;
        v[i] = true;
        for(int a : r[i]){
            dfs(a);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        r = rooms;
        v = vector<bool>(n , false);
        dfs(0);
        for(int i=0 ; i<n ; i++){
            if(v[i] == false)return false;
        }
        return true;
    }
};