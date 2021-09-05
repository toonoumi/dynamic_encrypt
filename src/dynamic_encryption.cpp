#include "dynamic_encryption.h"
#include "logger.h"

void print_hash(const BYTE hash[]){
    logger("Generating hash...");
    for (int i=0;i<32;i++)
        printf("%hx",hash[i]);
    puts("");
    logger("Hash generated.");
}

/*
 * @return returns the timestamp of the encryption
 */
std::string encrypt(std::istream&in, std::ostream&out, std::string secret_key){
    uint64_t millisec_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    auto timestamp = std::to_string(millisec_since_epoch);
    auto combined = secret_key + timestamp;
    SHA256_CTX *hash_gen = new SHA256_CTX;
    sha256_init(hash_gen);
    sha256_update(hash_gen, (BYTE*)combined.c_str(), combined.length());
    BYTE *hash = new BYTE[32];
    sha256_final(hash_gen, hash);

#ifndef PRODUCTION
    print_hash(hash);
    logger("Encrypting file...");
#endif
    while(!in.fail()){
        char b[32]={0}; //BYTE
        int end_index=32;
        in.read(b,32);
        end_index = in.gcount();
        for(int i=0;i<end_index;i++){
            b[i]+=hash[i];
        }
        out.write(b, end_index);
    }
#ifndef PRODUCTION
    logger("File encrypted.");
#endif

    delete hash_gen;
    delete[]hash;
    return timestamp;
}

/*
 * @return returns the timestamp of the encryption
 */
void decrypt(std::ifstream&in, std::ofstream&out, std::string secret_key, std::string timestamp){
    auto combined = secret_key + timestamp;
    SHA256_CTX *hash_gen = new SHA256_CTX;
    sha256_init(hash_gen);
    sha256_update(hash_gen, (BYTE*)combined.c_str(), combined.length());
    BYTE *hash = new BYTE[32];
    sha256_final(hash_gen, hash);

#ifndef PRODUCTION
    print_hash(hash);
    logger("Decrypting file...");
#endif
    while(!in.fail()){
        char b[32]={0}; //BYTE
        int end_index=32;
        in.read(b,32);
        end_index = in.gcount();
        for(int i=0;i<end_index;i++){
            b[i]-=hash[i];
        }
        out.write(b, end_index);
    }
#ifndef PRODUCTION
    logger("File decrypted.");
#endif

    delete hash_gen;
    delete[]hash;
}