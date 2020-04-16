#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

void permutations(string seq, int i, int n) {
    if (i == n -1) {
        cout << seq << endl;
        return;
    }

    for (int j = i; j < n; j++) {
        swap(seq[i], seq[j]);

        permutations(seq, i+1, n);

        swap(seq[i], seq[j]);
    }
}

int main() {
    string seq = "abc";
    permutations(seq, 0, seq.length());

    return 0;
}