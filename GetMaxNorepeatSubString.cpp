#include <iostream>
#include <string>
#include <map>

using namespace std;

int GetMaxLength(const string& seq) {
    if (seq.empty())
        return 0;
    
    // create the map to store the index
    map<char, int> containers;
    int len = 0;
    int start = 0;
    for (int i = 0; i < seq.length(); ++i) {
        if (containers.find(seq[i]) != containers.end()) {
            if (containers[seq[i]] < start)
                containers[seq[i]] = i; // update the new value
            else {
                len = max(len, i - start);
                start = containers[seq[i]] + 1;
                containers[seq[i]] = i;
            } 
        } else {
            // save the index
            containers[seq[i]] = i;
        }
    }

    return len;
}

int main() {
    string seq = "arabcacfr";
    cout << "Max length is " << GetMaxLength(seq) << endl;
    return 0;
}