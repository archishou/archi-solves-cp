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
using i32 = int32_t;
using i64 = int64_t;

using f32 = float;
using f64 = double;

using usize = size_t;

void solve() {
    i32 n{};
    cin >> n;
    i64 best = 0;
    i64 best_idx = 0;
    for (i32 idx = 0; idx < n; idx += 1) {
        i32 words{}, quality{};
        cin >> words >> quality;
        if (words > 10) continue;
        if (quality > best) {
            best = quality;
            best_idx = idx + 1;
        }
    }
    cout << best_idx << lend;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    i32 tc = 1;
    cin >> tc;
    for (i32 t = 0; t < tc; t++) {
        solve();
    }
    return 0;
}
