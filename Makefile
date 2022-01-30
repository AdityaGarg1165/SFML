all:	compile link

compile:
		g++ src -I src/include -c src/*.cpp

link:
	g++ *.o -o main -L src/lib -O3 -l sfml-window -l sfml-audio -l sfml-graphics -l sfml-system -mwindows && start main.exe