#include <iostream>


long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        std::cout << previous << " " << current << "\n";
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
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
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
    //get_fibonacci_huge_fast(n, m);
}
