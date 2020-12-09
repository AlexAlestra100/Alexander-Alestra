radii: lab5.o find_two_radii.o
		gcc lab5.o find_two_radii.o -o radii -lm
lab5.o: lab5.c lab5.h
		gcc -c lab5.c
find_two_radii.o: find_two_radii.c lab5.h
		gcc -c find_two_radii.c
