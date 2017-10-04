#!/bin/bash
for i in 4 8 16 32 64 128 256 512 1024 2048
do
	./bin/mat_mult_seq $i
	./bin/mat_mult_conc $i 4
done
