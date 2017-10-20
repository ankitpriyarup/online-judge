import java.util.*;
import java.io.*;

public class Booking {

    static int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    public static long parse(List<String> dates, String date, String time) {
        int dateInd = Collections.binarySearch(dates, date);

        int hour = Integer.parseInt(time.substring(0, 2));
        int minute = Integer.parseInt(time.substring(3));

        return (dateInd * 24L + hour) * 60L + minute;
    }

    public static List<String> allDates() {
        List<String> ret = new ArrayList<String>();
        for (int year = 2013; year <= 2016; ++year) {
            for (int month = 0; month < 12; ++month) {
                for (int day = 0; day < days[month]; ++day) {
                    ret.add(String.format("%d-%02d-%02d", year, month + 1, day + 1));
                }
            }
        }

        ret.add("2016-02-29");
        Collections.sort(ret);

        return ret;
    }

    public static void main(String[] args) throws IOException {
        List<String> dates = allDates();
        // System.out.println(dates);

        final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            PriorityQueue<Event> events = new PriorityQueue<>();
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                st.nextToken();
                long start = parse(dates, st.nextToken(), st.nextToken());
                long end = parse(dates, st.nextToken(), st.nextToken());

                events.add(new Event(start, 1));
                events.add(new Event(end + c, -1));
            }

            int val = 0;
            int ans = 0;
            while (!events.isEmpty()) {
                Event cur = events.poll();
                // System.out.printf("Event %d %d%n", cur.time, cur.delta);
                val += cur.delta;
                ans = Math.max(ans, val);
            }
            
            System.out.println(ans);
        }
    }

    public static class Event implements Comparable<Event> {
        long time;
        int delta;

        public Event(long time, int delta) {
            this.time = time;
            this.delta = delta;
        }

        public int compareTo(Event other) {
            if (time == other.time) {
                return Integer.compare(delta, other.delta);
            }

            return Long.compare(time, other.time);
        }
    }
}
