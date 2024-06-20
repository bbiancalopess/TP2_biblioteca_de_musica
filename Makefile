# Variáveis do compilador
CXX = g++
CXXFLAGS = -std=c++11 -Iinclude

# Diretórios
INCDIR = include
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Alvo principal
TARGET = $(BINDIR)/music_system

# Lista de arquivos fonte
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Lista de arquivos objeto
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Regras de compilação
all: $(TARGET)

$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CXX) $(OBJECTS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

# Limpeza
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Comando para rodar o programa
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
