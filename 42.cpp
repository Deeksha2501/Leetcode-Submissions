class Solution {
public:
    int trap(vector<int>& h) {
        if(h.size() == 0)return 0;
        int n = h.size();
        vector<int> left(n);
        vector<int> right(n);
        
        int lc = h[0];
        int rc = h[n-1];
        for(int i=1 ; i<n ; i++){
            if(lc < h[i]){
                lc = h[i];
            }
            left[i] = lc;
        }
        
        for(int i=n-2 ; i>=0 ; i--){
            if(rc < h[i]){
                rc = h[i];
            }
            right[i] = rc;
        }
        
        int sum=0;
            
        for(int i=1 ; i<n-1 ; i++){
            sum += (min(left[i], right[i])-h[i]);
        }
        
        return sum;
    }
};