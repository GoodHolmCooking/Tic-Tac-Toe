#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <ctime>

std::map<std::string, std::string> marked = {
    {"1A", " "},
    {"1B", " "},
    {"1C", " "},
    {"2A", " "},
    {"2B", " "},
    {"2C", " "},
    {"3A", " "},
    {"3B", " "},
    {"3C", " "}
};

void mark_x(std::string space) {
   marked[space] = "X";
}

void mark_o(std::string space) {
   marked[space] = "O";
}

void build_board() {
    std::string header_row = "   A | B | C \n\n";
    std::string divider = "  -----------\n";


    std::string row_one_a;
    row_one_a = "1) " + marked["1A"] + " ";

    std::string row_one_b;
    row_one_b = "| " + marked["1B"] + " |";

    std::string row_one_c;
    row_one_c = " " + marked["1C"] + " \n";
    std::string row_one = row_one_a + row_one_b + row_one_c;


    std::string row_two_a;
    row_two_a = "2) " + marked["2A"] + " ";

    std::string row_two_b;
    row_two_b = "| " + marked["2B"] + " |";

    std::string row_two_c;
    row_two_c = " " + marked["2C"] + " \n";
    std::string row_two = row_two_a + row_two_b + row_two_c;


    std::string row_three_a;
    row_three_a = "3) " + marked["3A"] + " ";

    std::string row_three_b;
    row_three_b = "| " + marked["3B"] + " |";

    std::string row_three_c;
    row_three_c = " " + marked["3C"] + " \n";
    std::string row_three = row_three_a + row_three_b + row_three_c;

    std::string board = header_row + row_one + divider + row_two + divider + row_three;

    std::cout << board << std::endl;
}

bool player_won() {
    // First column
    if ((marked["1A"] == "X") &&
        (marked["2A"] == "X") &&
        (marked["3A"] == "X")) 
    {
        return true;
    }

    // Second column
    else if ((marked["1B"] == "X") &&
        (marked["2B"] == "X") &&
        (marked["3B"] == "X"))
    {
        return true;
    }

    // Third column
    else if ((marked["1C"] == "X") &&
        (marked["2C"] == "X") &&
        (marked["3C"] == "X"))
    {
        return true;
    }

    // First row
    else if ((marked["1A"] == "X") &&
        (marked["1B"] == "X") &&
        (marked["1C"] == "X"))
    {
        return true;
    }

    // Second row
    else if ((marked["2A"] == "X") &&
        (marked["2B"] == "X") &&
        (marked["2C"] == "X"))
    {
        return true;
    }

    // Third row
    else if ((marked["3A"] == "X") &&
        (marked["3B"] == "X") &&
        (marked["3C"] == "X"))
    {
        return true;
    }

    // Left to right diagonal
    else if ((marked["1A"] == "X") &&
        (marked["2B"] == "X") &&
        (marked["3C"] == "X"))
    {
        return true;
    }

    // Right to left diagonal
    else if ((marked["3A"] == "X") &&
        (marked["2B"] == "X") &&
        (marked["1C"] == "X"))
    {
        return true;
    }
}

bool player_lost() {
    // First column
    if ((marked["1A"] == "O") &&
        (marked["2A"] == "O") &&
        (marked["3A"] == "O"))
    {
        return true;
    }

    // Second column
    else if ((marked["1B"] == "O") &&
        (marked["2B"] == "O") &&
        (marked["3B"] == "O"))
    {
        return true;
    }

    // Third column
    else if ((marked["1C"] == "O") &&
        (marked["2C"] == "O") &&
        (marked["3C"] == "O"))
    {
        return true;
    }

    // First row
    else if ((marked["1A"] == "O") &&
        (marked["2A"] == "O") &&
        (marked["3A"] == "O"))
    {
        return true;
    }

    // Second row
    else if ((marked["1B"] == "O") &&
        (marked["2B"] == "O") &&
        (marked["3B"] == "O"))
    {
        return true;
    }

    // Third row
    else if ((marked["1C"] == "O") &&
        (marked["2C"] == "O") &&
        (marked["3C"] == "O"))
    {
        return true;
    }

    // Left to right diagonal
    else if ((marked["1A"] == "O") &&
        (marked["2B"] == "O") &&
        (marked["3C"] == "O"))
    {
        return true;
    }

    // Right to left diagonal
    else if ((marked["3A"] == "O") &&
        (marked["2B"] == "O") &&
        (marked["1C"] == "O"))
    {
        return true;
    }
}

