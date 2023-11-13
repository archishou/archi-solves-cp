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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    i32 n = 1;
    cin >> n;
    for (i32 k = 1; k <= n; k++) {
        if (k <= 4) {
            if (k == 1) cout << 0 << lend;
            if (k == 2) cout << 6 << lend;
            if (k == 3) cout << 28 << lend;
            if (k == 4) cout << 96 << lend;
            continue;
        }

        u64 inner = (k - 4);
        u64 inner_choices = (k * k) - 1;

        u64 total = inner * inner * 8;
        total += inner * 6 * 4;
        total += inner * 4 * 4;

        total += 2 * 4;
        total += 4 * 4;
        total += 3 * 2 * 4;

        u64 ans = (inner_choices * k * k) - total;
        cout << ans / 2 << lend;
    }
    return 0;
}
