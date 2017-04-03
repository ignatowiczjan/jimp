//
// Created by janek on 03.04.17.
//

#include "CCounter.h"

using ::std::unique_ptr;
using ::std::make_unique;

namespace ccounter{
    std::unique_ptr<Counter> Init() {
        unique_ptr<Counter> ptr = make_unique<Counter>();
        return ptr;
    }

    void Inc(std::string key, std::unique_ptr<Counter> *counter) {
        counter;
    }

    int Counts(const std::unique_ptr<Counter> &counter, std::string key) {
        return 0;
    }

    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter) {

    }
}