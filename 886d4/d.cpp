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
    i32 n, k;
    cin >> n >> k;
    vector<i32> problems(0, n);

    auto possible = [&](i32 remove) {
        auto removed = 0; 
        for (auto idx = 1; idx < n; idx += 1) {
            if (problems[idx] - problems[idx - 1] > k) removed += 1;
        }
        return removed <= remove;
    };
    
    for (auto idx = 0; idx < n; idx += 1) {
        auto problem = 0;
        cin >> problem;
        problems.push_back(problem);
    }
    sort(problems.begin(), problems.end());
    i32 left = 0;
    i32 right = n;
    while (left < right) {
        i32 mid = left + (right - left) / 2;
        if (possible(mid)) right = mid;
        else left = mid + 1;
    }
    cout << left << lend;
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
