make all:
	rm -r dist
	mkdir dist
	cd dist

	g++ main.cpp -o dist/main.o -c -g
	
	g++ -o dist/target dist/main.o  -g
