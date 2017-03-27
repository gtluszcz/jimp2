//
// Created by Grzegorz on 26.03.2017.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <map>
#include <vector>
#include <iostream>

using std::string;
using std::map;
using std::vector;
using std::experimental::optional;
using ::std::literals::operator""s;

namespace nets {
    class JsonValue {
    protected:
        map<string, JsonValue> m;
        optional<double> d;
        optional<int> i;
        optional<bool> b;
        optional<string> s;
        optional<vector<JsonValue>> v;

    public:
        JsonValue(map<string, JsonValue> _value);
        JsonValue(double _value);
        JsonValue(int _value);
        JsonValue(bool _value);
        JsonValue(string _value);
        JsonValue(vector<JsonValue> _value);
        ~JsonValue();

        optional<JsonValue> ValueByName(const string &name) const;
        string ToString() const;
    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
