.PHONY: compile
		
compile:	main.o vendingMachine.o
			g++ main.cpp vendingMachine.o -o vendingMachine
##after compile run following command
## run: ./vendingMachine dimes dimes quarter ...... etc

.PHONY: clean
## clean:	Removes all generated files.
clean:
	$(RM) *.[adios] *.ii test.exe