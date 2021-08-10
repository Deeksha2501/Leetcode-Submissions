class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int i=0, j=arr.size()-1;
        int median = arr[j/2];
        vector<int> res(k);
        int p=0;
        while (p < k)
            if (median - arr[i] > arr[j] - median)
                res[p++] = arr[i++];  
            else
                res[p++] = arr[j--];      
        return res;
    }
};