#include "string_processor.h"
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cctype>

std::string StringProcessor::readUntilSevenDots(const std::string& filename) {
    std::ifstream file(filename);
    std::string result, line;
    
    while (std::getline(file, line)) {
        if (line.substr(0, 7) == ".......") break;
        if (!result.empty()) result += " ";
        result += line;
    }
    
    return result;
}

std::vector<int> StringProcessor::findAllOccurrences(const std::string& T, const std::string& P) {
    std::vector<int> positions;
    size_t pos = T.find(P);
    
    while (pos != std::string::npos) {
        positions.push_back(pos);
        pos = T.find(P, pos + 1);
    }
    
    return positions.empty() ? std::vector<int>{-1} : positions;
}

StringProcessor::CharacterAnalysis StringProcessor::analyzeCharacters(const std::string& T) {
    CharacterAnalysis analysis = {0, 0, 0};
    
    for (char c : T) {
        if (std::isdigit(c)) analysis.digits++;
        else if (isVowel(c)) analysis.vowels++;
        else if (isConsonant(c)) analysis.consonants++;
    }
    
    return analysis;
}

std::string StringProcessor::toLowerCase(const std::string& T) {
    std::string result = T;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

std::vector<std::string> StringProcessor::tokenize(const std::string& T) {
    std::vector<std::string> tokens;
    std::stringstream ss(toLowerCase(T));
    std::string token;
    
    while (ss >> token) {
        // Remove pontos
        token.erase(std::remove(token.begin(), token.end(), '.'), token.end());
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }
    
    std::sort(tokens.begin(), tokens.end());
    return tokens;
}

std::string StringProcessor::findSmallestToken(const std::string& T) {
    auto tokens = tokenize(T);
    return tokens.empty() ? "" : tokens[0];
}

std::vector<std::string> StringProcessor::findMostFrequentWords(const std::string& T) {
    auto tokens = tokenize(T);
    std::map<std::string, int> frequency;
    int maxFreq = 0;
    
    for (const auto& token : tokens) {
        maxFreq = std::max(maxFreq, ++frequency[token]);
    }
    
    std::vector<std::string> mostFrequent;
    for (const auto& pair : frequency) {
        if (pair.second == maxFreq) {
            mostFrequent.push_back(pair.first);
        }
    }
    
    return mostFrequent;
}

int StringProcessor::countLastLineCharacters(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::string lastLine;
    
    bool foundSeven = false;
    while (std::getline(file, line)) {
        if (foundSeven) {
            lastLine = line;
        }
        if (line.substr(0, 7) == ".......") {
            foundSeven = true;
        }
    }
    
    return lastLine.length();
}

bool StringProcessor::isVowel(char c) {
    c = std::tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool StringProcessor::isConsonant(char c) {
    return std::isalpha(c) && !isVowel(c);
} 