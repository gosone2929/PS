#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int main() {
    std::string main_str = "To be or not to be";
    std::string sub_str = "not";

    if (main_str.find(sub_str) != std::string::npos) {
        std::cout << "Substring found at index: " << main_str.find(sub_str) << std::endl;
    } else {
        std::cout << "Substring not found." << std::endl;
    }

    // Checking for a single character also works
    if (main_str.find('T') != string::npos) {
        std::cout << "Character 'T' found." << std::endl;
    }

    return 0;
}