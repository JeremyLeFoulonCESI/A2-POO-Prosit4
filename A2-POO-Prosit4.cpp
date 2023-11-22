#include <iostream>
#include "Emitter.hpp"
#include "HertzianSpace.hpp"
#include "Receiver.hpp"

int main()
{
    HertzianSpace* france = new HertzianSpace();
    
    Emitter* france_info = new Emitter(france, 144.4f);
    Emitter* sanef = new Emitter(france, 107.7);

    Receiver* radio1 = new Receiver(france);
    radio1->addUser("user1");
    radio1->switchUser("user1");
    radio1->subToFrequency(france_info->getFrequency(), "FranceInfo");
    radio1->subToFrequency(sanef->getFrequency(), "AutorouteInfo");
    radio1->switchRadio("FranceInfo");

    france_info->emit("Bienvenue");
    france_info->emit("Journal de 8h");
    france_info->emit("Un reportage signe france info");
    france_info->emit("Bonjour a toutes et a tous, bienvenue sur le journal de 20h");

    while (radio1->available()) {
        std::cout << "radio1: Received '" << radio1->read(nullptr) << "' from " << radio1->getFrequency() << ".\n";
    }

    radio1->switchRadio("AutorouteInfo");

    sanef->emit("Sanef 107.7, l'info autoroute en temps reel");
    sanef->emit("Un accident a ete detecte sur l'autoroute A42, kilometre 150");
    sanef->emit("Deux arbres sont tombes sur les voies sur l'A6 au kilometre 666");

    while (radio1->available()) {
        std::cout << "radio1: Received '" << radio1->read(nullptr) << "' from " << radio1->getFrequency() << ".\n";
    }

    delete radio1;
    delete france;
    delete france_info;
    delete sanef;
}
