#include <cstdio>
#include <cstring>

using namespace std;
char s[1000010];
int main() {
    scanf("%s", &s[0]);
    int index = strlen(s) - 1;
//    printf("%d\n", index);
    int count = 0;
    bool carry = false;
    for(;index>0;index--) {
        if(s[index] == '0') {
            if(carry) {
                count += 2;
            } else {
                count++;
            }
        } else {
            if(carry) {
                count++;
            } else {
                count += 2;
                carry = true;
            }
        }
    }
    if(carry) {
        count++;
    }
    printf("%d\n", count);
    return 0;
}
