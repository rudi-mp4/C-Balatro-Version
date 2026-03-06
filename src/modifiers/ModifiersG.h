#ifndef MODIFIERSG_H
#define MODIFIERSG_H

#include "IModifiers.h"

class PentaMultiplierModifier : public IModifier {
public:
    void apply(int& chips, int& mult) override {
        mult *= 5;
    }

    std::string getName() const override {
        return "Penta Power (x5 mult)";
    }
};

#endif
