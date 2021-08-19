class Solution {
public:
    vector<int> countBits(int n) {
      vector<int>dp(n+1);
		if(n) dp[1] = 1;
		for(int i=2; i<=n; i++)
		{
			dp[i] = dp[i/2] + (i&1);
		}
		return dp;  
    }
};


//another approach
class Solution {
    public int[] countBits(int n) {
        int[] res=new int[n+1];
        res[0]=0;
        for(int i=1;i<=n;i++){
            res[i]=1+(res[i&(i-1)]);
        }
        return res;
    }
}