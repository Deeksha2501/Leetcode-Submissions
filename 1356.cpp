class Solution {
public:
    static bool cmp(int a, int b){
        int cnt1=0, cnt2=0;
        int aa=a, bb=b;
        while(a){
            cnt1++;
             a= a&(a-1);
        }
        while(b){
            cnt2++;
            b = b&(b-1);
        }
        if(cnt1 == cnt2)return aa<bb;
        return cnt1 < cnt2;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin() , arr.end() , cmp);
        return arr;
    }
};