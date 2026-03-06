#ifndef MODIFIERSD_H
#define MODIFIERSD_H

#include "IModifiers.h"

class FlatBonus100Modifier : public IModifier {
public:
    int apply(int currentScore) override {
        return currentScore + 100;
    }

    std::string getName() const override {
        return "Flat Bonus Modifier (+100 Score)";
    }
};

#endif
