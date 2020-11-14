#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include "operations.h"

struct Instruction {
    Operations Operation;
    int Register;
    int FirstParam;
    int SecondParam;

    Instruction(Operations operation, int reg) :
        Operation(operation),
        Register(reg) { }
    Instruction(Operations operation, int reg, int param) :
        Operation(operation),
        Register(reg),
        FirstParam(param) { }
    Instruction(Operations operation, int reg, int first_param, int second_param) :
        Operation(operation),
        Register(reg),
        FirstParam(first_param),
        SecondParam(second_param) { }
};

#endif // INSTRUCTION_H_
