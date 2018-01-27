import java.io.*;
import java.util.*;

public class ShortestPath1 {
    static final int INF = (int) 1e9;

    public static int[] dijkstra(List<Edge>[] graph, int source) {
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(source, 0));
        int[] dist = new int[graph.length];
        Arrays.fill(dist, INF);
        dist[source] = 0;

        while (!pq.isEmpty()) {
            Edge current = pq.poll();
            int node = current.dest;
            int currentDist = current.weight;
            if (dist[node] < currentDist) {
                continue;
            }

            for (Edge e : graph[node]) {
                int dest = e.dest;
                int newDist = currentDist + e.weight;
                if (newDist < dist[dest]) {
                    dist[dest] = newDist;
                    pq.add(new Edge(dest, newDist));
                }
            }
        }

        return dist;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int numNodes = Integer.parseInt(st.nextToken());
            int numEdges = Integer.parseInt(st.nextToken());
            int numQueries = Integer.parseInt(st.nextToken());
            int source = Integer.parseInt(st.nextToken());

            if (numNodes == 0) {
                break;
            }

            // O(n) arraylists
            // sum |graph[0]| + |graph[1]| + |graph[2]| = O(m)
            List<Edge>[] graph = new List[numNodes];
            for (int i = 0; i < numNodes; i++) {
                graph[i] = new ArrayList<>();
            }

            for (int i = 0; i < numEdges; i++) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                int w = Integer.parseInt(st.nextToken());

                graph[u].add(new Edge(v, w));
            }

            int[] dist = dijkstra(graph, source);
            for (int i = 0; i < numQueries; i++) {
                int x = Integer.parseInt(br.readLine());
                if (dist[x] == INF) {
                    System.out.println("Impossible");
                } else {
                    System.out.println(dist[x]);
                }
            }

            System.out.println();
        }
    }

    public static class Edge implements Comparable<Edge> {
        int dest;
        int weight;

        public Edge(int dest, int weight) {
            this.dest = dest;
            this.weight = weight;
        }

        public int compareTo(Edge other) {
            return Integer.compare(weight, other.weight);
        }
    }
}
