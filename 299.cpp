class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char , int> g_map, s_map;
        int n = secret.length();
        int cows=0, bulls=0;
        for(int i=0 ; i<n ; i++){
            if(secret[i] == guess[i])bulls++;
            else{
                char s = secret[i];
                char g = guess[i];
                if(g_map[s] > 0){
                    cows++;
                    g_map[s]--;
                }else s_map[s]++;
                if(s_map[g] > 0){
                    cows++;
                    s_map[g]--;
                }else g_map[g]++;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

class Solution {
public:
    string getHint(string secret, string guess) {
        int i=0 , cows=0 , bulls=0;
        int n= secret.length();
        for(int i=0 ; i<n ; i++){
            if(secret[i] == guess[i]){
                secret[i] = 'a';
                guess[i] = 'b';
                bulls++;
            }
            else{
                for(int j=0 ; j<n ; j++){
                    if(secret[j] == guess[j]){
                        secret[j] = 'a';
                        guess[j] = 'b';
                        bulls++;
                    }
                    if(secret[j] == guess[i]){
                        secret[j] = 'a';
                        guess[i] = 'b';
                        cows++;
                        break;
                    }
                }
            }
        }
        std::string b = std::to_string(bulls);
    	std::string c = std::to_string(cows);
        
        return b+"A"+c+"B";
    }
};
