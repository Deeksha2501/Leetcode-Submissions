class Solution {
public:
    int getSum(vector<int> arr , int k){
        int sum=0 , n=arr.size();
        for(int i=0 ; i+k-1<n ; i++){
            // cout<<"\n\ni = "<<i;
            int p = k;
            int j = i;
            while(p--){
                // cout<<"\nj = "<<j;
                sum += arr[j];
                j++;
            }
        }
        return sum;
    }
    
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size() , sum=0;
        for(int i=1 ; i<n ; i+=2){
            // cout<<"\ni = "<<i;
            sum += getSum(arr , i);
        }
        if(n%2){
            sum += accumulate(arr.begin(), arr.end(), 0);
        }
        return sum;
    }
};