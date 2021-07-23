class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int h = n/2;
        string s1 = s.substr(0, h);
        // cout<<s1<<endl;
        string s2 = s.substr(h);
        // cout<<s2<<endl;
        
        unordered_set<char> v{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int count1=0, count2=0;
        
        for(int i=0 ; i<s1.length() ; i++){
            if(v.find(s1[i]) != v.end())count1++;
            if(v.find(s2[i]) != v.end())count2++;
        }
        return count1==count2;
        
    }
};