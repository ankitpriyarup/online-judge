#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef long double db;

const db MAX_TIME = 1e9 + 7;
const db EPS = 1e-12;

struct pt {
    db x, y;

    pt operator+(const pt& o) const {
        return pt {x + o.x, y + o.y};
    }

    pt operator-(const pt& o) const {
        return pt {x - o.x, y - o.y};
    }

    void operator+=(const pt& o) {
        x += o.x;
        y += o.y;
    }

    pt operator*(const db& f) const {
        return pt {f * x, f * y};
    }

    db operator*(const pt& o) const {
        return x * o.x + y * o.y;
    }

    db sqdist() const {
        return x * x + y * y;
    }
};

struct drop {
    pt p, v; 
    db r;

    inline db area() const {
        return M_PI * r * r;
    }

    inline void update(const db& delta) {
        p += v * delta;
    }
};

inline void print_drop(const drop& d) {
    // printf("%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", d.p.x, d.p.y, d.v.x, d.v.y, d.r);
}

drop merge(const drop& d1, const drop& d2) {
    db a1 = d1.area();
    db a2 = d2.area();

    db w1 = a1 / (a1 + a2);
    db w2 = a2 / (a1 + a2);

    return { d1.p * w1 + d2.p * w2,
             d1.v * w1 + d2.v * w2,
             sqrt(d1.r * d1.r + d2.r * d2.r) };
};

db get_dist(const drop& d1, const drop& d2, const db& t) {
    pt nd1p = d1.p + d1.v * t;
    pt nd2p = d2.p + d2.v * t;

    return (nd1p - nd2p).sqdist();
}

db intersect(const drop& d1, const drop& d2) {
    db target = (d1.r + d2.r) * (d1.r + d2.r);
    if (get_dist(d1, d2, 0.0) <= target + EPS) {
        return 0.0;
    }

    pt dp = d1.p - d2.p;
    pt dv = d1.v - d2.v;

    db a = dv.sqdist();
    db b = 2 * (dp * dv);
    db c = dp.sqdist() - target;

    db disc = b * b - 4 * a * c;

    // printf("a b c: %.3Lf %.3Lf %.3Lf\n", a, b, c);

    if (disc < -EPS) {
        return MAX_TIME + 14;
    }

    db t = (-b - sqrt(disc)) / (2.0 * a);
    // printf("t: %.3Lf\n", t);
    if (t > -EPS) {
        return t;
    } else {
        return MAX_TIME + 14;
    }
}

int n;
vector<drop> drops;

void update_pos(const db& delta) {
    for (int i = 0; i < n; ++i) {
        drops[i].update(delta);
    }
}

int main() {
    scanf("%d", &n);

    int x, y, vx, vy, r;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d %d", &x, &y, &vx, &vy, &r);
        drops.push_back({{(db) x, (db) y}, {(db) vx, (db) vy}, (db) r});
    }

    db time = 0.0;
    while (drops.size() > 1 and time < MAX_TIME + EPS) {
        db int_time = MAX_TIME + 4;
        int c1 = -1;
        int c2 = -1;

        for (int i = 0; i < drops.size(); ++i) {
            for (int j = i + 1; j < drops.size(); ++j) {
                db delta = intersect(drops[i], drops[j]);

                if (delta < int_time + EPS) {
                    int_time = delta;
                    c1 = i;
                    c2 = j;
                }
            }
        }

        if (c2 == -1) {
            // printf("No intersections found\n");
            break;
        }

        update_pos(int_time);
        time += int_time;

        drop d1 = drops[c1];
        drop d2 = drops[c2];
        // printf("First intersection in %.3Lf seconds\n", int_time);

        // printf("Drops %d and %d\n", c1, c2);
        print_drop(d1);
        print_drop(d2);

        drop d3 = merge(d1, d2);

        // printf("Merged to\n");
        print_drop(d3);

        drops.erase(drops.begin() + c2);
        drops.erase(drops.begin() + c1);

        drops.push_back(d3);
    }

    printf("%ld %.12Lf\n", drops.size(), time);

    return 0;
}
