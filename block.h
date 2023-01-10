#include <string>
#include <iostream>
#include <ctime>
#include <openssl/sha.h>
#include <iomanip>
#include <cmath>
#include <sstream>

class block
{
public:
    block(std::string previoushash, std::string data, int previousProof);
    ~block();
    void mineBlock();
    void setProof(int);
    void setHash(std::string);
    void printBlock();
    std::string hashBlock();

    int getIndex() {return index;}
    int getProof() {return proof;}
    std::string getPreviousHash() {return previoushash;}
    std::string getHash() {return hash;}
    std::string getTimeStamp() {return timestamp;}
    std::string getData() {return data;}
    int getNumberOfBlocks() {return numberOfBlocks;}
    int getPreviousProof() {return previousProof;}

private:
    int previousProof;

    int index;
    int proof;
    std::string previoushash;
    std::string hash;
    std::string timestamp;
    std::string data;
    static int numberOfBlocks;
};
