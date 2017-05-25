#include <message.h>
#include <stdio.h>
#include <algorithm>
#include "oops.h"

const int MASTER_NODE = 0;
const long long INF = 1e18 + 3;

using namespace std;

int main() {
    const int nodes = NumberOfNodes();
    const long long n = GetN();
    const int id = MyNodeId();

    if (id == MASTER_NODE) {
        long long hi = -INF;
        long long lo = INF;

        for (int node = 1; node < nodes; ++node) {
            Receive(node);
            long long chunk_hi = GetLL(node);
            hi = max(hi, chunk_hi);

            long long chunk_lo = GetLL(node);
            lo = min(lo, chunk_lo);
        }

        printf("%lld\n", hi - lo);
    } else {
        long long hi = -INF;
        long long lo = INF;

        for (int i = (id - 1); i < n; i += (nodes - 1)) {
            long long v = GetNumber(i);
            hi = max(hi, v);
            lo = min(lo, v);
        }

        PutLL(MASTER_NODE, hi);
        PutLL(MASTER_NODE, lo);
        Send(MASTER_NODE);
    }

    return 0;
}
