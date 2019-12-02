#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_fast(int n) {
    int fib_arr[n];
    fib_arr[0] = 0;
    fib_arr[1] = 1;

    for(int i = 2; i <= n; i++){
        fib_arr[i] = fib_arr[i - 1] + fib_arr[i - 2];  
    } 


    return fib_arr[n];
}

long long pisano_len(long long m) {
    long long prev = 0;
    long long curr = 1;
    long long new_entry = prev + curr;
    for(long long i = 0; i < (m*m); i++){
        new_entry = (prev + curr) % m;
        prev = curr;
        curr = new_entry;
        
        if(prev == 0 && curr == 1){
            return i + 1;
        }
    }
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    long long prev = 0;
    long long curr = 1;
    long long n_len = n % pisano_len(m);
    if(n_len == 0){
        return 0;
    }
    for(long long i = 0; i < n_len - 1; i++){
        long long prev_hold = prev;
        prev = curr;
        curr = (prev_hold + curr) % m;
        
    }
    return curr;

}

int main() {
    long long n = 0;
    std::cin >> n;
    long long sum = 0;
    long long n_len = n % pisano_len(10);
    for(long long i = 1; i <= n_len; i++){
        sum = sum + get_fibonacci_huge_fast(i, 10);
    }
    std::cout << sum % 10 << "\n";      

    
}
