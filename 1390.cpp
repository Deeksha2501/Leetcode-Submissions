class Solution {
    public int sumFourDivisors(int[] nums) {
        int sum=0;
        Map<Integer,Integer> map=new HashMap<>();
        Set<Integer> set=new HashSet<>();
        for(int num: nums){
            if(map.containsKey(num))sum+=map.get(num);
            else if(set.contains(num))continue;
            int temp=0;
            // if(num!=1)temp+=num;
            int count=0;
            boolean x=true;
            
            for(int i=1;i<=Math.sqrt(num);i++){
                if(num%i==0){
                    count++;
                    temp+=i;
                    if(num/i != i){
                        count++;
                        temp+= num/i;
                    }
                }
                if(count>4){
                    set.add(num);
                    x=false;
                    break;
                }
            }
            
            // cout<<"\nsum for "<<num<<" - "<<temp;
            // System.out.println(count);
            
            if(x==true && count==4){
                sum+=temp;
                map.put(num,temp);
            }
        }
        return sum;
    }
}