#include <array>
#include <bitset>
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

void print_bits(i32 n, i32 num) {
    i32 mask = 1 << (n - 1);
    for (int i = 0; i < n; i++) {
        cout << ((num & mask) ? 1 : 0);
        mask >>= 1; 
    }
    cout << lend;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    i32 n = 1;
    cin >> n;
    vector<i32> counts(65536, -1);
    counts[0] = 0;
    counts[1] = 1;

    i32 pidx = 2;
    for (i32 nidx = 2; nidx <= n; nidx += 1) {
        i32 len = pidx;
        for (i32 idx = len - 1; idx >= 0; idx -= 1) {
            i32 new_num = 1 << (nidx - 1);
            new_num |= counts[idx];
            counts[pidx] = new_num;
            pidx += 1;
        }
    }

    for (auto num : counts) {
        if (num == -1) break;
        print_bits(n, num);
        /* cout << bitset<16>(num) << lend; */
    }

    return 0;
}
