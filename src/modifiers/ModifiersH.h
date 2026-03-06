#ifndef MODIFIERSH_H
#define MODIFIERSH_H

#include "IModifiers.h"

class FlatBonus150Modifier : public IModifier {
public:
    void apply(int& chips, int& mult) override {
        chips += 150;
    }

    std::string getName() const override {
        return "Chipper Ultra (+150 chips)";
    }
};

#endif
