#Note that make with no arguments executes the first rule in the file.

LDFLAGS=-pthread

LOCALIDIR=./include
_LOCALDEPS=graphTest.h 
LOCALDEPS=$(patsubst %, $(LOCALIDIR)/%,$(_LOCALDEPS))

IDIR=../graphs/include
_DEPS=graph.h
DEPS=$(patsubst %, $(IDIR)/%,$(_DEPS))

TESTIDIR=../googletest/googletest/include/

ODIR=obj
SOURCE=./source

_OBJ=graphTest.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))
LIBS=/usr/local/lib/libgtest.a

CFLAGS= -std=c++14 -I$(IDIR) -I$(LOCALIDIR) -I$(TESTIDIR) -Wall -pedantic -g

$(ODIR)/%.o: $(SOURCE)/%.cpp $(DEPS) $(LOCALDEPS) 
	@mkdir -p $(ODIR)
	$(CXX) -c -o $@ $< $(CFLAGS)
 
graphtest: $(OBJ)
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)

info: 
	@echo 'LOCALDEPS is: "$(LOCALDEPS)"'
	@echo 'DEPS is: "$(DEPS)"'
	@echo 'OBJ is: "$(OBJ)"'

clean:
	rm -rf $(ODIR)
