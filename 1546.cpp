class Solution {
public:
    
    vector<int> arr;
    int target , n;
    
    int dfs(int i , int st , int sum){
        cout<<"\ni = "<<i<<" - st= "<<st<<" - sum = "<<sum;
        if(sum == target)return 1 + dfs(i+1 , i+1 , INT_MAX);
        if(i >= n)return 0;
        if(sum == INT_MAX)return dfs(i+1 , i , arr[i]);
        if(sum > target){
            return max(dfs(st+1 , st+1 , INT_MAX) , dfs(i+1 , st , sum+arr[i]));
        }else{
            return dfs(i+1 , st , sum+arr[i]);
        }
    }
    
    int maxNonOverlapping(vector<int>& nums, int target) {
        // arr = nums;
        // n = arr.size();
        // target = tgt;
        // return dfs(0 , 0 , INT_MAX);
        unordered_map<int , int> mp;
        mp.insert({0 , -1});
        int index=-1;
        int sum=0,res=0;
        for(int i=0 ; i<nums.size() ; i++){
            sum += nums[i];
            if(mp.find(sum-target) != mp.end() && mp[sum-target] >= index){
                res++;
                index=i;
            }
            mp[sum] = i;
        }
        return res;
    }
};
