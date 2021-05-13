class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int prev = 0;
        for(int i=0 ; i<groups.size() ; i++){
            bool flag = false;
            for(int j=prev ; j<=nums.size()-groups[i].size()  ; j++){
                int k = 0;
                for(k=0 ; k<groups[i].size() ;k++ ){
                    if(groups[i][k] != nums[j+k]){
                        break;
                    }
                }
                if(k == groups[i].size()){
                    prev = j+k;
                    flag = true;
                    break;
                }
            }
            if(flag == false)return false;
        }
        return true;
    }
};