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

bool in_ring(i64 r1, i64 r2, i64 x, i64 y) {
    if (r1 == x and r1 <= y and y <= r2) {
        return true;
    }
    if (r2 == x and r1 <= y and y <= r2) {
        return true;
    }
    if (r1 == y and r1 <= x and x <= r2) {
        return true;
    }
    if (r2 == y and r1 <= x and x <= r2) {
        return true;
    }
    return false;
} 

i32 compute(i64 x, i64 y) {
    if (in_ring(0, 9, x, y)) return 1;
    if (in_ring(1, 8, x, y)) return 2;
    if (in_ring(2, 7, x, y)) return 3;
    if (in_ring(3, 6, x, y)) return 4;
    if (in_ring(4, 5, x, y)) return 5;
    /* if (x == 0 or x == 9 or y == 0 or y == 9) { */
    /*     return 1; */
    /* } */
    /* if (x == 1 and 1 <= y and y <= 8) { */
    /*     return 2; */
    /* } */
    /* if (x == 8 and 1 <= y and y <= 8) { */
    /*     return 2; */
    /* } */
    /* if (x == 2 and 2 <= y and y <= 7) { */
    /*     return 3; */
    /* } */
    /* if (x == 7 and 2 <= y and y <= 7) { */
    /*     return 3; */
    /* } */
    /* if (x == 3 and 3 <= y and y <= 6) { */
    /*     return 4; */
    /* } */
    /* if (x == 6 and 3 <= y and y <= 6) { */
    /*     return 4; */
    /* } */
    /* if (x == 4 and 4 <= y and y <= 5) { */
    /*     return 5; */
    /* } */
    /* if (x == 5 and 4 <= y and y <= 5) { */
    /*     return 5; */
    /* } */
    return 0;
}

void solve() {
    vector<string> arrows(10);
    for (i64 i = 0; i < 10; i += 1) {
        cin >> arrows[i];
    }

    i32 total = 0;
    for (i64 y = 0; y < 10; y += 1) {
        for (i64 x = 0; x < 10; x += 1) {
            if (arrows[y][x] == '.') {
                continue;
            }
            /* cout << x << " " << y << " " << compute(x, y) << lend; */
            total += compute(x, y);
        }
    }
    cout << total << lend;

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
