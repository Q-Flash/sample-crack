#include <iostream>
#include "modules.hpp"

using namespace std;

int main()
{
  for (auto pwd: crackPasswords()) 
    cout<<pwd<<endl;//output the passwords that have been cracked
}
