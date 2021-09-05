class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& arr) {
        // int cnt=0;
        // int n = arr.size();
        // for(int i=0 ; i<n ; i++){
        //     for(int j=i+1 ; j<n ; j++){
        //         if((arr[i]+arr[j])%60 == 0)cnt++;
        //     }
        // }
        // return cnt;
        int res=0;
        vector<int> m(60, 0);
        for(auto t : arr){
            if(t%60 == 0)res += m[0];
            else res += m[60- (t%60)];
            m[t%60]++;
        }
        return res;
    }
};