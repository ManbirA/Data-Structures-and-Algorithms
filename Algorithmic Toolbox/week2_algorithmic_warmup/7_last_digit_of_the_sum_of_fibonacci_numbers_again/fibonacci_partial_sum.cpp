#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
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
    long long from, to;
    std::cin >> from >> to;
    long long sum = 0;
    long long n_len_to = to % pisano_len(10);
    long long n_len_from = from % pisano_len(10);
    if (n_len_to < n_len_from){
        n_len_to += pisano_len(10);
    } 
    for(long long i = n_len_from; i <= n_len_to; i++){
        sum = sum + get_fibonacci_huge_fast(i, 10);
    }
    std::cout << sum % 10 << "\n";
}
