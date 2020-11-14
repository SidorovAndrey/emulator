#ifndef COMPILER_H_
#define COMPILER_H_

#include <vector>

#include "instruction.h"

class Compiler {
    private:
        std::vector<int>* ParseInstruction(Instruction instruction) const;

    public:
        std::vector<int>* Compile(const Instruction* program, const int& size) const;
};

#endif // COMPILER_H_