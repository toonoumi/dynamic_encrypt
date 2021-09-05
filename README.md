# dynamic_encrypt

This program is designed to dynamically encrypt a file. It uses a key of your choice and a timestamp to encrypt your file. This program is not designed for keeping the data absolutely secret (it is still fairly safe), but more for against automatic detection. 

Remeber, keep the secret and timestamp secure.

## Install 

### Linux (Debian)
Pre-requisite: g++ (c++11), make.
clone the repo, then
```
sudo apt-get install g++ make
cd <REPLACE THIS WITH REPO PATH>
make && cd build
#binary is named dencrypt
```

## Usage

### Encryption
```
./dencrypt -e <secret text> <input file path> <output file path>
```
Please store your secret and the timestamp somewhere secret and secure

### Decryption

```
./dencrypt -d <secret text> <input file path> <output file path> <timestamp>
```
Use both the secret and timestamp to decrypt

## Disclaimer

This is a free software comes with absolutely no warranty. 

The author is not reponsible for any data lost related with this software.


