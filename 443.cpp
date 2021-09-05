class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int cnt=1;
        char prev = chars[0];
        int res=0;
        int j = 0;
        for(int i=1 ; i<n ; i++){
            if(chars[i] == prev)cnt++;
            else{
                chars[j] = prev;
                j++;
                if(cnt != 1){
                    string num = to_string(cnt);
                    // int m = num.length();
                    for(char c : num){
                        chars[j] = c;
                        j++;
                    }
                }
                cnt = 1;
            }
            prev = chars[i];
        }
        chars[j] = prev;
        j++;
        if(cnt != 1){
            string num = to_string(cnt);
            for(char c : num){
                chars[j] = c;
                j++;
            }
        }
        return j;
    }
};