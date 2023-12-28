static constexpr size_t N = 1e4 + 10;
static constexpr array<bool, N> gen_primes() {
    array<bool, N> prime;
    fill(prime.begin(), prime.end(), true);
    prime[0] = prime[1] = false;
    for (auto idx = 2; idx < prime.size(); idx += 1) {
        if (!prime[idx]) continue;
        for (auto nidx = idx * idx; nidx < prime.size(); nidx += idx) {
            prime[nidx] = false;
        }
    }
    return prime;
}
static constexpr auto prime = gen_primes();
