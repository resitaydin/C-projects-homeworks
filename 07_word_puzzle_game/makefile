all: clean compile run

compile: main.c 
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc main.c -c 
	@gcc main.o 

run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	./a.out
	@echo "Completed tests...."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f *.out
clear:
	@clear

 	
 	
