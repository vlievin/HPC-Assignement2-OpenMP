#!/bin/sh

# embedded options to qsub - start with #PBS
# -- Name of the job ---
#PBS -N HPC_poisson_problem
# -- specify queue --
#PBS -q hpcintro
# -- estimated wall clock time (execution time): hh:mm:ss --
#PBS -l walltime=00:30:00
# -- number of processors/cores/nodes (request X node with X cores) --
#PBS -l nodes=1:ppn=2
# -- CPU type --
#PBS -l feature='XeonE5-2680'
# -- user email address --
#PBS -M s151457@student.dtu.dk
# -- mail notification when begins(b), ends(e) and fails (a=aborted) --
#PBS -m a

# -- run in the current working (submission) directory --
if test X$PBS_ENVIRONMENT = XPBS_BATCH; then cd $PBS_O_WORKDIR; fi

# 1 2 4 8
THREADS=2
N=( 100 200 300 400 )
# jacobi parallel_jacobi gaussseidel
METHOD=( jacobi parallel_jacobi gaussseidel )

# waiting threads should be active and consume CPU power - better for performance
export OMP_WAIT_POLICY=active

for i in ${METHOD[@]} ; do
	for j in ${N[@]} ; do
		outfile="${i}-${CPUTYPE}-Threads_${THREADS}-N_${j}.dat"
		export OMP_NUM_THREADS="$THREADS"
		export SUNW_MP_WARN="true"
		time ./poisson "$j" 0 "$i" >> "$outfile" 2>&1

		NPROCS=`wc -l < "${PBS_NODEFILE}"`
		(
		        echo == CPUTYPE: $CPUTYPE
		        echo == NPROCS: $NPROCS
		        echo == PBS_NP: $PBS_NP
		        echo == PBS_NODENUM: $PBS_NODENUM
       			echo == PBS_NUM_NODES: $PBS_NUM_NODES
        		echo == PBS_NUM_PPN: $PBS_NUM_PPN
        		echo == PBS_TASKNUM: $PBS_TASKNUM
		) >> "$outfile" 2>&1
	done
done

