//
// Created by Grzegorz on 16.03.2017.
//

#include "TinyUrl.h"
#include <iostream>
#include <utility>
#include <string>
#include <array>
#include <memory>
#include <map>



namespace tinyurl {
    #include <memory>
    #include <iostream>
    #include <map>


    using TinyUrlCodec = std::map<std::string, std::string>;

    std::unique_ptr<TinyUrlCodec> Init() {
        std::unique_ptr<TinyUrlCodec> codec = std::make_unique<TinyUrlCodec>();
        (*codec).emplace("none", "000000");
        return codec;

    }

    void NextHash(std::array<char, 6> *state) {
        char chars[62] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        std::array<char, 6> laststate;

        for (int i=0; i<6; i++) {
            laststate[i] = (*state)[i];
            //std::cout<<laststate[i];
        }
        //std::cout<<std::endl;

        int i = 5;
        bool nextdigit = true;
        while (i >= 0){
            int index = 0;
            index = std::distance(chars, std::find(chars, chars + 62, laststate[i]));
            if (nextdigit) {
                index += 1;
            }
            //std::cout<<index<<" ";
            if(index > 61){
                index = index % 62;
                nextdigit = true;
            }
            else{
                nextdigit = false;
            }
            (*state)[i] = chars[index];
            i--;
        }
        //std::cout<<std::endl;
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {
        std::string lastkey = (**codec).rbegin()->second;
        std::array<char, 6> state;
        for (int i=0;i<6;i++){
            state[i]=lastkey[i];
        }
        NextHash(&state);
        std::string newhash;
        for (int j=0;j<6;j++){
            newhash+=state[j];
        }
        (**codec).emplace(url, newhash);
        return newhash;


    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {
        std::string decoded;
        for (auto &n : *codec) {
            if (n.second == hash){
                decoded = n.first;

            }
        }
        return decoded;
    }
}