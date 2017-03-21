//
// Created by Grzegorz on 21.03.2017.
//

#include "SimpleTemplateEngine.h"
#include <string>
#include <iostream>
#include <unordered_map>

namespace nets{

        //Konstruktor bezparametrowy
        View::View():temp(""){
            std::cout << "Konstruktor bezparametrowy" << std::endl;
        }

        //Konstruktor parametrowy
        View::View(std::string tekst){
            View::SetTekst(tekst);
        }

        //Destruktor wykonywany przed zwolnieniem pamięci
        View::~View(){

        }

        std::string View::Render(const std::unordered_map <std::string, std::string> &model) const{

        }

        std::string View::GetTekst() const{
            return this->temp;
        }

        void View::SetTekst(std::string tekst){
            this->temp = tekst;
        }

}