//You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. 
//Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both
//digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). 
//Your friend will use successive guesses and hints to eventually derive the secret number.
//Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 
//Please note that both secret number and friend's guess may contain duplicate digits.
//Example 1:
//Input: secret = "1807", guess = "7810"
//Output: "1A3B"
//Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.



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
