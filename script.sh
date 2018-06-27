#!/bin/bash
make
clear
echo "\033[35;1mWhat is your name ? \033[0m"
read name

echo "\033[34;1mWelcome to our supreme Corewar, $name \033[0m"
echo "\033[35;1mTEST ASM? (y \ n) \033[0m"
read answer

if [ $answer == "y" ]
then
for line in $(find Archive -name "*.s");
do

champ="$(echo "$line" | rev | cut -d . -f 2- | rev | tr -d "\n")"
rm -f a
rm -f b
rm -f "$champ.cor"

./asm "$champ.s" > c
if [ -f "$champ.cor" ]
	then
		my="1"
		cp "$champ.cor" a
	else
		my="0"
fi

rm -f "$champ.cor"
./original/asm "$champ.s" > d
if [ -f "$champ.cor" ]
	then
		orig="1"
		cp "$champ.cor" b
	else
		orig="0"
fi

if ([ "$my" = "0" ] && [ "$orig" = "1" ])
	then
 		DIFF=$(diff a b)
fi
rm -f a
rm -f b
rm -f c
rm -f d

if ([ "$DIFF" = "$(echo)" ] && [ "$my" = "$orig" ])
	then
		echo "\x1b[92mOK :D\x1b[0m: $champ"
	else
		echo "\x1b[91mKO :(\x1b[0m: $champ"
fi
done
rm ./Archive/*.cor
fi

echo "\033[35;1mTEST COREWAR? (y \ n) \033[0m"
read answer


if [ $answer == "y" ]
then
echo "\033[35;1mWould you like to change .s file to .cor file ? (y \ n) \033[0m"
read answer

if [ $answer == "y" ]
then
for file in Archive/*.s
do
./asm $file
done
i=1
for file in Archive/*.cor
do
champs[i]=$file
echo "\033[32;1m$i. $file \033[0m"
i=$[ $i + 1 ]
done
else
echo "no"
fi

answ="y"

while [ $answ == "y" ]
do

echo "\033[35;1mWould you like to run the virtual machine ? (y \ n) \033[0m"
read answ

nbr=5
if [ $answ == "y" ]
then
while [ $nbr -gt 4 ]
do
echo "\033[35;1mPlease enter your preferable number of players ? \033[0m"
read nbr
done
echo "\033[35;1mPlease enter champion(s) number(s) you want to run on the virtual machine ? \033[0m"
read p1 p2 p3 p4


if [ $nbr == "1" ]
then
echo "\033[34;1mOUR SUPREME COREWAR \033[0m"
./corewar ${champs[p1]}


elif [ $nbr == "2" ]
then
echo "\033[34;1mOUR SUPREME COREWAR \033[0m"
./corewar ${champs[p1]} ${champs[p2]}


elif [ $nbr == "3" ]
then
echo "\033[34;1mOUR SUPREME COREWAR \033[0m"
./corewar ${champs[p1]} ${champs[p2]} ${champs[p3]}


elif [ $nbr == "4" ]
then
echo "\033[34;1mOUR SUPREME COREWAR \033[0m"
./corewar ${champs[p1]} ${champs[p2]} ${champs[p3]} ${champs[p4]}
fi

fi
done
fi

echo "\033[34;1mThank you for sharing this moment with us! \033[0m"

find ./Archive -type f -name "*.cor" -delete
