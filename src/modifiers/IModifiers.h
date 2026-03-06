#ifndef IMODIFIERS_H
#define IMODIFIERS_H

#include <string>

class IModifier {
public:
    virtual ~IModifier() = default;

    // Mengubah chips dan mult setelah dihitung oleh ScoringSystem
    virtual void apply(int& chips, int& mult) = 0;

    // Nama modifier (untuk ditampilkan di shop / debug)
    virtual std::string getName() const = 0;
};

#endif