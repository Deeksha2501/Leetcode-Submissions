class Solution {
public:
    static bool cmp(vector<int> a , vector<int> b){
        if(a[0] == b[0])return a[1] < b[1];
        return a[0] > b[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& ppl) {
        int n = ppl.size();
        sort(ppl.begin(), ppl.end(), cmp);
        vector<vector<int>> res;
        for(int i=0 ; i<n ; i++){
            int a = ppl[i][0];
            int b = ppl[i][1];
            int nn = res.size();
            int cnt = 0, j=0;
            for(j=0 ; j<nn ; j++){
                if(cnt == b)break;
                if(res[j][0] >= a)cnt++;
            }
            res.insert(res.begin()+j , {a , b});
        }
        return res;
    }
};

class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people,new tempp());
        List<int[]> res=new ArrayList<int[]>();
        for(int[] p : people){
            res.add(p[1],p);
        }
        
        int[][] ress=new int[people.length][2];
        int j=0;
        for(int i=0;i<res.size();i++){
            if(res.get(i)!=null){
                ress[j][0]=res.get(i)[0];
                ress[j][1]=res.get(i)[1];
                j++;
            }
        }
        return ress;
    }
    public class tempp implements Comparator<int[]>{
        public int compare(int[] one,int[] two){
            if(one[0]==two[0]) return one[1]-two[1];
            return two[0]-one[0];
        }
    }
}


class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        if(a[1] == b[1])return a[0]<b[0];
        return a[1]<b[1];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        sort(p.begin() , p.end() , cmp);
        
        int n = p.size();
        vector<vector<int>>res(n);
        
        res[0] = p[0];
        for(int i=1 ; i<n ; i++){
            int a = p[i][0];
            int j=0;
            int count=0;
            int flag = 0;
            while(j<i){
                if(res[j][0] >= a)count++;
                if(count == p[i][1])break;                 
                j++;
            }
            
            // int pos = j;
            j++;
            
            while(j < i){
                if(res[j][0]<a)j++;
                else break;
            }
            
            res.insert(res.begin()+j , p[i]);
            
        }
        
        res.resize(n);
        
        return res;
    }
};