#ifndef MODIFIERSE_H
#define MODIFIERSE_H

#include "IModifiers.h"

class QuadMultiplierModifier : public IModifier {
public:
    int apply(int currentScore) override {
        return currentScore * 4;
    }

    std::string getName() const override {
        return "Quad Multiplier Modifier (x4 Score)";
    }
};

#endif
