#ifndef MODIFIERSD_H
#define MODIFIERSD_H

#include "IModifiers.h"

class FlatBonus100Modifier : public IModifier {
public:
    void apply(int& chips, int& mult) override {
        chips += 100;
    }

    std::string getName() const override {
        return "Chipper Deluxe (+100 chips)";
    }
};

#endif
