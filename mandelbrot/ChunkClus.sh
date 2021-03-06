#!/bin/sh

# embedded options to qsub - start with #PBS
# -- Name of the job ---
#PBS -N HPC_matrix_multipication
# -- specify queue --
#PBS -q hpcintro
# -- estimated wall clock time (execution time): hh:mm:ss --
#PBS -l walltime=00:30:00
# -- number of processors/cores/nodes (request X node with X cores) --
#PBS -l nodes=1:ppn=8
# -- CPU type --
#PBS -l feature='XeonE5-2680'
# -- user email address --
#PBS -M inigoreiriz@gmail.com
# -- mail notification when begins(b), ends(e) and fails (a=aborted) --
#PBS -m a

# -- run in the current working (submission) directory --
if test X$PBS_ENVIRONMENT = XPBS_BATCH; then cd $PBS_O_WORKDIR; fi

outfile="Chunksize_Output.txt"

NPROCS=`wc -l < "${PBS_NODEFILE}"`
(
        echo == CPUTYPE: $CPUTYPE
        echo == NPROCS: $NPROCS
        echo == PBS_NP: $PBS_NP
        echo == PBS_NODENUM: $PBS_NODENUM
        echo == PBS_NUM_NODES: $PBS_NUM_NODES
        echo == PBS_NUM_PPN: $PBS_NUM_PPN
        echo == PBS_TASKNUM: $PBS_TASKNUM

	echo "Dynamic Chunksize"
	i=1
	while [ $i -le 100 ]
	do
	OMP_SCHEDULE=dynamic,$i OMP_NUM_THREADS=8 OMP_WAIT_POLICY=active ./mandelbrot
	((i+=1))
	done

	echo "Static Chunksize"
	i=1
	while [ $i -le 100 ]
	do
	OMP_SCHEDULE=static,$i OMP_NUM_THREADS=8 OMP_WAIT_POLICY=active ./mandelbrot
	((i+=1))
	done

	echo "Guided Chunksize"
	i=1
	while [ $i -le 100 ]
	do
	OMP_SCHEDULE=guided,$i OMP_NUM_THREADS=8 OMP_WAIT_POLICY=active ./mandelbrot 
	((i+=1))
	done
) >> "$outfile" 

exit 0
