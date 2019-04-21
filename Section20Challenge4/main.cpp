// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

bool is_palindrome(const std::string& s) {
    std::stack<char> stack_for_string{};
    std::queue<char> queue_for_string{};
    for (auto c : s) {
        if (isalnum(c)) {
            stack_for_string.push(tolower(c));
            queue_for_string.push(tolower(c));
        }
    }
    while ((not queue_for_string.empty() and not stack_for_string.empty()) and (queue_for_string.front() == stack_for_string.top())) {
        queue_for_string.pop();
        stack_for_string.pop();
    }
    if (stack_for_string.empty() and queue_for_string.empty())
        return true;
    else
        return false;
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