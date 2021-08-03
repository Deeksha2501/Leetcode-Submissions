class Solution {
public:
    set<vector<int> > res;
    vector<int> arr;
    
    void dfs(int i , vector<int> v , int target){
        if(target == 0){
            res.insert(v);
            return;
        }
        if(i >= arr.size())return;
        
        vector<int> vv = v;
        if(arr[i] <= target){
            vv.push_back(arr[i]);
            dfs(i+1 , vv , target-arr[i]);
            dfs(i , vv , target-arr[i]);
        }
        dfs(i+1 , v , target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        arr = candidates;
        vector<int> v;
        dfs(0 , v , target);
        vector<vector<int>> ans;
        for(auto v : res){
            ans.push_back(v);
        }
        return ans;
    }
};