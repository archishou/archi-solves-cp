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
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    i64 n;
    cin >> n;

    vector<i32> seen{static_cast<i32>(n + 1), 0};
    seen.reserve(n);
    for (int idx = 0; idx < n - 1; idx++) {
        i32 num;
        cin >> num;
        seen[num] = 1;
    }
    auto idx = 1;
    while (seen[idx] != 0) {
        idx += 1;
    }
    cout << idx << lend;

    return 0;
}
