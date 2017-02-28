public class Nineteen {

    public static void main(String[] args) {
        int input = 3017957;
        Node[] nodes = new Node[input];
        for (int i = 1; i <= input; ++i) {
            nodes[i - 1] = new Node();
            nodes[i - 1].value = i;

            if (i > 1) {
                nodes[i - 1].prev = nodes[i - 2];
                nodes[i - 2].next = nodes[i - 1];
            }
        }

        nodes[0].prev = nodes[input - 1];
        nodes[input - 1].next = nodes[0];

        int length = input;
        Node cur = nodes[0];
        Node removal = nodes[0];
        int dist = 0;

        while (dist < length / 2) {
            removal = removal.next;
            ++dist;
        }

        while (length > 1) {
            int target = length / 2;
            while (dist < length / 2) {
                removal = removal.next;
                ++dist;
            }

            Node n = removal.next;
            removal.prev.next = removal.next;
            removal.next.prev = removal.prev;

            removal = n;

            length -= 1;
            cur = cur.next;
            dist -= 1;
        }

        System.out.println(cur.value);
    }


    private static class Node {
        Node prev;
        Node next;
        int value;
    }
}
