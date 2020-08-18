output: pruebas.o
	g++ -o -std=c++17 -Wall pruebas.o -o output

pruebas.o: pruebas.cpp
	g++ -c -std=c++17 -Wall pruebas.cpp

KDTree.o: KDTree.h KDTree.cpp
	g++ -c -std=c++17 -Wall KDTree.h

point.o: point.h point.cpp
	g++ -c -std=c++17 -Wall point.h

# output2: prueba.o burrito.o 
# 	g++ -o -std=c++17 -Wall prueba.o burrito.o -o output2

# main.o: prueba.cpp
# 	g++ -c -std=c++17 -Wall prueba.cpp

# burrito.o: burrito.cpp burrito.h
# 	g++ -c -std=c++17 -Wall burrito.cpp

clean:
	rm *.o