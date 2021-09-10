class Solution {
public:
    vector<int> arr;
    set<vector<int>> res;
    int n;
    
    void dfs(int i , int sum , vector<int> v){
        if(sum < 0)return;
        if(sum == 0){
            res.insert(v);
            return;
        }
        if(i >= n)return;
        for(int in=i ; in<n ; in++){
            if(in>i && arr[in]==arr[in-1])continue;
            if(sum-arr[in]<0)break;
            v.push_back(arr[in]);
            dfs(in+1 , sum-arr[in] , v);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        arr = candidates;
        sort(arr.begin() , arr.end());
        n = arr.size();
        dfs(0 , target , {});
        vector<vector<int>> ans(res.begin() , res.end());
        return ans;
    }
};