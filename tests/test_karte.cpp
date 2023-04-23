#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../2020_Uno/karta.h"

TEST_CASE("Karte", "[constructor]") {

    SECTION("Empty card."){
        kar::Karta karta= kar::Karta();

        REQUIRE(karta.get_vrednost() == 0);
    }


    SECTION("Copy constructor."){
        std::string boja = "plava";
        std::string znak = "herc";

        kar::Karta karta= kar::Karta(boja, znak);

        kar::Karta copy = kar::Karta(karta);

        REQUIRE(copy.get_boja().compare(boja) == 0);
        REQUIRE(copy.get_znak().compare(znak) == 0);
        REQUIRE(copy.get_vrednost() == karta.get_vrednost());
    }

    SECTION("Vrednost"){
        kar::Karta karta= kar::Karta("Crna", "herc");

        REQUIRE(karta.get_vrednost()==50);
    }


    SECTION("Vrednost"){
        kar::Karta karta= kar::Karta("plavo", "5herc");

        REQUIRE(karta.get_vrednost()==5);
    }


    SECTION("Vrednost"){
        kar::Karta karta= kar::Karta("plavo", "herc");

        REQUIRE(karta.get_vrednost()==20);
    }

    SECTION("Compare"){
        kar::Karta karta1 = kar::Karta("plavo", "herc");
        kar::Karta karta2 = kar::Karta("plavo", "herc");


        REQUIRE(kar::compare(karta1, karta2) == false);
    }

    SECTION("Compare"){
        kar::Karta karta1 = kar::Karta("plavo", "herc");
        kar::Karta karta2 = kar::Karta("Crna", "herc");

        REQUIRE(kar::compare(karta1, karta2) == true);
    }

    SECTION("== true"){
        kar::Karta karta1 = kar::Karta("plavo", "herc");
        kar::Karta karta2 = kar::Karta("plavo", "herc");


        REQUIRE((karta1 == karta2) == true);
    }


    SECTION("== true ista boja"){
        kar::Karta karta1 = kar::Karta("plavo", "herc");
        kar::Karta karta2 = kar::Karta("plavo", "tref");


        REQUIRE((karta1 == karta2) == true);
    }


    SECTION("== true isti znak"){
        kar::Karta karta1 = kar::Karta("plavo", "herc");
        kar::Karta karta2 = kar::Karta("crveno", "herc");


        REQUIRE((karta1 == karta2) == true);
    }

    SECTION("== true crno"){
        kar::Karta karta1 = kar::Karta("Crna", "herc");
        kar::Karta karta2 = kar::Karta("crveno", "tref");


        REQUIRE((karta1 == karta2) == true);
    }

    SECTION("== false"){
        kar::Karta karta1 = kar::Karta("plavo", "herc");
        kar::Karta karta2 = kar::Karta("crveno", "tref");


        REQUIRE((karta1 == karta2) == false);
    }
}
