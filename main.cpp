#include "biblio.h"

int main() {
    std::vector<Carte*> test;

    test.push_back(new Energie("Test", "description de folie", 0));

    return 0;
}
