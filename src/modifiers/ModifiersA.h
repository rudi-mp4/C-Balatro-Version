#ifndef MODIFIERSA_H
#define MODIFIERSA_H

#include "IModifiers.h"

class DoubleMultiplierModifier : public IModifier {
public:
    void apply(int& chips, int& mult) override {
        mult *= 2;
    }

    std::string getName() const override {
        return "Double Trouble";
    }
};

#endif