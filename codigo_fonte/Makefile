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


FLAGS1 = -O3 -Wall 
FLAGS2 = `pkg-config --cflags --libs opencv4`

# Executa as targets libed e myapps
all: clean libed cleanapps myapps

# Compila bibliotecas do projeto
libed: $(OBJETOS)/display_image.o $(OBJETOS)/escreve_no_arquivo.o $(OBJETOS)/ler_o_arquivo.o
	ar -rcs $(LIB)/libed.a $(OBJETOS)/*.o	
# Compila o arquivo main
myapps: $(BINARIOS)/main

# Template que compila as bibliotecas libed
$(OBJETOS)/%.o: $(SOURCE)/%.cpp $(HEADERS)/%.h
	g++ $(FLAGS1) -c $< -I $(HEADERS) -o $@ $(FLAGS2)

# Template que roda o executável
$(BINARIOS)/%: $(APPS)/%.cpp
	g++ $(FLAGS1) $< -led -L $(LIB) -I $(HEADERS) -o $@ $(FLAGS2)

# Após a compilação, roda o executável
run:
	cd bin && ./main

# Limpa as pastas /bin e /obj
clean:
	rm -rf $(BINARIOS)/* $(OBJETOS)/* $(LIB)/*

cleanapps:
	rm -rf $(BINARIOS)/* 	

