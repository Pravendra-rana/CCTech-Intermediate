.PHONY: all
all: compile
			./currencyConverter

compile:   	main.o currencyConverter.o
			g++ main.cpp currencyConverter.o -o currencyConverter

.PHONY: clean
clean:
	$(RM) *.[adios] *.ii 