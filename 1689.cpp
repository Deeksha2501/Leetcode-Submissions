class Solution {
public:
    int minPartitions(string n) {
        int i=1;
        int max = n[0]-'0';
        while(i<n.length()){
            if(max < (n[i]-'0')){
                max = n[i] - '0';
            }
            i++;
        }
        return max;
    }
};