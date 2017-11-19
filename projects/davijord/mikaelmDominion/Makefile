CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)

randomtest: randomtestcard1.c randomtestadventurer.c dominion.o rngs.o randomtestcard2.c
	echo "Running random test for Adventurer, Smithy, Remodel." > randomtestresults.out
	echo "Adventurer test" >> randomtestresults.out
	./randomtestadventurer >> randomtestresults.out
	gcov -ab dominion.c >> randomtestresults.out
	cat dominion.c.gcov > randomtestadventurer.out
	echo "Remodel test" >> randomtestresults.out
	./randomtestcard2 >> randomtestresults.out
	gcov -ab dominion.c >> randomtestresults.out
	cat dominion.c.gcov > randomtestcard2.out
	echo "Smithy test" >> randomtestresults.out
	./randomtestcard1 >> randomtestresults.out
	gcov -ab dominion.c >> randomtestresults.out
	cat dominion.c.gcov > randomtestcard1.out
	cat randomtestresults.out

testAdventurer: testAdventurer.c dominion.o rngs.o
	gcc -o testAdventurer -g testAdventurer.c dominion.o rngs.o $(CFLAGS)

testSmithy: testSmithy.c dominion.o rngs.o
	gcc -o testSmithy -g testSmithy.c dominion.o rngs.o $(CFLAGS)

testRemodel: testRemodel.c dominion.o rngs.o
	gcc -o testRemodel -g testRemodel.c dominion.o rngs.o $(CFLAGS)

UnitTest: testAdventurer.c testSmithy.c testRemodel.c dominion.o rngs.o
	echo "Running unit tests for Adventurer, Smithy, Remodel." > unittestresults.out
	echo "Adventurer test" >> unittestresults.out
	./testAdventurer >> unittestresults.out
	gcov -ab dominion.c >> unittestresults.out
	#cat dominion.c.gcov >> unittestresults.out
	echo "Remodel test" >> unittestresults.out
	./testRemodel >> unittestresults.out
	gcov -ab dominion.c >> unittestresults.out
	#cat dominion.c.gcov >> unittestresults.out
	echo "Smithy test" >> unittestresults.out
	./testSmithy >> unittestresults.out
	gcov -ab dominion.c >> unittestresults.out
	#cat dominion.c.gcov >> unittestresults.out
	cat unittestresults.out	

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
