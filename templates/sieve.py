N = 10**5 + 10
prime = [True for _ in range(N)]
prime[0] = prime[1] = False
for idx in range(2, len(prime)):
    if prime[idx]:
        for nidx in range(idx ** 2, len(prime), idx):
            prime[nidx] = False

