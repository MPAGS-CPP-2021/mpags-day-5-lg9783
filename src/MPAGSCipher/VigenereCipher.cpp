#include "VigenereCipher.hpp"
#include <algorithm>
#include <string>
#include <iostream>
#include "Alphabet.hpp"

VigenereCipher::VigenereCipher(const std::string& key)
{
    this->setKey(key);
}

void VigenereCipher::setKey(const std::string& key)
{
    // Store the key
    key_ = key;

    // Make sure the key is uppercase
    std::transform(std::begin(key_), std::end(key_), std::begin(key_),
        ::toupper);

    // Remove non-alphabet characters
    key_.erase(std::remove_if(std::begin(key_), std::end(key_),
        [](char c) { return !std::isalpha(c); }),
        std::end(key_));

    // Check if the key is empty and replace with default if so
    if(key_.length() ==0)
    {
        key_ = "KEY";
        std::cerr << "Warning: default key used" << std::endl;
    };

    // loop over the key

    for (const char & val: key_)
    {
    // Check letter is not already in the map
    if (charLookup_.find(val)!=charLookup_.end()){ continue;}

    // Find the letter position in the alphabet
    size_t pos {Alphabet::alphabet.find(val)};

    // Create a CaesarCipher using this position as a key
    CaesarCipher cCipher(pos);

    // Insert a std::pair of the letter and CaesarCipher into the lookup
    charLookup_.insert(std::make_pair(val, cCipher));

    }
}

std::string VigenereCipher::applyCipher(const std::string& inputText,
                                        const CipherMode cipherMode) const
{
    std::string outputText{""};
    size_t keyLength{key_.length()};

    // For each letter in input:
    for (std::size_t i{0}; i < inputText.size(); i ++) 
    {
        // Find the corresponding letter in the key, repeating/truncating as required
        size_t key_ind{i%keyLength};
        char key_val{key_[key_ind]};

        // Find the Caesar cipher from the lookup
        CaesarCipher cCipher{charLookup_.at(key_val)};

        // Run the (de)encryption
        // Add the result to the output
        outputText+=cCipher.applyCipher(std::string(1, inputText[i]), cipherMode);

    }

    return outputText;
}