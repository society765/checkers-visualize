all: a.out 
	./a.out 

a.out: *.cpp 
	g++ -std=c++17 *.cpp \
		-I"/usr/local/Cellar/dlib/19.16_1/include" \
		-L"/usr/local/Cellar/dlib/19.16_1/lib" -ldlib -L"." -lcheckers
