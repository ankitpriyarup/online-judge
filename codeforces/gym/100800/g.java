import java.util.*;
import java.io.*;

public class g {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int spend = (int) (Double.parseDouble(st.nextToken()) * 100);
        double drink = Double.parseDouble(st.nextToken());
        int available = Integer.parseInt(st.nextToken());
        
        String[] names = new String[available];
        double[] units = new double[available];
        int[] costs = new int[available];

        for (int a = 0; a < available; a++) {
            st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            names[a] = name;
            int percentage = Integer.parseInt(st.nextToken());
            String size = st.nextToken();
            double alcoholUnits = 0;
            if (size.equals("1/1"))
                alcoholUnits = percentage;
            else if (size.equals("1/2"))
                alcoholUnits = percentage / 2.0;
            else
                alcoholUnits = percentage / 3.0;
            units[a] = alcoholUnits;
            int cost = (int) (Double.parseDouble(st.nextToken()) * 100);
            costs[a] = cost;
        }

        HashMap<Integer, HashMap<Double, ArrayList<Integer>>> memo = new HashMap<>(); 
    
        ArrayList<Integer> result = solve(names, units, costs, memo, new ArrayList<Integer>(), spend, drink);
        if (result == null) {
            System.out.println("IMPOSSIBLE");
            return;
        }
        int[] toPurchase = new int[costs.length];
        for (Integer i : result) {
            toPurchase[i]++;
        }

        for (int a = 0; a < toPurchase.length; a++) {
            if (toPurchase[a] != 0)
                System.out.println(names[a] + " " + toPurchase[a]);
        }
    }

    private static ArrayList<Integer> solve(String[] names, double[] units, int[] costs, HashMap<Integer, HashMap<Double, ArrayList<Integer>>> memo, 
            ArrayList<Integer> soFar, int remainingSpend, double remainingDrink) {
        if (remainingSpend == 0 && remainingDrink == 0) 
            return soFar;
        if (remainingSpend < 0 || remainingDrink < 0)
            return null;
        if (memo.containsKey(remainingSpend) && memo.get(remainingSpend).containsKey(remainingDrink))
            return memo.get(remainingSpend).get(remainingDrink);

        for (int a = 0; a < names.length; a++) {
            ArrayList<Integer> copy = deepCopy(soFar);
            copy.add(a);
            ArrayList<Integer> result = solve(names, units, costs, memo, copy, remainingSpend - costs[a], remainingDrink - units[a]);
            if (!memo.containsKey(remainingSpend - costs[a]))
                memo.put(remainingSpend - costs[a], new HashMap<Double, ArrayList<Integer>>());
            if (!memo.get(remainingSpend - costs[a]).containsKey(remainingDrink - units[a]))
                memo.get(remainingSpend - costs[a]).put(remainingDrink - units[a], result);
            if (result != null)
                return result;
        }
        return null;
    }

    private static ArrayList<Integer> deepCopy(ArrayList<Integer> o) {
        ArrayList<Integer> newArr = new ArrayList<Integer>();
        for (Integer i : o) 
            newArr.add(i);
        return newArr;
    }
}
