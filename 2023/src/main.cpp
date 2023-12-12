#include <iostream>
#include "advent_of_code_23.hpp"

using namespace aoc_23;

int main(int argc, char* argv[])
{
    day01* day1 = new day01();
    day1->run();
    delete day1;

    day02* day2 = new day02();
    day2->run();
    delete day2;



    return 0;
}
