//
// Created by Grzegorz on 09.03.2017.
//

#include "XorCypherBreaker.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<string> &dictionary){
    string result;
    result = {'a','a','a'};
    vector<char> cypher = cryptogram;
    //Change cipher code to check if key is correct
    int counter=0;
    string final;
    for (int l = 0; l <26; l++) {
        for (int m = 0; m < 26 ; m++) {
            for (int n = 0; n < 26 ; n++) {
                result[0] = 97+l;
                result[1] = 97+m;
                result[2] = 97+n;
                cout << result << endl;

                int inside_counter=0;


                for (int i = 0; i+2< cypher.size(); i+=3) {
                    cypher[i] = cryptogram[i]^result[0];
                    cypher[i+1] = cryptogram[i+1]^result[1];
                    cypher[i+2] = cryptogram[i+2]^result[2];
                }
                cout << result;
                cout << "                                                ";
                for (int j = 0; j < 20 ; ++j) {
                    cout<<cypher[n+3]<<cypher[m+5]<<cypher[l+8]<<cypher[n+4]<<cypher[n+11]<<cypher[m+3]<<cypher[l+2]<<cypher[n+1]<<cypher[n+3]<<cypher[m+2];

                }
                cout<<endl;
                for (int i = 0; i+2< cypher.size(); i++) {
                    string check="";
                    check += cypher[i];
                    check += cypher[i+1];
                    check += cypher[i+2];
                    if (cypher[i]>=97 && cypher[i]<=122 && cypher[i+1]>=97 && cypher[i+1]<=122 && cypher[i+2]>=97 && cypher[i+2]<=122){
                        if (find(dictionary.begin(),dictionary.end(),check) != dictionary.end()) {
                            inside_counter++;
                            //cout << "Correct word is: "<< check << " for key: "<< result << endl;
                        }
                    }
                }

                if (inside_counter >= counter){
                    counter=inside_counter;
                    final = result;
                }
            }
        }
    }
    cout << "PASSWORD CRACKED" << endl;
    cout << "Password is: "<< final <<". Words found: "<< counter << endl;
    return final;
}

std::string XorDecypher(const std::vector<char> &cryptogram, const string key){
    vector<char> cypher = cryptogram;
    string result;
    for (int i = 0; i+2< cypher.size(); i+=3) {
        cypher[i] = cryptogram[i]^key[0];
        cypher[i+1] = cryptogram[i+1]^key[1];
        cypher[i+2] = cryptogram[i+2]^key[2];
    }
    for (int j = 0; j< cryptogram.size(); j++){
        result += cypher[j];
    }
    return result;
}
