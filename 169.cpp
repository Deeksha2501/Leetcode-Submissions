class Solution {
public:
    int majorityElement(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        int n = arr.size();
        return arr[n/2];
    }
};