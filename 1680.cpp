class Solution {
public:
    string get(int n)
    {
        string s = bitset<64> (n).to_string();
        
        const auto loc1 = s.find('1');

        if(loc1 != string::npos)
            return s.substr(loc1);

        return "0";
    }
    
    int concatenatedBinary(int n) {
        int shift=0,mod=1000000007;
        long result=0;
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0)shift++;
            result=((result<<shift)+i)%mod;
        }
        return (int)result;
    }
};