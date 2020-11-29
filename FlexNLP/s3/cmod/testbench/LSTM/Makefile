.PHONY: all clean

all: LSTM.cpp
	g++ -o test -Wall -Wpedantic -std=c++11 LSTM.cpp
	
run:
	./test
data/%.npy: createnpy.py
	mkdir -p data
	python3 createnpy.py

clean:
	rm test
