#ifndef MODIFIERSF_H
#define MODIFIERSF_H

#include "IModifiers.h"

class FlatBonus125Modifier : public IModifier {
public:
    void apply(int& chips, int& mult) override {
        chips += 125;
    }

    std::string getName() const override {
        return "Chipper Supreme (+125 chips)";
    }
};

#endif
