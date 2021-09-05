class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size() != s.size())return false;
        if((goal+goal).find(s) != string::npos)return true;
        return false;
    }
};