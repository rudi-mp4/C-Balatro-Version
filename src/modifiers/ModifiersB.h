#ifndef MODIFIERSB_H
#define MODIFIERSB_H

#include "IModifiers.h"

class FlatBonusModifier : public IModifier {
public:
    int apply(int currentScore) override {
        return currentScore + 50;
    }

    std::string getName() const override {
        return "Flat Bonus Modifier (+50 Score)";
    }
};

#endif