class Solution {
    public int[] avoidFlood(int[] rains) {
        HashMap<Integer,Integer> map=new HashMap<>();
        List<Integer> list=new ArrayList<>();
        int[] result=new int[rains.length];
        for(int i=0;i<rains.length;i++){
            if(rains[i]==0){
                list.add(i);
                result[i]=1;
            }
            else{
                int temp=map.getOrDefault(rains[i],-1);
                if(temp==-1)map.put(rains[i],i);
                else{
                    if(list.size()>0){
                        for(int j=0;j<list.size();j++){
                            if(list.get(j)>temp){
                                result[list.get(j)]=rains[i];
                                list.remove(j);
                                break;
                            }
                            if(j==list.size()-1)return new int[]{};
                        }
                    }else return new int[]{};
                    map.put(rains[i],i);
                }
                result[i]=-1;
            }
        }
        return result;
    }
}