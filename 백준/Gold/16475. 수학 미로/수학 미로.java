import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int n, m, k, l, p;
    static int nodeMax = 10000;
    static ArrayList<ArrayList<Edge>> graph = new ArrayList<>();
    static ArrayList<ArrayList<Edge>> reverseGraph = new ArrayList<>();
    static Set<Integer> trapNodeSet = new HashSet<>();
    static Map<Integer, ArrayList<Edge>> trapEdgeMap = new HashMap<>();
    static int s, e;
    static int middleNode;
    static int minDistOfPushSwitch;

    public static void main(String[] args) throws IOException {
        input();
        setReverseGraph();

        int ans = dijkstra(s, e, graph);
        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
        br.close();
    }

    private static void dfs(int pushCnt, int now, int dist) {
        if(pushCnt < p && dist > minDistOfPushSwitch) {
            return;
        }
        if(pushCnt == p) {
            if(minDistOfPushSwitch > dist) {
                minDistOfPushSwitch = dist;
                middleNode = now;
            }
            return;
        }

        for(Edge edge : graph.get(now)) {
            if(trapNodeSet.contains(edge.end)) {
                dfs(pushCnt + 1, edge.end, dist + edge.dist);
            } else {
                dfs(pushCnt, edge.end, dist + edge.dist);
            }
        }
    }

    private static void setReverseGraph() {
        for(int i=0; i<graph.size(); i++){
            reverseGraph.add(new ArrayList<>());
        }
        for(int i=0; i<graph.size(); i++){
            ArrayList<Edge> edges = trapEdgeMap.get(i);

            for(Edge edge : graph.get(i)){
                int isExist = 0;
                for(int j=0; j<edges.size(); j++){
                    if(edges.get(j).end == edge.end){
                        isExist = 1;
                        break;
                    }
                }

                if (isExist == 1) {
                    reverseGraph.get(edge.end).add(new Edge(i, edge.dist, 0));
                }
                else {
                    reverseGraph.get(i).add(new Edge(edge.end, edge.dist, 0));
                }
            }
        }
    }

    private static int dijkstra(int startNode,int arriveNode, ArrayList<ArrayList<Edge>> g) {
        int ret = 0;

        Queue<Edge> q = new PriorityQueue<>(new Comparator<Edge>() {
            @Override
            public int compare(Edge o1, Edge o2) {
                return o1.dist - o2.dist;
            }
        });
        int[][][] dist = new int[nodeMax + 1][2][p];
        for(int i = 0; i < nodeMax + 1; i++){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < p; k++){
                    dist[i][j][k] = Integer.MAX_VALUE;
                }
            }
        }

        dist[startNode][0][0] = 0;
        q.add(new Edge(startNode, 0, 0));

        while(!q.isEmpty()){
            Edge cur = q.poll();

            if(cur.end == arriveNode){
                ret = cur.dist;
                break;
            }

            if((cur.pcnt / p)%2 == 0){
                for(Edge next : g.get(cur.end)){
                    int nextPcnt = cur.pcnt;
                    if(trapNodeSet.contains(next.end)){
                        nextPcnt++;
                    }

                    if(dist[next.end][0][nextPcnt % p] <= cur.dist + next.dist){
                        continue;
                    }
                    dist[next.end][0][nextPcnt % p] = cur.dist + next.dist;
                    q.add(new Edge(next.end, dist[next.end][0][nextPcnt % p], nextPcnt));
                }
            } else {
                for(Edge next : reverseGraph.get(cur.end)){
                    int nextPcnt = cur.pcnt;
                    if(trapNodeSet.contains(next.end)){
                        nextPcnt++;
                    }

                    if(dist[next.end][1][nextPcnt % p] <= cur.dist + next.dist){
                        continue;
                    }
                    dist[next.end][1][nextPcnt % p] = cur.dist + next.dist;
                    q.add(new Edge(next.end, dist[next.end][1][nextPcnt % p], nextPcnt));
                }
            }
        }

        if(ret == 0){
            ret = -1;
        }

        return ret;
    }

    private static void input() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        // 1번째 줄 입력
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());
        p = Integer.parseInt(st.nextToken());

        // 함정 지역번호
        if(k != 0){
            st = new StringTokenizer(br.readLine());
        }
        for(int i = 0; i < k; i++) {
            int node = Integer.parseInt(st.nextToken());
            trapNodeSet.add(node);
        }

        // 간선 정보
        for(int i=0; i<n + 1; i++){
            graph.add(new ArrayList<>());
            trapEdgeMap.put(i, new ArrayList<>());
        }
        for(int i=0; i<m-l; i++){
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int dist = Integer.parseInt(st.nextToken());

            graph.get(start).add(new Edge(end, dist, 0));
        }
        for(int i=0; i<l; i++){
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int dist = Integer.parseInt(st.nextToken());

            graph.get(start).add(new Edge(end, dist, 0));
            trapEdgeMap.get(start).add(new Edge(end, dist, 0));
        }

        // 출발 노드, 도착 노드
        st = new StringTokenizer(br.readLine());
        s = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());
    }

    static class Edge {
        private int end;
        private int dist;
        private int pcnt;

        public Edge(int end, int dist, int pcnt){
            this.end = end;
            this.dist = dist;
            this.pcnt = pcnt;
        }
    }
}
