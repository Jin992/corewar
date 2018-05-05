# ./corewar $1 -d 100 > t1
# ./VM $1 -d 100 > t2
# diff t1 t2
# rm t1 t2
# ./corewar $1 -d 100 > t1
# ./VM $1 -d 100 > t2
# diff t1 t2
# rm t1 t2
# ./corewar $1 -d 500 > t1
# ./VM $1 -d 500 > t2
# diff t1 t2
# rm t1 t2
# ./corewar $1 -d 1000 > t1
# ./VM $1 -d 1000 > t2
# diff t1 t2
# rm t1 t2
# ./corewar $1 -d 2000 > t1
# ./VM $1 -d 2000 > t2
# diff t1 t2
# rm t1 t2
# ./corewar $1 -d 3000 > t1
# ./VM $1 -d 3000 > t2
# diff t1 t2
# rm t1 t2
./corewar $1 $2 $3 $4 > t2
./VM $1 $2 $3 $4 > t1
diff t1 t2
rm t1 t2