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
    i64 sz;
    cin >> sz;
    vector<i64> nums(sz, 0); 

    i64 prod = 1;
    i64 zeros = 0; 
    for (i64 i = 0; i < sz; i++) {
        cin >> nums[i];
        if (nums[i] != 0) {
            prod *= nums[i];
        } else {
            zeros += 1;
        }
    }

    if (zeros >= 2) {
        cout << 0 << lend;
        return;
    }

    if (zeros == 1) {
        cout << prod << lend;
        return;
    }
    
    i64 best = 0;
    for (i64 i = 0; i < sz; i++) {
        i64 nb = (prod / nums[i]) * (nums[i] + 1);
        if (nb > best) best = nb;
    }
    cout << best << lend;
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
