#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../2020_Uno/igrac.h"

TEST_CASE("Igrac", "[constructor]") {

    SECTION("Player's name."){
        std::string name = "test igrac";
        Ig::Igrac i = Ig::Igrac(name);
        
        std:string actual = i.get_ime();

        REQUIRE(name.compare(actual)==0);
    }

    SECTION("Initial points."){
        std::string name = "test igrac";
        Ig::Igrac i = Ig::Igrac(name);
        int expected = 0;

        int actual = i.get_broj_poena();

        REQUIRE(expected==actual);
    }
}

TEST_CASE("Igrac: adding and removing cards.", "[vuci]") {

    SECTION("Vuci."){
        Ig::Igrac igrac = Ig::Igrac("test player");
        kar::Karta karta = kar::Karta();

        igrac.vuci(karta);

        REQUIRE(igrac.broj_karata()==1);
    }

    SECTION("Vuci 2."){
        Ig::Igrac igrac = Ig::Igrac("test player");
        kar::Karta karta = kar::Karta();

        igrac.vuci(karta);
        igrac.vuci(karta);

        REQUIRE(igrac.broj_karata()==2);
    }

    SECTION("Izbaci, karta postoji.") {
        Ig::Igrac igrac = Ig::Igrac("test player");
        kar::Karta crveno_tref = kar::Karta("crveno", "tref");

        igrac.vuci(crveno_tref);

        igrac.izbaci(crveno_tref);

        REQUIRE(igrac.broj_karata()==0);
    }


    SECTION("Izbaci, karta ne postoji.") {
        Ig::Igrac igrac = Ig::Igrac("test player");
        kar::Karta crveno_tref = kar::Karta("crveno", "tref");
        kar::Karta crveno_herc = kar::Karta("crveno", "herc");

        igrac.vuci(crveno_tref);

        igrac.izbaci(crveno_herc);

        REQUIRE(igrac.broj_karata()==1);
    }

    SECTION("Prefeririana boja, crvena ako su sve iste"){
        Ig::Igrac igrac = Ig::Igrac("test player");
       
        std::string expected = "Crvena";

        std::string actual = igrac.preferirana_boja(1,1,1,1);

        REQUIRE(expected.compare(actual)==0);
    }


    SECTION("Prefeririana boja, crvena"){
        Ig::Igrac igrac = Ig::Igrac("test player");
       
        std::string expected = "Crvena";

        std::string actual = igrac.preferirana_boja(2,1,1,1);

        REQUIRE(expected.compare(actual)==0);
    }

    SECTION("Prefeririana boja, zuta"){
        Ig::Igrac igrac = Ig::Igrac("test player");
       
        std::string expected = "Zuta";

        std::string actual = igrac.preferirana_boja(1,2,1,1);

        REQUIRE(expected.compare(actual)==0);
    }


    SECTION("Prefeririana boja, zelena"){
        Ig::Igrac igrac = Ig::Igrac("test player");
       
        std::string expected = "Zelena";

        std::string actual = igrac.preferirana_boja(1,1,2,1);

        REQUIRE(expected.compare(actual)==0);
    }


    SECTION("Prefeririana boja, plava"){
        Ig::Igrac igrac = Ig::Igrac("test player");
       
        std::string expected = "Plava";

        std::string actual = igrac.preferirana_boja(1,1,1,2);

        REQUIRE(expected.compare(actual)==0);
    }

    SECTION("Dodaj poene"){
        Ig::Igrac igrac = Ig::Igrac("test player");

        igrac.dodaj_poene(5);

        REQUIRE(igrac.get_broj_poena() == 5);
    }

    SECTION("Izbaci sve karte"){
        Ig::Igrac igrac = Ig::Igrac("test player");
       
        igrac.vuci(kar::Karta());
        igrac.vuci(kar::Karta());
        igrac.vuci(kar::Karta());

        igrac.izbaci_sve_karte();

        REQUIRE(igrac.broj_karata()==0);
           
    }


    SECTION("Izbaci kartu"){
        Ig::Igrac igrac = Ig::Igrac("test player");
       
        igrac.vuci(kar::Karta("Crvena", "tref"));
        igrac.vuci(kar::Karta("Zuta", "herc"));
        igrac.vuci(kar::Karta("Zelena", "pik"));
        igrac.vuci(kar::Karta("Plava", "pik"));

        kar::Karta crveno_tref = kar::Karta("Crvena", "tref");

        std::vector<int> ostali_karte{2,3,4};
        std::string boja = "Crvena";

        kar::Karta izbaceno = igrac.izbaci_kartu(crveno_tref, ostali_karte, boja);

        REQUIRE(izbaceno==crveno_tref);
           
    }

    SECTION("Odigraj umereno"){
        Ig::Igrac igrac = Ig::Igrac("test player");

        kar::Karta za_izbacivanje = kar::Karta("crveno", "+2");
        std::vector<kar::Karta> validne_karte{
            za_izbacivanje,
            kar::Karta("crveno", "+4"),
            kar::Karta("crveno", "Joker"),
            kar::Karta("crveno", "Block"),
            kar::Karta("crveno", "Revrse")
        };

        kar::Karta izbaceno = igrac.odigraj_umereno(validne_karte);

        REQUIRE(za_izbacivanje==izbaceno);
           
    }

    SECTION("Odigraj lezerno"){
        Ig::Igrac igrac = Ig::Igrac("test player");

        kar::Karta za_izbacivanje = kar::Karta("crveno", "+4");
        std::vector<kar::Karta> validne_karte{
            za_izbacivanje,
            kar::Karta("crveno", "+2"),
            kar::Karta("crveno", "Joker"),
            kar::Karta("crveno", "Block"),
            kar::Karta("crveno", "Revrse")
        };

        kar::Karta izbaceno = igrac.odigraj_lezerno(validne_karte);

        REQUIRE(za_izbacivanje==izbaceno);
           
    }


    SECTION("Ima sta da se odigra"){
        Ig::Igrac igrac = Ig::Igrac("test player");
        igrac.vuci(kar::Karta("crveno", "tref"));
        igrac.vuci(kar::Karta("crveno", "herc"));
        igrac.vuci(kar::Karta("crveno", "pik"));

        kar::Karta na_talonu = kar::Karta("Crna", "");

        bool ret = igrac.ima_sta_da_odigra(na_talonu);

        REQUIRE(ret);
    }

    SECTION("Poeni u ruci"){
        Ig::Igrac igrac = Ig::Igrac("test player");
        igrac.vuci(kar::Karta("crveno", "tref")); // 20p
        igrac.vuci(kar::Karta("Crna", "pik")); // 50p
        igrac.vuci(kar::Karta("crveno", "2")); // 2 

        int poeni = 72;

        int ret = igrac.broj_poena_u_ruci();

        REQUIRE(ret == poeni);
    }

}