# Chat v0.1
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude -g
TARGET = chat
SRCDIR = src
INCDIR = include
BUILDDIR = build

# 源文件列表
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

# 确保build目录存在
$(shell mkdir -p $(BUILDDIR))

# 默认目标：编译整个项目
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# 编译规则
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理编译结果
clean:
	rm -rf $(BUILDDIR) $(TARGET)

# 伪目标声明
.PHONY: clean

