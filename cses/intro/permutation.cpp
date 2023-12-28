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

    i32 N = 0; 
    cin >> N;

    if (N == 2 || N == 3) {
        cout << "NO SOLUTION" << lend;
        return 0;
    } else if (N == 4) {
        cout << "2 4 1 3" << lend;
        return 0;
    }

    i32 gap = (N + 1) / 2;
    for (int i = 0; i < N / 2; i++) {
        cout << (i + 1) << " " << i + 1 + gap << " ";
    }

    if (N % 2 == 1) cout << gap << lend;


    return 0;
}
