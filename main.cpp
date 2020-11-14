#include <vector>

#include "cpu.h"
#include "compiler.h"
#include "instruction.h"
#include "operations.h"

int main() {
    Instruction program[] = {
        Instruction { Operations::Add, 0x00, 5, 2 },
        Instruction { Operations::Div, 0x01, 6, 3 },
        Instruction { Operations::Prnt, 0x00 },
        Instruction { Operations::Prnt, 0x01 }
    };

    Compiler comp;
    auto bytecode = comp.Compile(program, 4);

    Cpu cpu(bytecode);
    cpu.Run();
}