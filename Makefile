CXX=g++
RM=rm -f
CXXFLAGS += -shared -fPIC
SRCS=socket.cpp
OBJS=$(subst .cpp,.o,$(SRCS))	
libserversocket.so: socket.cpp 
	$(CXX) $(CXXFLAGS) socket.cpp -o libserversocket.so
clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) tool
