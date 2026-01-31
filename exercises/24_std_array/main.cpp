#include "../exercise.h"
#include <array>
#include <cstring>

// READ: std::array <https://zh.cppreference.com/w/cpp/container/array>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    {
        std::array<int, 5> arr{{1, 2, 3, 4, 5}};
        ASSERT(arr.size() == 5, "Fill in the correct value.");
        ASSERT(sizeof(arr) == 20, "Fill in the correct value.");
        int ans[]{1, 2, 3, 4, 5};
        ASSERT(std::memcmp(arr.data(), ans, sizeof(ans)) == 0, "Fill in the correct values.");
    }
    {
        std::array<double, 8> arr;
        ASSERT(arr.size() == 8, "Fill in the correct value.");
        ASSERT(sizeof(arr) == 64, "Fill in the correct value.");
    }
    {
        std::array<char, 21> arr{"Hello, InfiniTensor!"};
        ASSERT(arr.size() == 21, "Fill in the correct value.");
        ASSERT(sizeof(arr) == 21, "Fill in the correct value.");
        ASSERT(std::strcmp(arr.data(), "Hello, InfiniTensor!") == 0, "Fill in the correct value.");
    }
    return 0;
}
/*
std::array 是 C++ 标准库提供的一个容器模板，用于表示固定大小的数组。它封装了一个静态数组，并提供了一些方便的成员函数来操作数组元素。
与传统的 C 风格数组相比，std::array 提供了更好的类型安全性和易用性。它支持标准容器的接口，例如 size() 方法来获取数组大小，
begin() 和 end() 方法来获取迭代器等。此外，std::array 还可以与标准库算法无缝集成。在使用 std::array 时，需要指定数组的元素类型和大小。
例如，std::array<int, 5> 表示一个包含 5 个整数的数组。由于大小在编译时确定，std::array 的大小是固定的，不能动态改变。
总体来说，std::array 是一种现代 C++ 中推荐使用的数组类型，适用于需要固定大小数组的场景。

int是4字节，char是1字节，double是8字节。
*/
