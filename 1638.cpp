class Solution {
public:
    int countSubstrings(string s, string t) {
        int count = 0;
        
        // take substring starting from every pair of points between 0 to s.length and 0 to t.length => O(N^2)
        // count the number of substring which has exactly 1 mismatch => O(N)  
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;j<t.length();j++)
            {
                int misMatch = 0;
                
                for(int k=0;i+k<s.length() && j+k<t.length();k++)
                {
                    if(s[i+k]!=t[j+k])misMatch++;
                    
                    if(misMatch>1) break;
                    
                    count+= misMatch;
                }
            }
        }
        
        return count;
        
    }
};