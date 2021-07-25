class Solution {
    public int smallestChair(int[][] times, int targetFriend) {
        Map<Integer,Integer> map1=new HashMap<>();
        Map<Integer,Integer> map2=new HashMap<>();
        int[] nums=new int[times.length];
        PriorityQueue<int[]> queue1=new PriorityQueue<>((a,b)->(a[1]-b[1]));
        for(int i=0;i<times.length;i++){
            map1.put(times[i][0],i);
        }
        Arrays.sort(times,(a,b)->(a[0]-b[0]));
        for(int i=0;i<times.length;i++){
            int start_time=times[i][0];
            if(queue1.size()>0){
            int top=queue1.peek()[1];
            while(queue1.size()>0 && top<=start_time){
                int s=queue1.poll()[0];
                
                int index=map2.get(s);
                nums[index]=0;
                if(queue1.size()>0)top=queue1.peek()[1];
            }
            }
            if(map1.get(start_time)==targetFriend){
                for(int j=0;j<nums.length;j++){
                    if(nums[j]==0)return j;
                }
            }else{
                for(int j=0;j<nums.length;j++){
                    if(nums[j]==0){
                        nums[j]=1;
                        map2.put(times[i][0],j);
                        queue1.add(times[i]);
                        break;
                    }
                }
            }
        }
        return times.length;
    }
}