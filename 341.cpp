/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> res;
    int cnt;
    
    void dfs(vector<NestedInteger> nl){
        for(NestedInteger i : nl){
            if(i.isInteger())res.push_back(i.getInteger());
            else dfs(i.getList());
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
        cnt = 0;
    }
    
    int next() {
        int t= res[cnt];
        cnt++;
        return t;
        
    }
    
    bool hasNext() {
        if(cnt < res.size())return true;
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */