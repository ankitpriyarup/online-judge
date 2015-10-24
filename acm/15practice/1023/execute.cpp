#include <iostream>
#include <vector>

using namespace std;

vector<string> program;
long long stack [1005];
int sp = 0;

string execute() {
    for (auto it = program.begin(); it != program.end(); ++it) {
        if (*it == "NUM") {
            it++;
            int num = stoi(*it);
            stack[sp++] = num;
        } else if (*it == "POP") {
            if (sp == 0) {
                return "ERROR";
            }
            sp--;
        } else if (*it == "INV") {
            if (sp == 0) {
                return "ERROR";
            }
            stack[sp - 1] *= -1;
        } else if (*it == "DUP") {
            if (sp == 0) {
                return "ERROR";
            }
            stack[sp] = stack[sp - 1];
            sp++;
        } else if (*it =="SWP") {
            if (sp < 2) {
                return "ERROR";
            }
            long long temp = stack[sp - 1];
            stack[sp - 1] = stack[sp - 2];
            stack[sp - 2] = temp;
        } else if (*it == "ADD") {
            if (sp < 2) {
                return "ERROR";
            }
            long long left = stack[sp - 2];
            long long right = stack[sp - 1];
            stack[sp - 2] = left + right;
            if (stack[sp - 2] > 1000000000LL || stack[sp - 2] < -1000000000LL) {
                return "ERROR";
            }
            sp--;
        } else if (*it == "SUB") {
            if (sp < 2) {
                return "ERROR";
            }
            long long left = stack[sp - 2];
            long long right = stack[sp - 1];
            stack[sp - 2] = left - right;
            if (stack[sp - 2] > 1000000000LL || stack[sp - 2] < -1000000000LL) {
                return "ERROR";
            }
            sp--;
        } else if (*it == "MUL") {
            if (sp < 2) {
                return "ERROR";
            }
            long long left = stack[sp - 2];
            long long right = stack[sp - 1];
            stack[sp - 2] = left * right;
            if (stack[sp - 2] > 1000000000LL || stack[sp - 2] < -1000000000LL) {
                return "ERROR";
            }
            sp--;
        } else if (*it == "DIV") {
            if (sp < 2) {
                return "ERROR";
            }
            long long left = stack[sp - 2];
            long long right = stack[sp - 1];
            if (right == 0) {
                return "ERROR";
            }
            bool negate = (left < 0) ^ (right < 0);
            if (left < 0) {
                left = -left;
            }
            if (right < 0) {
                right = -right;
            }
            stack[sp - 2] = (negate ? -1LL : 1LL) * left / right;
            if (stack[sp - 2] > 1000000000LL || stack[sp - 2] < -1000000000LL) {
                return "ERROR";
            }
            sp--;
        } else if (*it == "MOD") {
            if (sp < 2) {
                return "ERROR";
            }
            long long left = stack[sp - 2];
            long long right = stack[sp - 1];
            if (right == 0) {
                return "ERROR";
            }
            bool negate = (left < 0);
            if (left < 0) {
                left = -left;
            }
            if (right < 0) {
                right = -right;
            }
            stack[sp - 2] = (negate ? -1LL : 1LL) * (left % right);
            if (stack[sp - 2] > 1000000000LL || stack[sp - 2] < -1000000000LL) {
                return "ERROR";
            }
            sp--;
        }
    }

    if (sp != 1) {
        return "ERROR";
    } else {
        return to_string((int) stack[0]);
    }
}

int main() {
    string inst, x;
    int N, V;
    while (cin >> inst) {
        if (inst == "QUIT") {
            break;
        }

        program.clear();

        while (true) {
            if (inst == "END") {
                break;
            } else {
                program.push_back(inst);
            }

            cin >> inst;
        }

        cin >> N;
        for (int cnum = 0; cnum < N; ++cnum) {
            cin >> V;
            stack[0] = V;
            sp = 1;
            cout << execute() << '\n';
        }
        cout << '\n';
    }
    return 0;
}
