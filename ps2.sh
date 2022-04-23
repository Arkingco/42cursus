CNT=5
LIMIT=12
INDEX=0
ITER=10000
NUM_OVER=0
MAX=$LIMIT
ARG=`jot -r $CNT -2147483648 2147483647 | tr "\n" " "`
NUM=`./push_swap $ARG | wc -l`

while [ $INDEX -lt $ITER ]
do
echo "	:	$NUM"
if [ $NUM -ge $LIMIT ]; then
NUM_OVER=`expr $NUM_OVER + 1`
fi
if [ $NUM -gt $MAX ]; then
MAX=$NUM
fi
ARG=`jot -r $CNT -2147483648 2147483647 | tr "\n" " "`
NUM=`./push_swap $ARG | wc -l`
INDEX=`expr $INDEX + 1`
done
echo "$NUM_OVER overred operations for $ITER times"
if [ $NUM_OVER -gt 0 ]; then
echo "Biggest operation number : $MAX"
echo "fix it!!!!!!!!!!"
fi
