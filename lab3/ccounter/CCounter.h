//
// Created by janek on 03.04.17.
//

#ifndef JIMP_EXERCISES_CCOUNTER_H
#define JIMP_EXERCISES_CCOUNTER_H

#include <string>
#include <memory>
#include <map>

namespace ccounter {
    using ::std::string;
    using ::std::map;
    using ::std::unique_ptr;

    struct Counter{
        map<string, int> count;
    };

    unique_ptr<Counter> Init();

    void Inc(string key, unique_ptr<Counter> *counter);

    int Counts(const unique_ptr<Counter> &counter, string key);

    void SetCountsTo(string key, int value, unique_ptr<Counter> *counter);
}


#endif //JIMP_EXERCISES_CCOUNTER_H
