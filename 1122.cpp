class Solution {
public:
    
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> cnt(1001 , 0);
        for(int i : arr1)cnt[i]++;
        int i=0;
        for(int el : arr2){
            while(cnt[el]-- > 0){
                arr1[i] = el;
                i++;
            }
        }
        for(int n=0 ; n<1001 ; n++){
            while(cnt[n]-- > 0){
                arr1[i] = n;
                i++;
            }   
        }
        return arr1;
    }
    
};


class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_map<int,int> mp;
        for(int i:arr2)mp[i]=0;
        
        vector<int> temp,res;
        for(int i=0 ; i<arr1.size() ; i++){
            if(mp.find(arr1[i]) != mp.end()){
                mp[arr1[i]]++;
            }else{
                temp.push_back(arr1[i]);
            }
        }
        
        for(int i : arr2){
            while(mp[i]--)res.push_back(i);
        }
        sort(temp.begin() , temp.end());
        for(int i:temp)res.push_back(i);
        return res;
    }
};