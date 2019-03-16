#include "catch.hpp"
#include "../src/hash.hpp"
#include "../src/modules.hpp"
#include <vector>
#include <string>
#include <fstream>


#define PASS_FILE "./data/passwd.hash"

using namespace std;
using strings=vector<string>;


const string alpha0="abcdefghijklmnopqrstuvwxyz";
const string alpha1="jbygmudhnoteaisrlcwfpvkxqz";
const string alpha2="~jbygmudhnoteaisrlcwfpvkxqz~";
const  string alpha3="'|\"<[)`=%^?/#_Q-@Y.UFGCIONMBEAxvwy895kb3d2tnioaers1lm0phu4g67fjzqSRTLPDHKJW!*VZX$,+; ~&\\]:(>{}";
 
vector<string> getPass()
{
  ifstream i{PASS_FILE};
  vector<string> S;
  string s;
 
  if(!i) throw std::iostream::failure("Could not open file " PASS_FILE  " for reading");
    

  while (i>>s) S.push_back(s);

 return S;
}



TEST_CASE("Testing compliance of sha1sum")
{
  REQUIRE(hashString("hello") == "aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d");
  REQUIRE(hashString("")      == "da39a3ee5e6b4b0d3255bfef95601890afd80709");
}



TEST_CASE("⁎ TIER 1 TESTS: Basic ☺  ", "[basic]")
{

 auto hashes = getPass();

  CHECK( crack(101, 12, 2.5,4, 1,alpha0, hashes) == strings{"tonm"}); 
  CHECK( crack(52936, 13, 2.37,7, 8076,alpha2, hashes) == strings{"ninerws"}); 
  CHECK( crack(200, 13, 2.37,3, 100,alpha2, hashes) == strings{"has", "set", "air", 
                                                               "foe", "let", "rat"}); 
}


TEST_CASE("⁑ TIER 2 TESTS: Not as Basic  ☹ ", "[notbasic]")
{

 auto hashes = getPass();

  CHECK( crack(1000, 12, 2.5,4, 0,alpha1, hashes) == strings{}); 
  CHECK( crack(461, 13, 1.8,6, 0, "", hashes) == strings{}); 
}



TEST_CASE("⁂  TIER 3 TESTS: Definitely not Basic  💢 ", "[notnotbasic]")
{

 auto hashes = getPass();

  CHECK( crack(8200, 1, 20015.27,3, 50,"", hashes) == strings{}); 
  CHECK( crack(200, 12, 2.37,5, 10000,alpha2, hashes) == strings{  "asian", "hindi", "teana", "tahir", "cohen", "teeth"}); 
  CHECK( crack(0, 50, 14.89,5, 10000,alpha3, hashes) == strings{"3seth", "!yJ5a", "L1es}", "T0~3M"}); 
}


