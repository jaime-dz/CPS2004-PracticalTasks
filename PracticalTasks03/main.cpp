#include <iostream>
#include <vector>
#include <fstream>
#include "product.h"
#include "grocery.h"
/*#include "electronics.h"
#include "clothing.h"
#include "book.h"
#include "toy.h"*/
#include "persistence.h"

void clearCollection(std::vector<Product*>& collection)
{
    for(Product* pr:collection)
        delete pr;
    collection.clear();
}

int main()
{
    std::vector<Product*> collection;
    int opt=0;

    do
    {
        std::cout<<"Choose an option\n\n"<<"1. Add Grocery\n"<<"2. Save collection\n"<<"3. Load collection\n"<<"4. Exit\n";
        std::cin>>opt;
        std::cin.ignore();

        if(opt==1)
        {
            std::string name, id, desc, cat;
            double price, weight;
            std::cout<<"Name: ";std::getline(std::cin, name);
            std::cout<<"Price: ";std::cin>>price;std::cin.ignore();
            std::cout<<"ID: ";std::getline(std::cin,id);
            std::cout<<"Description: ";std::getline(std::cin, desc);
            std::cout<<"Category: ";std::getline(std::cin, cat);
            std::cout<<"Weight: ";std::cin>>weight;std::cin.ignore();

            collection.push_back(new Grocery(name, price, id, desc, cat, weight));
            std::cout<<"Product successfully added.\n";
        }
        else if(opt==2)
        {
            std::ofstream outFile("products.txt");
            if(outFile.is_open())
            {
                for(const Product* pr:collection)
                    pr->persist(outFile);
                outFile.close();
                std::cout<<"Collection saved to 'products.txt'.\n";
            }
            else
            {
                std::cerr<<"Failed to open the file.\n";
            }
        }
        else if(opt==3)
        {
            std::ifstream inFile("products.txt");
            if(inFile.is_open())
            {
                clearCollection(collection);
                collection=restore(inFile);
                inFile.close();
                std::cout<<"Collection successfully loaded ("<<collection.size()<<" elements).\n";
            }
            else
            {
                std::cerr<<"Failed to open the file.\n";
            }
        }
    } while (opt!=4);
    
    std::cout<<"COLLECTION: \n";
    for(const Product* pr:collection)
    {
        pr->display();
        std::cout<<std::endl;
    }

    clearCollection(collection);
    return 0;
}