#include <vector>
#include <iostream>

using namespace std;

int shellSort(vector<int>& array) {
    int length = array.size();

    for (int gap = length / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < length; i++) {
            int temp = array[i];

            int j;
            for (j = i; j >= gap && array[j-gap] > temp; j-=gap) {
                array[j] = array[j-gap];
            }

            array[j] = temp;
        }
    }

    return 0;
}

void printArray(const vector<int>& array, int n) 
{ 
    for (int i=0; i<n; i++) 
        cout << array[i] << " "; 
    cout << endl;
} 
  
int main() 
{ 
    vector<int> array = {12, 34, 54, 2, 3};
    int i; 
    int n = array.size();
  
    cout << "Array before sorting: \n"; 
    printArray(array, n); 
  
    shellSort(array); 
  
    cout << "\nArray after sorting: \n"; 
    printArray(array, n); 
  
    return 0; 
} 