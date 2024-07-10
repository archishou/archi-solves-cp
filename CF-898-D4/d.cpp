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
    string s;
    i32 k;
    cin >> k;
    cin >> k;
    cin >> s;

    i64 l = 0;
    i64 r = 0;
    i64 total_ops = 0;
    while (r < s.size()) {
        if (s[r] == 'B') {
            total_ops += 1;
            r += k;
        } else {
            while (r < s.size() and s[r] == 'W') {
                r += 1;
            }
        }
    }
    cout << total_ops << lend;
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
