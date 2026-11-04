#include "product.h"
#include "electronics.h"
#include "persistence.h"
#include "grocery.h"
#include "clothing.h"
#include "book.h"
#include "toy.h"
#include <sstream>
#include <string>

std::vector<Product*> restore(std::ifstream& in)
{
    std::vector<Product*> collection;
    std::string line;

    while(std::getline(in, line))
    {
        if(line.empty()) continue;

        std::stringstream ss(line);
        std::string typeID;
        std::getline(ss, typeID, '|');

        if(typeID=="GROCERY")
        {
            collection.push_back(Grocery::restoreFromStream(ss));
        }
        else if(typeID=="ELECTRONICS")
        {
            collection.push_back(Electronics::restoreFromStream(ss));
        }
        else if(typeID=="CLOTHING")
        {
            collection.push_back(Clothing::restoreFromStream(ss));
        }
        else if(typeID=="BOOK")
        {
            collection.push_back(Book::restoreFromStream(ss));
        }
        else if(typeID=="TOY")
        {
            collection.push_back(Toy::restoreFromStream(ss));
        }
    }
    return collection;
}