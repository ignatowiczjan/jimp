//
// Created by jan on 27.03.17.
//

#include "SimpleJson.h"
#include <iostream>

using std::cout;
using ::std::vector;
using ::std::map;
using ::std::cout;
using ::std::endl;
using ::std::string;
using ::nets::JsonValue;
using ::std::literals::operator""s;


using namespace nets;

int main(){
    JsonValue str(R"(\\\\\\\"http:\\\\\\\"klmno)");
    cout << str.ToString();
    vector<JsonValue> js {JsonValue{56.6},JsonValue{45},JsonValue{"abc"s}};
    map<string, JsonValue> obj_v {{"values",JsonValue{js}},{"name",JsonValue{"Test name"}},{"age",JsonValue{13}}};
    JsonValue obj {obj_v};
    // {"age": 13, "name": "Test name", "values": [56.6, 45, "abc"]} kolejność argumentów nie ma znaczenia w przypadku obiektu

    cout << obj.ToString() << endl;
    cout << "name: " << obj.ValueByName("name")->ToString() << endl;
    cout << "values: " << obj.ValueByName("values")->ToString() << endl;
    cout << "age: " << obj.ValueByName("age")->ToString() << endl;
    //obiekty optional można traktować jak wartości boolean (true wartość obecna, false optional jest pusty)
    if (obj.ValueByName("name")) {
        cout << "is present" << endl;
    } else {
        cout << "is absent" << endl;
    }
}

