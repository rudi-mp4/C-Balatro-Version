#ifndef RUNSESSION_H
#define RUNSESSION_H

#include <string>
#include <vector>
#include <iostream>

// Class Card dipindah ke sini (tidak perlu Card.h)
class Card {
private:
    std::string nomor;
    std::string bentuk;
    int skor;

public:
    Card(std::string n, std::string b, int s) : nomor(n), bentuk(b), skor(s) {}

    std::string getNomor() const { return nomor; }
    std::string getBentuk() const { return bentuk; }
    int getSkor() const { return skor; }

    void tampilkan() const {
        std::cout << "[" << nomor << " of " << bentuk << "] (Skor: " << skor << ")";
    }
};

// Deklarasi RunSession
class RunSession {
public:
    void startMenu();

private:
    std::vector<Card> deck; // Tumpukan kartu permainan
    
    void runGameLoop();
    void initializeDeck();  // Fungsi untuk membuat dan mengacak 52 kartu
};

#endif