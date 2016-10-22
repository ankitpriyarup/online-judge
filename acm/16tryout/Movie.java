import java.io.*;
import java.util.*;

public class Movie {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        scan.nextLine();
        while (scan.hasNextLine()) {
            String line = scan.nextLine();
            if (line.indexOf(" ") >= 0) {
                System.out.println(line + ": Age of Darkness");
            } else {
                System.out.println(line + " Returns");
            }
        }
    }
}
