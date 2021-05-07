class Solution {
public:
    bool squareIsWhite(string c) {
        int x = c[0]-'a';
        int y = c[1]-'1';
        return ((x+y)%2 == 1)?true:false;
    }
};