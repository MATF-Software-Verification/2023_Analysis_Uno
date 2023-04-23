#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../2020_Uno/igra.h"

TEST_CASE("Igra", "") {

    SECTION("Odigraj"){
        std::vector<std::string> imena_igraca = std::vector<string>{"igrac1", "igra2"};
        igra::Igra igra = igra::Igra(imena_igraca);
        
        igra.odigraj();

        REQUIRE(true);
    }

}