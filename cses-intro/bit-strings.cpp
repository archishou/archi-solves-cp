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
    i64 n = 1;
    cin >> n;

    if (n == 1) {
        cout << 2 << lend;
        return 0;
    }

    i64 MOD = 1e9 + 7;

    i64 out = 1;
    i64 a = 2;
    while (n > 0) {
        if (n % 2 == 1) {
            out = (out * a) % MOD;
        }

        a = (a * a) % MOD;
        n /= 2;
    }

    cout << out << lend;


    return 0;
}
