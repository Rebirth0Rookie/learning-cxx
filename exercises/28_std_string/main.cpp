#include "../exercise.h"
#include <string>

// READ: 字符串 <https://zh.cppreference.com/w/cpp/string/basic_string>

int main(int argc, char **argv) {
    // READ: 字符串字面量 <https://zh.cppreference.com/w/cpp/string/basic_string/operator%22%22s>
    using namespace std::string_literals;
    auto hello = "Hello"s;
    auto world = "world";
    // READ: `decltype` 表达式 <https://zh.cppreference.com/w/cpp/language/decltype>
    // READ: `std::is_same_v` 元编程判别 <https://zh.cppreference.com/w/cpp/types/is_same>
    ASSERT((std::is_same_v<decltype(hello), std::string>), "Fill in the missing type.");
    ASSERT((std::is_same_v<decltype(world), const char*>), "Fill in the missing type.");
    // TODO: 将 `?` 替换为正确的字符串
    ASSERT(hello + ", " + world + '!' == "Hello, world!", "Fill in the missing string.");
    return 0;
}
/*
decltype的作用是获取变量或表达式的类型。在这个例子中：
- decltype(hello) 获取变量 hello 的类型，它是 std::string 类型，因为 "Hello"s 使用了字符串字面量后缀 s，表示这是一个 std::string 对象。
- decltype(world) 获取变量 world 的类型，它是 const char* 类型，因为 "world" 是一个普通的字符串字面量，默认类型是 const char*。

is same_v 是一个类型特征，用于在编译时比较两个类型是否相同。如果相同，is_same_v 的值为 true，否则为 false。

"Hello"s调用的是准库定义的用户自定义字面量 operator""s，这个字面量返回一个std::string对象
用户自定义字面量是C++11引入的一种特性，允许程序员为自定义类型定义字面量后缀，从而使得字面量可以直接转换为该类型的对象。
在这个例子中，"Hello"s 使用了字符串字面量后缀 s，这个后缀是由标准库定义的，表示将字符串字面量转换为 std::string 对象。
*/