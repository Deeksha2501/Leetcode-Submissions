class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int cnt=0;
        for(int i : arr)if(i==0)cnt++;
        int m = arr.size();
        int n = m + cnt;
        for(int i=n-1, j=m-1 ; i>=0, j>=0 ; i--, j--){
            if(arr[j] == 0){
                if(i < m)arr[i] = arr[j];
                i--;
                if(i < m)arr[i] = arr[j];
                
            }else{
                if(i < m)arr[i] = arr[j];
            }
        }
    }
};