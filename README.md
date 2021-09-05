# dynamic_encrypt

Pre-requisite: g++ (c++11), make.

## Install 

Pre-requisite: g++ (c++11), make.
```
sudo apt-get install g++ make
cd <REPLACE THIS TO REPO PATH>
make && cd build
#binary is named dencrypt
```

## Usage

### Encryption
```
./dencrypt -e <secret> <input file> <output file>
```
Please store your secret and the timestamp somewhere secret and secure

### Decryption

```
./dencrypt -d <secret> <input file> <output file> <timestamp>
```
Use both the secret and timestamp to decrypt

