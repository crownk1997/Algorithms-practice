#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Combi(const string& seq, int reqLen, int s, int currLen, vector<bool>& check, int length) {
    if (currLen > reqLen)
        return;
    else if (currLen == reqLen) {
        // cout << "\t";
        for (int i = 0; i < length; i++) {
            if (check[i] == true)
                cout << seq[i] << " ";
        }
        cout << endl;
        return;
    }
    
    if (s == length)
        return;
    
    check[s] = true;
    Combi(seq, reqLen, s + 1, currLen + 1, check, length);
    check[s] = false;
    Combi(seq, reqLen, s + 1, currLen, check, length);
}

int main() {
    string seq = "abcde";
    int length = seq.length();
    vector<bool> check(length, false);
    for (int i = 1; i <= length; i++)
        Combi(seq, i, 0, 0, check, length);
    return 0;
}