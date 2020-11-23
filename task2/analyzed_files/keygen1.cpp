#include <iostream>
#include <string>

int main () {
    std::cout << "Home task 1. Keygen\nInput username: ";
    std::string username;
    std::cin >> username;

    std::string output;
    int length = username.size();
    int counter = 0;
    for (int i = 0; i < length; i++) {
        char current = username[i];
        int res = ((i + 0x11) * length * 0xff + current) % 0x4b + 0x30;
        output += static_cast<char>(res);
    }
    std::cout << "Password: " << output << "\n";
}
