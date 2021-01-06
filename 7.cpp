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