#define CATCH_CONFIG_MAIN
#include "catch.hpp"


#include "../2020_Uno/spil.h"

TEST_CASE("Spil", "[constructor]") {

    SECTION("Empty card."){
        spil::Spil spil = spil::Spil();

        REQUIRE(spil.broj_karata_u_spilu() == 108);
    }

    SECTION("Izvuci kartu"){
        spil::Spil spil = spil::Spil();
        
        spil.izvuci_kartu();

        REQUIRE(spil.broj_karata_u_spilu() == 107);
    }

    SECTION("set spill"){
        spil::Spil spil = spil::Spil();
        std::vector<kar::Karta> dodatSpil = vector<kar::Karta> {
            kar::Karta(),
            kar::Karta(),
            kar::Karta(),
            kar::Karta(),
        };

        int len = spil.broj_karata_u_spilu() + dodatSpil.size() - 1;

        kar::Karta izbacena_karta = spil.set_spil(dodatSpil);

        REQUIRE(len == spil.broj_karata_u_spilu());
    }

    SECTION("promesaj spil"){
        spil::Spil spil = spil::Spil();
        int initial_len = spil.broj_karata_u_spilu();        

        spil.promesaj();

        REQUIRE(initial_len == spil.broj_karata_u_spilu());
    }
}
