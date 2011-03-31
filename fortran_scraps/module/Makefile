OBJECTS=extra.o main.o
main: $(OBJECTS)
	ifort $(OBJECTS) -o main
extra.o: extra.f
	ifort -c extra.f
main.o: main.f
	ifort -c main.f
clean:
	rm main $(OBJECTS) \
	extra.mod
