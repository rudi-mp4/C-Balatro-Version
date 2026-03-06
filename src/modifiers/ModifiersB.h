#ifndef MODIFIERSB_H
#define MODIFIERSB_H

#include "IModifiers.h"

class FlatBonusModifier : public IModifier {
public:
    void apply(int& chips, int& mult) override {
        chips += 50;
    }

    std::string getName() const override {
        return "Chipper Reward (+50 chips)";
    }
};

#endif