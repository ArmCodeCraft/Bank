CXX = g++  
CXXFLAGS = -std=c++11 -Wall -Wextra -g
LDFLAGS = -pthread

OBJDIR = obj
SRCDIR = src

OBJS = $(OBJDIR)/Bank.o $(OBJDIR)/Client.o

.PHONY: all clean release debug coverage

all: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o bank $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

release: CXXFLAGS += -O2 -DNDEBUG
release: clean all

debug: CXXFLAGS += -DDEBUG
debug: clean all

clean:
	rm -rf $(OBJDIR) bank

