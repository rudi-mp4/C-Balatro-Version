#ifndef MODIFIERSG_H
#define MODIFIERSG_H

#include "IModifiers.h"

class PentaMultiplierModifier : public IModifier {
public:
    int apply(int currentScore) override {
        return currentScore * 5;
    }

    std::string getName() const override {
        return "Penta Multiplier Modifier (x5 Score)";
    }
};

#endif
