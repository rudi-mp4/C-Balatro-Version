#ifndef MODIFIERSF_H
#define MODIFIERSF_H

#include "IModifiers.h"

class FlatBonus125Modifier : public IModifier {
public:
    int apply(int currentScore) override {
        return currentScore + 125;
    }

    std::string getName() const override {
        return "Flat Bonus Modifier (+125 Score)";
    }
};

#endif
