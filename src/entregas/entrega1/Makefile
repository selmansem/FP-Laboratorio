# ============================================================================
# @file Makefile
#
# @brief Makefile para compilar y ejecutar las entregas de prácticas de FP.
#
# @author Souhaib El Bakali Manout
# @email souhaibem@correo.ugr.es
# @date 2026-01-05
#
# @usage
#   make help   - Muestra todos los targets disponibles
#   make all    - Compila todos los programas
#   make test   - Ejecuta todos los tests
#   make clean  - Elimina los ejecutables generados
#
# ============================================================================

# ============================================================================
# CONFIGURACIÓN
# ============================================================================

CXX      := g++
CXXFLAGS := -Wall -std=c++11

# Directorios de salida
BIN_DIR   := bin
TESTS_DIR := tests

# Colores para output (se desactivan si no hay terminal)
ifneq ($(TERM),)
    GREEN  := \033[0;32m
    YELLOW := \033[0;33m
    CYAN   := \033[0;36m
    NC     := \033[0m
else
    GREEN  :=
    YELLOW :=
    CYAN   :=
    NC     :=
endif

# Modo verbose: make test V=1
ifdef V
    VERBOSE_FLAG := -v
endif

# ============================================================================
# DEFINICIÓN DE ACTIVIDADES
# ============================================================================

# Actividad 1: Proceso de Kaprekar
SRC1      := ENTREGA_1-1_SOUHAIB_EL-BAKALI_MANOUT.cpp
TEST_SRC1 := ENTREGA_1-1_TESTS_SOUHAIB_EL-BAKALI_MANOUT.cpp
EJ1       := $(BIN_DIR)/entrega1_1
TEST_EJ1  := $(TESTS_DIR)/entrega1_1_test
NAME1     := Kaprekar

# Actividad 2: Mayor Palíndromo
SRC2      := ENTREGA_1-2_SOUHAIB_EL-BAKALI_MANOUT.cpp
TEST_SRC2 := ENTREGA_1-2_TESTS_SOUHAIB_EL-BAKALI_MANOUT.cpp
EJ2       := $(BIN_DIR)/entrega1_2
TEST_EJ2  := $(TESTS_DIR)/entrega1_2_test
NAME2     := Palíndromo

# Actividad 3: Tableros de importancia relativa
SRC3      := ENTREGA_1-3_SOUHAIB_EL-BAKALI_MANOUT.cpp
TEST_SRC3 := ENTREGA_1-3_TESTS_SOUHAIB_EL-BAKALI_MANOUT.cpp
EJ3       := $(BIN_DIR)/entrega1_3
TEST_EJ3  := $(TESTS_DIR)/entrega1_3_test
NAME3     := Importancia Relativa

# Lista de todos los ejecutables (para clean)
ALL_EJS   := $(EJ1) $(EJ2) $(EJ3)
ALL_TESTS := $(TEST_EJ1) $(TEST_EJ2) $(TEST_EJ3)

# ============================================================================
# TARGETS PRINCIPALES
# ============================================================================

.PHONY: all test testv clean help list
.PHONY: ej1 ej2 ej3 test1 test2 test3 test1v test2v test3v
.PHONY: run1 run2 run3

# Target por defecto
.DEFAULT_GOAL := help

help list:
	@echo "$(CYAN)═══════════════════════════════════════════════════════════$(NC)"
	@echo "$(CYAN)  Makefile - Fundamentos de Programación                   $(NC)"
	@echo "$(CYAN)═══════════════════════════════════════════════════════════$(NC)"
	@echo ""
	@echo "$(YELLOW)Compilación:$(NC)"
	@echo "  make all       Compila todos los programas"
	@echo "  make ej1       Compila Actividad 1: $(NAME1)"
	@echo "  make ej2       Compila Actividad 2: $(NAME2)"
	@echo "  make ej3       Compila Actividad 3: $(NAME3)"
	@echo ""
	@echo "$(YELLOW)Ejecución:$(NC)"
	@echo "  make run1      Ejecuta Actividad 1"
	@echo "  make run2      Ejecuta Actividad 2"
	@echo "  make run3      Ejecuta Actividad 3"
	@echo ""
	@echo "$(YELLOW)Tests:$(NC)"
	@echo "  make test      Ejecuta todos los tests"
	@echo "  make test1     Tests de Actividad 1"
	@echo "  make test2     Tests de Actividad 2"
	@echo "  make test3     Tests de Actividad 3"
	@echo "  make testv     Todos los tests (verbose)"
	@echo "  make test1v    Tests de Actividad 1 (verbose)"
	@echo "  make test2v    Tests de Actividad 2 (verbose)"
	@echo "  make test3v    Tests de Actividad 3 (verbose)"
	@echo ""
	@echo "$(YELLOW)Otros:$(NC)"
	@echo "  make clean     Elimina ejecutables"
	@echo "  make help      Muestra esta ayuda"
	@echo ""
	@echo "$(YELLOW)Tip:$(NC) Usa V=1 para modo verbose: make test1 V=1"
	@echo ""

# ============================================================================
# COMPILACIÓN
# ============================================================================

# Crear directorios si no existen
$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(TESTS_DIR):
	@mkdir -p $(TESTS_DIR)

all: $(ALL_EJS)
	@echo "$(GREEN)✓ Compilación completa$(NC)"

ej1: $(EJ1)
ej2: $(EJ2)
ej3: $(EJ3)

$(EJ1): $(SRC1) | $(BIN_DIR)
	@echo "$(CYAN)[CC]$(NC) Compilando Actividad 1: $(NAME1)..."
	@$(CXX) $(CXXFLAGS) -o $@ $<
	@echo "$(GREEN)✓ $(EJ1) generado$(NC)"

$(EJ2): $(SRC2) | $(BIN_DIR)
	@echo "$(CYAN)[CC]$(NC) Compilando Actividad 2: $(NAME2)..."
	@$(CXX) $(CXXFLAGS) -o $@ $<
	@echo "$(GREEN)✓ $(EJ2) generado$(NC)"

$(EJ3): $(SRC3) | $(BIN_DIR)
	@echo "$(CYAN)[CC]$(NC) Compilando Actividad 3: $(NAME3)..."
	@$(CXX) $(CXXFLAGS) -o $@ $<
	@echo "$(GREEN)✓ $(EJ3) generado$(NC)"

# ============================================================================
# EJECUCIÓN
# ============================================================================

run1: $(EJ1)
	@./$(EJ1)

run2: $(EJ2)
	@./$(EJ2)

run3: $(EJ3)
	@./$(EJ3)

# ============================================================================
# TESTS
# ============================================================================

test: test1 test2 test3
	@echo ""
	@echo "$(GREEN)✓ Todos los tests ejecutados$(NC)"

testv: test1v test2v test3v
	@echo ""
	@echo "$(GREEN)✓ Todos los tests ejecutados (verbose)$(NC)"

# Compilación de tests
$(TEST_EJ1): $(TEST_SRC1) | $(TESTS_DIR)
	@echo "$(CYAN)[CC]$(NC) Compilando tests Actividad 1..."
	@$(CXX) $(CXXFLAGS) -o $@ $<

$(TEST_EJ2): $(TEST_SRC2) | $(TESTS_DIR)
	@echo "$(CYAN)[CC]$(NC) Compilando tests Actividad 2..."
	@$(CXX) $(CXXFLAGS) -o $@ $<

$(TEST_EJ3): $(TEST_SRC3) | $(TESTS_DIR)
	@echo "$(CYAN)[CC]$(NC) Compilando tests Actividad 3..."
	@$(CXX) $(CXXFLAGS) -o $@ $<

# Ejecución de tests
test1: $(TEST_EJ1)
	@echo ""
	@echo "$(YELLOW)══════════ TESTS ACTIVIDAD 1: $(NAME1) ══════════$(NC)"
	@./$(TEST_EJ1) $(VERBOSE_FLAG)

test2: $(TEST_EJ2)
	@echo ""
	@echo "$(YELLOW)══════════ TESTS ACTIVIDAD 2: $(NAME2) ══════════$(NC)"
	@./$(TEST_EJ2) $(VERBOSE_FLAG)

test3: $(TEST_EJ3)
	@echo ""
	@echo "$(YELLOW)══════════ TESTS ACTIVIDAD 3: $(NAME3) ══════════$(NC)"
	@./$(TEST_EJ3) $(VERBOSE_FLAG)

# Tests verbose (atajos)
test1v: VERBOSE_FLAG := -v
test1v: test1

test2v: VERBOSE_FLAG := -v
test2v: test2

test3v: VERBOSE_FLAG := -v
test3v: test3

# ============================================================================
# LIMPIEZA
# ============================================================================

clean:
	@echo "$(CYAN)[RM]$(NC) Limpiando ejecutables..."
	@rm -rf $(BIN_DIR) $(TESTS_DIR)
	@echo "$(GREEN)✓ Limpieza completada$(NC)"