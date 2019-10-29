OBJ = sqlite3databases.o
TARGET = sqlite3databases
CXX = g++
APPFLAGS= -std=c++11
#//预处理使用的选项
#CFLAGS +=-lsqlite3
#编译的时候使用的选项
LDFLAGS+=-lsqlite3
#链接库使用的选项

$(TARGET):$(OBJ)   #自定义变量引用时使用$(OBJ)
	    $(CXX) $(OBJ)  -o $(TARGET) $(LDFLAGS)


%.o:%.cpp   #%.o %.cpp 自动匹配终极目标TARGET的依赖
	$(CXX)  -c $< $(APPFLAGS) -o $@

# $<:规则中的第一个依赖sqlite3databases.o ->sqlite3databases.cpp
# $@规则中的目标文件:%.o sqlite3databases.o
# $^规则中的所有依赖

.PHONY:clean
clean:
	rm $(OBJ) $(TARGET) -f
