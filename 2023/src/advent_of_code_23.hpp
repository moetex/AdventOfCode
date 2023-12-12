#ifndef ADVENT_OF_CODE_23_H
#define ADVENT_OF_CODE_23_H

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <regex>

namespace aoc_23
{
    class day{
    public:
        virtual void run() = 0;
        virtual ~day() = default;

        int result_part1 = 0;
        int result_part2 = 0;

    protected:
        virtual void read_file(const std::string& file_name) = 0;
    };

    class day01 : day{
    public:
        void run() override;

    private:
        void read_file(const std::string& file_name) override;
        static int evaluate_part1(const std::string& line);
        static int evaluate_part2(const std::string& line);
        static std::pair<int, int> find_most_right(const std::string& line);
        static std::pair<int, int> find_most_left(const std::string& line);

    };

    class day02 : day{
    public:
        void run() override;

        constexpr static int MAX_RED = 12;
        constexpr static int MAX_GREEN = 13;
        constexpr static int MAX_BLUE = 14;

    private:

        void read_file(const std::string& file_name) override;
        static int determine_game_id(const std::string &line);
        static int determine_part1_result(const std::string& line);
        static int determine_part2_result(const std::string &line);

    };

}

#endif //ADVENT_OF_CODE_23_H
