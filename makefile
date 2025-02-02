# Variáveis
CXX       = g++
CXXFLAGS  = -Wall -std=c++17 -I./include  # Adiciona o diretório include

# Diretórios
SRC_DIR     = src
OBJ_DIR     = obj
INCLUDE_DIR = include

# Arquivos
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
EXEC = program.exe

.PHONY: all clean

all: $(EXEC)

# Regra para compilar o executável a partir dos arquivos objeto
$(EXEC): $(OBJS)
	@echo Compilando o executável...
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar arquivos .cpp em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo Compilando $<...
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para garantir que o diretório de objetos exista
$(OBJ_DIR):
	@echo Criando diretório $(OBJ_DIR)...
	if not exist "$(OBJ_DIR)" mkdir "$(OBJ_DIR)"

# Regra para limpar os arquivos objeto e o executável
clean:
	@echo Limpando arquivos...
	if exist "$(OBJ_DIR)\*.o" del /q "$(OBJ_DIR)\*.o"
	if exist "$(EXEC)" del /q "$(EXEC)"
