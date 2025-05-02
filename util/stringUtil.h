#include <sstream>
#include<vector>
#include <string>

using namespace std;

template <typename T>
bool splitStringToArray(const std::string& input, std::vector<T> &vec, const char spliter)
{
    vec.clear();
    std::stringstream ss(input);
    std::string token;
    while(std::getline(ss, token, spliter)){
        try {
               vec.emplace_back(std::stoi(token));
           } catch (const std::invalid_argument& e) {
                return false;
           } catch (const std::out_of_range& e) {
                return false;
           }
    }
    return true;
}

