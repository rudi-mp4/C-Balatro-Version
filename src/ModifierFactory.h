#ifndef MODIFIERFACTORY_H
#define MODIFIERFACTORY_H

#include "modifiers/IModifiers.h"
#include "modifiers/ModifiersA.h"
#include "modifiers/ModifiersB.h"
#include "modifiers/ModifiersC.h"
#include "modifiers/ModifiersD.h"
#include "modifiers/ModifiersE.h"
#include "modifiers/ModifiersF.h"
#include "modifiers/ModifiersG.h"
#include "modifiers/ModifiersH.h"

class ModifierFactory {
public:

    static IModifier* createModifier(const std::string& type){

        if(type=="double")
            return new DoubleMultiplierModifier();

        if(type=="flat")
            return new FlatBonusModifier();

        if(type=="triple")
            return new TripleMultiplierModifier();

        if(type=="flat100")
            return new FlatBonus100Modifier();

        if(type=="quad")
            return new QuadMultiplierModifier();

        if(type=="flat125")
            return new FlatBonus125Modifier();

        if(type=="penta")
            return new PentaMultiplierModifier();

        if(type=="flat150")
            return new FlatBonus150Modifier();

        return nullptr;
    }
};

#endif