#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int n;

vector<int> st;
queue<int> q;
priority_queue<int> pq;

bool is_stack = true;
bool is_queue = true;
bool is_pq = true;

void insert(const int& x) {
    if (is_stack) {
        st.push_back(x);
    }

    if (is_queue) {
        q.push(x);
    }

    if (is_pq) {
        pq.push(x);
    }
}

void remove(const int& x) {
    if (is_stack) {
        if (!st.empty() and x == st.back()) {
            st.pop_back();
        } else {
            is_stack = false;
        }
    }

    if (is_queue) {
        if (!q.empty() and x == q.front()) {
            q.pop();
        } else {
            is_queue = false;
        }
    }

    if (is_pq) {
        if (!pq.empty() and x == pq.top()) {
            pq.pop();    
        } else {
            is_pq = false;
        }
    }
}

int main() {
    int type, x;
    while (scanf("%d", &n) == 1) {
        st.clear();
        while (!q.empty())
            q.pop();
        while (!pq.empty())
            pq.pop();

        is_stack = true;
        is_queue = true;
        is_pq = true;

        while (n-- > 0) {
            scanf("%d %d", &type, &x);
            if (type == 1) {
                insert(x);
            } else {
                remove(x);
            }
        }

        if (is_stack and !is_queue and !is_pq) {
            printf("stack\n");
        } else if (!is_stack and is_queue and !is_pq) {
            printf("queue\n");
        } else if (!is_stack and !is_queue and is_pq) {
            printf("priority queue\n");
        } else if (!is_stack and !is_queue and !is_pq) {
            printf("impossible\n");
        } else {
            printf("not sure\n");
        }
    }
}
