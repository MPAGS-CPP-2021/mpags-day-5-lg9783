#ifndef CIPHER_HPP
#define CIPHER_HPP

#include <string>
#include "CipherMode.hpp"
/**
 * \file Cipher.hpp
 * \brief Contains the declaration of the Cipher class
 */

/**
 * \class Cipher
 * \brief Encrypt or decrypt text using a cipher with the given key
 */

class Cipher {
    public:

    // Defaults
    Cipher() = default;
    Cipher(const Cipher& rhs) = default;
    Cipher(Cipher&& rhs) = default;
    Cipher& operator=(const Cipher& rhs) = default;
    Cipher& operator=(Cipher&& rhs) = default;
    virtual ~Cipher() = default;

    /**
     * \brief Apply the cipher to the provided text
     *
     * \param inputText the text to encrypt or decrypt
     * \param cipherMode whether to encrypt or decrypt the input text
     * \return the result of applying the cipher to the input text
     */
    virtual std::string applyCipher( const std::string& inputText,
    const CipherMode mode ) const = 0;

};

#endif