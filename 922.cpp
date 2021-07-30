class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        for(auto el : nums){
            if(el%2)odd.push_back(el);
            else even.push_back(el);
        }
        int e=0, o=0;
        for(int i=0 ; i<nums.size() ; i++){
            if(i%2){
                nums[i] = odd[o];
                o++;
            }else{
                nums[i] = even[e];
                e++;
            }
        }
        return nums;
    }
};