
class Solution {
    public int mincostTickets(int[] days, int[] cost) {
        int[] dp=new int[days[days.length-1]+1];
        dp[0]=0;
        int i=0;
        for(int j=1;j<dp.length;j++){
            if(days[i]==j){
                int min=Integer.MAX_VALUE;
                min=Math.min(min,dp[Math.max(0,(j-1))]+cost[0]);
                min=Math.min(min,dp[Math.max(0,(j-7))]+cost[1]);
                min=Math.min(min,dp[Math.max(0,(j-30))]+cost[2]);
                dp[j]=min;
                i++;
            }else{
                dp[j]=dp[j-1];
            }
        }
        return dp[dp.length-1];
    }
}