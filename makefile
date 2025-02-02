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
TXT_FILES = $(wildcard *.txt)  # Encontra todos os arquivos .txt no diretório atual

# Regra padrão: compilar o executável e mover os arquivos .txt
all: $(EXEC) | $(DATA_DIR)
	@echo "Compilando o executável..."
	$(EXEC)
	$(MAKE) move_txt

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar arquivos .cpp em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "Compilando $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Garantir que o diretório obj exista
$(OBJ_DIR):
	@echo "Criando diretório $(OBJ_DIR)..."
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

# Garantir que o diretório data exista
$(DATA_DIR):
	@echo "Criando diretório $(DATA_DIR)..."
	if not exist $(DATA_DIR) mkdir $(DATA_DIR)

# Regra para mover arquivos .txt para o diretório data
move_txt: $(TXT_FILES) | $(DATA_DIR)
	@echo "Movendo arquivos .txt para o diretório $(DATA_DIR)..."
	move $(TXT_FILES) $(DATA_DIR)\

# Regra para limpar os arquivos de objeto, o executável e o diretório data
clean:
	@echo "Limpando arquivos..."
	@if exist $(OBJ_DIR) rd /s /q $(OBJ_DIR) || true
	@if exist $(EXEC) del /q $(EXEC)
	@if exist $(OBJ_DIR) del /q $(OBJ_DIR)\*.o
	@if exist $(DATA_DIR) rd /s /q $(DATA_DIR) || true

.PHONY: all clean move_txt
