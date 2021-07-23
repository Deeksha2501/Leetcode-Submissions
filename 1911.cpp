//java solution

class Solution {
    int[] nums;
    Long[][] dp;
    
    public long maxAlternatingSum(int[] nums) {
        this.nums=nums;
        dp=new Long[nums.length+1][2];
        return dfs(0,true);
    }
    public long dfs(int i, boolean even){
        if(i>=nums.length)return 0;
        int x=even==true?0:1;
        if(dp[i][x]!=null)return dp[i][x];
        if(even==true){
            return dp[i][x]=Math.max(nums[i]+dfs(i+1,!even),dfs(i+1,even));
        }else{
            return dp[i][x]=Math.max(dfs(i+1,!even)-nums[i],dfs(i+1,even));
        }
    }
}