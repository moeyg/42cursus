#include "StreamEditor.hpp"

StreamEditor::StreamEditor(const std::string& filename, const std::string& s1, const std::string& s2)
    : filename(filename), s1(s1), s2(s2) { }

StreamEditor::~StreamEditor(void) { }

bool    StreamEditor::processFile()
{
    std::ifstream inputFileStream;
    std::ofstream outputFileStream;

    if (!openFiles(inputFileStream, outputFileStream)) { return false; }

    int s1Length = s1.length();
    int s2Length = s2.length();

    while (true)
    {
        std::string target;
        std::getline(inputFileStream, target);

        size_t index = 0;
        while (true)
        {
            index = target.find(s1, index);
            if (index == std::string::npos) { break; }
            target.erase(index, s1Length);
            target.insert(index, s2);
            index += s2Length;
        }

        outputFileStream << target;
        if (inputFileStream.eof()) { break; }
        outputFileStream << std::endl;
    }

    inputFileStream.close();
    outputFileStream.close();

    return true;
}

bool    StreamEditor::openFiles(std::ifstream& inputFileStream, std::ofstream& outputFileStream)
{
    inputFileStream.open(filename);
    if (inputFileStream.fail())
    {
        std::cerr << RED << "Error: Failed to open the input file: " << filename << RESET << std::endl;
        return false;
    }

    std::string outputFile = filename + ".replace";
    outputFileStream.open(outputFile);
    if (outputFileStream.fail())
    {
        std::cerr << RED << "Error: Failed to open the output file: " << outputFile << RESET << std::endl;
        inputFileStream.close();
        return false;
    }

    std::cout << YELLOW << "Complete: Replaced with input string." << RESET << std::endl;

    return true;
}