import java.io.*;
import java.util.*;

public class Polish {
    public static class Node {
        String root;
        Node left, right;
        boolean isNumber;

        public Node(String token) {
            this.root = token;
            this.left = null;
            this.right = null;

            char c = token.charAt(0);
            this.isNumber = !('a' <= c && c <= 'z');
        }

        private Node(String token, Node left, Node right) {
            this.root = token;
            this.left = left;
            this.right = right;
            this.isNumber = false;
        }

        public static Node makeNode(String token, Node left, Node right) {
            if (left.isNumber && right.isNumber) {
                int a = Integer.parseInt(left.root);
                int b = Integer.parseInt(right.root);

                if (token.equals("+")) {
                    return new Node(Integer.toString(a + b));
                } else if (token.equals("-")) {
                    return new Node(Integer.toString(a - b));
                } else {
                    return new Node(Integer.toString(a * b));
                }
            } else {
                return new Node(token, left, right);
            }
        }

        public static void recurse(List<String> tokens, Node node) {
            tokens.add(node.root);
            if (node.left != null) {
                recurse(tokens, node.left);
            }
            if (node.right != null) {
                recurse(tokens, node.right);
            }
        }

        public List<String> getTokens() {
            List<String> tokens = new ArrayList<String>();
            recurse(tokens, this);
            return tokens;
        }
    }

    public static Node parse(StringTokenizer st) {
        String token = st.nextToken();
        if (token.equals("+") || token.equals("-") || token.equals("*")) {
            Node left = parse(st);
            Node right = parse(st);
            return Node.makeNode(token, left, right);
        } else {
            return new Node(token);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int testCase = 1;
        String line;
        while ((line = br.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(line);
            if (!st.hasMoreTokens()) {
                break;
            }

            Node root = parse(st);
            System.out.printf("Case %d:", testCase++);
            for (String token : root.getTokens()) {
                System.out.printf(" %s", token);
            }
            System.out.println();
        }
    }
}
