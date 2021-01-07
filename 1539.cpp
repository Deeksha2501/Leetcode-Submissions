class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> res;
        res.push_back(0);
        int n = arr.size();
        int curr = 1;
        for(int i=0 ; i<n ;){
            if(curr == arr[i]){
                i++;
                curr++;
            }else{
                res.push_back(curr);
                curr++;
            }
            // if(res.size() >= k){
            //     break;
            // }
        }
        // for(int i=0 ; i<res.size() ; i++){
        //     cout<<res[i]<<" ";
        // }
        cout<<endl;
        if(res.size()>k){
            // cout<<"hk";
            return res[k];
        }
        else{
            int temp = k-res.size()+1;
            return arr[n-1]+temp;
        }
        return 0;
    }
};