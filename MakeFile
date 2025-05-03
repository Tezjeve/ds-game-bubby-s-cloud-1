# Makefile voor devkitPro-project
TARGET = mygame
OBJS = main.o
CXXFLAGS = -g -O2 -Wall -I$(DEVKITPRO)/libnds/include
LDFLAGS = -L$(DEVKITPRO)/libnds/lib -lnds -lnds9 -lm

$(TARGET).nds: $(OBJS)
    $(CXX) -o $(TARGET).nds $(OBJS) $(LDFLAGS)

main.o: main.cpp
    $(CXX) -c main.cpp $(CXXFLAGS)

clean:
    rm -f $(TARGET).nds $(OBJS)
