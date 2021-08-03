class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string , vector<string>> mp;
        for(int i=0 ; i<bank.size() ; i++){
            string s = bank[i];
            for(int j=0 ; j<s.length() ; j++){
                string ss = s;
                ss[j] = '*';
                mp[ss].push_back(s);
            }
        }
        
        unordered_set<string> st;
        queue<string> q;
        q.push(start);
        int cnt=0;
        while(q.size() > 0){
            cnt++;
            int n = q.size();
            for(int k=0 ; k<n ; k++){
                string s = q.front();
                q.pop();
                for(int j=0 ; j<s.length() ; j++){
                    string temp = s;
                    temp[j] = '*';
                    vector<string> v = mp[temp];
                    for(string a : v){
                        if(a == end)return cnt;
                        if(st.find(a) == st.end()){
                            q.push(a);
                            st.insert(a);
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};