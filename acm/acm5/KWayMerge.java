import java.io.*;
import java.util.*;

public class KWayMerge {

    public static class Data {
        final public String id;
        final public int shardId;
        final public int size;
        final public int lastModified;
        final public int lastRead;

        public Data(String id, int shardId, int size, int lastModified, int lastRead) {
            this.id = id;
            this.shardId = shardId;
            this.size = size;
            this.lastModified = lastModified;
            this.lastRead = lastRead;
        }
    }

    public static class DataComparator implements Comparator<Data> {
        private String orderedBy;

        public DataComparator(String orderedBy) {
            this.orderedBy = orderedBy;
        }

        public int compare(Data d1, Data d2) {
            if (this.orderedBy.equals("id")) {
                return d1.id.compareTo(d2.id);
            } else if (this.orderedBy.equals("size")) {
                return Integer.compare(d1.size, d2.size);
            } else if (this.orderedBy.equals("lm")) {
                return Integer.compare(d1.lastModified, d2.lastModified);
            } else {
                return Integer.compare(d1.lastRead, d2.lastRead);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        final Scanner s = new Scanner(System.in);

        final int D = s.nextInt();
        final int Q = s.nextInt();
        final int S = s.nextInt();

        final List<List<Data>> sortedData = new ArrayList<List<Data>>();
        final List<Data> all = new ArrayList<Data>();
        for (int i = 0; i < S; i++) {
            sortedData.add(new ArrayList<Data>());
        }

        for (int i = 0; i < D; i++) {
            final String id = s.next();
            final int shardId = s.nextInt();
            final int size = s.nextInt();
            final int lastModified = s.nextInt();
            final int lastRead = s.nextInt();

            final Data current = new Data(id, shardId, size, lastModified, lastRead);
            sortedData.get(shardId).add(current);
            all.add(current);
        }

        for (int i = 0; i < Q; i++) {
            final int k = s.nextInt();
            final String orderedBy = s.next();
            final int shardId = s.nextInt();

            if (shardId == -1) {
                Collections.sort(all, new DataComparator(orderedBy));
                System.out.println(all.get(k).id);
            } else {
                final List<Data> cloneList = new ArrayList<Data>(sortedData.get(shardId));
                Collections.sort(cloneList, new DataComparator(orderedBy));
                System.out.println(cloneList.get(k).id);
            }
        }
    }
}
