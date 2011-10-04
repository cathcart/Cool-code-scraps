Slurm Jobs report
=================

Mixture of c and python to get job data from a [slurm](https://computing.llnl.gov/linux/slurm/) controlled cluster.

Compile/Installation
--------------------

Compile the c code `final.c` that'll poll the slurm database for us with:

	$gcc -o final final.c -lslurm


assuming slurm is in the LD_LIBRARY_PATH.

Running
-------

First run the c code, `./final`, to get the raw output.
	$./final|awk 'FNR>2{print}'>tmp
This also ignores the first two lines which are for error reporting. (from both `./final` and the slurm functions).  
The `jobs.py` script then parses the raw dump of slurm job data to give us a nice report about our jobs.

	$python jobs.py


Automatic running with crontabs
-------------------------------

`run.sh` acts to wrap all of the above commands and email the report to your email address. Add the following line to your crontab
	0 */2 * * * sh run.sh
being sure to give the full absolute path and chmod u+x the relevent files (`./final`,`jobs.py` and `run.sh`).
This runs the report every two hours.


TODO
----

Monitor the returned values from `./final` to make sure we've pulled the data from the slurm database correctly.
