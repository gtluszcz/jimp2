//
// Created by Grzegorz on 28.03.2017.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H
#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <vector>
using std::experimental::string_view;

namespace pool {
    class TextPool {
    protected:
        std::set<const string_view> tekst;

    public:
        //Rule of Five (z usuniętą możliwością kopiowania)

        //1. konstruktor kopiujący
        //TextPool(const TextPool &xxx);

        //2. konstruktor przenoszący
        TextPool(TextPool &&xxx);

        //3. operator przypisania kopiujący
        //TextPool &operator=(const TextPool &xxx);

        //4. operator przypisania przenoszący
        TextPool &operator=(TextPool &&xxx);

        //5. Destruktor
        ~TextPool();


        //domyślny konstruktor
        TextPool();

        //konstruktor z listą inicjalizacyjną
        TextPool(const std::initializer_list<const std::string> &elements);

        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;


    };
}
#endif //JIMP_EXERCISES_TEXTPOOL_H
