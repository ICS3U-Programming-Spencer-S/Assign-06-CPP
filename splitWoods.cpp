// Copyright (c) 2022 All rights reserved.
// .
// Created by: Spencer S
// Date : Dec 18, 2022
// A program which uses lists and without functions
// to round a decimal number

#include <iostream>
#include <string>
#include <vector>

// function definition
std::vector<std::string> split_words(std::string input_strs) {
    // splits the the list
    std::vector<std::string> words;
    // declaring variables
    int start = 0;
    int end = 0;
    while ((end = input_strs.find(" ", start)) != std::string::npos) {
        words.push_back(input_strs.substr(start, end - start));
        start = end + 1;
    }
    words.push_back(input_strs.substr(start));

    // creates an empty list for later
    std::vector<std::string> odd_words;

    // for loop to run though until it's out of words
    for (int i = 0; i < words.size(); i++) {
        // to determine if a word is odd
        if (i % 2 == 0) {
            // moves to fix array
            odd_words.push_back(words[i]);
        }
    }

    // returns to the main function
    return odd_words;
}

int main() {
    // intro text
    std::cout <<
    "This is a program which accepts a line of strings" << std::endl;
    std::cout << "before finding the odd words in the line" << std::endl;
    std::cout << "" << std::endl;

    // obtains user input
    std::cout << "Enter a line of words: ";
    std::string input_raw;
    std::getline(std::cin, input_raw);

    // strips the above input for only words
    std::string input_strs = input_raw;

    // calls the above function into use
    std::vector<std::string> odd_words = split_words(input_strs);
    // check to see if no words were inputted
    if (odd_words.empty()) {
        std::cout <<
        "You inputted zero words, press enter to continue." << std::endl;
        std::cin.ignore();
        // end correct output
    } else {
        std::cout << "The odd words are:";
        for (const auto& word : odd_words) {
            std::cout << " " << word;
        }
        std::cout << std::endl;
    }
    // restart message
    std::cout << "Would you like to restart? (y/n): ";
    char answer;
    std::cin >> answer;
    std::cin.ignore();
    while (answer == 'y') {
        main();
        std::cout << "Would you like to restart? (y/n): ";
        std::cin >> answer;
        std::cin.ignore();
    }

    return 0;
}
