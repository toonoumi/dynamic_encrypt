/*********************************************************************
* Filename:   dynamic_encryption
* Author: Xingyu
* Copyright:  MIT
* Disclaimer: This code is presented "as is" without any guarantees.
* Details:    Use it to encrypt and decrypt your files. Feel free to 
			  use the idea, or components in your project.
*********************************************************************/

#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "sha256.h"
#include <string>
#include <chrono>
#include <sys/time.h>
#include <cstring>

/*
 * @return returns the timestamp of the encryption
 */
std::string encrypt(std::istream&in, std::ostream&out, std::string secret_key);

/*
 * @return returns the timestamp of the encryption
 */
void decrypt(std::ifstream&in, std::ofstream&out, std::string secret_key, std::string timestamp);