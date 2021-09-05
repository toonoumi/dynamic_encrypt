/*********************************************************************
* Filename:   main.c
* Author: Xingyu
* Copyright:  MIT
* Disclaimer: This code is presented "as is" without any guarantees.
* Details:    Use it to encrypt and decrypt your files. Feel free to 
			  use the idea, or components in your project.
*********************************************************************/

#include <iostream>
#include <fstream>
#include "dynamic_encryption.h"
#include "logger.h"
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;

int main(int argc, char**argv){
	if(argc < 2){
		cout<<"\033[1;31mUsage: [-e | -d] <secret key> <input file> <output path>\033[0m"<<endl;
		//cout<<"Expecting 4 arguements but got: "<<argc-1<<endl;
		exit(0);
	}else if (strcmp(argv[1],"-h")==0 || strcmp(argv[1],"--help")==0 || strcmp(argv[1],"help")==0){
		cout<<"\033[1;31mUsage: [-e | -d] <secret key> <input file> <output path>\033[0m"<<endl;
		exit(0);
	}else if (strcmp(argv[1],"-e")==0){
		if (argc != 5){
			cout<<"\033[1;31mUsage: [-e | -d] <secret key> <input file> <output path>\033[0m"<<endl;
			cout<<"Expecting 4 arguements but got: "<<argc-1<<endl;
			exit(0);
		}
		//----------------------------encrypt file------------------------------//
		ofstream out (argv[4]);
		ifstream in (argv[3]);
		std::string secret_key = argv[2];

		auto timestamp = encrypt(in, out, secret_key);
		logger("Fetched Timestamp:");
		cout<<timestamp<<endl;

		logger("Closing files...");
		out.close();
		in.close();
		logger("Files closed.");

	}else if (strcmp(argv[1],"-d")==0){
		if (argc != 6){
			cout<<"\033[1;31mUsage: [-e | -d] <secret key> <input file> <output path> <timestamp>\033[0m"<<endl;
			cout<<"Expecting 5 arguements but got: "<<argc-1<<endl;
			exit(0);
		}
		//----------------------------decrypt file------------------------------//
		ofstream out (argv[4]);
		ifstream in (argv[3]);
		std::string secret_key = argv[2];
		std::string timestamp = argv[5];

		decrypt(in, out, secret_key, timestamp);

		logger("Closing files...");
		out.close();
		in.close();
		logger("Files closed.");
	}	

	return 0;
}
