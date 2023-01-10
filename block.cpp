#include "block.h"

int block::numberOfBlocks = 0;

block::block(std::string previoushash, std::string data, int previousProof) : data(data), previoushash(previoushash), previousProof(previousProof)
{
    index = ++numberOfBlocks;
    this->mineBlock();
    time_t now = time(0);
    timestamp = ctime(&now);
}

block::~block()
{
    numberOfBlocks--;
}

void block::setProof(int x)
{
    proof = x;
}

void block::setHash(std::string x)
{
    hash = x;
}
void block::mineBlock()
{
    std::string hashh;
    int proof = 1;
    bool check = true;
    while(check)
    {
        std::string str = std::to_string(std::pow((proof - previousProof), 2)) + std::to_string(index) + data;
        unsigned char hash[SHA256_DIGEST_LENGTH];

        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, str.c_str(), str.size());
        SHA256_Final(hash, &sha256);

        std::stringstream ss;

        for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        {
            ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
        }
        
        hashh = ss.str();
        if(hashh.substr(0,4) == "0000")
        {
            check = false;
        }
        else
        {
            proof++;
        }
    }
    this->setHash(hashh);
    this->setProof(proof);
}

std::string block::hashBlock()
{
    std::string str = std::to_string(std::pow((this->proof - previousProof), 2)) + std::to_string(index) + data;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }        
    return ss.str();
}

void block::printBlock()
{
    std::cout << "Index: " <<this->getIndex() << std::endl;
	std::cout << "Nounce: " <<this->getProof() << std::endl;
	std::cout << "Time Stamp: " <<this->getTimeStamp();
	std::cout << "Data: " <<this->getData() << std::endl;
	std::cout << "Previous Hash: " <<this->getPreviousHash() << std::endl;
	std::cout << "Hash: " <<this->getHash() << std::endl;
}