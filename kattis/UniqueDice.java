import java.io.*;
import java.util.*;

public class UniqueDice {
    private static final int MAX_ID = 6 * 6 * 6 * 6 * 6 * 6;

    private static class Die {
        public final int[] faces;
        public final int id;
        Die(int[] faces) {
            this.faces = faces;
            this.id = getId();
        }

        List<Die> rotate() {
            List<Die> rotations = new ArrayList<>();
            int top = faces[0];
            int bottom = faces[1];
            int front = faces[2];
            int back = faces[3];
            int left = faces[4];
            int right = faces[5];
            // top -> front
            rotations.add(new Die(new int[]{back, front, top, bottom, left, right}));
            // left -> front
            rotations.add(new Die(new int[]{top, bottom, left, right, back, front}));

            return rotations;
        }

        private int getId() {
            int id = 0;
            for (int i = 0; i < 6; ++i) {
                id = faces[i] + 6 * id;
            }

            return id;
        }
    }

    private static class DSU {
        public int n;
        public int[] uf;

        DSU(int n) {
            this.n = n;
            uf = new int[n];
            for (int i = 0; i < n; i++) {
                uf[i] = i;
            }
        }

        public int find(int x) {
            if (uf[x] == x) {
                return x;
            } else {
                int res = find(uf[x]);
                uf[x] = res;
                return res;
            }
        }

        public void merge(int x, int y) {
            int xr = find(x);
            int yr = find(y);
            if (xr == yr) {
                return;
            }
            uf[xr] = yr;
        }
    }

    private static DSU generateDice() {
        DSU dsu = new DSU(MAX_ID);
        for (int a = 0; a < 6; ++a) {
            for (int b = 0; b < 6; ++b) {
                for (int c = 0; c < 6; ++c) {
                    for (int d = 0; d < 6; ++d) {
                        for (int e = 0; e < 6; ++e) {
                            for (int f = 0; f < 6; ++f) {
                                Die die = new Die(new int[]{a, b, c, d, e, f});
                                for (Die other : die.rotate()) {
                                    dsu.merge(other.id, die.id);
                                }
                            }
                        }
                    }
                }
            }
        }

        return dsu;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // Horrible idea: generate all dice, use disjoint set
        DSU dsu = generateDice();

        int n = Integer.parseInt(br.readLine());
        int[] freq = new int[MAX_ID];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int[] faces = new int[6];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 6; ++j) {
                faces[j] = Integer.parseInt(st.nextToken()) - 1;
            }

            Die die = new Die(faces);
            int x = dsu.find(die.id);
            ans = Math.max(ans, ++freq[x]);
        }

        System.out.println(ans);
    }
}
