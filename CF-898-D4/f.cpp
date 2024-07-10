#include <array>
#include <cstdint>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

const string lend = "\n";

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using i8 = int8_t;
using i16 = int16_t;
using i64 = int64_t;

using f32 = float;
using f64 = double;

using usize = size_t;

void solve() {
    i64 n;
    i64 k;
    cin >> n;
    cin >> k;
    vector<i64> fruits(n, 0);
    vector<i64> heights(n, 0);
    for (i64 i = 0; i < n; i += 1) {
        cin >> fruits[i];
    }
    for (i64 i = 0; i < n; i += 1) {
        cin >> heights[i];
    }
    vector<i64>prefix(n + 1, 0);
    for (i64 i = 0; i < n; i += 1) {
        prefix[i + 1] = prefix[i] + fruits[i];
    }
    i64 l = 0; 
    i64 r = 1; 
    i64 best = 0;
    while (r < n) {
        r = max(l, r);
        while (r < n and prefix[r + 1] - prefix[l] < k and heights[r] % heights[r-1] == 0) {
            r += 1;
        }
        cout << l << " " << r << " " << prefix[r] - prefix[l] << lend;
        if (prefix[r + 1] - prefix[l] < k) {
            best = max(best, r - l);
        }
        l += 1;
    }
    cout << best << lend;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    i64 tc = 1;
    cin >> tc;
    for (i64 t = 0; t < tc; t++) {
        solve();
    }
    return 0;
}
