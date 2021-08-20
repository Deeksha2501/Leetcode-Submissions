class Solution {
public:
    int getSum(int n){
        // cout<<"\n = "<<n;
        int sum=0;
        while(n){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int , int> mp;
        for(int i=lowLimit ; i<= highLimit ; i++){
            mp[getSum(i)]++;
        }
        int mx = 0;
        int res = 0;
        for(auto [key, val] : mp){
            // cout<<"\nkey = "<<key;
            // cout<<" val = "<<val;
            mx = max(val , mx);
        }
        return mx;
    }
};