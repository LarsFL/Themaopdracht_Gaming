#ifndef RANDOM_NUMBER_HPP
#define RANDOM_NUMBER_HPP

#include <random>

float getRandomNumber(float lower, float upper) {
    std::default_random_engine generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(lower, upper);
    return distribution(generator);
}

#endif // RANDOM_NUMBER_HPP