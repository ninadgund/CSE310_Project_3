
SRCDIR = .
#SOURCES = $(SRCDIR)/main.cpp #$(SRCDIR)/util.cpp $(SRCDIR)/maxheap.cpp $(SRCDIR)/ratio.cpp $(SRCDIR)/hashtable.cpp $(SRCDIR)/bstmgr.cpp
SOURCES =  ./main.cpp ./AdjNode.cpp ./Graph.cpp ./GraphManager.cpp ./Node.cpp ./util.cpp ./FloydWarshall.cpp ./DFS.cpp ./Stack.cpp ./StackNode.cpp

all : gp

gp : $(SOURCES)
	g++ -o gp $(SOURCES)

# g++ -o gp ./main.cpp ./AdjNode.cpp ./Graph.cpp ./GraphManager.cpp ./Node.cpp ./util.cpp ./FloydWarshall.cpp ./DFS.cpp ./Stack.cpp ./StackNode.cpp
