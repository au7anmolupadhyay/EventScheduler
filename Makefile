all:
	g++ -o scheduler src/*.cpp -Iinclude -lcurl -pthread

clean:
	rm -f scheduler