# Specify the target executables
TARGET1 = server.out
TARGET2 = client.out

# Specify the C++ compiler
CXX = g++

# Specify the C++ compiler flags
CXXFLAGS = -std=c++11 -O2 -pthread

# list the object files that are dependent on
SRCS1 = ServerClass.cpp DefaultIO.o SocketIO.o CLI.o ClientData.o Command.o UploadCommand.o SettingCommand.o ClassifyDataCommand.o DisplayResultCommand.o DownloadResultCommand.o Can.o Cheb.o Distance.o Euc.o DataSetsHandler.o Knn.o Man.o Minikovski.o
SRCS2 = Client.cpp DefaultIO.o SocketIO.o ClientCommand.o ClassifyDataClientCommand.o DisplayResultClientCommand.o UploadClientCommand.o SettingClientCommand.o DownloadResultClientCommand.o

# Specify the object files for each target
OBJS1 = $(SRCS1:.cpp=.o)
OBJS2 = $(SRCS2:.cpp=.o)

# Default target
all: $(TARGET1) $(TARGET2)

# Build the first target executable
$(TARGET1): $(OBJS1)
	$(CXX) $(CXXFLAGS) $(OBJS1) -o $(TARGET1)

# Build the second target executable
$(TARGET2): $(OBJS2)
	$(CXX) $(CXXFLAGS) $(OBJS2) -o $(TARGET2)

# Compile the source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(TARGET1) $(TARGET2) $(OBJS1) $(OBJS2)

