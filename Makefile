CXX = g++
CXXFLAGS = -std=c++11 -Wall -I include

SRCS = Sed.cpp Evenement.cpp Arrivee.cpp Depart.cpp Banque.cpp Caissier.cpp FileAttente.cpp Client.cpp Simulation.cpp

OBJS = $(SRCS:.cpp=.o)

EXEC = Simulation

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
