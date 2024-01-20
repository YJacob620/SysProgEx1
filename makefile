# variables
C_FILES_BASE = auxiliaryFunctions.c basicClassification.c
O_FILES_BASE = auxiliaryFunctions.o basicClassification.o

# .o files
$(O_FILES_BASE): $(C_FILES_BASE)
	gcc -Wall -c $(C_FILES_BASE)

advancedClassificationLoop.o: advancedClassificationLoop.c
	gcc -Wall -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c
	gcc -Wall -c advancedClassificationRecursion.c

# libraries
loops: libclassloops.a # static loop

libclassloops.a: $(O_FILES_BASE) advancedClassificationLoop.o
	ar -r libclassloops.a $(O_FILES_BASE) advancedClassificationLoop.o

recursives: libclassrec.a # static recursive

libclassrec.a: $(O_FILES_BASE) advancedClassificationRecursion.o 
	ar -r libclassrec.a $(O_FILES_BASE) advancedClassificationRecursion.o

loopd: libclassloops.so # dynamic loop

libclassloops.so: $(O_FILES_BASE) advancedClassificationLoop.o 
	gcc -Wall -fPIC -shared $(O_FILES_BASE) advancedClassificationLoop.o -o libclassloops.so

recursived: libclassrec.so # dynamic recursive

libclassrec.so: $(O_FILES_BASE) advancedClassificationRecursion.o 
	gcc -Wall -fPIC -shared $(O_FILES_BASE) advancedClassificationRecursion.c -o libclassrec.so

# executables
mains: main.o libclassrec.a # static recursive
	gcc -Wall main.o -l:libclassrec.a -L. -o mains

maindloop: main.o libclassloops.so # dynamic loop
	gcc -Wall main.o -L. -l:libclassloops.so -o maindloop -Wl,-rpath,.

maindrec: main.o libclassrec.so # dynamic recursive
	gcc -Wall main.o -L. -l:libclassrec.so -o maindrec -Wl,-rpath,.

main.o: main.c
	gcc -Wall -c main.c

# general commands
all : $(O_FILES_BASE) advancedClassificationLoop.o advancedClassificationRecursion.o libclassloops.a libclassrec.a libclassloops.so libclassrec.so

clean:
	rm -f *.o *.a *.so maind* mains
