//
// Created by saso on 30/01/2022.
//

#include <vector>
#include "../api/DoubleHashingStrategy.h"

template
class DoubleHashingStrategy<int>;

template<typename T>
DoubleHashingStrategy<T>::DoubleHashingStrategy(int tableSize) : tableSize(tableSize) {
    setSieve();
}

template<typename T>
void DoubleHashingStrategy<T>::setSieve() {
    // Create a boolean array "prime[0..tableSize]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    std::vector<bool> prime(tableSize + 1, true);

    for (int p = 2; p * p <= tableSize; p++) {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p]) {
            for (int i = p * p; i <= tableSize; i += p)
                prime[i] = false;
        }
    }

    for (int i = tableSize; i >= 2; i--)
        if (prime[i]) {
            primeNumber = prime[i];
            return;
        }
}


template<typename T>
int DoubleHashingStrategy<T>::hashCode(T key) {
    return firstHashCode(key);
}

template<typename T>
int DoubleHashingStrategy<T>::firstHashCode(T key) {
    return (key % tableSize);
}

template<typename T>
int DoubleHashingStrategy<T>::rehash(T key, int iterationNo) {
    return (firstHashCode(key) + iterationNo * secondHashCode(key)) % tableSize;
}

template<typename T>
int DoubleHashingStrategy<T>::secondHashCode(T key) {
    return primeNumber - (key % primeNumber);
}




