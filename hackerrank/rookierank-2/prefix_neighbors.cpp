#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 400001;
const int WORD_SIZE = 12;
const int TRIE_SIZE = MAXN * WORD_SIZE;
const int ALPHABET_SIZE = 26;

int trie[TRIE_SIZE][ALPHABET_SIZE];
bool word_end[TRIE_SIZE];
int next_node;

int n;
char string_in[WORD_SIZE];

void insert() {
	int node = 0;
	int len = strlen(string_in);

	for (int i = 0; i < len; ++i) {
		int char_ind = string_in[i] - 'A';
		if (trie[node][char_ind] == -1) {
			trie[node][char_ind] = next_node++;
		}

		node = trie[node][char_ind];
	}

	word_end[node] = true;
}

long long dfs(int node, long long cur_val, bool take) {
	// take means you _can_ take the first node available (but dont have to)
	// 0 means you cannot

	if (word_end[node] and take) {
		long long with_root = cur_val;
		for (int i = 0; i < ALPHABET_SIZE; ++i) {
			if (trie[node][i] != -1) {
				with_root += dfs(trie[node][i], cur_val + i + 'A', 0);
			}
		}

		long long without_root = 0;
		for (int i = 0; i < ALPHABET_SIZE; ++i) {
			if (trie[node][i] != -1) {
				without_root += dfs(trie[node][i], cur_val + i + 'A', 1);
			}
		}

		return max(with_root, without_root);
	} else {
		long long cur = 0;
		for (int i = 0; i < ALPHABET_SIZE; ++i) {
			if (trie[node][i] != -1) {
				cur += dfs(trie[node][i], cur_val + i + 'A', word_end[node] ^ take);
			}
		}
		return cur;
	}
}

int main() {
	memset(trie, -1, sizeof(trie));
	memset(word_end, 0, sizeof(word_end));    
	next_node = 1;
	scanf("%d", &n);

	string s;
	for (int i = 0; i < n; ++i) {
		scanf("%s", string_in);
		insert();
	}

	long long ans = max(dfs(0, 0, 0), dfs(0, 0, 1));
	printf("%lld\n", ans);
	return 0;
}

