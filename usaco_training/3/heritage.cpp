/*
ID: rednano1
PROG: heritage
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

string preorder, inorder;
map<char, int> inorder_pos;

void postorder(int preindex, int start, int end, ofstream &fout) {
    if (end <= start) {
        return;
    }
    int inorder_root_pos = inorder_pos[preorder[preindex]];
    int left_tree_size = inorder_root_pos - start;
    int right_tree_size = end - inorder_root_pos - 1;

    // print the left subtree
    if (left_tree_size > 0) {
        postorder(preindex + 1, start, inorder_root_pos, fout);
    }
    // print the right subtree
    if (right_tree_size > 0) {
        postorder(preindex + left_tree_size + 1, inorder_root_pos + 1, end, fout);
    }
    /*
    cout << "Preindex " << preindex << ", ";
    cout << "Left tree size " << left_tree_size << ", ";
    cout << "right tree size " << right_tree_size << '\n';
    */

    fout << preorder[preindex];
}


int main() {
    ifstream fin ("heritage.in");
    ofstream fout("heritage.out");

    fin >> inorder >> preorder;
    int N = inorder.size();

    for (int i = 0; i < N; ++i) {
        inorder_pos[inorder[i]] = i;
    }

    postorder(0, 0, N, fout);
    fout << '\n';
}
