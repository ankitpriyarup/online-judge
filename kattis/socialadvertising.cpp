#include <iostream>
#include <cstring>

using namespace std;

int num_people;
int masks[22];
const int INF = 100;

int dfs(int index, int cur_mask, int moves) {
    if (index == num_people) {
        return cur_mask == (1 << num_people) - 1 ? moves : INF;
    }

    return min(dfs(index + 1, cur_mask, moves),
               dfs(index + 1, cur_mask | masks[index], moves + 1));
}

int main() {
    int num_cases;
    int num_friends;
    int friend_id;

    cin >> num_cases;
    while (num_cases-- > 0) {
        memset(masks, 0, sizeof(masks));

        cin >> num_people;
        for (int i = 0; i < num_people; ++i) {
            cin >> num_friends;
            for (int j = 0; j < num_friends; ++j) {
                cin >> friend_id;
                masks[i] |= (1 << (friend_id - 1));
            }

            masks[i] |= (1 << i);
        }

        cout << dfs(0, 0, 0) << '\n';
    }

    return 0;
}
