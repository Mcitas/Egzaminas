#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>
#include <regex>

using std::cout;
using std::cin;
using std::endl;
using std::unordered_map;
using std::ifstream;
using std::ofstream;
using std::string;
using std::getline;
using std::stringstream;
using std::vector;
using std::regex;
using std::smatch;
using std::sregex_iterator;
using std::regex_match;

void count(string eil, unordered_map<string, int>& zodziai, unordered_map<string, vector<int>>& eilutes, int eil_sk);
void WordCount();
void simboliuPasalinimas(string& zodis);
