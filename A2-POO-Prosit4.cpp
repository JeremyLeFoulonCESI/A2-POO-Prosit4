#include <iostream>
#include "Emitter.hpp"
#include "HertzianSpace.hpp"

int main()
{
    HertzianSpace* france = new HertzianSpace();
    
    Emitter* france_info = new Emitter(france, 144.4);
    france_info->emit("Bienvenue");
    france_info->emit("Journal de 8h");
    france_info->emit("Un reportage signe france info");

    for (size_t i = 0; france->available(france_info->getFrequency(), i); i++) {
        std::cout << "Read '" << france->read(france_info->getFrequency(), i, nullptr) << "'\n";
    }

    delete france;
    delete france_info;
}
