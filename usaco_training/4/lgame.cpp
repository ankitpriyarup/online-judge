/*
ID: rednano1
PROG: lgame
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <set>
#include <utility>

using namespace std;

multimap<string, string> words;
int best_score;
int scores[] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};
set<pair<string, string> > ans;

int score_word(string s) {
    int ans = 0;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
        ans += scores[s[i] - 'a'];
    }

    return ans;
}

int main() {
    ifstream fin("lgame.in");
    ifstream fdict("lgame.dict");
    ofstream fout("lgame.out");

    string s;
    fdict >> s;
    while (s != ".") {
        string t(s);
        sort(s.begin(), s.end());
        words.insert(make_pair(s, t));
        fdict >> s;
    }

    fdict.close();

    string inp;
    fin >> inp;
    fin.close();

    int inp_n = inp.size();
    sort(inp.begin(), inp.end());
    best_score = 0;

    for (int mask = 1; mask < (1 << inp_n); ++mask) {
        string word;
        for (int i = 0; i < inp_n; ++i) {
            if (mask & (1 << i))
                word += inp[i];
        }

        if (words.find(word) != words.end()) {
            int score = score_word(word);
            if (score > best_score)
                ans.clear();

            if (score >= best_score) {
                auto range = words.equal_range(word);
                for (auto it = range.first; it != range.second; ++it)
                    ans.insert(make_pair(it->second, ""));
                best_score = score;
            }


            int other_mask = ((1 << inp_n) - 1) & (~mask);
            for (int submask = other_mask; submask > 0; submask = (submask - 1) & other_mask) {
                string word2;
                for (int i = 0; i < inp_n; ++i) {
                    if (submask & (1 << i))
                        word2 += inp[i];
                }

                if (words.find(word2) != words.end()) {
                    int total_score = score + score_word(word2);
                    if (total_score > best_score)
                        ans.clear();

                    if (total_score >= best_score) {
                        auto range1 = words.equal_range(word);
                        auto range2 = words.equal_range(word2);
                        for (auto it1 = range1.first; it1 != range1.second; ++it1) {
                            for (auto it2 = range2.first; it2 != range2.second; ++it2) {
                                string a = it1->second;
                                string b = it2->second;
                                ans.insert(make_pair(min(a, b), max(a, b)));
                            }
                        }
                        best_score = total_score;
                    }
                }
            }
        }
    }

    fout << best_score << '\n';
    for (auto it = ans.begin(); it != ans.end(); ++it) {
        fout << it->first;
        if (it->second != "")
            fout << ' ' << it->second;
        fout << '\n';
    }
    fout.close();

    return 0;
}
