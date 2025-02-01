#include <iostream>

int multiply(int n, int values[], int values_size) {
    int carry = 0;

    for (int i = 0; i < values_size; i++) {
        int production = values[i] * n + carry;

        values[i] = production % 10;

        carry = production / 10;
    }

    while (carry) {
        values[values_size] = carry % 10;
        carry = carry / 10;

        values_size++;
    }
    return values_size;
}

void extraLongFactorials(int n) {
    int values[200];

    values[0] = 1;
    int values_size = 1;

    for (int i = 2; i <= n; i++)
        values_size = multiply(i, values, values_size);
    for (int i = values_size - 1; i >= 0; i--)
        std::cout << values[i];
}

int main() {

    extraLongFactorials(30);
}