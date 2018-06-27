#!/bin/sh

./corewar $1 $2 $3 $4 $5 $6 >  a
./test $1 $2 $3 $4 $5 $6 > b

DIFF=$(diff a b) 
if [ "$DIFF" == "" ] 
then
    echo "<<<<<< OK >>>>>>>" $1 " "
    cat a
else
	echo "<<<<<< KO >>>>>>>" $1
	cat 
fi
rm a b