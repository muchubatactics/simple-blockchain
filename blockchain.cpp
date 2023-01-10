#include "blockchain.h"

blockchain::blockchain(std::string genesisBlockData)
{
    Genesis = new block("0", genesisBlockData, 0);
    chain.push_back(Genesis);
}

blockchain::~blockchain()
{
    for(int i = 0; i < chain.size(); i++)
    {
        if(chain[i])
        {
            delete chain[i];
        }
    }
    chain.clear();
}

void blockchain::createBlock(std::string data)
{
    block *ptr = new block(chain.back()->getHash(),data, chain.back()->getProof());
    chain.push_back(ptr);
}

bool blockchain::isChainValid()
{
    for(int i = 0; i < chain.size(); i++)
    {
        if(i == 0)
        {
            if(chain[i]->getHash().substr(0, 4) != "0000")
            {
                return false;
            }
        }
        else
        {
            if(chain[i]->getHash().substr(0, 4) != "0000")
            {
                return false;
            }
            if(chain[i]->getPreviousHash() != chain[i-1]->hashBlock())
            {
                return false;
            }
        }

    }
    return true;
}

void blockchain::printChain()
{
    for(block*a : chain)
    {
        a->printBlock();
        std::cout << "\n\n\n";
    }
}