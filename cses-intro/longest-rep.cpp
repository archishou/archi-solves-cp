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


    string s{};
    cin >> s;

    auto idx = 1;
    auto best = 1;
    while (idx < s.size()) {
        auto size = 0;
        while (s[idx] == s[idx - 1]) {
            size += 1; idx += 1;
        }
        best = max(size + 1, best);
        idx += 1;
    }

    cout << best << lend;

    return 0;
}
