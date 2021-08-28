class Solution {
public:
    int numSteps(string s) {
        int i=s.length()-1; 
        int carry = 0, res=0;
        while(i >0){
            res++;
            if(s[i]-'0' + carry == 1){
                res++;
                carry = 1;
            }
            i--;
        }
        return res + carry;
    }
};

// 1100
//     carry = 1
    
//     res = 2+2;
    

