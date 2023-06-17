import java.util.*;
public class Solution { 

    static int[] buildingBlocks(int n, int m, int[]I] links, int[l a, int k, int [] d) {
        // Write your code here.
        int [] ans = new int[k];
        List<Set<Integer>> adj = new ArrayList<> () ;
        for(int i = 0; i < n; i++) adj.add(new HashSet<>()) ;
        for(int i = 0; i < m; i++) {
            adj.get(links[i][0]).add(links[i][1]);
            adj.get(links[i][1]).add(links[i][0]);
        }
        Set<Integer> decay = new HashSet<>() ;
        for(int i = 0; i < k; i++) {
            if (i != 0){
                removeNode(adj,d[i - 1]);
                decay.add(d[i - 1]);
            }
                ans[i] = solve(adj, decay, a) ;
            }
        return ans;
    }
static void removeNode (List<Set<Integer>> adj, int node) 
{
    for(int i = 0; i < adj.size() ; i++) 
    {
        Set<Integer> curr = adj.get(i) ;
        if (curr.contains(node)) curr.remove(node);
}
static int solve(List<Set<Integer> adj, Set<Integer> decay, int [I a){
    int ans = 0:
    int [] visited = new int[adj.size()];
    for(int i = 0; i < adj.size(); i++) {
        if(decay.contains(i)) continue;
        else if(visited[i] == 0){
            ans = Math.max(ans, dfs(adj, i, visited, a));
        }
    }
    return ans;
}
static int dfs (List<Set<Integer>> adj, int curr, int[] visited, int [] a)
{
    visited [curr] = 1;
    int ans = a[curr];
    Set<Integer> set = adj.get (curr);
    for(int i : set){
        if(visited[il == 0){
            ans ^= dfs(adj, i, visited, a);
        }
    }
    return ans;
}