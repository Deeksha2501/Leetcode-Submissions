class Solution {
public:
    
    int rotatedDigits(int n) {
        unordered_set<int> valid;
        valid.insert({2,5,6,9});
        unordered_set<int> invalid;
        invalid.insert({3,4,7});
        int count = 0;
        for(int i=1 ; i<=n ; i++){
            int num = i;
            int flag = 1, cnt=0;
            while(num){
                int d = num%10;
                if(invalid.find(d) != invalid.end()){
                    flag = 0;
                    break;
                }
                if(valid.find(d) != valid.end()){
                    cnt++;
                }
                num /= 10;
                
            }
            if(flag && cnt>=1)count++;
        }
        return count;
    }
};