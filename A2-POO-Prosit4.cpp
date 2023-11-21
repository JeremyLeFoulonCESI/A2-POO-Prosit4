#include <iostream>
#include "Emitter.hpp"
#include "HertzianSpace.hpp"
#include "Receiver.hpp"

int main()
{
    HertzianSpace* france = new HertzianSpace();
    
    Emitter* france_info = new Emitter(france, 144.4f);

    Receiver* radio1 = new Receiver(france);
    radio1->addUser("user1");
    radio1->switchUser("user1");
    radio1->switchRadio(france_info->getFrequency());

    france_info->emit("Bienvenue");
    france_info->emit("Journal de 8h");
    france_info->emit("Un reportage signe france info");
    france_info->emit("Bonjour a toutes et a tous, bienvenue sur le journal de 20h");

    while (radio1->available()) {
        std::cout << "radio1: Received '" << radio1->read(nullptr) << "' from " << radio1->getFrequency() << ".\n";
    }

    delete radio1;
    delete france;
    delete france_info;
}
