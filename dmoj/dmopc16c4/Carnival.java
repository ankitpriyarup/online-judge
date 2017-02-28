import java.io.*;
import java.util.*;

public class Carnival {
    public static class Stall implements Comparable<Stall> {
        int index;
        int pos;
        Set<Integer> types;

        public Stall(int index, int pos) {
            this.index = index;
            this.pos = pos;
            this.types = new HashSet<>();
        }

        public int compareTo(Stall other) {
            if (this.pos == other.pos) {
                return Integer.compare(this.index, other.index);
            }

            return Integer.compare(this.pos, other.pos);
        }

        @Override
        public boolean equals(Object o) {
            if (o == this) return true;
            if (!(o instanceof Stall)) {
                return false;
            }

            Stall other = (Stall) o;
            return this.index == other.index && this.pos == other.pos && this.types.equals(other.types);
        }

        @Override
        public int hashCode() {
            return Objects.hash(this.index, this.pos, this.types);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        Stall[] stalls = new Stall[n + 5];
        TreeSet<Stall>[] inverse = new TreeSet[1003];
        for (int i = 0; i <= 1000; ++i) {
            inverse[i] = new TreeSet<Stall>();
        }

        for (int i = 1; i <= n; i++) {
            int pos = Integer.parseInt(st.nextToken());
            stalls[i] = new Stall(i, pos);
        }

        for (int i = 0; i < s; i++) {
            st = new StringTokenizer(br.readLine());
            int stall = Integer.parseInt(st.nextToken());
            int type = Integer.parseInt(st.nextToken());

            stalls[stall].types.add(type);
            inverse[type].add(stalls[stall]);
        }

        int q = Integer.parseInt(br.readLine());

        for (int qq = 0; qq < q; qq++) {
            st = new StringTokenizer(br.readLine());
            String command = st.nextToken();
            if (command.equals("Q")) {
                int type = Integer.parseInt(st.nextToken());
                System.out.println(inverse[type].isEmpty() ? -1 : inverse[type].first().index);
            } else if (command.equals("A")) {
                int x = Integer.parseInt(st.nextToken());
                int k = Integer.parseInt(st.nextToken());

                stalls[x].types.add(k);
                inverse[k].add(stalls[x]);
            } else if (command.equals("S")) {
                int x = Integer.parseInt(st.nextToken());
                int k = Integer.parseInt(st.nextToken());

                stalls[x].types.remove(k);
                inverse[k].remove(stalls[x]);
            } else if (command.equals("E")) {
                int x = Integer.parseInt(st.nextToken());
                int k = Integer.parseInt(st.nextToken());

                for (int type : stalls[x].types) {
                    inverse[type].remove(stalls[x]);
                }

                stalls[x].types.clear();
                stalls[x].pos = k;
            }
        }
    }
}
