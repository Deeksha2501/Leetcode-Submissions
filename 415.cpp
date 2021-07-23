class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.length();
        int m = num2.length();
        int i=n-1;
        int j=m-1, carry=0;
        string res="";
        while(i>=0 || j>=0){
            int n1=0, n2=0;
            if(i>=0)n1 = num1[i]-'0';
            if(j>=0)n2 = num2[j]-'0';
            int sum = n1+n2+carry;
            if(sum>=10){
                sum = sum-10;
                carry = 1;
            }else{
                carry = 0;
            }
            // cout<<"\nsum = "<<sum;
            char m = sum + '0';
            res = m + res;
            i--;
            j--;
        }
        if(carry)res = '1' + res;
        
        return res;
    }
};




