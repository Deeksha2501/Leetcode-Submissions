class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left=0, right=0;
        for(int w : weights){
            left = max(w , left);
            right += w;
        }
        
        while(left < right){
            int mid = left + (right-left)/2;
            int need=1, curr=0;
            for(int w : weights){
                if(curr + w > mid){
                    need++;
                    curr=0;
                }
                curr += w;
            }
            if(need > D)left = mid+1;
            else right = mid;
        }
        return left;
    }
};

