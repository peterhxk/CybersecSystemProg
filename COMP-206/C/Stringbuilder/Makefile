minicalc : minicalc.c
        gcc -Wall -o minicalc minicalc.c -lm

stringbuilder: stringbuilder.c
        gcc -Wall -o stringbuilder stringbuilder.c

.PHONY : test
test : run-tests minicalc
        ./run-tests
