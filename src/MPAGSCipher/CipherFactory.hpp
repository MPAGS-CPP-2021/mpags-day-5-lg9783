#ifndef CIPHERFACTORY_HPP
#define CIPHERFACTORY_HPP

#include <memory>
#include "Cipher.hpp"
#include "CipherType.hpp"

/// add docs 

std::unique_ptr<Cipher> cipherFactory(const CipherType type, const std::string& key);

#endif