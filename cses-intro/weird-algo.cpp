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

    while (n != 1) {
        cout << n << " ";
        if (n % 2 == 0) n /= 2;
        else {
            n *= 3; 
            n += 1;
        }
    }
    cout << 1;
    return 0;
}
