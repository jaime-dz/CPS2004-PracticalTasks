#ifndef PERSISTENCE
#define PERSISTENCE
#include <vector>
#include <fstream>
#include "product.h"

std::vector<Product*> restore(std::ifstream& in);

#endif