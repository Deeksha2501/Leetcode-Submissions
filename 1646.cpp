class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> v(n+1);
        v[0] = 0;
        if(n <= 1){
            return n;
        }
        v[1] = 1;
        // 2*i + 1 < n+1
        //     2*i < n;
        
        int mx = max(v[0] , v[1]);
        
        for(int i=1 ; i<=ceil(n/2) ; i++){
            if(2*i < n+1){
                v[2*i] = v[i];
                mx = max(mx , v[2*i]);
            }
            if(2*i + 1 < n+1){
                v[2*i + 1] = v[i] + v[i+1];
                 mx = max(mx , v[2*i + 1]);
            }
            // cout<<"\ni = "<<i;
            // mx = max({mx , v[2*i] , v[2*i + 1]});
        }
        return mx;
        
    }
};