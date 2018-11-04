BIN  = ./dist
SRC  = ./src
INC  = ./include


compile: 
	gcc $(SRC)/memoryManagement.c -o $(BIN)/memoryManagement
	gcc $(SRC)/memoryManagementPointers.c -o $(BIN)/memoryManagementPointers
	gcc $(SRC)/memoryManagementMalloc.c -o $(BIN)/memoryManagementMalloc
	
run:
	./$(BIN)/memoryManagement
	./$(BIN)/memoryManagementMalloc
	./$(BIN)/memoryManagementPointers


clean: 
	rm ./$(BIN)/*.exe