std::tuple<bool, std::string> block_victory(std::string space_one, std::string space_two, std::string space_three) {
    std::string victory[3] = { space_one, space_two, space_three };
    for (std::string victory_space : victory) {

        // Check each element in a victory sequence
        if (marked[victory_space] == " ") {
            for (std::string occupied_space : victory) {
                int sequence_count = 0;

                // Look at every other element, so 2A + 2B if looking at 1A.
                if (occupied_space != victory_space) {

                    // If the space is an X, increase the count.
                    if (marked[occupied_space] == "X") {
                        sequence_count += 1;
                    }
                }

                // Sequence count of 2 means 2 spaces counted, block or player will get victory next turn.
                if (sequence_count == 2) {
                    std::tuple<bool, std::string> blocker(true, victory_space);
                    return blocker;
                }
                else {
                    std::tuple<bool, std::string> nothing(false, "");
                    return nothing;
                }
            }
        }
    }
}

int main()
{
    std::string space;

    build_board();
    bool game_in_play = true;

    std::cout << "Let's play a game of Tic-Tac-Toe." << std::endl;
    std::cout << "To play, enter a row and column designation." << std::endl;
    std::cout << "To enter a mark in the top left corner, you would enter 1A." << std::endl;
    std::cout << "Enter a space to mark..." << std::endl;

    

    while (game_in_play) {
        std::cin >> space;
        // Allow for toupper if you have time.

        // Check if the input is a viable key
        if (marked.find(space) != marked.end()) {
            // Input is a viable key

            if (marked[space] == " ") {
                mark_x(space);
                build_board();
           
                if (player_won()) {
                    std::cout << "You won!" << std::endl;
                    game_in_play = false;
                }
                else if (player_lost()) {
                    std::cout << "You lost :(" << std::endl;
                    game_in_play = false;
                }
                else {
                    // game takes a turn
                    std::cout << "Game is taking a turn..." << std::endl;
                    
                    // check if a block is needed to prevent player victory
                    std::string selected_space = "";

                    // column A
                    if (selected_space.empty()) {
                        std::tuple<bool, std::string> block_check(block_victory("1A", "2A", "3A"));
                        if (std::get<0>(block_check)) {
                            selected_space = std::get<1>(block_check);
                        }
                    }

                    // column B
                    if (selected_space.empty()) {
                        std::tuple<bool, std::string> block_check(block_victory("1B", "2B", "3B"));
                        if (std::get<0>(block_check)) {
                            selected_space = std::get<1>(block_check);
                        }
                    }


                    // column C
                    if (selected_space.empty()) {
                        std::tuple<bool, std::string> block_check(block_victory("1C", "2C", "3C"));
                        if (std::get<0>(block_check)) {
                            selected_space = std::get<1>(block_check);
                        }
                    }

                    // row 1
                    if (selected_space.empty()) {
                        std::tuple<bool, std::string> block_check(block_victory("1A", "1B", "1C"));
                        if (std::get<0>(block_check)) {
                            selected_space = std::get<1>(block_check);
                        }
                    }

                    // row 2
                    if (selected_space.empty()) {
                        std::tuple<bool, std::string> block_check(block_victory("2A", "2B", "2C"));
                        if (std::get<0>(block_check)) {
                            selected_space = std::get<1>(block_check);
                        }
                    }

                    // row 3
                    if (selected_space.empty()) {
                        std::tuple<bool, std::string> block_check(block_victory("3A", "3B", "3C"));
                        if (std::get<0>(block_check)) {
                            selected_space = std::get<1>(block_check);
                        }
                    }

                    // down diagonal
                    if (selected_space.empty()) {
                        std::tuple<bool, std::string> block_check(block_victory("1A", "2B", "3C"));
                        if (std::get<0>(block_check)) {
                            selected_space = std::get<1>(block_check);
                        }
                    }

                    // upward diagonal
                    if (selected_space.empty()) {
                        std::tuple<bool, std::string> block_check(block_victory("3A", "2B", "1C"));
                        if (std::get<0>(block_check)) {
                            selected_space = std::get<1>(block_check);
                        }
                    }

                    // if victory is not imminent, select a random space from the spaces still available.
                    std::string available_spaces[9] = { "1A", "1B", "1C", "2A", "2B", "2C", "3A", "3B", "3C" };
                    std::vector<std::string> viable_spaces;
                    int num_of_spaces = 0;

                    for (std::string available_space : available_spaces) {
                        if (marked[available_space] == " ") {
                            viable_spaces.push_back(available_space);
                            num_of_spaces += 1;
                        }
                    }
                    
                    srand(time(0));
                    int rand_space = rand() % num_of_spaces;
                    selected_space = viable_spaces[rand_space];

                    mark_o(selected_space);
                    build_board();
                    std::cout << "Enter a space to mark..." << std::endl;
                }

            }
            else {
                std::cout << "Space already marked. Please choose a different space." << std::endl;
            }
        }
        else {
            std::cout << "Please enter a viable space." << std::endl;
        }


    }
    system("pause>0");
}