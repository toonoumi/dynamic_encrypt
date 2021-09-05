all:
	mkdir -p build
	g++ -o build/dencrypt src/*.c src/*.cpp 