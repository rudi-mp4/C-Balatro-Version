#include "ScoringSystem.h"
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

// --- Implementasi Logika Poker ---

PokerHandResult StandardPokerStrategy::evaluateHand(const vector<Card>& cards) {
    int jumlahKartu = cards.size();

    auto makeResult = [&](string nama, int base, int multiplier, vector<int> indices) -> PokerHandResult {
        int skorKombinasi = base * multiplier;
        int total = skorKombinasi;

        for (int idx : indices) {
            total += cards[idx].getSkor();
        }

        return {nama, skorKombinasi, total, indices};
    };

    if (jumlahKartu < 1 || jumlahKartu > 5) {
        return makeResult("Invalid", 0, 0, {});
    }

    map<string, vector<int>> nomorIndices;
    map<string, int> nomorCount;
    map<string, int> bentukCount;

    for (int i = 0; i < jumlahKartu; i++) {
        string nomor = cards[i].getNomor();
        string bentuk = cards[i].getBentuk();

        nomorIndices[nomor].push_back(i);
        nomorCount[nomor]++;
        bentukCount[bentuk]++;
    }

    // ===== STRAIGHT FLUSH =====
    if (jumlahKartu == 5 && bentukCount.size() == 1) {
        vector<string> urutan = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
        vector<int> posisi;

        for (int i = 0; i < jumlahKartu; i++) {
            for (size_t j = 0; j < urutan.size(); j++) {
                if (cards[i].getNomor() == urutan[j]) {
                    posisi.push_back(j);
                    break;
                }
            }
        }

        sort(posisi.begin(), posisi.end());

        bool isStraight = true;
        for (int i = 1; i < posisi.size(); i++) {
            if (posisi[i] != posisi[i-1] + 1) {
                isStraight = false;
                break;
            }
        }

        if (isStraight)
            return makeResult("Straight Flush", 100, 8, {0,1,2,3,4});
    }

    // ===== FOUR OF A KIND =====
    for (auto& pair : nomorCount) {
        if (pair.second == 4)
            return makeResult("Four of a Kind", 60, 7, nomorIndices[pair.first]);
    }

    // ===== FULL HOUSE =====
    bool hasThree = false, hasTwo = false;
    string triple, pairVal;

    for (auto& p : nomorCount) {
        if (p.second == 3) { hasThree = true; triple = p.first; }
        if (p.second == 2) { hasTwo = true; pairVal = p.first; }
    }

    if (hasThree && hasTwo) {
        vector<int> idx = nomorIndices[triple];
        idx.insert(idx.end(),
                   nomorIndices[pairVal].begin(),
                   nomorIndices[pairVal].end());
        return makeResult("Full House", 40, 4, idx);
    }

    // ===== FLUSH =====
    if (jumlahKartu == 5 && bentukCount.size() == 1)
        return makeResult("Flush", 35, 4, {0,1,2,3,4});

    // ===== STRAIGHT =====
    if (jumlahKartu == 5) {
        vector<string> urutan = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
        vector<int> posisi;

        for (int i = 0; i < jumlahKartu; i++) {
            for (size_t j = 0; j < urutan.size(); j++) {
                if (cards[i].getNomor() == urutan[j]) {
                    posisi.push_back(j);
                    break;
                }
            }
        }

        sort(posisi.begin(), posisi.end());

        bool isStraight = true;
        for (int i = 1; i < posisi.size(); i++) {
            if (posisi[i] != posisi[i-1] + 1) {
                isStraight = false;
                break;
            }
        }

        if (isStraight)
            return makeResult("Straight", 30, 4, {0,1,2,3,4});
    }

    // ===== THREE OF A KIND =====
    for (auto& pair : nomorCount) {
        if (pair.second == 3)
            return makeResult("Three of a Kind", 30, 3, nomorIndices[pair.first]);
    }

    // ===== TWO PAIR =====
    vector<string> pairs;
    for (auto& p : nomorCount)
        if (p.second == 2) pairs.push_back(p.first);

    if (pairs.size() >= 2) {
        vector<int> idx = nomorIndices[pairs[0]];
        idx.insert(idx.end(),
                   nomorIndices[pairs[1]].begin(),
                   nomorIndices[pairs[1]].end());
        return makeResult("Two Pair", 20, 2, idx);
    }

    // ===== ONE PAIR =====
    if (pairs.size() == 1)
        return makeResult("Pair", 10, 2, nomorIndices[pairs[0]]);

    // ===== HIGH CARD =====
    int maxIndex = 0;
    int maxSkor = cards[0].getSkor();

    for (int i = 1; i < jumlahKartu; i++) {
        if (cards[i].getSkor() > maxSkor) {
            maxSkor = cards[i].getSkor();
            maxIndex = i;
        }
    }

    return makeResult("High Card", 5, 1, {maxIndex});
}

string StandardPokerStrategy::getStrategyName() {
    return "Standard Poker Rules";
}

// --- Implementasi Context ---

ScoringSystem::ScoringSystem() : strategy(nullptr) {}

ScoringSystem::~ScoringSystem() {
    if (strategy != nullptr) {
        delete strategy;
    }
}

void ScoringSystem::setStrategy(IScoringStrategy* newStrategy) {
    if (strategy != nullptr) {
        delete strategy;
    }
    strategy = newStrategy;
}

PokerHandResult ScoringSystem::calculateScore(const vector<Card>& cards) {
    if (strategy == nullptr) {
        cout << "[System] Error: Scoring strategy not set!\n";
        return {"Error", 0, 0, {}};
    }
    return strategy->evaluateHand(cards);
}