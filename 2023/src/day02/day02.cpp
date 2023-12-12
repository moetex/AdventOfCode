#include "../advent_of_code_23.hpp"

namespace aoc_23
{
    void day02::run()
    {
        read_file("../../src/day02/input.txt");
        std::cout << "result for day 2: " << std::endl;
        std::cout << "result of part 1: " << result_part1 << std::endl;
        std::cout << "result of part 2: " << result_part2 << std::endl;
        std::cout << std::endl;
    }

    void day02::read_file(const std::string &file_name)
    {
        std::ifstream file(file_name);
        std::string line;

        if (file.is_open())
        {
            while (std::getline(file, line))
            {
                result_part1 += determine_part1_result(line);
                result_part2 += determine_part2_result(line);
            }
        }
        else
        {
            std::cerr << "Error occurred while reading file" << std::endl;
        }
        file.close();


    }

    int day02::determine_game_id(const std::string &line)
    {
        // search for game id
        std::regex game_id_regex("(\\d+):");
        std::smatch matches;
        std::regex_search(line, matches, game_id_regex);

        return stoi(matches[1].str());
    }

    int day02::determine_part1_result(const std::string &line)
    {
        int game_id = determine_game_id(line);

        // pattern for numbers of each cube color
        std::regex pattern("(\\d+)\\s+(red|green|blue)");
        std::sregex_iterator iterator(line.begin(), line.end(), pattern);
        std::sregex_iterator end;

        bool valid = false;

        while (iterator != end)
        {
            std::smatch matches2 = *iterator;
            std::string number = matches2[1].str();
            std::string color = matches2[2].str();

            int found_number = stoi(number);

            bool valid_red = color == "red" && found_number <= MAX_RED;
            bool valid_blue = color == "blue" && found_number <= MAX_BLUE;
            bool valid_green = color == "green" && found_number <= MAX_GREEN;

            if (valid_red || valid_blue || valid_green)
            {
                valid = true;
            }
            else
            {
                valid = false;
                break;
            }
            ++iterator;
        }
        if (valid)
            return game_id;
        else
            return 0;
    }

    int day02::determine_part2_result(const std::string &line)
    {

        // pattern for numbers of each cube color
        std::regex pattern("(\\d+)\\s+(red|green|blue)");
        std::sregex_iterator iterator(line.begin(), line.end(), pattern);
        std::sregex_iterator end;

        std::vector<int> red_cubes;
        std::vector<int> green_cubes;
        std::vector<int> blue_cubes;

        while (iterator != end)
        {
            std::smatch matches = *iterator;
            std::string number = matches[1].str();
            std::string color = matches[2].str();

            int found_number = stoi(number);


            if(color == "red")
                red_cubes.push_back(found_number);
            if(color == "green")
                green_cubes.push_back(found_number);
            if(color == "blue")
                blue_cubes.push_back(found_number);

            ++iterator;
        }

        int max_read = *std::max_element(red_cubes.begin(), red_cubes.end());
        int max_green = *std::max_element(green_cubes.begin(), green_cubes.end());
        int max_blue = *std::max_element(blue_cubes.begin(), blue_cubes.end());

        return max_read * max_green * max_blue;

    }

}