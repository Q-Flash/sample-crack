//https://stackoverflow.com/questions/6934232/is-there-a-simple-c-or-c-function-that-calculates-the-sha1-hash-of-a-string


//Compile as
//g++ sha1.cpp -o sha1 -lcrypto
//https://stackoverflow.com/questions/22988320/undefined-reference-to-sha1-at-line#22988369

#ifndef MY_SIMPLE_SHA1_HASH_FUNCTION
#define MY_SIMPLE_SHA1_HASH_FUNCTION

#include <openssl/sha.h>
#include <sstream>
#include <iomanip>
using namespace std;

string hashString(string str)
{  
  unsigned char hashed_str[SHA_DIGEST_LENGTH]; // == 20
  stringstream ssout;
  string output;

 
  SHA1(reinterpret_cast<const unsigned char*>(str.c_str()), 
       str.size(), hashed_str);

  ssout<<setfill('0');

  for(auto i = 0U; i < SHA_DIGEST_LENGTH; i++)
     ssout<<hex<<setw(2)<<static_cast<int>(hashed_str[i]);

  ssout>>output;

  return output;
}

#endif
