#include "MagicalContainer.hpp"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

bool isPrime(int num) {
    if (num <= 1)
        return false;
    else if(num == 2)
        return true;
    else {
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0)
                return false;
        }
    }

    return true;
}



namespace ariel {

    // MagicalContainer

    void MagicalContainer::addAscElem(){
        ascElement.clear();
        for (auto it = mainElements.begin(); it != mainElements.end(); ++it)
        {
            ascElement.push_back(&(*it));
        }

        sort(ascElement.begin(), ascElement.end(), [](int* a, int* b) {return *a < *b;});
    }

    void MagicalContainer::addCrossElem(){
        crossElements.clear();
        auto start = mainElements.begin();
        auto end = --mainElements.end();

        while(start < end)
        {
            crossElements.push_back(&(*start));
            crossElements.push_back(&(*end));
            start++;
            end--;
        }
        if (start == end)
        {
            crossElements.push_back(&(*start));
        }
    }
    
    void MagicalContainer::addPrimeElem(){
        primeElements.clear();
        for (auto it = mainElements.begin(); it != mainElements.end(); ++it)
        {
            if (isPrime(*it))
            {
                primeElements.push_back(&(*it));
            }
        }
    }

    void MagicalContainer::addElement(int element) {
        if (find(mainElements.begin(), mainElements.end(), element) != mainElements.end()) {
        // Element already exists, do not add it again
            return;
        }

        mainElements.push_back(element);

        addAscElem();

        addCrossElem();

        addPrimeElem();

    }

    void MagicalContainer::removeElement(int elem)
    {
        // Check if elem is in mainElements
        auto it = find(mainElements.begin(), mainElements.end(), elem);
        if (it == mainElements.end())
        {
            throw runtime_error("Invalid argument");
        }

        // Erase the element from mainElements
        mainElements.erase(it);

        addAscElem();

        addCrossElem();

        addPrimeElem();
    }


    int MagicalContainer::size() const {
        return this->mainElements.size();
    }

    vector<int> MagicalContainer::getElements() const{
        return this->mainElements;
    }

    // AscendingIterator

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& cont)
        : container(cont), ascIterator(cont.ascElement.begin()), index(0) {}

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other)
        : container(other.container), ascIterator(other.ascIterator), index(other.index) {}

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        if(ascIterator == container.ascElement.end())
        {
            throw runtime_error("Out of range");
        }
        ++ascIterator;
        ++index;
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        if(&container != &other.container)
        {
            throw invalid_argument("Invalid argument");
        }
        return this->index == other.index;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        if(&container != &other.container) 
        {
            throw invalid_argument("Iterators are pointing at different containers");
        }
        return this->index != other.index;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        if(&container != &other.container) 
        {
            throw invalid_argument("Iterators are pointing at different containers");
        }
        return this->index > other.index;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        if(&container != &other.container) 
        {
            throw invalid_argument("Iterators are pointing at different containers");
        }
        return this->index < other.index;
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other)
    {
        if (&container != &other.container)
        {
            throw runtime_error("Iterators are pointing at different containers");
        }

        ascIterator = other.ascIterator;
        index = other.index;
        return *this;
    }

    int MagicalContainer::AscendingIterator::operator*() const {
        
        if(ascIterator == container.ascElement.end())
        {
            throw out_of_range("Out of range");
        }
        return **ascIterator;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::begin(){
        ascIterator = container.ascElement.begin();
        index = 0;
        return *this;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::end() {
        ascIterator = container.ascElement.end();
        index = container.ascElement.size();
        return *this;
    }

    // SideCrossIterator

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& cont)
        : container(cont), crossIterator(cont.crossElements.begin()), index(0){}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
        : container(other.container), crossIterator(other.crossIterator),
        index(other.index){}


    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        if(crossIterator == container.crossElements.end())
        {
            throw runtime_error("Out of range");
        }
        ++crossIterator;
        ++index;
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        if(&container != &other.container) 
        {
            throw invalid_argument("Iterators are pointing at different containers");
        }
        return this->index == other.index;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        if(&container != &other.container) 
        {
            throw invalid_argument("Iterators are pointing at different containers");
        } 
        return this->index != other.index;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        if(&container != &other.container) 
        {
            throw invalid_argument("Iterators are pointing at different containers");
        }
        return this->index > other.index;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        if(&container != &other.container) 
        {
            throw invalid_argument("Iterators are pointing at different containers");
        }
        return this->index < other.index;
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other)
    {
        if (&container != &other.container)
        {
            throw runtime_error("Iterators are pointing at different containers");
        }

        crossIterator = other.crossIterator;
        return *this;
    }

    int MagicalContainer::SideCrossIterator::operator*() const {
        if(crossIterator == container.crossElements.end())
        {
            throw out_of_range("Out of range");
        }
        return **crossIterator;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator:: begin(){
        crossIterator = container.crossElements.begin();
        index = 0;
        return *this;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator:: end() {
        crossIterator = container.crossElements.end();
        index = container.crossElements.size();
        return *this;
    }

    // PrimeIterator

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& cont)
        : container(cont), primeIterator(cont.primeElements.begin()), index(0) {}


    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other)
    : container(other.container), primeIterator(other.primeIterator), index(other.index) {}

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        if(primeIterator == container.primeElements.end())
        {
            throw runtime_error("Out of range");
        }
        ++primeIterator;
        ++index;
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        if(&container != &other.container) 
        {
            throw invalid_argument("Iterators are pointing at different containers");
        }
        return this->index == other.index;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        if(&container != &other.container) 
        {
            throw invalid_argument("Iterators are pointing at different containers");
        }
        return this ->index != other.index;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        if(&container != &other.container) 
        {
            throw invalid_argument("Iterators are pointing at different containers");
        }    
        return this->index > other.index;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        if(&container != &other.container) 
        {
            throw invalid_argument("Iterators are pointing at different containers");
        }        
        return this->index < other.index;
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other)
    {
        if (&container != &other.container)
        {
            throw runtime_error("Iterators are pointing at different containers");
        }

        primeIterator = other.primeIterator;
        index = other.index;
        return *this;
    }

    int MagicalContainer::PrimeIterator::operator*() const {
        if(primeIterator == container.primeElements.end())
        {
            throw out_of_range("Out of range");
        }
        return **primeIterator;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator:: begin(){
        primeIterator = container.primeElements.begin();
        index = 0;
        return *this;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator:: end(){
        primeIterator = container.primeElements.end();
        index = container.primeElements.size();
        return *this;
    }
} 


