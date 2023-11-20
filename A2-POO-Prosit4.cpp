#include <iostream>
#include "Emitter.hpp"

int main()
{
    Emitter* france_info = new Emitter();
    france_info->emit("Bienvenue");
    france_info->emit("Journal de 8h");
    france_info->emit("Reportage signe france info");

    for (size_t i = 0; france_info->available(i); i++) {
        std::cout << "Read '" << france_info->read(i, nullptr) << "'\n";
    }

    delete france_info;
}
