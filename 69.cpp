class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)return 0;
        long long low = 0, high = x;
        int ans = -1;
        while(low<=high){
            long long mid = (low+high)/2;
            if(mid*mid > x)high = mid-1;
            else{
                low = mid+1;
            }
        }
        return low-1;
    }
};