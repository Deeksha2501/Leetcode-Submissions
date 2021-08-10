class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int cnt=0,n=bits.size();
        for(int i=n-2 ; i>=0 ; i--){
            if(bits[i])cnt++;
            else break;
        }
        if(cnt%2==0)return true;
        return false;
    }
};