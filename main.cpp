#include "blockchain.h"

int main()
{
	blockchain BlockChain("m");
	std::string x[] = {
		"a",
		"s",
		"m",
		"j",
		"s",
		"w",
		"v",
		"e",
		"h"
	};
	for(int i = 0; i < 9; i++)
	{
		BlockChain.createBlock(x[i]);
	}
	if(BlockChain.isChainValid())
	{
		BlockChain.printChain();
	}
}

