#ifndef __STREAMEDITOR_HPP__
#define __STREAMEDITOR_HPP__

#include <iostream>
#include <fstream>
#include <string>

#define RED    "\033[0;31m"
#define YELLOW "\033[0;33m"
#define RESET  "\033[0m"

class StreamEditor
{
private:
    std::string filename;
    std::string s1;
    std::string s2;

    bool    openFile(std::ifstream& inputFileStream, std::ofstream& outputFileStream);

public:
    StreamEditor(const std::string& filename, const std::string& s1, const std::string& s2);
    ~StreamEditor(void);
    bool    processFile(void);
};

#endif
