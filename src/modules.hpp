#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "hash.hpp"

using namespace std;


bool passwordValid(string hashedpwd, const vector<string>&listOfHashes){
  for (int i = 0; i < static_cast<int>(listOfHashes.size()); i++){
    if (listOfHashes[i] == hashedpwd)
      return true;
  }
      return false;
}


vector<string> crack(int seed, int mean, float std_dev,
                     int passwd_length, int num_guesses,
                     string alphabet, const vector<string>& pwd_hashes)
{
  vector<string> found_passwords = {};//initialize as empty vector
  string guess;

  //Get cracking!!

  mt19937 eng(seed);
  string guessPassword;

  normal_distribution<float>nd(mean, std_dev);

    for (int i = 0; i < num_guesses; i++){
      for (int j = 0; j < passwd_length; j++){
          guessPassword += alphabet[nd(eng)];
      }
      string hashedPassword = hashString(guessPassword);
/*
      for (int i = 0; i < pwd_hashes.size(); i++){
        if (pwd_hashes[i] == hashedPassword)
          found_passwords.push_back(guessPassword);
      }
*/


      if (passwordValid(hashedPassword, pwd_hashes)){
        found_passwords.push_back(guessPassword);
      }



}

  return found_passwords;
}



vector<string> crackPasswords()
{
  int random_seed, mean;
  float sd;
  int passwd_len, num_guesses;
  string alpha;
  vector<string> hashes = {};
  string a_hash;

   //getting configuration data
   cin>>random_seed>>mean>>sd>>passwd_len>>num_guesses>>alpha;


  while(cin >> a_hash)//get hashes
     hashes.push_back(a_hash);

//---verify input----
   cout<<random_seed<<" "<<mean<<" "<<sd<<" "<<
       passwd_len<<" "<<num_guesses<<" "<<alpha<<"\n\n"; //assuming passwords have no spaces

  for (auto i = 0u; i < (10u < hashes.size()?10:hashes.size( )); ++i)
     cout<<hashes[i]<<endl;

  if (hashes.size() > 10)
      cout<<"..."<<endl;


  cout<<endl<<hashes.size()<<" hashes read"<<endl;


  return crack(random_seed, mean, sd, passwd_len, num_guesses, alpha, hashes);
}
