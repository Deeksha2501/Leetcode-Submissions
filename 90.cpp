class Solution {
public:
    vector<int> arr;
    set<vector<int>> res;
    
    void dfs(int i , vector<int> v){
        if(i >= arr.size()){
            res.insert(v);
            return;
        }
        vector<int> vv = v;
        v.push_back(arr[i]);
        dfs(i+1 , v);
        dfs(i+1 , vv);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        arr = nums;
        vector<int> v;
        vector<vector<int>> ans;
        dfs(0 , v);
        for(auto v : res){
            ans.push_back(v);
        }
        return ans;
    }
};