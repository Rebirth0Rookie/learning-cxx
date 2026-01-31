#include "../exercise.h"
#include <cstring>
#include <memory>
#include <string>
#include <vector>

// READ: `std::unique_ptr` <https://zh.cppreference.com/w/cpp/memory/unique_ptr>

std::vector<std::string> RECORDS;

class Resource {
    std::string _records;

public:
    void record(char record) {
        _records.push_back(record);
    }

    ~Resource() {
        RECORDS.push_back(_records);//销毁资源的时候，将记录保存到全局变量RECORDS中
    }
};

using Unique = std::unique_ptr<Resource>;
Unique reset(Unique ptr) {
    // 重制资源，返回一个新的资源指针，并且资源数据记录为r
    if (ptr) ptr->record('r');
    return std::make_unique<Resource>();
}
Unique drop(Unique ptr) {
    // 丢弃资源，返回空指针，并且资源数据记录为d
    if (ptr) ptr->record('d');
    return nullptr;
}
Unique forward(Unique ptr) {
    // 转发资源，返回传入的资源指针，并且资源数据记录为f
    if (ptr) ptr->record('f');
    return ptr;
}

int main(int argc, char **argv) {
    std::vector<std::string> problems[3];

    drop(forward(reset(nullptr)));
    // 首先将一个空指针重置，交给unique_ptr管理一个新资源，返回后RECORDS记录'r'
    // 然后将该资源转发，记录'f'
    // 最后丢弃该资源，记录'd'
    problems[0] = std::move(RECORDS);
    // RECORDS是一个全局string变量
    // 将RECORDS的资源控制权移交给problems[0]，并清空RECORDS

    forward(drop(reset(forward(forward(reset(nullptr))))));
    problems[1] = std::move(RECORDS);

    drop(drop(reset(drop(reset(reset(nullptr))))));
    problems[2] = std::move(RECORDS);

    // ---- 不要修改以上代码 ----

    std::vector<const char *> answers[]{
        {"fd"},
        // TODO: 分析 problems[1] 中资源的生命周期，将记录填入 `std::vector`
        // NOTICE: 此题结果依赖对象析构逻辑，平台相关，提交时以 CI 实际运行平台为准
        // 本题在MacOS系统上实现
        {"d", "ffr"},
        {"d", "d", "r"},
    };

    // ---- 不要修改以下代码 ----


    for (auto i = 0; i < 3; ++i) {
        ASSERT(problems[i].size() == answers[i].size(), "wrong size");
        for (auto j = 0; j < problems[i].size(); ++j) {
            ASSERT(std::strcmp(problems[i][j].c_str(), answers[i][j]) == 0, "wrong location");
        }
    }

    return 0;
}
