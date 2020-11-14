#include <iostream>
#include <vector>

#include "cpu.h"
#include "operations.h"

Cpu::Cpu(std::vector<int>* program, int registers) {
    registers_ = new std::vector<int>(registers);
    program_ = program;
    instruction_pointer_ = 0;
}

Cpu::~Cpu() {
    delete program_;
    delete registers_;
}

void Cpu::Run() {
    do {
        int instruction = program_->at(instruction_pointer_);
        std::cout << "PTR: " << instruction_pointer_ << "; R0 = " << registers_->at(0) << " R1 = " << registers_->at(1) << "\n";
        switch (instruction) {
            case Operations::Add:
                Add();
                break;

            case Operations::Sub:
                Sub();
                break;

            case Operations::Mul:
                Mul();
                break;

            case Operations::Div:
                Div();
                break;

            case Operations::Prnt:
                Prnt();
                break;
        }
    } while (++instruction_pointer_ < program_->size());
}

// TODO: figure out why commented row's not working

void Cpu::Add() {
    int x1 = ++instruction_pointer_;
    int x2 = ++instruction_pointer_;
    int x3 = ++instruction_pointer_;
    registers_->at(program_->at(x1)) = program_->at(x2) + program_->at(x3);

    // registers_->at(program_->at(++instruction_pointer_)) = (program_->at(++instruction_pointer_)) + (program_->at(++instruction_pointer_));
}

void Cpu::Sub() {
    int x1 = ++instruction_pointer_;
    int x2 = ++instruction_pointer_;
    int x3 = ++instruction_pointer_;
    registers_->at(program_->at(x1)) = program_->at(x2) - program_->at(x3);
    //registers_->at(program_->at(++instruction_pointer_)) = (program_->at(++instruction_pointer_)) - (program_->at(++instruction_pointer_));
}

void Cpu::Mul() {
    int x1 = ++instruction_pointer_;
    int x2 = ++instruction_pointer_;
    int x3 = ++instruction_pointer_;
    registers_->at(program_->at(x1)) = program_->at(x2) * program_->at(x3);
    //registers_->at(program_->at(++instruction_pointer_)) = (program_->at(++instruction_pointer_)) * (program_->at(++instruction_pointer_));
}

void Cpu::Div() {
    int x1 = ++instruction_pointer_;
    int x2 = ++instruction_pointer_;
    int x3 = ++instruction_pointer_;
    registers_->at(program_->at(x1)) = program_->at(x2) / program_->at(x3);
    //registers_->at(program_->at(++instruction_pointer_)) = (program_->at(++instruction_pointer_)) / (program_->at(++instruction_pointer_));
}

void Cpu::Prnt() {
    std::cout << registers_->at(program_->at(++instruction_pointer_)) << '\n';
}
