#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int DOWN = 0;
const int RIGHT = 1;
const int UP = 2;
const int LEFT = 3;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const char* dir_names[] = {"DOWN", "RIGHT", "UP", "LEFT"};

char result[20];
bool cache[4];

bool blocked(int dir) {
    if (!cache[dir]) {
        printf("LOOK %s\n", dir_names[dir]);
        fflush(stdout);
        scanf("%s", result);

        cache[dir] = strcmp(result, "UNSAFE") == 0;
    }

    return cache[dir];
}


int main() {
    ios_base::sync_with_stdio(false);
    int face_dir = DOWN;
    int hand_dir = LEFT;

    bool found = false;

    while (!found) {
        // make sure there's a wall to our right hand
        bool hand_wall = blocked(hand_dir);

        if (!hand_wall) {
            // turn and move
            memset(cache, 0, sizeof(cache));
            printf("GO %s\n", dir_names[hand_dir]);
            fflush(stdout);
            face_dir = hand_dir;
            hand_dir = (face_dir + 3) % 4;

            scanf("%s", result);
            found = strcmp(result, "YES") == 0;
        } else {
            // try and move forward
            bool forward_wall = blocked(face_dir);

            if (!forward_wall) {
                memset(cache, 0, sizeof(cache));
                printf("GO %s\n", dir_names[face_dir]);
                fflush(stdout);
                scanf("%s", result);

                found = strcmp(result, "YES") == 0;
            } else {
                ++face_dir;
                ++hand_dir;
                face_dir %= 4;
                hand_dir %= 4;
            }
        }
    }

    return 0;
}
