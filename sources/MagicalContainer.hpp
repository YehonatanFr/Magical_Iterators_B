#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <vector>
#include <algorithm>



// namespace ariel
namespace ariel {

    class MagicalContainer {
    private:
        std::vector<int> mainElements;
        std::vector<int> ascElement;
        std::vector<int> crossElements;
        std::vector<int> primeElements;

    public:
        MagicalContainer() = default; 
        ~MagicalContainer() = default; 

        void addElement(int element);
        void removeElement(int element);
        int size() const;
        std::vector<int> getElements() const;

        MagicalContainer(const MagicalContainer& other) = default;
        MagicalContainer& operator=(const MagicalContainer& other) = default;
        MagicalContainer(MagicalContainer&& other) = default;
        MagicalContainer& operator=(MagicalContainer&& other) = default;

        class AscendingIterator {
        private:
            MagicalContainer& container;
            std::vector<int>::iterator ascIterator;
            size_t index;

        public:
            AscendingIterator(MagicalContainer& cont);
            AscendingIterator(const AscendingIterator& other);
            ~AscendingIterator() = default;

            AscendingIterator& operator=(const AscendingIterator& other) = delete;
            AscendingIterator(AscendingIterator&& other) = default;
            AscendingIterator& operator=(AscendingIterator&& other) = delete;

            AscendingIterator& operator++();

            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            bool operator>(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;

            int operator*() const;

            AscendingIterator &begin();
            AscendingIterator &end();
        };

        class SideCrossIterator {
        private:
            MagicalContainer& container;
            std::vector<int>::iterator crossIterator;
            size_t index;
            bool forward;

        public:
            SideCrossIterator(MagicalContainer& cont);
            SideCrossIterator(const SideCrossIterator& other);
            ~SideCrossIterator() = default;

            SideCrossIterator& operator=(const SideCrossIterator& other) = delete;
            SideCrossIterator(SideCrossIterator&& other) = default;
            SideCrossIterator& operator=(SideCrossIterator&& other) = delete;

            SideCrossIterator& operator++();

            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            bool operator>(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;

            int operator*() const;

            SideCrossIterator &begin();
            SideCrossIterator &end();
        };

        class PrimeIterator {
        private:
            MagicalContainer& container;
            std::vector<int>::iterator primeIterator;
            size_t index;

        public:
            PrimeIterator(MagicalContainer& cont);
            PrimeIterator(const PrimeIterator& other);
            ~PrimeIterator() = default;

            PrimeIterator& operator=(const PrimeIterator& other) = delete;
            PrimeIterator(PrimeIterator&& other) = default;
            PrimeIterator& operator=(PrimeIterator&& other) = delete;

            PrimeIterator& operator++();
            
            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;
            
            int operator*() const;

            PrimeIterator &begin();
            PrimeIterator &end();
        };

    };

} 


#endif
