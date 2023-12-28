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
    string initial_string = "";
    cin >> initial_string;

    vector<i32> freq(26, 0);
    for (char c : initial_string) {
        freq[c - 'A'] += 1;
    }

    i32 odd_freq = 0;
    i32 odd_alpha = -1;
    for (i32 alpha = 0; alpha < 26; alpha += 1) {
        if (freq[alpha] % 2 == 1) {
            odd_freq += 1;
            odd_alpha = alpha;
        }
    }
    if (odd_freq > 1) {
        cout << "NO SOLUTION" << lend; return 0;
    }
    if (odd_alpha == -1) {
        string output = "";
        for (i32 alpha = 0; alpha < 26; alpha += 1) {
            if (freq[alpha] == 0) continue;
            for (i32 count = 0; count < freq[alpha] / 2; count += 1) {
                output += char(alpha + 'A');
            }
        }
        for (i32 idx = output.size() - 1; idx >= 0; idx -= 1) {
            output += output[idx];
        }
        cout << output << lend;
    } else {
        string output = "";
        for (i32 alpha = 0; alpha < 26; alpha += 1) {
            if (freq[alpha] == 0) continue;
            if (freq[alpha] % 2 == 1) continue;
            for (i32 count = 0; count < freq[alpha] / 2; count += 1) {
                output += char(alpha + 'A');
            }
        }
        for (i32 count = 0; count < freq[odd_alpha]; count += 1) {
            output += char(odd_alpha + 'A');
        }
        for (i32 idx = output.size() - freq[odd_alpha] - 1; idx >= 0; idx -= 1) {
            output += output[idx];
        }
        cout << output << lend;
    }
    return 0;
}
