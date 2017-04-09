//
// Created by janek on 03.04.17.
//

#include "CCounter.h"

using ::std::unique_ptr;
using ::std::make_unique;

namespace ccounter {
    std::unique_ptr<Counter> Init() {
        unique_ptr<Counter> ptr = make_unique<Counter>();
        return ptr;
    }

    void Inc(std::string key, std::unique_ptr<Counter> *counter) {
        auto &c = *counter;
        if (c->count.find(key) == c->count.end())
            c->count[key] = 1;
        else
            c->count[key] += 1;
    }

    int Counts(const std::unique_ptr<Counter> &counter, std::string key) {
        if (counter->count.find(key) != counter->count.end())
            return counter->count[key];
        else
            return 0;
    }

    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter) {
        (*counter)->count[key] = value;
    }
}