all:
	gcc ls.c -o ls
	gcc mkdir.c -o mkdir
	gcc cat.c -o cat
	gcc date.c -o date
	gcc rm.c -o rm
	gcc shell.c -lreadline
	./a.out

clear:
	rm -f ls mkdir cat date rm a.out