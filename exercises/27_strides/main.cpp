#include "../exercise.h"
#include <vector>
#include <stack>

// 张量即多维数组。连续存储张量即逻辑结构与存储结构一致的张量。
// 通常来说，形状为 [d0, d1, ..., dn] 的张量，第 n 维是 dn 个连续的元素，第 n-1 维是 dn-1 个连续的 dn 个元素，以此类推。
// 张量的步长或跨度指的是张量每个维度上坐标 +1 时，数据指针跨过的范围。
// 因此，一个连续张量，其第 n 维的步长为 1，第 n-1 维的步长为 dn，第 n-2 维的步长为 dn*dn-1，以此类推。
// 例如，一个 2x3x4 张量，其步长为 [12, 4, 1]。

// READ: 类型别名 <https://zh.cppreference.com/w/cpp/language/type_alias>
using udim = unsigned int;

/// @brief 计算连续存储张量的步长
/// @param shape 张量的形状
/// @return 张量每维度的访问步长
std::vector<udim> strides(std::vector<udim> const &shape) {
    std::vector<udim> strides(shape.size());
    // TODO: 完成函数体，根据张量形状计算张量连续存储时的步长。
    // READ: 逆向迭代器 std::vector::rbegin <https://zh.cppreference.com/w/cpp/container/vector/rbegin>
    //       使用逆向迭代器可能可以简化代码
    /*
    逆向迭代器的用法:
    for (auto it = shape.rbegin(); it != shape.rend(); ++it) {
        // *it 即为当前维度的大小
    }
    shapes.rbegin() 返回指向最后一个元素的迭代器
    shapes.rend() 返回指向第一个元素之前的迭代器
    通过 it - shape.rbegin() 可以计算当前维度是第几个维度
    例如 shape = {2, 3, 4}
    当 it 指向 4 时，it - shape.rbegin() == 0
    当 it 指向 3 时，it - shape.rbegin() == 1
    当 it 指向 2 时，it - shape.rbegin() == 2
    通过这个值可以索引 strides 数组，设置对应维度的步长
    计算步长时，可以维护一个变量 stride，初始值为 1
    每次迭代时，将当前维度的步长设置为 stride，然后将 stride 乘以当前维度的大小，作为下一个维度的步长基础
    */
    udim stride = 1;
    std::stack<udim> temp_stack;
    for (auto it = shape.rbegin(); it != shape.rend(); ++it) {
        temp_stack.push(stride);
        stride *= *it;
    }
    while (!temp_stack.empty()) {
        strides[strides.size() - 1 - (temp_stack.size() - 1)] = temp_stack.top();
        temp_stack.pop();
    }
    return strides;
}

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    ASSERT((strides({2, 3, 4}) == std::vector<udim>{12, 4, 1}), "Make this assertion pass.");
    ASSERT((strides({3, 4, 5}) == std::vector<udim>{20, 5, 1}), "Make this assertion pass.");
    ASSERT((strides({1, 3, 224, 224}) == std::vector<udim>{150528, 50176, 224, 1}), "Make this assertion pass.");
    ASSERT((strides({7, 1, 1, 1, 5}) == std::vector<udim>{5, 5, 5, 5, 1}), "Make this assertion pass.");
    return 0;
}
