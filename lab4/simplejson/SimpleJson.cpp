//
// Created by Grzegorz on 26.03.2017.
//
#include "SimpleJson.h"
#include <string>

using nets::JsonValue;
using std::to_string;
using ::std::literals::operator""s;

JsonValue::~JsonValue(){
    m.clear();

}

JsonValue::JsonValue(map<string, JsonValue> _value) {
    m = _value;

}

JsonValue::JsonValue(double _value) {
    d = _value;
}

JsonValue::JsonValue(int _value) {
    i = _value;
}

JsonValue::JsonValue(bool _value) {
    b = _value;
}

JsonValue::JsonValue(string _value) {
    string cos = _value;
    for (int i=0;i<cos.length();i++){
        if (cos[i]=='\"' || cos[i]=='\\'){
            cos.insert(i, 1,'\\');
            i++;
        }
    }
    s=cos;
}

JsonValue::JsonValue(vector<JsonValue> _value) {
    v = _value;
}

optional<JsonValue> JsonValue::ValueByName(const string &name) const {
    for (auto &n : this->m) {
        if (n.first==name){
            return n.second;
        }
    }
}

string JsonValue::ToString() const {
    if (s) {
        //std::cout<<"string value"<<std::endl;
        string cos = *s;
        return "\"" + cos + "\"";
    }
    else if (d) {
        //std::cout<<"double value"<<std::endl;
        string data =  std::to_string(*d);
        for(int j=0;j<data.length();j++){
            bool slice = true;
            for (int k=data.length()-1;k>=j;k-=1){
                if (data[k]!='0'){slice=false;}
            }
            if (slice){
                data = data.substr(0,j);
                break;
            }
        }
        //data = data.substr(0,i);
        return data;
    }
    else if (i) {
        //std::cout<<"integer value"<<std::endl;
        return std::to_string(*i);
    }
    else if (b) {
        //std::cout<<"boolean value"<<std::endl;
        if (*b==false){return "false";}
        else if (*b==true){return "true";}
    }
    else if (v) {
        //std::cout<<"vector value"<<std::endl;
        string data = "[";
        for (auto &n : *v) {
            data = data+", "+n.ToString();
        }
        data += "]";
        data = data.substr(2);
        data[0]='[';
        return data;
    }
    else if (&m != nullptr) {
        string data = "{";
        for (auto &n : this->m) {
            string cos = n.first;
            for (int i=0;i<cos.length();i++){
                if (cos[i]=='\"' || cos[i]=='\\'){
                    cos.insert(i, 1,'\\');
                    i++;
                }
            }
            data = data+"\""+cos+"\": "+n.second.ToString()+", ";
        }
        data[data.size()-2]='}';
        data.pop_back();
        return data;
    }
}