class Solution {
public:
    signed long long int reverse(signed long long int num) {
    signed long long int rev_num = 0 , flag = 0; 
    if (num < 0){
        num = -num;
        flag = 1;
    }
    while(num > 0) 
    { 
        rev_num = rev_num*10 + num%10; 
        num = num/10; 
    } 
        
    if (rev_num > (pow(2 , 31) - 1)) {
        return 0;
    }
    
        if(flag == 1){
            return -rev_num;
        }
        else{
            return rev_num;
        }
    }
};



//2nd approach
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x != 0){
            int pop = x%10;
            x /= 10;
            if(rev > INT_MAX/10 || rev == INT_MAX/10 && pop> 7)return 0;
            if(rev < INT_MIN/10 || rev == INT_MIN/10 && pop < -8)return 0;
            rev = 10*rev + pop;
        }
        return rev;
    }
};