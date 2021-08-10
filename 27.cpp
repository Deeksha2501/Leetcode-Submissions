class Solution {
public:
    int removeElement(vector<int>& arr, int val) {
        int i=0,j=0;
        int n=arr.size();
        while(j < n){
            if(arr[j] != val){
                arr[i] = arr[j];
                i++;
            }
            j++;
        }
        return i;
    }
};


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> :: iterator itr;
        for(itr = nums.begin() ; itr != nums.end() ; itr++){
            if(*itr == val){
                nums.erase(itr);
                itr--;
            }
        }
        return nums.size();
    }
};


