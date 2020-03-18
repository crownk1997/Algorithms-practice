#include <iostream>
#include <vector>

using namespace std;

int maxProductAfterCutting(int length) {
    if (length < 2)
        return 0;
    if (length == 2)
        return 1;
    if (length == 3)
        return 2;
    
    vector<int> product_array(length + 1);

    product_array[0] = 0;
    product_array[1] = 1;
    product_array[2] = 2;
    product_array[3] = 3;

    int max = 0;

    for (int i = 4; i <= length; i++) {
        for (int j = 1; j <= i/2; j++) {
            int product = product_array[j] * product_array[i - j];
            if (product > max)
                max = product;
        }
        product_array[i] = max;
    }

    return product_array[length];
}



int main() {
    int length = 5;

    std::cout << "Max product is " << maxProductAfterCutting(length) << std::endl;

    return 0;
}