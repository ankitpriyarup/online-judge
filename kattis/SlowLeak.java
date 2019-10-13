// Run Dijkstra's from every pump

import java.io.*;
import java.util.*;

public class SlowLeak {
    static final long INF = (long)1e18;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int m = scan.nextInt();
        int t = scan.nextInt();
        int d = scan.nextInt();

        List<Edge>[] graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        int subN = t + 2;
        int[] repairs = new int[subN];
        repairs[0] = 0;
        repairs[t + 1] = n - 1;
        for (int i = 1; i <= t; i++) {
            repairs[i] = scan.nextInt() - 1;
        }

        for (int i = 0; i < m; i++) {
            int u = scan.nextInt() - 1;
            int v = scan.nextInt() - 1;
            int w = scan.nextInt();

            graph[u].add(new Edge(v, w));
            graph[v].add(new Edge(u, w));
        }

        List<Edge>[] subGraph = new List[subN];
        for (int i = 0; i < subN; i++) {
            subGraph[i] = new ArrayList<>();
        }
        for (int i = 0; i < subN; i++) {
            long[] dists = dijkstra(graph, repairs[i]);
            for (int j = 0; j < subN; j++) {
                int v = repairs[j];
                if (dists[v] <= d) {
                    // d is an int, so dists[v] must be an int as well
                    subGraph[i].add(new Edge(j, (int)dists[v]));
                }
            }
        }

        long[] res = dijkstra(subGraph, 0);

        if (res[subN - 1] == INF) {
            System.out.println("stuck");
        } else {
            System.out.println(res[subN - 1]);
        }
    }

    public static class Edge {
        int dest;
        int cost;
        public Edge(int dest, int cost) {
            this.dest = dest;
            this.cost = cost;
        }
    }

    private static long[] dijkstra(List<Edge> graph[], int src) {
        PriorityQueue<State> pq = new PriorityQueue<>();
        pq.add(new State(src, 0));
        long[] dists = new long[graph.length];
        Arrays.fill(dists, INF);
        dists[src] = 0;

        while (!pq.isEmpty()) {
            State cur = pq.poll();
            if (dists[cur.node] != cur.dist) {
                continue;
            }

            for (Edge e : graph[cur.node]) {
                int v = e.dest;
                long newDist = cur.dist + e.cost;
                if (newDist < dists[v]) {
                    dists[v] = newDist;
                    pq.add(new State(v, dists[v]));
                }
            }
        }

        return dists;
    }

    public static class State implements Comparable<State> {
        int node;
        long dist;
        State(int node, long dist) {
            this.node = node;
            this.dist = dist;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj == null) {
                return false;
            }

            State other = (State) obj;
            return node == other.node
                && dist == other.dist;
        }

        @Override
        public int compareTo(State other) {
            if (dist == other.dist) {
                return Integer.compare(node, other.node);
            }
            return Long.compare(dist, other.dist);
        }

        @Override
        public String toString() {
            return String.format("{%d %d}", node, dist);
        }
    }
}
