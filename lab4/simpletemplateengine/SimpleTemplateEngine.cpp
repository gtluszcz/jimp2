//
// Created by Grzegorz on 21.03.2017.
//

#include "SimpleTemplateEngine.h"
#include <string>
#include <iostream>
#include <unordered_map>
#include <regex>
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
            std::regex pattern ("(\\{\\{[A-Za-z0-9_]+\\}\\})");
            std::string line = this->temp;
            std::smatch match;
            while (regex_search(line, match, pattern)) {
                int replaced = 0;
                std::string match_str = match.str();
                int size = match_str.length();
                for (auto &n : model) {
                    if(("{{"+n.first+"}}") == match_str) {
                        line.replace(match.position(), size, n.second);
                        replaced = 1;
                        break;
                    }
                }
                if (replaced == 0){
                    line.replace(match.position(), size, "");
                }
            }
            return line;
        }

        std::string View::GetTekst() const{
            return this->temp;
        }

        void View::SetTekst(std::string tekst){
            this->temp = tekst;
        }

}