#pragma once

#include <string>
#include <stdint.h>

namespace captain {

enum class Role {
    Proposer = 0;  // 提出提案，收集结论，告诉learner
    Acceptor;  // 举手党，反馈提案结果
    Learner;  // 老百姓负责学习精神
};

//  提案, 包含一个编号和一个value
struct Proposal {
    int64_t number;
    std::string value;
};

struct Vote {
    int64_t max_number;  // accepter 看到的当前最大的提案编号
    int64_t accept_number; // accepter 已经接受的提案编号
    std::string accept_value; // accepter 已经接受的value
};

class Person {
public:
    Person() {}
    virtual ~Person() {}

    void Propare();

    void Accept();

private:
    Role role_;
    int64_t uuid_;
    int64_t local_proposal_num_;
};

} // namespace captain
