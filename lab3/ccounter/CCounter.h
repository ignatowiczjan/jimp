//
// Created by janek on 03.04.17.
//

#ifndef JIMP_EXERCISES_CCOUNTER_H
#define JIMP_EXERCISES_CCOUNTER_H

#include <string>
#include <memory>
#include <map>

namespace ccounter {
    struct Counter{
        int count;
    };

    std::unique_ptr<Counter> Init();

    void Inc(std::string key, std::unique_ptr<Counter> *counter);

    int Counts(const std::unique_ptr<Counter> &counter, std::string key);

    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter);
}


#endif //JIMP_EXERCISES_CCOUNTER_H
