#!/bin/sh

# embedded options to qsub - start with #PBS
# -- Name of the job ---
#PBS -N HPC_matrix_multipication
# -- specify queue --
#PBS -q hpcintro
# -- estimated wall clock time (execution time): hh:mm:ss --
#PBS -l walltime=00:30:00
# -- number of processors/cores/nodes (request X node with X cores) --
#PBS -l nodes=1:ppn=20
# -- CPU type --
#PBS -l feature='XeonE5-2680'
# -- user email address --
#PBS -M inigoreiriz@gmail.com
# -- mail notification when begins(b), ends(e) and fails (a=aborted) --
#PBS -m a

# -- run in the current working (submission) directory --
if test X$PBS_ENVIRONMENT = XPBS_BATCH; then cd $PBS_O_WORKDIR; fi

outfile="No_Scheduling.txt"

NPROCS=`wc -l < "${PBS_NODEFILE}"`
(
        echo == CPUTYPE: $CPUTYPE
        echo == NPROCS: $NPROCS
        echo == PBS_NP: $PBS_NP
        echo == PBS_NODENUM: $PBS_NODENUM
        echo == PBS_NUM_NODES: $PBS_NUM_NODES
        echo == PBS_NUM_PPN: $PBS_NUM_PPN
        echo == PBS_TASKNUM: $PBS_TASKNUM

	i=1
	while [ $i -le 20 ]
	do
	OMP_NUM_THREADS=$i OMP_WAIT_POLICY=active ./mandelbrot >> "$outfile" 
	((i+=1))
	done
) 

exit 0
