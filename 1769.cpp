class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> v, ans(boxes.length());
        for(int i=0 ; i<boxes.length() ; i++){
            if(boxes[i] == '1')v.push_back(i);
        }
        for(int i=0 ; i<boxes.length() ; i++){
            for(int j=0 ; j<v.size() ; j++){
                ans[i] += abs(v[j]-i);
            }
        }
        return ans;
    }
};