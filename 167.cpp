class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int i=0, j=arr.size()-1;
        vector<int> v;
        while(i < j){
            if(arr[i]+arr[j] == target){
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
            else if(arr[i]+arr[j] > target){
                j--;
            }else i++;
        }
        return v;
    }
};