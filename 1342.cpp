class Solution {
public:
    int numberOfSteps(int n) {
        if(n==0)return 0;
        int cnt=0;
        while(n){
            if(n&1)cnt+=2;
            else cnt++;
            n = n >> 1;
        }
        return cnt-1;
    }
};