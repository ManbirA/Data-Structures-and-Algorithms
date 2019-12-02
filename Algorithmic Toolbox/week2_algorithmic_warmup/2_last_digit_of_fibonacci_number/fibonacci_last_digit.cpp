#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    long fib_arr[n];
    fib_arr[0] = 0;
    fib_arr[1] = 1;

    for(int i = 2; i <= n; i++){
        fib_arr[i] = (fib_arr[i - 1] + fib_arr[i - 2]) % 10;  
    } 


    return fib_arr[n];
}

int main() {
    int n;
    std::cin >> n;
    //int c = get_fibonacci_last_digit_naive(n);
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }
