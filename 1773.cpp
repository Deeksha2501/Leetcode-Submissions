class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int v,count=0;
        if(ruleKey == "type")v=0;
        if(ruleKey == "color")v=1;
        if(ruleKey == "name")v=2;
        for(int i=0 ; i<items.size() ; i++){
            if(items[i][v] == ruleValue)count++;
        } 
        
        return count;
    }
};