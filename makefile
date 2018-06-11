all:		CChat CSouris CAnimal CTerrain CJeu main
		g++ -o main main.o CJeu.o CTerrain.o CAnimal.o CChat.o CSouris.o

CJeu:		CJeu.cpp CJeu.h
		g++ -c CJeu.cpp

CTerrain:	CTerrain.cpp CTerrain.h
		g++ -c CTerrain.cpp

CAnimal:	CAnimal.cpp CAnimal.h
		g++ -c CAnimal.cpp

CChat:		CChat.cpp CChat.h
		g++ -c CChat.cpp

CSouris:	CSouris.cpp CSouris.h
		g++ -c CSouris.cpp

main:		main.cpp
		g++ -c main.cpp

clean:
		rm *.o ; rm main