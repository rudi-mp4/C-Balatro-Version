#include <iostream>
#include <string>

void showMenu() {
    std::cout << "\n===============================" << std::endl;
    std::cout << "     Aku Balatro" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "1. Start" << std::endl;
    std::cout << "2. Exit" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Select option: ";
}

void startRun() {
    std::cout << "\nStarting Run Session..." << std::endl;
    std::cout << "Initializing Deck and Modifiers..." << std::endl;
    // Logika RunSession akan diimplementasikan di Commit berikutnya
    std::cout << "\n(Game Loop Placeholder - Press Enter to return to menu)" << std::endl;
    std::cin.ignore();
    std::cin.get();
}

int main() {
    int choice = 0;
    bool running = true;

    while (running) {
        showMenu();
        
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                startRun();
                break;
            case 2:
                std::cout << "Exiting game." << std::endl;
                running = false;
                break;
            default:
                std::cout << "Try again." << std::endl;
                break;
        }
    }

    return 0;
}