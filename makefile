# Variáveis
CXX = g++
CXXFLAGS = -Wall -std=c++17 -I./include  # Adiciona o diretório include

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include  # Diretório de cabeçalhos
DATA_DIR = data  # Diretório de dados

# Arquivos
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
EXEC = program.exe

# Regra padrão: compilar o executável
all: $(EXEC) | $(DATA_DIR)

$(EXEC): $(OBJS)
	@echo "Compilando o executável..."
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar arquivos .cpp em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "Compilando $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Garantir que o diretório obj exista
$(OBJ_DIR):
	@echo "Criando diretório $(OBJ_DIR)..."
	mkdir $(OBJ_DIR)

# Garantir que o diretório data exista
$(DATA_DIR):
	@echo "Criando diretório $(DATA_DIR)..."
	mkdir $(DATA_DIR)

# Regra para limpar os arquivos de objeto e o executável
clean:
	@echo "Limpando arquivos..."
	@if exist $(OBJ_DIR) rd /s /q $(OBJ_DIR) || true
	@if exist $(EXEC) del /q $(EXEC)
	@if exist $(OBJ_DIR) del /q $(OBJ_DIR)\*.o

.PHONY: all clean
