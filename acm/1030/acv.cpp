#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t-- > 0)
    {
        int n;
        cin >> n;

        double count = 0;
        for (int i = 0; i < n; ++i)
        {
            int x; string s;
            cin >> x >> s;

            if (s[0] == 'M')
                count += 12.0 * 9.99;
            else
                count += 99.00;
        }

        printf("%.02f\n", count);
    }
}
