class Solution {
public:
    char slowestKey(vector<int>& rt, string kp) {
        int res = rt[0];
        char ans = kp[0];
        for(int i=1 ; i<rt.size() ; i++){
            if(rt[i]-rt[i-1] == res){
                if(kp[i] > ans)ans = kp[i];
            }else if(rt[i]-rt[i-1] > res){
                res = rt[i]-rt[i-1];
                ans = kp[i];
            }
        }
        return ans;
    }
};