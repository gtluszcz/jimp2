//
// Created by Grzegorz on 10.06.2017.
//

#include "TimeRecorder.h"
#include <iostream>
#include <thread>
#include <string>
using namespace profiling;

std::string TestStringFunction() {
    return "test"s;
}

struct TestLongFunction {
    TestLongFunction(int ms) : ms(ms) {}

    int operator()() const {
        std::this_thread::sleep_for(std::chrono::milliseconds{ms});
        return 0;
    }

    int ms;
};

int main(){
    std::pair<int, double> record = TimeRecorder(TestLongFunction(0));
    std::cout<<record.first<<std::endl;
    std::cout<<record.second<<std::endl;

}