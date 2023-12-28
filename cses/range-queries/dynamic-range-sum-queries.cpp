#include <array>
#include <cstdint>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

const string lend = "\n";
const string sep = " ";

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

    i32 n, q;
    cin >> n >> q;
    vector<vector<i64>> tree_ranges(4 * n + 1, vector<i64>(2, 0));
    vector<i64> tree(4 * n + 1, 0);
    vector<i64> nums(n, 0);
    for (i32 i = 0; i < n; i += 1) {
        cin >> nums[i];
    }

    auto init = [&](auto& self, auto idx, auto left, auto right) {
        tree_ranges[idx] = {left, right};
        if (left == right) {
            tree[idx] = nums[left];
            return;
        }
        i64 mid = left + (right - left) / 2;
        self(self, 2 * idx, left, mid);
        self(self, 2 * idx + 1, mid + 1, right);
        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    };

    auto update = [&](auto& self, auto tree_idx, auto nums_idx, auto value) {
        auto range_left  = tree_ranges[tree_idx][0];
        auto range_right = tree_ranges[tree_idx][1];
        if (nums_idx > range_right) return;
        if (nums_idx < range_left) return;
        if (tree_ranges[tree_idx][0] == tree_ranges[tree_idx][1]) {
            tree[tree_idx] = value;
            return;
        }
        self(self, 2 * tree_idx, nums_idx, value);
        self(self, 2 * tree_idx + 1, nums_idx, value);
        tree[tree_idx] -= nums[nums_idx];
        tree[tree_idx] += value;
    };

    auto update_root = [&](auto nums_idx, auto value) {
        update(update, 1, nums_idx, value);
        nums[nums_idx] = value;
    };

    auto query = [&](auto& self, auto tree_idx, auto left, auto right) {
        if (left > right) return static_cast<u64>(0);
        auto tleft = tree_ranges[tree_idx][0];
        auto tright = tree_ranges[tree_idx][1];
        if (left == tleft and tright == right) {
            return static_cast<u64>(tree[tree_idx]);
        }
        if (right < tleft) return (u64) 0; 
        if (left > tright) return (u64) 0;

        auto left_node_rb = tree_ranges[tree_idx * 2][1];
        auto right_node_lb = tree_ranges[tree_idx * 2 + 1][0];
        u64 left_ans{}, right_ans{};
        if (right <= left_node_rb) {
            left_ans = self(self, tree_idx * 2, left, right);
        } else if (left >= right_node_lb) {
            right_ans = self(self, tree_idx * 2 + 1, left, right);
        } else {
            left_ans =  self(self, tree_idx * 2,     left,           left_node_rb);
            right_ans = self(self, tree_idx * 2 + 1, right_node_lb,  right);
        }
        return left_ans + right_ans;
    };

    auto query_root = [&](auto left, auto right) {
        return query(query, 1, left, right);
    };

    init(init, 1, 0, n - 1);

    for (i32 idx = 0; idx < 2 * n + 1; idx += 1) {
        cout << idx << sep << tree_ranges[idx][0] << ":" << tree_ranges[idx][1] << sep << tree[idx] << lend;
    }

    for (i32 qidx = 0; qidx < q; qidx += 1) {
        i32 type, val1, val2;
        cin >> type >> val1 >> val2;
        if (type == 1) {
            update_root(val1 - 1, val2);
        } else {
            cout << query_root(val1 - 1, val2 - 1) << lend;
        }
    }
    return 0;
}
