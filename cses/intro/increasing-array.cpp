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

    i64 N;
    cin >> N;
    
    vector<i64> nums{N, 0};
    for (int i = 0; i < N; i++) {
        i64 num;
        cin >> num;
        nums.push_back(num);
    }

    auto total = 0ull;
    for (i32 idx = 3; idx < nums.size(); idx += 1) {
        if (nums[idx] < nums[idx - 1]) {
            total += nums[idx - 1] - nums[idx];
            nums[idx] = nums[idx - 1];
        }
    }
    cout << total << lend;

    return 0;
}
