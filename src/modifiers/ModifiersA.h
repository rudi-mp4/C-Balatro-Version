#ifndef MODIFIERSA_H
#define MODIFIERSA_H

#include "IModifiers.h"

class DoubleMultiplierModifier : public IModifier {
public:
    int apply(int currentScore) override {
        return currentScore * 2;
    }

    std::string getName() const override {
        return "Double Multiplier Modifier (x2 Score)";
    }
};

#endif