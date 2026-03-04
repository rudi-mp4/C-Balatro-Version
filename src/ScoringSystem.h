#ifndef SCORINGSYSTEM_H
#define SCORINGSYSTEM_H

#include <string>
#include <vector>
#include "RunSession.h" 


// Struktur untuk menyimpan hasil dari evaluasi kartu
struct PokerHandResult {
    std::string namaKombinasi;
    int skorKombinasi;
    int skorTotal;
    std::vector<int> indeksKartuTerpakai;
};

// --- Behavioral Pattern: Strategy ---
class IScoringStrategy {
public:
    virtual ~IScoringStrategy() = default;
    virtual PokerHandResult evaluateHand(const std::vector<Card>& cards) = 0;
    virtual std::string getStrategyName() = 0;
};

class StandardPokerStrategy : public IScoringStrategy {
public:
    PokerHandResult evaluateHand(const std::vector<Card>& cards) override;
    std::string getStrategyName() override;
};

// Context Class
class ScoringSystem {
private:
    IScoringStrategy* strategy;

public:
    ScoringSystem();
    ~ScoringSystem();

    void setStrategy(IScoringStrategy* newStrategy);
    PokerHandResult calculateScore(const std::vector<Card>& cards);
};

#endif