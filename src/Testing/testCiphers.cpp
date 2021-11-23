//! Unit Tests for MPAGSCipher Cipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "PlayfairCipher.hpp"
#include "CaesarCipher.hpp"
#include "VigenereCipher.hpp"

bool testCiphers( const Cipher& cipher, const CipherMode mode,
const std::string& inputText, const std::string& outputText){
    return outputText == cipher.applyCipher(inputText, mode);
}

TEST_CASE("Playfair Cipher encryption") {
  PlayfairCipher cc{"hello"};
  REQUIRE(testCiphers(cc,  CipherMode::Encrypt, "BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA") );
}

TEST_CASE("Playfair Cipher decryption") {
  PlayfairCipher cc{"hello"};
  REQUIRE(testCiphers(cc,  CipherMode::Decrypt, "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA", "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ") );
}

TEST_CASE("Caesar Cipher encryption")
{
    CaesarCipher cc{10};
    REQUIRE(testCiphers(cc,  CipherMode::Encrypt,"HELLOWORLD", "ROVVYGYBVN"));
}

TEST_CASE("Caesar Cipher decryption")
{
    CaesarCipher cc{10};
    REQUIRE(testCiphers(cc,  CipherMode::Decrypt,"ROVVYGYBVN", "HELLOWORLD"));
}


TEST_CASE("Vigenere Cipher encryption") {
  VigenereCipher cc{"key"};
  REQUIRE( testCiphers(cc,  CipherMode::Encrypt,"HELLOWORLD","RIJVSUYVJN"));
}

TEST_CASE("Vigenere Cipher decryption") {
  VigenereCipher cc{"key"};
  REQUIRE( testCiphers(cc,  CipherMode::Decrypt,"RIJVSUYVJN", "HELLOWORLD"));
}

