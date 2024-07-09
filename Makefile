FLAGS = -g -Wall -pedantic 
OBJECT = source/main.o source/gestao.o source/astronauta.o source/voo.o

all: gestao

compile: ${OBJECT}
	g++ ${OBJECT} -o gestao

run:
	./gestao

source/main.o: main.cpp gestao.hpp
	g++ ${FLAGS} -c main.cpp -o source/main.o

source/gestao.o: gestao.cpp gestao.hpp astronauta.hpp
	g++ ${FLAGS} -c gestao.cpp -o source/gestao.o

source/astronauta.o: astronauta.cpp astronauta.hpp
	g++ ${FLAGS} -c astronauta.cpp -o source/astronauta.o

source/voo.o: voo.cpp voo.hpp
	g++ ${FLAGS} -c voo.cpp -o source/voo.o
	
