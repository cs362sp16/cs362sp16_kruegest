CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player

unitTest1:
	gcc -fprofile-arcs -ftest-coverage  dominion.c unittest1.c rngs.c -o unittest1 -lm -g

unitTest2:
	gcc -fprofile-arcs -ftest-coverage  dominion.c unittest2.c rngs.c -o unittest2 -lm -g

unitTest3:
	gcc -fprofile-arcs -ftest-coverage  dominion.c unittest3.c rngs.c -o unittest3 -lm -g

unitTest4:
	gcc -fprofile-arcs -ftest-coverage  dominion.c unittest4.c rngs.c -o unittest4 -lm -g

cardTest1:
	gcc -fprofile-arcs -ftest-coverage  dominion.c cardTest1.c rngs.c -o cardtest1 -lm -g

cardTest2:
	gcc -fprofile-arcs -ftest-coverage  dominion.c cardTest2.c rngs.c -o cardtest2 -lm -g

cardTest3:
	gcc -fprofile-arcs -ftest-coverage  dominion.c cardTest3.c rngs.c -o cardtest3 -lm -g

cardTest4:
	gcc -fprofile-arcs -ftest-coverage  dominion.c cardTest4.c rngs.c -o cardtest4 -lm -g


unittestresults.out: unitTest1 unitTest2 unitTest3 unitTest4  cardTest1 cardTest2 cardTest3 cardTest4 dominion.c dominion.h rngs.o -lm
	./unittest1 >> unittestresults.out 
	./unittest2 >> unittestresults.out 
	./unittest3 >> unittestresults.out 
	./unittest4 >> unittestresults.out
	./cardtest1 >> unittestresults.out 
	./cardtest2 >> unittestresults.out 
	./cardtest3 >> unittestresults.out 
	./cardtest4 >> unittestresults.out 
	gcov dominion.c >> unittestresults.out 


clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
 