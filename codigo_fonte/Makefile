# arquivo Makefile que auxilia na criação e organização 
#pastas para programação em C e C++ para distribuições Linux. 
# Observação: O arquivo main.c, bem como os arquivos de cabeçalho 
#são meramente para fins de exemplificar o funcionamento do Makefile

HEADERS 	= ./headers
SOURCE  	= ./source
BINARIOS	= ./bin
OBJETOS 	= ./obj
APPS    	= ./app
LIB         = ./lib


FLAGS = -O3 -Wall 

# Executa as targets libed e myapps
all: libed cleanapps myapps

# Compila bibliotecas do projeto
libed: $(OBJETOS)/soma.o $(OBJETOS)/sub.o $(OBJETOS)/mult.o $(OBJETOS)/div.o
	ar -rcs $(LIB)/libed.a $(OBJETOS)/*.o
	
# Compila o arquivo main
myapps: $(BINARIOS)/main

# Template que compila as bibliotecas libed
$(OBJETOS)/%.o: $(SOURCE)/%.c $(HEADERS)/%.h
	gcc $(FLAGS) -c $< -I $(HEADERS) -o $@

# Template que roda o executável
$(BINARIOS)/%: $(APPS)/%.c 
	gcc $(FLAGS) $< -led -L $(LIB) -I $(HEADERS) -o $@

# Após a compilação, roda o executável
run:
	$(BINARIOS)/main

# Limpa as pastas /bin e /obj
clean:
	rm -rf $(BINARIOS)/* $(OBJETOS)/* $(LIB)/*

cleanapps:
	rm -rf $(BINARIOS)/* 	

