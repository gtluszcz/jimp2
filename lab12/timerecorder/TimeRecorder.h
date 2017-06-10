//
// Created by Grzegorz on 10.06.2017.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <chrono>
#include <utility>
#include <thread>
using namespace std;
using namespace chrono;

namespace profiling{
    template<class T>
    auto TimeRecorder(T object);

    template<class T>
    auto TimeRecorder(T object){

        time_point<high_resolution_clock> t1, t2;
        t1 = high_resolution_clock::now();
        auto wynik = object();

        // Programy wykonywały mi się za szybko i zaokrąglało czas do 0ms wiec dodałem 1ms sleep
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        t2 = high_resolution_clock::now();




        duration<float> duration = t2 - t1;
        auto duration2 = duration_cast<milliseconds>(duration);
        return std::make_pair(wynik,duration2.count());
    }
}
#endif //JIMP_EXERCISES_TIMERECORDER_H
