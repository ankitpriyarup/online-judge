import java.io.*;
import java.util.*;

public class C {
    public static void main(String[] args) throws IOException {
        final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        List<Person> people = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            // strip final colon
            name = name.substring(0, name.length() - 1);
            List<Integer> values = new ArrayList<>();
            while (st.hasMoreTokens()) {
                String value = st.nextToken();
                switch(value) {
                    case "upper":
                        values.add(2);
                        break;
                    case "middle":
                        values.add(1);
                        break;
                    case "lower":
                        values.add(0);
                        break;
                }
            }

            people.add(new Person(name, values));
        }

        Collections.sort(people);
        Collections.reverse(people);
        for (Person p : people) {
            System.out.println(p.name);
        }
    }

    public static class Person implements Comparable<Person> {
        String name;
        List<Integer> score;

        public Person(String name, List<Integer> score) {
            this.name = name;
            this.score = score;
        }

        public int compareTo(Person other) {
            int ptr1 = score.size() - 1;
            int ptr2 = other.score.size() - 1;
            while (ptr1 >= 0 || ptr2 >= 0) {
                int s1 = ptr1 >= 0 ? score.get(ptr1) : 1;
                int s2 = ptr2 >= 0 ? other.score.get(ptr2) : 1;

                if (s1 != s2) {
                    return Integer.compare(s1, s2);
                }

                --ptr1;
                --ptr2;
            }

            return other.name.compareTo(name);
        }
    }
}
