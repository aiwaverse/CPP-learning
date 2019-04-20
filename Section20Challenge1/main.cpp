// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

bool is_palindrome(const std::string& s) {
    std::deque<char> string_1{};
    for (auto letter : s) {
        if (isalnum(letter))
            string_1.push_front(tolower(letter));
    }
	std::deque<char> string_2{};
    for (auto letter : s) {
        if (isalnum(letter))
            string_2.push_back(tolower(letter));
    }
	if(string_1 == string_2)
		return true;
	else
		return false;	
    /*for (size_t i{0}; i < ceil(deque_string.size() / 2); ++i) {
        if (deque_string.at(i) != deque_string.at(deque_string.size() - 1 - i))
            return false;
    }
    return true;*/
}

int main() {
    std::vector<std::string> test_strings{"a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
                                          "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
                                          "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome"};

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result"
              << "String" << std::endl;
    for (const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}