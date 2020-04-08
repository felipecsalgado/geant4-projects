#!/bin/bash -x
#Stephan Kuschel, April 2013
# Stefan Tietze, December 2015 - modified to use slurm instead of pbs

#SBATCH --output=mpi-out.%j
#SBATCH --error=mpi-out.%j
#SBATCH -J geant4 # Name of your job
#SBATCH -p long
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=24
#SBATCH --time=48:00:00 # max. runtime in hours


#echo ------------------------------------------------------
echo SLURM: Is running on $SLURM_NTASKS threads
echo SLURM: sbatch is running on $SLURM_SUBMIT_HOST
echo SLURM: executing queue is $SLURM_JOB_PARTITION
echo SLURM: working directory is $SLURM_SUBMIT_DIR
echo SLURM: job identifier is $SLURM_JOB_ID
echo SLURM: job name is $SLURM_JOB_NAME
echo Start time: $(date)
echo ------------------------------------------------------

cd $SLURM_SUBMIT_DIR

#echo "." | mpirun -np 24 ./LXe cerenkov_cad.mac > output.log
source /opt/geant4/bin/geant4.sh
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/GEANT4/CADMesh-install/
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/GEANT4/CADMesh-install/lib
./TestEm3 target.mac > output_target.txt

echo ------------------------------------------------------
echo job completed successfully: $(date)
