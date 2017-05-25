#include <message.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include "query_of_death.h"

const int MASTER_NODE = 0;
const int TRIALS = 15;

using namespace std;

bool get_bounds(long long items, long long id, long long nodes, long long& start, long long& end) {
    if (nodes > items)
        nodes = items;

    start = items * id / nodes;
    end = items * (id + 1) / nodes;

    return id < nodes;
}

int main() {
    const long long nodes = NumberOfNodes();
    const long long id = MyNodeId();

    const long long len = GetLength();

    if (id == MASTER_NODE) {
        long long ans = 0LL;
        for (int node = 1; node < nodes; ++node) {
            Receive(node);
            long long sum = GetLL(node);

            if (sum > len) {
                long long start, end;
                get_bounds(len, node - 1, nodes - 1, start, end);

                long long bad = sum - len - 1;
                for (long long i = start; i < end; ++i) {
                    if (i == bad) continue;

                    ans += GetValue(i);
                }

                ans += GetValue(bad);
            } else {
                ans += sum;
            }
        }

        printf("%lld\n", ans);
    } else {
        long long start, end;
        if (!get_bounds(len, id - 1, nodes - 1, start, end)) {
            PutLL(MASTER_NODE, 0);
            Send(MASTER_NODE);
            return 0;
        }

        bool found_bad = false;
        long long sum = 0;
        for (long long i = start; !found_bad and i < end; ++i) {
            long long exp = GetValue(i);
            for (int j = 0; !found_bad and j < TRIALS; ++j) {
                if (GetValue(i) != exp) {
                    found_bad = true;
                    PutLL(MASTER_NODE, i + len + 1);
                    Send(MASTER_NODE);
                    break;
                }
            }

            sum += exp;
        }

        if (!found_bad) {
            PutLL(MASTER_NODE, sum);
            Send(MASTER_NODE);
        }
    }

    return 0;
}
