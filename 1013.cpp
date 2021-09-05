class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=0;
        for(int i : arr)sum+=i;
        if(sum%3!=0)return false;
        sum=sum/3;
        int count=0;
        int summ=0;
        for(int i : arr){
            summ+=i;
            if(summ==sum){
                summ=0;
                count++;
            }
        }
        return count>=3;
    }
};
