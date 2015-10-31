#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int t; 
    scanf("%d", &t);

    while (t-- > 0)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int people[n];
        int rooms[m];

        //printf("%d %d\n", n, m);
        for (int i = 0; i < n; ++i)
            scanf("%d", people + i);
        for (int i = 0; i < m; ++i)
            scanf("%d", rooms + i);

        sort(people, people + n);
        sort(rooms, rooms + m);
        int i1 = 0;
        int i2 = 0;
        
        int count = 0;
        while (i1 < n && i2 < m)
        {
            if (people[i1] <= rooms[i2])
            {
                ++count;
                ++i1;
                ++i2;
            }
            else
            {
                ++i2;
            }
        }

        printf("%d\n", count);
    }
}
