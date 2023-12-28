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
    i32 n = 1;
    cin >> n;

    u64 total = (n * (n + 1)) / 2;

    if (total % 2 == 1) {
        cout << "NO" << lend;
        return 0;
    }

    cout << "YES" << lend;

    if (n % 2 == 1) {
        i64 s1 = (n - 4 + 1) / 2 + 2;
        cout << s1 << lend;
        cout << "1 2" << " ";

        for (i32 i = 4; i < n / 4 + 4; i++) {
            cout << i << " " << n - i + 4 << " ";
        }
        cout << lend;

        cout << n - s1 << lend;
        cout << "3 ";

        for (i32 i = n / 4 + 4; i < n / 2 + 3; i++) {
            cout << i << " " << n - i + 4 << " ";
        }
        return 0;
    }

    i64 s1 = (n + 1) / 2;
    cout << s1 << lend;

    for (i32 i = 1; i < n / 4 + 1; i++) {
        cout << i << " " << n - i + 1 << " ";
    }
    cout << lend;

    cout << n - s1 << lend;

    for (i32 i = n / 4 + 1; i < n / 2 + 1; i++) {
        cout << i << " " << n - i + 1 << " ";
    }
    return 0;

}
