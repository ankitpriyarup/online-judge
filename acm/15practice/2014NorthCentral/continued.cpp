#include <cstdio>

using namespace std;

int a[10];

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    if (a < 0) {
        return gcd(-a, b);
    }
    if (b < 0) {
        return gcd(a, -b);
    }

    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    if ((a < 0) ^ (b < 0)) {
        return lcm(-a, b);
    }
    return a * (b / gcd(a, b));
}

struct rational {
    long long num, den;
    rational(long long num): num(num), den(1) {};
    rational(long long num, long long den): num(num), den(den) {};
};

void print(rational r) {
    //printf("%lld // %lld \n", r.num, r.den);
    
    // figure out what the representation is. This could take more than 10 ops...
    long long num = r.num;
    long long den = r.den;
    printf("%lld", num / den);
    num = num % den;

    long long temp;
    while (num > 0) {
        temp = num;
        num = den;
        den = temp;

        printf(" %lld", num / den);
        num = num % den;
    }

    printf("\n");
}

rational neg(rational& other) {
    return rational(-1 * other.num, other.den);
}

rational flip(rational& other) {
    if (other.num < 0) {
        return rational(-1 * other.den, -1 * other.num);
    } else {
        return rational(other.den, other.num);
    }
}

// a/b + c/d = ad + bc/bd
rational add(rational r1, rational r2) {
    long long new_den = lcm(r1.den, r2.den);
    long long new_num = r1.num * (new_den / r1.den) + r2.num * (new_den / r2.den);
    long long new_gcd = gcd(new_num, new_den);

    return rational(new_num / new_gcd, new_den / new_gcd);
}

rational mul(rational r1, rational r2) {
    long long new_num = r1.num * r2.num;
    long long new_den = r1.den * r2.den;
    long long new_gcd = gcd(new_num, new_den);

    return rational(new_num / new_gcd, new_den / new_gcd);
}

rational from_fraction() {
    int i = 9;
    while (i >= 0 && a[i] == 0) {
        i--;
    }

    rational r = rational(a[i]);
    i--;
    while (i >= 0) {
        r = flip(r);
        r = add(r, rational(a[i]));
        i--;
    }

    return r;
}


int main() {
    int n1, n2;
    int c = 1;
    while (scanf("%d %d", &n1, &n2) == 2) {
        for (int i = 0; i < 10; ++i) {
            a[i] = 0;
        }

        for (int i = 0; i < n1; ++i) {
            scanf("%d", &a[i]);
        }
        rational r1 = from_fraction();

        for (int i = 0; i < 10; ++i) {
            a[i] = 0;
        }
        for (int i = 0; i < n2; ++i) {
            scanf("%d", &a[i]);
        }
        rational r2 = from_fraction();

        printf("Case %d:\n", c);
        print(add(r1, r2));
        print(add(r1, neg(r2)));
        print(mul(r1, r2));
        print(mul(r1, flip(r2)));
    }

    return 0;
}
