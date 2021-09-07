all:
	mkdir -p build
	g++ -o build/fdencrypt src/dencrypt_file.cpp src/dynamic_encryption.cpp \
		src/logger.c src/sha256.c -O3 -w
	