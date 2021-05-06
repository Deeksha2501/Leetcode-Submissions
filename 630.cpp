class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(),courses.end(),cmp);
        
        
        priority_queue<int> p;
        
        int time = 0,count=0;
        
        for(int i=0 ; i<courses.size() ; i++){
            if((time+courses[i][0])<= courses[i][1]){
                count++;
                time += courses[i][0];
                p.push(courses[i][0]);
            }else{
                if(p.size()>0){
                    int x = p.top();
                    if(x>courses[i][0]){
                        p.pop();
                        time -= x;
                        time += courses[i][0];
                        p.push(courses[i][0]);
                    }
                }
            }
        }
        
        return count;
    }
};