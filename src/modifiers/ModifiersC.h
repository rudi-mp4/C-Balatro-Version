#ifndef MODIFIERSC_H
#define MODIFIERSC_H

#include "IModifiers.h"

class TripleMultiplierModifier : public IModifier {
public:
    void apply(int& chips, int& mult) override {
        mult *= 3;
    }

    std::string getName() const override {
        return "Triple Threat (x3 mult)";
    }
};

#endif
