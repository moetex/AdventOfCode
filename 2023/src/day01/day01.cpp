#include "../advent_of_code_23.hpp"

namespace aoc_23
{
    void day01::run()
    {
        read_file("../../src/day01/input.txt");
        std::cout << "result for day 1: " << std::endl;
        std::cout << "result of part 1: " << result_part1 << std::endl;
        std::cout << "result of part 2: " << result_part2 << std::endl;
        std::cout << std::endl;
    }

    std::vector<std::string> number_words = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    std::pair<int, int> day01::find_most_left(const std::string& line)
    {
        int number = 0;
        int index = 0;
        for(int i = 0; i < line.length(); i++)
        {
            if(std::isdigit(line[i]))
            {
                number = line[i] - '0';
                index = i;
                break;
            }
        }
        return std::make_pair(number, index);
    }

    std::pair<int, int> day01::find_most_right(const std::string& line)
    {
        int number = 0;
        int index = 0;
        for(int i = line.length() - 1; i >= 0; i--)
        {
            if(std::isdigit(line[i]))
            {
                number = line[i] - '0';
                index = i;
                break;
            }
        }
        return std::make_pair(number, index);
    }

    int day01::evaluate_part1(const std::string& line)
    {
        int left = find_most_left(line).first;
        int right = find_most_right(line).first;
        int line_sum = (left * 10) + right;

        return line_sum;
    }

    int day01::evaluate_part2(const std::string& line)
    {
        // Storage for found numbers with its index in a line.
        std::unordered_map<int, int> found_words;

        // add only most left and most right digits to found words
        std::pair<int, int> most_left = find_most_left(line);
        std::pair<int, int> most_right = find_most_right(line);

        found_words[most_left.second] = most_left.first;
        found_words[most_right.second] = most_right.first;

        for(const std::string& number : number_words)
        {
            size_t index = line.find(number);
            while(index != std::string::npos)
            {
                // find out index of found word to get digit
                auto iterator = std::find(number_words.begin(), number_words.end(), number);
                int digit = std::distance(number_words.begin(), iterator) + 1;
                found_words[index] = digit;

                index = line.find(number, index + 1);
            }
        }

        auto min = std::min_element(found_words.begin(), found_words.end());
        auto max = std::max_element(found_words.begin(), found_words.end());

        return min->second * 10 + max->second;
    }

    void day01::read_file(const std::string& file_name)
    {
        std::ifstream file (file_name);
        std::string line;
        if(file.is_open())
        {
            while(std::getline(file, line))
            {

                result_part1 += evaluate_part1(line);
                result_part2 += evaluate_part2(line);
            }
        }
        else
        {
            std::cerr << "Error occurred while reading file" << std::endl;
        }

        file.close();
    }

}
