class Solution {
public:
    
    string repeat(string s, int n)
    {
        string s1 = s;

        for (int i=1; i<n;i++)
            s += s1; 

        // cout<<"\ns = "<<s;
        return s;
    }
    
    int repeatedStringMatch(string a, string b) {
        int temp=b.length()/a.length();
        if(a.find(b) != string::npos)return 1;
        if(repeat(a,temp).find(b) != string::npos)return temp;
        if(repeat(a,temp+1).find(b) != string::npos)return temp+1;
        if(repeat(a,temp+2).find(b) != string::npos)return temp+2;
        return -1;
    }
};