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