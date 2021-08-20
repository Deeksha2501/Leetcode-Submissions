class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> value(n);
        for(int i=0 ; i<n ; i++){
            value[i] = 0;
            for(int j=0 ; j<words[i].length() ; j++){
                value[i] |= 1 << (words[i][j] - 'a');
            }
        }
        int res=0;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                if((value[i] & value[j]) == 0){
                    int temp = words[i].length() * words[j].length();
                    res = max(res , temp);
                }
            }
        }
        return res;
    }
};