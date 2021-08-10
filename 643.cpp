class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double temp = 0;
        for(int i=0 ; i<k ; i++){
            temp+=nums[i];
        }
        
        double t = temp;
       
        for(int i=k ; i<n ; i++){
            double temp_sum = temp+nums[i]-nums[i-k];
            t = max(t, temp_sum);
            temp = temp_sum;
        }
        double sum = t/k;
        return sum;
    }
};