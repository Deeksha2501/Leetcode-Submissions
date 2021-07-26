class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wl) {
        unordered_map<string , vector<string>>m;
        for(int i=0 ; i<wl.size() ; i++){
            string s=wl[i];
            for(int j=0 ;j<s.length(); j++) {
                string ss = s;
                ss[j] = '*';
                m[ss].push_back(s);
            }
        }
        
        unordered_set<string> st;
        queue<string> q;
        q.push(beginWord);
        int cnt=1;
        while(q.size()>0){
            cnt++;
            int n = q.size();
            for(int k=0 ; k<n ; k++){
                string s = q.front();
                q.pop();
                 for(int j=0 ;j<s.length(); j++) {
                    string ss = s;
                    ss[j] = '*';
                    vector<string> v = m[ss];
                     for(string a : v){
                         if(a == endWord)return cnt;
                         if(st.find(a) == st.end()){
                             q.push(a);
                             st.insert(a);
                         }
                     }
                }
            }
        }
        return 0;
    }
};


