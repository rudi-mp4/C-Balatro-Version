#ifndef SHOPSYSTEM_H
#define SHOPSYSTEM_H

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "ModifierFactory.h"

struct ShopItem {
    std::string label;
    std::string factoryKey;
    int buyPrice;
    int sellPrice;
};

class ShopSystem {
public:

    static void openShop(std::vector<IModifier*>& inventory, int& currency) {

        static const std::vector<ShopItem> allItems = {
            {"2x mult skor",  "double",  6,  3},
            {"+50 skor",      "flat",    4,  2},
            {"x3 mult skor",  "triple",  10, 5},
            {"+100 skor",     "flat100", 10, 5},
            {"x4 mult skor",  "quad",    20, 10},
            {"+125 skor",     "flat125", 20, 10},
            {"x5 mult skor",  "penta",   30, 15},
            {"+150 skor",     "flat150", 30, 15}
        };

        // Pilih 2 modifier random
        std::vector<int> indices(allItems.size());
        for(size_t i=0;i<indices.size();i++) indices[i]=(int)i;

        static bool seeded = false;
        if(!seeded){ srand((unsigned)time(nullptr)); seeded=true; }

        for(size_t i=indices.size()-1;i>0;i--){
            size_t j=rand()%(i+1);
            std::swap(indices[i],indices[j]);
        }

        std::vector<ShopItem> shopItems = { allItems[indices[0]], allItems[indices[1]] };
        std::vector<bool> sold(shopItems.size(), false);

        while (true) {

            std::cout << "\n===== SHOP =====\n";
            std::cout << "Currency: $" << currency << "\n";
            std::cout << "1. Lanjut sesi berikutnya\n";
            std::cout << "2. Beli\n";
            std::cout << "3. Jual\n";
            std::cout << "4. Exit to Menu\n";
            std::cout << "Pilih: ";

            std::string input;
            getline(std::cin,input);

            // ===== LANJUT =====
            if(input=="1"){
                return;
            }

            // ===== BELI =====
            else if(input=="2"){

                while(true){

                    std::cout<<"\n=== BELI MODIFIER ===\n";
                    for(size_t i=0;i<shopItems.size();i++){
                        std::cout<<i+1<<". "<<shopItems[i].label;
                        if(sold[i])
                            std::cout<<" [TERJUAL]";
                        else
                            std::cout<<" ($"<<shopItems[i].buyPrice<<")";
                        std::cout<<"\n";
                    }
                    std::cout<<shopItems.size()+1<<". Back\n";
                    std::cout<<"Pilih: ";

                    getline(std::cin,input);

                    int choice = 0;
                    try { choice = stoi(input); } catch(...) { choice = 0; }

                    if(choice>=1 && choice<=(int)shopItems.size()){

                        if(sold[choice-1]){
                            std::cout<<"Modifier sudah terjual\n";
                        }
                        else{
                            const ShopItem& item = shopItems[choice-1];

                            if(currency>=item.buyPrice){

                                currency-=item.buyPrice;

                                inventory.push_back(
                                    ModifierFactory::createModifier(item.factoryKey)
                                );

                                sold[choice-1]=true;
                                std::cout<<"Berhasil membeli "<<item.label<<"\n";
                            }
                            else{
                                std::cout<<"Currency tidak cukup\n";
                            }
                        }
                    }

                    else if(choice==(int)shopItems.size()+1){
                        break;
                    }

                    else{
                        std::cout<<"Pilihan tidak valid\n";
                    }
                }
            }

            // ===== JUAL =====
            else if(input=="3"){

                if(inventory.empty()){
                    std::cout<<"Tidak ada modifier untuk dijual\n";
                    continue;
                }

                std::cout<<"\n=== INVENTORY ===\n";

                for(size_t i=0;i<inventory.size();i++){
                    std::cout<<i+1<<". "<<inventory[i]->getName()<<"\n";
                }

                std::cout<<"Pilih modifier yang ingin dijual (0 untuk cancel): ";

                getline(std::cin,input);

                int idx = 0;
                try { idx = stoi(input); } catch(...) { idx = 0; }

                if(idx<=0 || idx>(int)inventory.size())
                    continue;

                IModifier* mod = inventory[idx-1];

                // Tentukan harga jual berdasarkan nama modifier
                std::string name = mod->getName();
                if(name.find("x5")!=std::string::npos || name.find("+150")!=std::string::npos)
                    currency+=15;
                else if(name.find("x4")!=std::string::npos || name.find("+125")!=std::string::npos)
                    currency+=10;
                else if(name.find("x3")!=std::string::npos || name.find("+100")!=std::string::npos)
                    currency+=5;
                else if(name.find("Double")!=std::string::npos || name.find("x2")!=std::string::npos)
                    currency+=3;
                else
                    currency+=2;

                delete mod;

                inventory.erase(inventory.begin()+idx-1);

                std::cout<<"Modifier berhasil dijual\n";
            }

            // ===== EXIT MENU =====
            else if(input=="4"){
                throw std::runtime_error("exit");
            }

            else{
                std::cout<<"Pilihan tidak valid\n";
            }
        }
    }
};

#endif