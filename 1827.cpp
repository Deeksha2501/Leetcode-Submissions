class Solution {
public:
    int minOperations(vector<int>& arr) {
        // sort(arr.begin(), arr.end());
        int count=0;
        for(int i=0 ; i<arr.size()-1 ; i++){
            if(arr[i+1] <= arr[i]){
                // cout<<"\nat i= "<<i;
                count += arr[i]-arr[i+1]+1;
                arr[i+1] = arr[i] + 1;
                // cout<<"\na[i+1] = "<<arr[i+1];
            }
        }
        return count;
    }
};