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

bool is_possible(vector<i64> coral, i64 max_water, i64 height) {
    i64 total = 0;
    for (i64 i = 0; i < coral.size(); i += 1) {
        if (coral[i] >= height) continue;
        total += height - coral[i];
    }
    return total <= max_water;
}

void solve() {
    i64 sz;
    i64 max_water;
    cin >> sz;
    cin >> max_water;

    i64 max_coral = 0;
    vector<i64> coral(sz, 0);
    for (i64 i = 0; i < sz; i += 1) {
        cin >> coral[i];
        if (coral[i] > max_coral) max_coral = coral[i];
    }

    i64 l = 2; 
    i64 r = max_water + max_coral + 10;
    while (l < r) {
        i64 mid = l + (r - l) / 2;
        if (not is_possible(coral, max_water, mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l - 1 << lend;
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
