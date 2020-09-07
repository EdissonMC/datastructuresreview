output: priorityqueue3.o
	g++ -o -std=c++17 -Wall priorityqueue3.o -o output

priorityqueue3.o: priorityqueue3.cpp
	g++ -c -std=c++17 -Wall priorityqueue3.cpp

prueba.o: prueba.h prueba.cpp
	g++ -c -std=c++17 -Wall prueba.cpp
	
point.o: point.h point.cpp
	g++ -c -std=c++17 -Wall point.cpp

# output2: prueba.o burrito.o 
# 	g++ -o -std=c++17 -Wall prueba.o burrito.o -o output2

# main.o: prueba.cppl
# 	g++ -c -std=c++17 -Wall prueba.cpp

# burrito.o: burrito.cpp burrito.h
# 	g++ -c -std=c++17 -Wall burrito.cpp

clean:
	rm *.o