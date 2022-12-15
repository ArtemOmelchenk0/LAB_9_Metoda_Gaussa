all :
	gcc -Wall --pedantic src/*.c -o bin/gauss

test1 : all
	bin/gauss dane/A dane/b

test2 : all
	bin/gauss dane/A_ dane/b_

test3 : all
	bin/gauss dane/A_2 dane/b_2

