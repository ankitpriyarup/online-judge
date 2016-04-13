import java.util.*;

public class ExploringNumbers {
    public boolean isPrime(int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;

        for (int d = 3; d * d <= n; d += 2) {
            if (n % d == 0) return false;   
        }

        return true;
    }

    public int numberOfSteps(int n) {
        final Set<Integer> seen = new HashSet<>();
        int x = n;
        int l = 1;

        while (l < n && !isPrime(x) && !seen.contains(x)) {
            System.out.println(x);
            l++;
            seen.add(x);
            int y = 0;
            while (x > 0) {
                int d = x % 10;
                y += d * d;
                x /= 10;
            }
            x = y;
            System.out.println(x);
        }

        return (l >= n) ? -1 : l;
    }

    public static void main(String[] args) {
        ExploringNumbers en = new ExploringNumbers();
        System.out.println(en.numberOfSteps(12366));
    }
}
