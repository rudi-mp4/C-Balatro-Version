#ifndef MODIFIERSE_H
#define MODIFIERSE_H

#include "IModifiers.h"

class QuadMultiplierModifier : public IModifier {
public:
    void apply(int& chips, int& mult) override {
        mult *= 4;
    }

    std::string getName() const override {
        return "Quad Force (x4 mult)";
    }
};

#endif
