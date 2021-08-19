class Solution {
public:
    vector<vector<int>> res;
    int n;
    vector<int> arr;
    
    void dfs(int i , vector<int> v){
        if(i == n){
            res.push_back(v);
            return;
        }
        vector<int> vv = v;
        vv.push_back(arr[i]);
        dfs(i+1 , v);
        dfs(i+1 , vv);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        arr = nums;
        n = arr.size();
        dfs(0 , {});
        return res;
    }
};