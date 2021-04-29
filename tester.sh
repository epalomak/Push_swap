
#!/bin/bash
from=$1
to=$2
count=$3
avg=0
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

if [ "$#" -lt 3 ]
then
	echo "\nUsage: tester.sh arg1 arg2 arg3"
	echo "	arg1 = start number\n	arg2 = last number\n	arg3 = amount of test runs\n"
	exit
fi

for ((i = 1; i <= count; i++))
	do
		ARG=`ruby -e "puts ($from..$to).to_a.shuffle.join(' ')"`
		MOVES=`./push_swap "$ARG" | wc -l`
		RES=`./push_swap "$ARG" | ./checker "$ARG"`
		let "avg += $MOVES"
		if [ "$RES" = "OK" ]
		then
			echo "\n	test $i	$MOVES	${GREEN}$RES${NC}"
		fi
		if [ "$RES" = "KO" ] 
		then
			echo "\n	test $i	$MOVES	${RED}$RES${NC}"
					echo " ${RED}$ARG${NC}"
		fi
done
let "avg = avg / count"
echo "\navarage moves = $avg"