CXX = g++
CXXFLAGS = -std=c++11 -Wall -I include -g

SRCS = Sed.cpp Evenement.cpp Arrivee.cpp Depart.cpp Banque.cpp Caissier.cpp FileAttente.cpp Client.cpp Simulation.cpp

OBJS = $(SRCS:.cpp=.o)

EXEC = Simulation

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

doc:
	doxygen Doxyfile

clean:
	rm -f $(OBJS) $(EXEC)

clean_doc:
	rm -R html latex
