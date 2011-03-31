OBJECTS=so_example.o main.o variables.o
.SUFFIXES: .F90

FC=ifort

FLAGS=-g -c
 
#.F90.o:
#	$(FC) -c $<

main: $(OBJECTS)
	$(FC) $(OBJECTS) -g -o main


so_example.o: so_example.F90 variables.o
	$(FC) $(FLAGS) so_example.F90
variables.o: variables.F90
	$(FC) $(FLAGS) variables.F90
main.o: main.F90
	ifort $(FLAGS) main.F90

clean:
	rm main $(OBJECTS) \
	so_example.mod variables.mod
