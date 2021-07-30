class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(n+1 , 0);
        for(auto el : nums){
            temp[el]++;
        }
        vector<int> res(2);
        for(int i=1 ; i<=n ; i++){
            if(temp[i] == 0)res[1] = i;
            if(temp[i] == 2)res[0] = i;
        }
        return res;
    }
};
