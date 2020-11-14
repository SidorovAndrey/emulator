#ifndef CPU_H_
#define CPU_H_

#include <vector>

class Cpu {
    private:
        std::vector<int>* program_;
        std::vector<int>* registers_;
        unsigned int instruction_pointer_;

        void Add();
        void Sub();
        void Mul();
        void Div();
        void Prnt();

    public:
        Cpu(std::vector<int>* program, int registers = 12);
        ~Cpu();

        void Run();
};

#endif // CPU_H_
