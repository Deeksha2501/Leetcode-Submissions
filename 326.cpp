class Solution {
public:
    bool isPowerOfThree(int n){ 

        //return (n > 0 && 1162261467 % n == 0);


        if (n<1) return false;
        while(n > 1){
            if(n%3 !=0)return false;
            n = n/3;
        }
        return true;
    }
};

