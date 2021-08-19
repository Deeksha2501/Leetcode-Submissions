class Solution {
public:
    int countTriplets(vector<int>& arr) {
        arr.insert(arr.begin() , 0);
        int n = arr.size();
        for(int i=1 ; i<n ; i++){
            arr[i] = arr[i] ^ arr[i-1];
        }
        int res=0;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                if(arr[i] == arr[j])res += j-i-1;
            }
        }
        return res;
    }
};

