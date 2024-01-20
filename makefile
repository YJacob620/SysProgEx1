C_FILES_BASE = auxiliaryFunctions.c basicClassification.c
O_FILES_BASE = auxiliaryFunctions.o basicClassification.o

loops: $(O_FILES_BASE) advancedClassificationLoop.o # static loop
	ar -r libclassloops.a $(O_FILES_BASE) advancedClassificationLoop.o

recursives: $(O_FILES_BASE) advancedClassificationRecursion.o # static recursive
	ar -r libclassrec.a $(O_FILES_BASE) advancedClassificationRecursion.o

loopd: $(O_FILES_BASE) advancedClassificationLoop.o # dynamic loop
	gcc -Wall -fPIC -shared $(O_FILES_BASE) advancedClassificationLoop.o -o libclassloops.so

recursived: $(O_FILES_BASE) advancedClassificationRecursion.o # dynamic recursive
	gcc -Wall -fPIC -shared $(O_FILES_BASE) advancedClassificationRecursion.c -o libclassrec.so

$(O_FILES_BASE): $(C_FILES_BASE)
	gcc -Wall -c $(C_FILES_BASE)

advancedClassificationLoop.o: advancedClassificationLoop.c
	gcc -Wall -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c
	gcc -Wall -c advancedClassificationRecursion.c

libclassloops.a:
	make loops

mains: main.c libclassrec.a # static recursive
	gcc -Wall main.c -l:libclassrec.a -L. -o mains

libclassrec.a:
	make recursives

maindloop: main.c libclassloops.so # dynamic loop
	gcc -Wall main.c -L. -l:libclassloops.so -o maindloop -Wl,-rpath,.

libclassloops.so:
	make loopd

maindrec: main.c libclassrec.so # dynamic recursive
	gcc -Wall main.c -L. -l:libclassrec.so -o maindrec -Wl,-rpath,.

libclassrec.so:
	make recursived

all : $(O_FILES_BASE) advancedClassificationLoop.o advancedClassificationRecursion.o libclassloops.a libclassrec.a libclassloops.so libclassrec.so

clean:
	rm -f *.o *.a *.so maind* mains
