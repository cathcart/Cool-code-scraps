#include <stdio.h>
#include <stdlib.h>
#include "slurm.h"
#include "slurm_errno.h"
#include <time.h>

int main( int argc, char *argv[]){

  job_info_msg_t ** resp;
  job_info_t *job_array;

  resp=malloc(sizeof(job_info_msg_t));
 if ( slurm_load_jobs((time_t)NULL,resp,SHOW_ALL)){
   printf("slurm error\n");
   slurm_perror ("slurm_load_jobs error");
   exit(EXIT_FAILURE);
 }else{
   printf("command ran ok\n");
 }

 slurm_print_job_info_msg (stdout, *resp,0);//dumps all info to stdout

 return 0;
}
