class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        if(arr[0] != 1)arr[0] = 1;
        for(int i=1 ; i<arr.size() ; i++){
            // cout<<"arr[i] = "<<arr[i];
            // cout<<"arr[i-1] = "<<arr[i-1];
            if(abs(arr[i]-arr[i-1])>1){
                arr[i] = arr[i-1]+1;
            }
        }
        return arr[arr.size()-1];
    }
};