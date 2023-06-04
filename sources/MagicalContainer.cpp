#include "MagicalContainer.hpp"

using namespace std;

bool isPrime(int num) {
    if (num <= 1)
        return false;
    
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    
    return true;
}



namespace ariel {

    // MagicalContainer

    void MagicalContainer::addElement(int element) {
        // elements.push_back(element);
    }

    void MagicalContainer::removeElement(int element) {
        // elements.erase(remove(elements.begin(), elements.end(), element), elements.end());
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

    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        // TODO: Implement the increment operator
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        // TODO: Implement the equality operator
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        // TODO: Implement the inequality operator
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        // TODO: Implement the greater than operator
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        // TODO: Implement the less than operator
        return false;
    }

    int MagicalContainer::AscendingIterator::operator*() const {
        // TODO: Implement the dereference operator
        return 0;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::begin(){
        return *this;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::end() {
        return *this;
    }

    // SideCrossIterator

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& cont)
        : container(cont), crossIterator(cont.crossElements.begin()) , index(0){}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
    : container(other.container), crossIterator(other.crossIterator), index(other.index){}

    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        // TODO: Implement the increment operator
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        // TODO: Implement the equality operator
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        // TODO: Implement the inequality operator
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        // TODO: Implement the greater than operator
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        // TODO: Implement the less than operator
        return false;
    }

    int MagicalContainer::SideCrossIterator::operator*() const {
        // TODO: Implement the dereference operator
        return 0;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator:: begin(){
        return *this;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator:: end() {
        return *this;
    }

    // PrimeIterator

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& cont)
        : container(cont), primeIterator(cont.primeElements.begin()), index(0) {}


    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other)
    : container(other.container), primeIterator(other.primeIterator), index(other.index) {}

    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        // TODO: Implement the increment operator
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        // TODO: Implement the equality operator
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        // TODO: Implement the inequality operator
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        // TODO: Implement the greater than operator
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        // TODO: Implement the less than operator
        return false;
    }

    int MagicalContainer::PrimeIterator::operator*() const {
        // TODO: Implement the dereference operator
        return 0;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator:: begin(){
        return *this;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator:: end(){
        return *this;
    }
} 


