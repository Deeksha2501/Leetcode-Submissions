class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int l=n/4;
        for(int i=0;i<n-l;i++)
            if(arr[i]==arr[i+l])
                return arr[i];
        return -1;
    }
};