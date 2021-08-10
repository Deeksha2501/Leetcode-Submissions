class Solution {
public:
    
    int mod = 1000000007;
    
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> q;
        int ans=0;
        
        for(int i=0 ; i<n ; i++){
            q.push(make_pair(nums[i], i));
        }
        left--;
        right--;
        for(int i=0 ; i<=right ; i++){
            pair<int, int> p = q.top();
            q.pop();
            if(i >= left){
                ans = (ans%mod + p.first%mod)%mod;
            }
            if(p.second < n-1){
                p.first = (p.first%mod + nums[++p.second]%mod)%mod;
                q.push(p);
            }
        }
        return ans;
    }
};


class Solution {
public:
    int rangeSum(vector<int>& arr, int n, int left, int right) {
        long long int sum=0;
        vector<int> v;
        for(int i=0 ; i<n ; i++){
            sum = 0;
            for(int j = i ; j<n ; j++){
                sum += arr[j];
                v.push_back(sum);
            }
            
        }
        sort(v.begin() , v.end());
        sum =0;
        for(int i=left-1 ; i<right ; i++){
            sum += v[i];
            sum = sum%1000000007;
        }
        return (int)sum;
    }
};