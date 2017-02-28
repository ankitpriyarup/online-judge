class Node(object):
    def __init__(self, value):
        self.value = value
        self.prev = None
        self.next = None


def main():
    inp = 3017957
    nodes = [Node(v + 1) for v in range(inp)]
    for i in range(1, inp):
        nodes[i].prev = nodes[i - 1]
        nodes[i - 1].next = nodes[i]

    nodes[0].prev = nodes[-1]
    nodes[-1].next = nodes[0]

    chain_len = inp
    thief = nodes[0]
    target = nodes[0]
    dist = 0

    while dist < chain_len // 2:
        target = target.next
        dist += 1

    while chain_len > 1:
        target_dist = chain_len // 2
        while dist < target_dist:
            target = target.next
            dist += 1

        new_target = target.next
        target.next.prev = target.prev
        target.prev.nxt = target.next

        target = new_target

        chain_len -= 1
        thief = thief.next
        dist -= 1

    print(thief.value)


main()
