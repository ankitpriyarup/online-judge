/*
USER: rednano1
PROG: window
LANG: C++11
*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <complex>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

struct window {
    int x1, y1, x2, y2;
    window *prev, *next;

    window(window* other):
        x1(other->x1), y1(other->y1), x2(other->x2), y2(other->y2), prev(nullptr), next(nullptr) { }

    window(int x1, int y1, int x2, int y2):
        x1(x1), y1(y1), x2(x2), y2(y2), prev(nullptr), next(nullptr) { }
};

window *head, *last;

void insert_head(window* node) {
    if (head == nullptr) {
        head = last = node;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
    }
}

void insert_last(window* node) {
    if (head == nullptr) {
        head = last = node;
    } else {
        node->prev = last;
        last->next = node;
        last = node;
    }
}

void remove_self(window* node) {
    if (head == node) {
        head = node->next;
    }
    if (last == node) {
        last = node->prev;
    }

    if (node->prev != nullptr) {
        node->prev->next = node->next;
    }

    if (node->next != nullptr) {
        node->next->prev = node->prev;
    }

    node->prev = nullptr;
    node->next = nullptr;
}

window* lookup['z' + 1];

bool intersect(int a, int b, int c, int d) {
    return (a <= c and c < b) or (c <= a and a < d);
}

bool intersect(window* a, window* b) {
    return intersect(a->x1, a->x2, b->x1, b->x2) and intersect(a->y1, a->y2, b->y1, b->y2);
}

struct event {
    int x, open, y1, y2;

    bool operator<(const event& other) const {
        if (x == other.x) {
            if (open == other.open) {
                if (y1 == other.y1) {
                    return y2 < other.y2;
                }

                return y1 < other.y1;
            }

            return open < other.open;
        }

        return x < other.x;
    }
};

int get_overlap(const multiset<pair<int, int> >& ms) {
    if (ms.empty()) return 0;

    int layers = 0;
    int last = ms.begin()->first;
    int ans = 0;

    for (auto p : ms) {
        if (layers > 0) {
            ans += p.first - last;
        }

        last = p.first;
        if (p.second == 1) {
            ++layers;
        } else {
            --layers;
        }
    }

    return ans;
}

int get_visible(window* node) {
    int ans = 0;
    window* ptr = head;

    // x, open/close, y range
    vector<event> events;

    while (ptr != node) {
        if (intersect(ptr, node)) {
            events.push_back(event{max(ptr->x1, node->x1), +1, max(ptr->y1, node->y1), min(ptr->y2, node->y2)});
            events.push_back(event{min(ptr->x2, node->x2), -1, max(ptr->y1, node->y1), min(ptr->y2, node->y2)});
        }

        ptr = ptr->next;
    }

    sort(begin(events), end(events));

    int last = node->x1;
    multiset<pair<int, int> > ys;
    for (event ev : events) {
        if (ev.x != last) {
            int width = ev.x - last;
            int lap = get_overlap(ys);

            ans += width * lap;
            last = ev.x;
        }

        if (ev.open == 1) {
            ys.insert({ev.y1, 1});
            ys.insert({ev.y2, -1});
        } else {
            auto it = ys.find({ev.y1, 1});
            ys.erase(it);

            it = ys.find({ev.y2, -1});
            ys.erase(it);
        }
    }

    return ans;
}

int main() {
    freopen("window.in", "r", stdin);
    freopen("window.out", "w", stdout);

    head = last = nullptr;
    string line;

    while(true) {
        getline(cin, line);
        if (cin.eof()) break;

        stringstream ss(line);
        string word;
        getline(ss, word, ',');
        char command = word[0];
        char id = word[2];
        int bounds[4];

        if (command == 'w') {
            for (int i = 0; i < 4; ++i) { 
                getline(ss, word, ',');
                if (i == 3) {
                    word.pop_back();
                }
                bounds[i] = stoi(word);
            }

            for (int d = 0; d < 2; ++d) {
                if (bounds[0 | d] > bounds[2 | d]) {
                    swap(bounds[0 | d], bounds[2 | d]);
                }
            }

            // printf("Creating window with id %c (%d, %d, %d, %d)\n", id, bounds[0], bounds[1], bounds[2], bounds[3]);
            window* cur = new window(bounds[0], bounds[1], bounds[2], bounds[3]);
            insert_head(cur);
            lookup[id] = cur;
        } else if (command == 's') {
            window* node = lookup[id];
            // printf("Getting overlap for window %c\n", id);
            int area = get_visible(node);
            int total = (node->x2 - node->x1) * (node->y2 - node->y1);

            printf("%.3f\n", 100.0 * (total - area) / total);
        } else {
            window* node = lookup[id];
            remove_self(node);

            if (command == 't') {
                insert_head(node);
            } else if (command == 'b') {
                insert_last(node);
            } else {
                // printf("Deleting window with id %c\n", id);
                delete node;
            }
        }
    }

    while (head != nullptr) {
        window* node = head;
        head = head->next;

        delete node;
    }

    return 0;
}
