#ifndef IMODIFIERS_H
#define IMODIFIERS_H

#include <string>

class IModifier {
public:
    virtual ~IModifier() = default;

    // Mengubah skor setelah dihitung oleh ScoringSystem
    virtual int apply(int currentScore) = 0;

    // Nama modifier (untuk ditampilkan di shop / debug)
    virtual std::string getName() const = 0;
};

#endif