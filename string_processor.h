#ifndef STRING_PROCESSOR_H
#define STRING_PROCESSOR_H

#include <string>
#include <vector>
#include <map>

class StringProcessor {
public:
    // Questão 1: Lê o arquivo até encontrar linha com 7 pontos
    std::string readUntilSevenDots(const std::string& filename);
    
    // Questão 2: Encontra todas as ocorrências de P em T
    std::vector<int> findAllOccurrences(const std::string& T, const std::string& P);
    
    // Questão 3: Análise de caracteres
    struct CharacterAnalysis {
        int digits;
        int vowels;
        int consonants;
    };
    CharacterAnalysis analyzeCharacters(const std::string& T);
    std::string toLowerCase(const std::string& T);
    
    // Questão 4: Tokenização e ordenação
    std::vector<std::string> tokenize(const std::string& T);
    std::string findSmallestToken(const std::string& T);
    
    // Questão 5: Palavra mais frequente
    std::vector<std::string> findMostFrequentWords(const std::string& T);
    
    // Questão 6: Contar caracteres da última linha
    int countLastLineCharacters(const std::string& filename);

private:
    bool isVowel(char c);
    bool isConsonant(char c);
};

#endif 