//
// Created by Grzegorz on 21.03.2017.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#include <string>
#include <unordered_map>
namespace nets{

    class View {
    public:
        //Konstruktor bezparametrowy
        View();
        //Konstruktor parametrowy
        View(std::string tekst);
        //Destruktor wykonywany przed zwolnieniem pamięci
        ~View();

        std::string Render(const std::unordered_map <std::string, std::string> &model) const;

        std::string GetTekst() const;

        void SetTekst(std::string tekst);
    private:
        //w przeciwienstwie do pythona C++ wymaga jawnej deklaracji składowych pól klasy:
        std::string temp;
    };
}
#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
