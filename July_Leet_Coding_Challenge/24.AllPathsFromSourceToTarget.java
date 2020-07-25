class Solution {
    
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        return constructPath(0, graph);
    }
    
    public List<List<Integer>> constructPath(int node, int[][] graph) {
        int N = graph.length;
        List<List<Integer>> returnList = new ArrayList();
        // System.out.println("node before: "+ node);
        
        if (node == N-1){
            // System.out.println("HERE"); 
            List<Integer> path = new ArrayList();
            path.add(N-1);
            returnList.add(path);
            return returnList;
            // returnList.add(aPath);
        }
        
        for (int j = 0; j<graph[node].length; j++){
            // System.out.println("node after: "+ node);
            for (List<Integer> path: constructPath(graph[node][j], graph)) {
                // System.out.println("path before add: " + path); 
                path.add(0, node);
                returnList.add(path);
                // System.out.println("path: " + path); 
                // System.out.println("graph[node][j]: \n" + graph[node][j]); 
            }
        }
        
        return returnList;
    }
}


