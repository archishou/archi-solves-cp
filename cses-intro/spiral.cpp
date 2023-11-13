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
    i64 row, col;
    cin >> row >> col;
    i64 top = max(col, row)*max(col, row);

    if (col == row) {
        cout << top - row + 1 << lend;
        return;
    }

    if (col > row) {
        if (col % 2) {
            cout << top - row + 1 << lend;
            return;
        }
        cout << top - col - (col - row) + 1 << lend;
        return;
    } else {
        if (row % 2 == 0) {
            cout << top - col + 1 << lend;
            return;
        }
        cout << top - row - (row - col) + 1 << lend;
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 0; t < tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
