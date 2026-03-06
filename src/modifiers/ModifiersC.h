#ifndef MODIFIERSC_H
#define MODIFIERSC_H

#include "IModifiers.h"

class TripleMultiplierModifier : public IModifier {
public:
    int apply(int currentScore) override {
        return currentScore * 3;
    }

    std::string getName() const override {
        return "Triple Multiplier Modifier (x3 Score)";
    }
};

#endif
