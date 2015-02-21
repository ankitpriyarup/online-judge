import java.io.*;
import java.util.*;

public class Split {

    public static void main(String[] args) throws IOException {
        final Scanner s = new Scanner(System.in);
        final int T = s.nextInt();
        for (int casen = 1; casen <= T; casen++) {
            int N = s.nextInt();
            double total = s.nextDouble();
            HashMap<String, Set<String>> taskList = new HashMap<String, Set<String>>();
            LinkedHashMap<String, Double> names = new LinkedHashMap<String, Double>();
            for (int i = 0; i < N; i++) {
                String name = s.next();
                names.put(name, 0.0);
                int tasks = s.nextInt();
                s.nextLine();
                for (int j = 0; j < tasks; j++) {
                    String task = s.nextLine();
                    if (!taskList.containsKey(task)) {
                        taskList.put(task, new LinkedHashSet<String>());
                    }
                    taskList.get(task).add(name);
                }
            }

            double perTask = total / taskList.size();
            for (Map.Entry<String, Set<String>> entry : taskList.entrySet()) {
                double pay = perTask / entry.getValue().size();
                for(String name : entry.getValue()) {
                    names.put(name, names.get(name) + pay);
                }
            }

            System.out.printf("Case #%d:\n", casen);
            for (Map.Entry<String, Double> entry : names.entrySet()) {
                System.out.printf("%s: %.2f\n", entry.getKey(), entry.getValue());
            }
        }
    }
}
