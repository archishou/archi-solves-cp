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
    i32 a{}, b{};
    cin >> a >> b;

    if (a < b) swap(a, b);

    if (b < a / 2) {cout << "NO" << lend; return;}

    if (a == b * 2) {cout << "YES" << lend; return;}

    pair<int, int> modded = {a % 3, b % 3};
    if (modded == pair{1, 2} || modded == pair{2, 1} || modded == pair{0, 0}) {
        cout << "YES" << lend;
        return;
    }
    cout << "NO" << lend;

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
