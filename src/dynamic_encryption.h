#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "sha256.h"
#include <string>
#include <chrono>
#include <sys/time.h>
#include <cstring>
//auto millisec_since_epoch = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

/*
 * @return returns the timestamp of the encryption
 */
std::string encrypt(std::istream&in, std::ostream&out, std::string secret_key);

/*
 * @return returns the timestamp of the encryption
 */
void decrypt(std::ifstream&in, std::ofstream&out, std::string secret_key, std::string timestamp);