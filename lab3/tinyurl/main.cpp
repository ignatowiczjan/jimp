//
// Created by janek on 03.04.17.
//

#include "TinyUrl.h"
#include <iostream>
using namespace tinyurl;
using std::cout;
using std::endl;

int main() {
    auto codec = Init();
    auto voronoi_shortened = Encode("https://en.wikipedia.org/wiki/Voronoi_diagram", &codec);
    auto movie_shortened = Encode("https://www.youtube.com/watch?v=cWDdd5KKhts", &codec);
    cout << Decode(codec, voronoi_shortened) << endl;
    cout << Decode(codec, movie_shortened) << endl;

    return 0;
}

