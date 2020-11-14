#include "compiler.h"

std::vector<int>* Compiler::Compile(const Instruction* program, const int& size) const {
    std::vector<int>* result = new std::vector<int>();
    for (int i = 0; i < size; i++) {
        std::vector<int>* byte_instruction = ParseInstruction(program[i]);
        for (int j = 0; j < byte_instruction->size(); j++) {
            result->push_back(byte_instruction->at(j));
        }
    }

    return result;
}

std::vector<int>* Compiler::ParseInstruction(const Instruction instruction) const {
    auto res = new std::vector<int>();
    res->push_back(static_cast<int>(instruction.Operation));
    res->push_back(instruction.Register);

    if (instruction.Operation != Operations::Prnt) {
        res->push_back(instruction.FirstParam);
        res->push_back(instruction.SecondParam);
    }

    return res;
}
