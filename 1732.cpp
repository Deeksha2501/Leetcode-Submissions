class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxm = 0;
        maxm = max(gain[0], maxm);
        for(int i=1 ; i<gain.size() ; i++){
            gain[i] = gain[i]+ gain[i-1];
            maxm = max(maxm , gain[i]);
        }
        return maxm;
    }
};

