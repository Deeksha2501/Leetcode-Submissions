class Solution {
public:
    static bool myCmp(vector<int> a , vector<int> b){
        return a[0]<b[0];
    }
    
    int videoStitching(vector<vector<int>>& clips, int time) {
        
        int maxm = 0, end=0;
        
        sort(clips.begin() , clips.end() , myCmp);
        vector<int> dp(time+1 , INT_MAX);
        dp[0] = 0;
        
        for(int i=0 ; i<clips.size() ; i++){
           for(int j=clips[i][0]+1 ; j <= min(clips[i][1] , time) ; j++){
               if(dp[clips[i][0]] != INT_MAX)dp[j] = min(dp[j] , dp[clips[i][0]]+1);
           }
        }
        if(dp[time] >= INT_MAX || dp[time]<0)return -1;
        return dp[time];
    }
};
