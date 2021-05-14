class Solution {
public:
    int numSplits(string s) {
        string s1 = s.substr(0, 1);
        string s2 = s.substr(1);

        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        m1[s1[0]]++;
        for(int i=0 ; i<s2.length() ; i++){
            m2[s2[i]]++;
        }
        int count=0;
        
        if(m1.size() == m2.size())count++;
        for(int i=1 ; i<s.length()-1 ; i++){
            m1[s[i]]++;
            m2[s[i]]--;
            if(m2[s[i]] <= 0)m2.erase(s[i]);

            if(m1.size() == m2.size())count++;
        }
        return count;
    }
};