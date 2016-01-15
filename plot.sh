#!/bin/bash

### grep from dat files

K_LINE=`find . -name "*.dat" -exec  grep 'k is:' {} \;`
K=`echo "$K_LINE" | grep -Eo '[0-9]{1,7}'`

METHOD_LINE=`find . -name "*.dat" -exec  grep 'The argument supplied for the method is:' {} \;`
METHOD=`echo "$METHOD_LINE" | awk '{print $8}'`

N_LINE=`find . -name "*.dat" -exec  grep 'The argument supplied for N is:' {} \;`
N=`echo "$N_LINE" | awk '{print $7}'`

THREAD_LINE=`find . -name "*.dat" -exec  grep 'PBS_NUM_PPN:' {} \;`
THREAD=`echo "$THREAD_LINE" | awk '{print $3}'`

TIME_LINE=`find . -name "*.dat" -exec  grep 'elapsed' {} \;`
TIME_REP=`echo "$TIME_LINE" | awk '{print $3}'`
TIME="$(echo $TIME_REP | sed 's/elapsed/\n/g')"

paste <(echo "$K") <(echo "$N") <(echo "$THREAD") <(echo "$TIME") <(echo "$METHOD") --delimiters ';'
