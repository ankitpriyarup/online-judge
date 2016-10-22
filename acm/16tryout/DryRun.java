import java.io.*;
import java.util.*;

public class DryRun {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = Integer.parseInt(scan.nextLine());
        while (n-- > 0) {
            System.out.println("I like " + scan.nextLine() + ".");
        }
    }
}
