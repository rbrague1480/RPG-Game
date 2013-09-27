run: rpg
	./rpg

rpg: game.o vector.o display.o  main.cpp texture.o 
	g++ -g main.cpp game.o vector.o display.o texture.o -o rpg -framework OpenGL -framework GLUT -lpng
	
game.o: game.cpp game.h
	g++ -g -c game.cpp

vector.o: vector.cpp vector.h
	g++ -g -c vector.cpp

display.o: display.cpp display.h
	g++ -g -c display.cpp

texture.o: texture.cpp texture.h
	g++ -g -c texture.cpp

clean:
	rm test *.o