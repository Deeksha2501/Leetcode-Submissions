//java solution

class Solution {
    
    public int longestStrChain(String[] words){
        int n=words.length;
        if(n<=1)return n;
        Arrays.sort(words,(w1,w2)->Integer.compare(w1.length(), w2.length()));
        HashMap<Integer,List<Integer>> map=new HashMap<>();
        for(int i=0;i<words.length;i++){
            int l=words[i].length();
            if(map.get(l)==null)map.put(l,new ArrayList<>());
            map.get(l).add(i);
        }
        int res=1;
        int[] dp=new int[n];
        Arrays.fill(dp,1);
        for(int i=0;i<n;i++){
            List<Integer> list=map.getOrDefault(words[i].length()-1,new ArrayList<>());
            for(int j: list){
                if (!check(words[i], words[j])) continue;
                dp[i] = Math.max(dp[i], dp[j]+1);
            }
            res=Math.max(res,dp[i]);
        }
        return res;
    }
    public boolean check(String w1, String w2) {
        final int L1 = w1.length(), L2 = w2.length();
        if (L1-1 != L2) return false;
        int i = 0, j = 0; 
        while (i < L1 && j < L2 && w1.charAt(i) == w2.charAt(j)) {
            i++;
            j++;
        }
        i++; 
        while (i < L1 && j < L2 && w1.charAt(i) == w2.charAt(j)) {
            i++;
            j++;
        }
        return i == L1 && j == L2;
    }
}