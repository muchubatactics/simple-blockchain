#include <vector>
#include "block.h"

class blockchain
{
public:
	blockchain(std::string genesisBlockData);
	~blockchain();
	void createBlock(std::string data);
	bool isChainValid();
	void printChain();
private:
	std::vector<block*> chain;
	block* Genesis;
};