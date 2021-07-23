class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int i=0, j=0 , cnt =0 , n = arr.size();
        while(j<n){
            if(arr[j] == 0){
                // cnt++;
            }else{
                arr[i] = arr[j];
                i++;
            }
            j++;
        }
        for(int kk = i ; kk<n ; kk++){
            arr[kk] = 0;
        }
    }
};