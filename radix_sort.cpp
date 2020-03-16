#include <iostream>
#include <vector>

using namespace std;

int getMax(const vector<int>& array, int n) {
    int mx = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > mx)
            mx = array[i];
    return mx;
}

void countSort(vector<int>& array, int n, int exp) {
    int output[n];
    int i, count[10] = {};

    for (i = 0; i < n; i++)
        count[(array[i]/exp)%10]++;
    
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    for (i = n - 1; i >= 0; i--) {
        output[count[(array[i]/exp) %10] - 1] = array[i];
        count[(array[i]/exp)%10]--;
    }

    for (i = 0; i < n; i++)
        array[i] = output[i];
}

void radixsort(vector<int>& array, int n) {
    int m = getMax(array, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(array, n, exp);
}

void printArray(const vector<int>& array, int n) {
    for (int i = 0; i < n; i++) 
        cout << array[i] << " ";
    cout << endl;
}

int main() {
    vector<int> array = {170, 45, 75, 90, 802, 24, 2, 66}; 
    int n = array.size(); 
    radixsort(array, n); 
    printArray(array, n); 
    return 0;
}