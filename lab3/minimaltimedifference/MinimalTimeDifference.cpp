//
// Created by janek on 03.04.17.
//


#include "MinimalTimeDifference.h"




namespace minimaltimedifference {

    unsigned int ToMinutes(std::string time_HH_MM) {
        unsigned int hour, minutes, time = 0;
        std::regex tim{R"((\d{1,2}):(\d{1,2}))"};
        std::smatch matches;
        std::stringstream ss;
        if (regex_match(time_HH_MM, matches, tim)) {
            ss << matches[1];
            ss >> hour;
            ss.clear();
            ss << matches[2];
            ss >> minutes;
            time = (hour * 60) + minutes;
        }
        return time;
    }

    unsigned int MinimalTimeDifference(std::vector<std::string> times) {
        unsigned int difference = 24 * 60;
        int tab[times.size()], tmp;
        int i = 0;

        for (auto n : times) {
            tab[i] = ToMinutes(n);
            i++;
        }
        for (i = 0; i < times.size(); i++) {
            for (int j = i; j < times.size(); j++) {
                if (i == j) continue;
                tmp = tab[i] - tab[j];

                if (tmp < 0)
                    tmp = tab[j] - tab[i];
                if (tmp > 12 * 60)
                    tmp = 24 * 60 - tmp;
                if (tmp < difference)
                    difference = (unsigned int) tmp;
            }
        }
        return difference;
    }
}