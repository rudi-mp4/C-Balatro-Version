#ifndef MODIFIERSH_H
#define MODIFIERSH_H

#include "IModifiers.h"

class FlatBonus150Modifier : public IModifier {
public:
    int apply(int currentScore) override {
        return currentScore + 150;
    }

    std::string getName() const override {
        return "Flat Bonus Modifier (+150 Score)";
    }
};

#endif
