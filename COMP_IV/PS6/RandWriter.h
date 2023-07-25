// Copyright 2022 Matthew Lorette Anaya
#ifndef RANDWRITER_H 
#define RANDWRITER_H  

#include <iostream>
#include <string>
#include <map>
#include <exception>
#include <utility>
#include <random>

class RandWriter {
 private:
 
    int rw_k;            
    std::string rw_txt;  
    std::map<std::string, std::map<char, int>> rw_table;
    
 public:

    RandWriter(std::string text, int k);

    int orderK() const;
    int freq(std::string kgram) const;
    int freq(std::string kgram, char c) const;

    std::string getText() const;
    std::string generate(std::string kgram, int L) const;
    
    std::map<std::string, std::map<char, int>> get_table() const;

    char kRand(std::string kgram) const;

    friend std::ostream& operator<<(std::ostream& out, const RandWriter&
    rw);

};
#endif   