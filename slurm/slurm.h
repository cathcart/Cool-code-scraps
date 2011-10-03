/* slurm/slurm.h.  Generated from slurm.h.in by configure.  */
/*****************************************************************************\
 *  slurm.h - Definitions for all of the SLURM RPCs
 *****************************************************************************
 *  Copyright (C) 2002-2007 The Regents of the University of California.
 *  Copyright (C) 2008-2009 Lawrence Livermore National Security.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
 *  Written by Morris Jette <jette1@llnl.gov>, et. al.
 *  CODE-OCEC-09-009. All rights reserved.
 *
 *  This file is part of SLURM, a resource management program.
 *  For details, see <https://computing.llnl.gov/linux/slurm/>.
 *  Please also read the included file: DISCLAIMER.
 *
 *  SLURM is free software; you can redistribute it and/or modify it under
 *  the terms of the GNU General Public License as published by the Free
 *  Software Foundation; either version 2 of the License, or (at your option)
 *  any later version.
 *
 *  In addition, as a special exception, the copyright holders give permission
 *  to link the code of portions of this program with the OpenSSL library under
 *  certain conditions as described in each individual source file, and
 *  distribute linked combinations including the two. You must obey the GNU
 *  General Public License in all respects for all of the code used other than
 *  OpenSSL. If you modify file(s) with this exception, you may extend this
 *  exception to your version of the file(s), but you are not obligated to do
 *  so. If you do not wish to do so, delete this exception statement from your
 *  version.  If you delete this exception statement from all source files in
 *  the program, then also delete it here.
 *
 *  SLURM is distributed in the hope that it will be useful, but WITHOUT ANY
 *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 *  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 *  details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with SLURM; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
\*****************************************************************************/

#ifndef _SLURM_H
#define _SLURM_H

/* BEGIN_C_DECLS should be used at the beginning of your declarations,
   so that C++ compilers don't mangle their names.  Use _END_C_DECLS at
   the end of C declarations. */
/* #undef BEGIN_C_DECLS */
/* #undef END_C_DECLS */
#ifdef __cplusplus
# define BEGIN_C_DECLS	extern "C" {
# define END_C_DECLS	}
#else
# define BEGIN_C_DECLS	/* empty */
# define END_C_DECLS	/* empty */
#endif

/* PARAMS is a macro used to wrap function prototypes, so that compilers
   that don't understand ANSI C prototypes still work, and ANSI C
   compilers can issue warnings about type mismatches.  */
/* #undef PARAMS */
#if defined (__STDC__) || defined (_AIX) \
	|| (defined (__mips) && defined (_SYSTYPE_SVR4)) \
	|| defined(WIN32) || defined(__cplusplus)
# define PARAMS(protos)	protos
#else
# define PARAMS(protos)	()
#endif

/* Define to 1 if you have Blue Gene system support. */
/* #undef HAVE_BG */

/* Define to 1 if emulating or running on Blue Gene/L system */
/* #undef HAVE_BGL */

/* Define to 1 if emulating or running on Blue Gene/P system */
/* #undef HAVE_BGP */

/* 4-dimensional architecture counting the nodes under a switch as additional
   dimension */
/* #undef SYSTEM_DIMENSIONS */

/* Define to 1 if you have the `elan3' library (-lelan3). */
/* #undef HAVE_ELAN */

/* Define to 1 if you have the <sys/socket.h> header file. */
#define HAVE_SYS_SOCKET_H 1

BEGIN_C_DECLS

#include <slurm/slurm_errno.h>

#if HAVE_STDINT_H
#  include <stdint.h>		/* for uint16_t, uint32_t definitions */
#endif
#if HAVE_INTTYPES_H
#  include <inttypes.h>		/* for uint16_t, uint32_t definitions */
#endif
#include <stdbool.h>
#include <stdio.h>		/* for FILE definitions */
#include <sys/types.h>		/* for uid_t definition */
#include <time.h>		/* for time_t definitions */
#include <unistd.h>

#ifdef CRAPPY_COMPILER
  /*
   * 'bool' can be implemented in a variety of ways.
   * C++ may define it one way.
   * <stdbool.h> may declare 'bool' to be a different type, such as
   * an enum which is not necessarily compatible with C++.
   *
   * If your compiler can't resolve 'bool', just define
   * CRAPPY_COMPILER at build time in order for SLURM to
   * define it's own version of bool.
   */

/*    #undef TRUE */
   #define TRUE   1

/*    #undef FALSE */
   #define FALSE  0

   typedef unsigned char SLURM_BOOL;
/*    #undef bool */
   #define bool SLURM_BOOL
#endif

/* Define slurm_addr below to avoid including extraneous slurm headers */
#ifdef	HAVE_SYS_SOCKET_H
#  ifndef __slurm_addr_defined
#    include <netinet/in.h>
#    define  __slurm_addr_defined
     typedef struct sockaddr_in slurm_addr;
#  endif
#endif

#ifndef __slurm_cred_t_defined
#  define __slurm_cred_t_defined
   typedef struct slurm_job_credential slurm_cred_t;
#endif

/* Define switch_jobinfo_t below to avoid including extraneous slurm headers */
#ifndef __switch_jobinfo_t_defined
#  define  __switch_jobinfo_t_defined
   typedef struct switch_jobinfo switch_jobinfo_t;	/* opaque data type */
#endif

/* Define job_resources_t below
 * to avoid including extraneous slurm headers */
#ifndef __job_resources_t_defined
#  define  __job_resources_t_defined	/* Opaque data for select plugins */
   typedef struct job_resources job_resources_t;
#endif

/* Define select_jobinfo_t, select_nodeinfo_t below
 * to avoid including extraneous slurm headers */
#ifndef __select_jobinfo_t_defined
#  define  __select_jobinfo_t_defined	/* Opaque data for select plugins */
   typedef struct select_jobinfo select_jobinfo_t;  /* for BlueGene */
   typedef struct select_nodeinfo select_nodeinfo_t;  /* for BlueGene */
#endif

/* Define jobacctinfo_t below to avoid including extraneous slurm headers */
#ifndef __jobacctinfo_t_defined
#  define  __jobacctinfo_t_defined
   typedef struct jobacctinfo jobacctinfo_t;     /* opaque data type */
#endif

/* Define allocation_msg_thread_t below to avoid including extraneous
 * slurm headers */
#ifndef __allocation_msg_thread_t_defined
#  define  __allocation_msg_thread_t_defined
   typedef struct allocation_msg_thread allocation_msg_thread_t;
#endif

#ifndef __sbcast_cred_t_defined
#  define  __sbcast_cred_t_defined
   typedef struct sbcast_cred sbcast_cred_t;		/* opaque data type */
#endif

/*****************************************************************************\
 *      DEFINITIONS FOR VERSION MANAGEMENT
\*****************************************************************************/

#define SLURM_VERSION_NUM(a,b,c) (((a) << 16) + ((b) << 8) + (c))
#define SLURM_VERSION_MAJOR(a)   (((a) >> 16) & 0xff)
#define SLURM_VERSION_MINOR(a)   (((a) >>  8) & 0xff)
#define SLURM_VERSION_MICRO(a)    ((a)        & 0xff)

/* Define the API's version. Update in META as needed.
 * Also defined in config.h.
 * High-order byte is major version. Update when existing APIs change.
 * Middle byte     is minor version. Update when new functions are added.
 * Low-order byte  is micro version. Update on patches and bug fixes. */
#ifndef SLURM_API_VERSION
#define SLURM_API_VERSION 0x150000
#endif

/*****************************************************************************\
 *	DEFINITIONS FOR INPUT VALUES
\*****************************************************************************/

/* INFINITE is used to identify unlimited configurations,  */
/* eg. the maximum count of nodes any job may use in some partition */
#define	INFINITE (0xffffffff)
#define NO_VAL	 (0xfffffffe)
#define MAX_TASKS_PER_NODE 128

/* Job step ID of batch scripts */
#define SLURM_BATCH_SCRIPT (0xfffffffe)

/* last entry must be JOB_END, keep in sync with job_state_string and
 *	job_state_string_compact. values may be ORed with JOB_STATE_FLAGS
 *	below.  */
enum job_states {
	JOB_PENDING,		/* queued waiting for initiation */
	JOB_RUNNING,		/* allocated resources and executing */
	JOB_SUSPENDED,		/* allocated resources, execution suspended */
	JOB_COMPLETE,		/* completed execution successfully */
	JOB_CANCELLED,		/* cancelled by user */
	JOB_FAILED,		/* completed execution unsuccessfully */
	JOB_TIMEOUT,		/* terminated on reaching time limit */
	JOB_NODE_FAIL,		/* terminated on node failure */
	JOB_END			/* not a real state, last entry in table */
};
#define	JOB_STATE_BASE    0x00ff   /* Used for job_states above */
#define	JOB_STATE_FLAGS   0xff00   /* Used for state flags below */
#define	JOB_COMPLETING    0x8000   /* Waiting for epilog completion */
#define	JOB_CONFIGURING   0x4000   /* Allocated nodes booting */

#define READY_JOB_FATAL	   -2	/* fatal error */
#define READY_JOB_ERROR    -1	/* ordinary error */
#define READY_NODE_STATE 0x01	/* node is ready */
#define READY_JOB_STATE  0x02	/* job is ready to execute */

#define MAIL_JOB_BEGIN 0x0001	/* notify when job begins */
#define MAIL_JOB_END   0x0002	/* notify when job ends */
#define MAIL_JOB_FAIL  0x0004	/* notify if job fails */

#define NICE_OFFSET 10000	/* offset for job's nice value */

/* Reason for job to be pending rather than executing or reason for job
 * failure. If multiple reasons exists, only one is given for the sake of
 * system efficiency */
enum job_state_reason {
/* Reasons for job to be pending */
	WAIT_NO_REASON = 0,	/* not set or job not pending */
	WAIT_PRIORITY,		/* higher priority jobs exist */
	WAIT_DEPENDENCY,	/* dependent job has not completed */
	WAIT_RESOURCES,		/* required resources not available */
	WAIT_PART_NODE_LIMIT,	/* request exceeds partition node limit */
	WAIT_PART_TIME_LIMIT,	/* request exceeds partition time limit */
	WAIT_PART_STATE,	/* requested partition is down */
	WAIT_HELD,		/* job is held, priority==0 */
	WAIT_TIME,		/* job waiting for specific begin time */
	WAIT_LICENSES,		/* job is waiting for licenses */
	WAIT_ASSOC_JOB_LIMIT,	/* user/bank job limit reached */
	WAIT_ASSOC_RESOURCE_LIMIT,/* user/bank resource limit reached */
	WAIT_ASSOC_TIME_LIMIT,  /* user/bank time limit reached */
	WAIT_RESERVATION,	/* reservation not available */
	WAIT_NODE_NOT_AVAIL,	/* required node is DOWN or DRAINED */
	WAIT_TBD1,
	WAIT_TBD2,
	FAIL_DOWN_PARTITION,	/* partition for job is DOWN */
	FAIL_DOWN_NODE,		/* some node in the allocation failed */
	FAIL_BAD_CONSTRAINTS,	/* constraints can not be satisfied */
	FAIL_SYSTEM,		/* slurm system failure */
	FAIL_LAUNCH,		/* unable to launch job */
	FAIL_EXIT_CODE,		/* exit code was non-zero */
	FAIL_TIMEOUT,		/* reached end of time limit */
	FAIL_INACTIVE_LIMIT,	/* reached slurm InactiveLimit */
	FAIL_BANK_ACCOUNT	/* invalid bank account */
};

enum job_acct_types {
	JOB_START,
	JOB_STEP,
	JOB_SUSPEND,
	JOB_TERMINATED
};

enum connection_type {
	SELECT_MESH, 		/* nodes wired in mesh */
	SELECT_TORUS, 		/* nodes wired in torus */
	SELECT_NAV,		/* nodes wired in torus else mesh */
	SELECT_SMALL, 		/* nodes in a small partition */
	SELECT_HTC_S,           /* nodes in a htc running SMP mode */
	SELECT_HTC_D,           /* nodes in a htc running Dual mode */
	SELECT_HTC_V,           /* nodes in a htc running VN mode */
	SELECT_HTC_L            /* nodes in a htc running in Linux mode */
};

enum node_use_type {
	SELECT_COPROCESSOR_MODE,/* use extra processor for communications */
	SELECT_VIRTUAL_NODE_MODE,/* application uses both processors */
	SELECT_NAV_MODE		/* either mode is acceptable */
};

enum select_jobdata_type {
	SELECT_JOBDATA_GEOMETRY,/* data-> uint16_t geometry[SYSTEM_DIMENSIONS] */
	SELECT_JOBDATA_ROTATE,	/* data-> uint16_t rotate */
	SELECT_JOBDATA_CONN_TYPE,	/* data-> uint16_t connection_type */
	SELECT_JOBDATA_BLOCK_ID,	/* data-> char *bg_block_id */
	SELECT_JOBDATA_NODES,	/* data-> char *nodes */
	SELECT_JOBDATA_IONODES,	/* data-> char *ionodes */
	SELECT_JOBDATA_NODE_CNT,	/* data-> uint32_t node_cnt */
	SELECT_JOBDATA_ALTERED,    /* data-> uint16_t altered */
	SELECT_JOBDATA_MAX_CPUS,	/* data-> uint32_t max_cpus */
	SELECT_JOBDATA_BLRTS_IMAGE,/* data-> char *blrtsimage */
	SELECT_JOBDATA_LINUX_IMAGE,/* data-> char *linuximage */
	SELECT_JOBDATA_MLOADER_IMAGE,/* data-> char *mloaderimage */
	SELECT_JOBDATA_RAMDISK_IMAGE,/* data-> char *ramdiskimage */
	SELECT_JOBDATA_REBOOT,	/* data-> uint16_t reboot */
	SELECT_JOBDATA_RESV_ID,	/* data-> char *reservation_id */
};

enum select_nodedata_type {
	SELECT_NODEDATA_BITMAP_SIZE, /* data-> uint16_t */
	SELECT_NODEDATA_SUBGRP_SIZE, /* data-> uint16_t */
	SELECT_NODEDATA_SUBCNT,      /* data-> uint16_t */
	SELECT_NODEDATA_BITMAP,      /* data-> bitstr_t * needs to be
				      * freed with FREE_NULL_BITMAP */
	SELECT_NODEDATA_STR,         /* data-> char *  needs to be
				      * freed with xfree */
};

enum select_print_mode {
	SELECT_PRINT_HEAD,	/* Print just the header */
	SELECT_PRINT_DATA,	/* Print just the data */
	SELECT_PRINT_MIXED,	/* Print "field=value" */
	SELECT_PRINT_MIXED_SHORT,/* Print less "field=value" */
	SELECT_PRINT_BG_ID,	/* Print just the BG_ID */
	SELECT_PRINT_NODES,	/* Print the nodelist */
	SELECT_PRINT_CONNECTION,/* Print just the CONNECTION type */
	SELECT_PRINT_ROTATE,    /* Print just the ROTATE */
	SELECT_PRINT_GEOMETRY,	/* Print just the GEO */
	SELECT_PRINT_START,	/* Print just the START location */
	SELECT_PRINT_MAX_CPUS,  /* Print just the MAX CPUS */
	SELECT_PRINT_BLRTS_IMAGE,/* Print just the BLRTS IMAGE */
	SELECT_PRINT_LINUX_IMAGE,/* Print just the LINUX IMAGE */
	SELECT_PRINT_MLOADER_IMAGE,/* Print just the MLOADER IMAGE */
	SELECT_PRINT_RAMDISK_IMAGE,/* Print just the RAMDISK IMAGE */
	SELECT_PRINT_REBOOT,	/* Print just the REBOOT */
	SELECT_PRINT_RESV_ID,	/* Print just Cray/BASIL reservation ID */
};

enum select_node_cnt {
	SELECT_GET_NODE_SCALING,      /* Give scaling factor for node count */
	SELECT_GET_NODE_CPU_CNT,      /* Give how many cpus are on a node */
	SELECT_GET_BP_CPU_CNT,        /* Give how many cpus are on a
				       * base partition */
	SELECT_APPLY_NODE_MIN_OFFSET, /* Apply min offset to variable */
	SELECT_APPLY_NODE_MAX_OFFSET, /* Apply max offset to variable */
	SELECT_SET_NODE_CNT,	      /* Set altered node cnt */
	SELECT_SET_BP_CNT             /* Given a node cnt return the
				       * base partition count */
};

/* jobacct data types */
enum jobacct_data_type {
	JOBACCT_DATA_TOTAL,	/* data-> jobacctinfo_t * */
	JOBACCT_DATA_PIPE,      /* data-> file descriptor */
	JOBACCT_DATA_RUSAGE,	/* data-> rusage set user_cpu_sec,
				 * user_cpu_usec, sys_cpu_sec, sys_cpu_usec */
	JOBACCT_DATA_MAX_VSIZE,	/* data-> uint32_t vsize */
	JOBACCT_DATA_MAX_VSIZE_ID,	/* data-> jobacct_id_t vsize */
	JOBACCT_DATA_TOT_VSIZE,	/* data-> uint32_t vsize */
	JOBACCT_DATA_MAX_RSS,	/* data-> uint32_t psize */
	JOBACCT_DATA_MAX_RSS_ID,	/* data-> jobacct_id_t psize */
	JOBACCT_DATA_TOT_RSS,	/* data-> uint32_t psize */
	JOBACCT_DATA_MAX_PAGES,	/* data-> uint32_t psize */
	JOBACCT_DATA_MAX_PAGES_ID,	/* data-> jobacct_id_t psize */
	JOBACCT_DATA_TOT_PAGES,	/* data-> uint32_t psize */
	JOBACCT_DATA_MIN_CPU,	/* data-> uint32_t psize */
	JOBACCT_DATA_MIN_CPU_ID,	/* data-> jobacct_id_t psize */
	JOBACCT_DATA_TOT_CPU	/* data-> uint32_t psize */
};

/* Possible task distributions across the nodes */
typedef enum task_dist_states {
	/* NOTE: start SLURM_DIST_CYCLIC at 1 for HP MPI */
	SLURM_DIST_CYCLIC = 1,	/* distribute tasks 1 per node, round robin */
	SLURM_DIST_BLOCK,	/* distribute tasks filling node by node */
	SLURM_DIST_ARBITRARY,	/* arbitrary task distribution  */
	SLURM_DIST_PLANE,	/* distribute tasks by filling up
				   planes of lllp first and then by
				   going across the nodes See
				   documentation for more
				   information */
	SLURM_DIST_CYCLIC_CYCLIC,/* distribute tasks 1 per node,
				   round robin, same for lowest
				   level of logical processor (lllp) */
	SLURM_DIST_CYCLIC_BLOCK, /* cyclic for node and block for lllp  */
	SLURM_DIST_BLOCK_CYCLIC, /* block for node and cyclic for lllp  */
	SLURM_DIST_BLOCK_BLOCK,	/* block for node and block for lllp  */
	SLURM_NO_LLLP_DIST,	/* No distribution specified for lllp */
	SLURM_DIST_UNKNOWN	/* unknown dist */
} task_dist_states_t;

/* Open stdout/err file mode, 0 for system default (JobFileAppend) */
#define OPEN_MODE_APPEND	1
#define OPEN_MODE_TRUNCATE	2

typedef enum cpu_bind_type {	/* cpu binding type from --cpu_bind=... */
	/* verbose can be set with any other flag */
	CPU_BIND_VERBOSE   = 0x01, /* =v, */
	/* the following auto-binding flags are mutually exclusive */
	CPU_BIND_TO_THREADS= 0x02, /* =threads */
	CPU_BIND_TO_CORES  = 0x04, /* =cores */
	CPU_BIND_TO_SOCKETS= 0x08, /* =sockets */
	CPU_BIND_TO_LDOMS  = 0x10, /* locality domains */
	/* the following manual binding flags are mutually exclusive */
	/* CPU_BIND_NONE needs to be the lowest value among manual bindings */
	CPU_BIND_NONE	   = 0x20, /* =no */
	CPU_BIND_RANK  	   = 0x40, /* =rank */
	CPU_BIND_MAP	   = 0x80, /* =map_cpu:<list of CPU IDs> */
	CPU_BIND_MASK	   = 0x100,/* =mask_cpu:<list of CPU masks> */
	CPU_BIND_LDRANK    = 0x200,/* =locality domain rank */
	CPU_BIND_LDMAP	   = 0x400,/* =map_ldom:<list of locality domains> */
	CPU_BIND_LDMASK	   = 0x800,/* =mask_ldom:<list of ldom masks> */

	/* the following is used only as a flag for expressing
	 * the contents of TaskPluginParams */
	CPU_BIND_CPUSETS   = 0x8000
} cpu_bind_type_t;

typedef enum mem_bind_type {    /* memory binding type from --mem_bind=... */
	/* verbose can be set with any other flag */
	MEM_BIND_VERBOSE= 0x01,	/* =v, */
	/* the following manual binding flags are mutually exclusive */
	/* MEM_BIND_NONE needs to be the first in this sub-list */
	MEM_BIND_NONE   = 0x02,	/* =no */
	MEM_BIND_RANK   = 0x04,	/* =rank */
	MEM_BIND_MAP    = 0x08,	/* =map_mem:<list of CPU IDs> */
	MEM_BIND_MASK   = 0x10,	/* =mask_mem:<list of CPU masks> */
	MEM_BIND_LOCAL  = 0x20	/* =local */
} mem_bind_type_t;

/* The last entry in node_states must be STATE_END, keep in sync with
 * node_state_string. values may be ORed with NODE_STATE_FLAGS below.
 * Node states typically alternate between NODE_STATE_IDLE and
 * NODE_STATE_ALLOCATED. The NODE_STATE_COMPLETING flag will be set
 * when jobs are in the process of terminating. */
enum node_states {
	NODE_STATE_UNKNOWN,	/* node's initial state, unknown */
	NODE_STATE_DOWN,	/* node in non-usable state */
	NODE_STATE_IDLE,	/* node idle and available for use */
	NODE_STATE_ALLOCATED,	/* node has been allocated to a job */
	NODE_STATE_ERROR,	/* node is in an error state */
	NODE_STATE_MIXED,	/* node is in has a mixed state */
	NODE_STATE_FUTURE,	/* node slot reserved for future use */
	NODE_STATE_END		/* last entry in table */
};
#define NODE_STATE_BASE       0x00ff
#define NODE_STATE_FLAGS      0xff00
#define NODE_RESUME           0x0100	/* Restore a DRAINED, DRAINING, DOWN
					 * or FAILING node to service (e.g.
					 * IDLE or ALLOCATED). Used in
					 * slurm_update_node() request */
#define NODE_STATE_DRAIN      0x0200	/* node do not new allocated work */
#define NODE_STATE_COMPLETING 0x0400	/* node is completing allocated job */
#define NODE_STATE_NO_RESPOND 0x0800	/* node is not responding */
#define NODE_STATE_POWER_SAVE 0x1000	/* node in power save mode */
#define NODE_STATE_FAIL       0x2000	/* node is failing, do not allocate
					 * new work */
#define NODE_STATE_POWER_UP   0x4000	/* restore power or otherwise
					 * configure a a node */
#define NODE_STATE_MAINT      0x8000	/* node in maintenance reservation */

/* used to define the size of the credential.signature size
 * used to define the key size of the io_stream_header_t
 */
#define SLURM_SSL_SIGNATURE_LENGTH 128

/* Used as show_flags for slurm_get_ and slurm_load_ function calls.
 * Values can be can be ORed */
#define SHOW_ALL	0x0001	/* Show info for "hidden" partitions */
#define SHOW_DETAIL	0x0002	/* Show detailed resource information */

/* Define keys for ctx_key argument of slurm_step_ctx_get() */
enum ctx_keys {
	SLURM_STEP_CTX_STEPID,	/* get the created job step id */
	SLURM_STEP_CTX_TASKS,	/* get array of task count on each node */
	SLURM_STEP_CTX_TID,	/* get array of task IDs for specified node */
	SLURM_STEP_CTX_RESP,	/* get job step create response message */
	SLURM_STEP_CTX_CRED,
	SLURM_STEP_CTX_SWITCH_JOB,
	SLURM_STEP_CTX_NUM_HOSTS,
	SLURM_STEP_CTX_HOST,
	SLURM_STEP_CTX_JOBID,
	SLURM_STEP_CTX_USER_MANAGED_SOCKETS
};

typedef enum select_type_plugin_info {
	SELECT_TYPE_INFO_NONE = 0, /* Initiatlization value */
	CR_CPU,    /* Resources are shared down to the level of
		    * logical processors which can be socket,
		    * core, or thread depending on the system.*/
	CR_SOCKET, /* Resources are shared down to the socket level.
		    *  Jobs will not be co-allocated within a sockets */
	CR_CORE,   /* Resources are shared down to the core level
		    * Jobs will not be co-allocated within a core */
	CR_MEMORY, /* Memory as consumable resources, Memory is not
		    * over-commited when selected as a CR.  Jobs could
		    * be co-allocated within cores */
	CR_SOCKET_MEMORY, /* Socket and Memory are CRs */
	CR_CORE_MEMORY,   /* Core and Memory are CRs */
	CR_CPU_MEMORY     /* CPU and Memory are CRs */
} select_type_plugin_info_t ;

#define MEM_PER_CPU  0x80000000
#define SHARED_FORCE 0x8000

#define PRIVATE_DATA_JOBS	  0x0001 /* job/step data is private */
#define PRIVATE_DATA_NODES	  0x0002 /* node data is private */
#define PRIVATE_DATA_PARTITIONS	  0x0004 /* partition data is private */
#define PRIVATE_DATA_USAGE	  0x0008 /* accounting usage data is private */
#define PRIVATE_DATA_USERS	  0x0010 /* accounting user data is private */
#define PRIVATE_DATA_ACCOUNTS	  0x0020 /* accounting account data is private*/
#define PRIVATE_DATA_RESERVATIONS 0x0040 /* reservation data is private */

#define PRIORITY_RESET_NONE	0x0000	/* never clear */
#define PRIORITY_RESET_NOW	0x0001	/* clear now (when slurmctld restarts) */
#define PRIORITY_RESET_DAILY	0x0002	/* clear daily at midnight */
#define PRIORITY_RESET_WEEKLY	0x0003	/* clear weekly at Sunday 00:00 */
#define PRIORITY_RESET_MONTHLY	0x0004	/* clear monthly on first at 00:00 */
#define PRIORITY_RESET_QUARTERLY 0x0005	/* clear quarterly on first at 00:00 */
#define PRIORITY_RESET_YEARLY	0x0006	/* clear yearly on first at 00:00 */

/*****************************************************************************\
 *	PROTOCOL DATA STRUCTURE DEFINITIONS
\*****************************************************************************/

typedef struct job_descriptor {	/* For submit, allocate, and update requests */
	char *account;		/* charge to specified account */
	uint16_t acctg_freq;	/* accounting polling interval (seconds) */
	char *alloc_node;	/* node making resource allocation request
				 * NOTE: Normally set by slurm_submit* or
				 * slurm_allocate* function */
	uint16_t alloc_resp_port; /* port to send allocation confirmation to */
	uint32_t alloc_sid;	/* local sid making resource allocation request
				 * NOTE: Normally set by slurm_submit* or
				 * slurm_allocate* function */
	uint32_t argc;		/* number of arguments to the script */
	char **argv;		/* arguments to the script */
	time_t begin_time;	/* delay initiation until this time */
	uint16_t ckpt_interval;	/* periodically checkpoint this job */
	char *ckpt_dir;	 	/* directory to store checkpoint images */
	char *comment;		/* arbitrary comment (used by Moab scheduler) */
	uint16_t contiguous;	/* 1 if job requires contiguous nodes,
				 * 0 otherwise,default=0 */
	char *cpu_bind;		/* binding map for map/mask_cpu */
	uint16_t cpu_bind_type;	/* see cpu_bind_type_t */
	char *dependency;	/* syncrhonize job execution with other jobs */
	time_t end_time;	/* time by which job must complete, used for
				 * job update only now, possible deadline
				 * scheduling in the future */
	char **environment;	/* environment variables to set for job,
				 *  name=value pairs, one per line */
	uint32_t env_size;	/* element count in environment */
	char *exc_nodes;	/* comma separated list of nodes excluded
				 * from job's allocation, default NONE */
	char *features;		/* comma separated list of required features,
				 * default NONE */
	uint32_t group_id;	/* group to assume, if run as root. */
	uint16_t immediate;	/* 1 if allocate to run or fail immediately,
				 * 0 if to be queued awaiting resources */
	uint32_t job_id;	/* job ID, default set by SLURM */
	uint16_t kill_on_node_fail; /* 1 if node failure to kill job,
				 * 0 otherwise,default=1 */
	char *licenses;		/* licenses required by the job */
	uint16_t mail_type;	/* see MAIL_JOB_ definitions above */
	char *mail_user;	/* user to receive notification */
	char *mem_bind;		/* binding map for map/mask_cpu */
	uint16_t mem_bind_type;	/* see mem_bind_type_t */
	char *name;		/* name of the job, default "" */
	char *network;		/* network use spec */
	uint16_t nice;		/* requested priority change,
				 * NICE_OFFSET == no change */
	uint32_t num_tasks;	/* number of tasks to be started,
				 * for batch only */
	uint8_t open_mode;	/* out/err open mode truncate or append,
				 * see OPEN_MODE_* */
	uint16_t other_port;	/* port to send various notification msg to */
	uint8_t overcommit;	/* over subscribe resources, for batch only */
	char *partition;	/* name of requested partition,
				 * default in SLURM config */
	uint16_t plane_size;	/* plane size when task_dist =
				   SLURM_DIST_PLANE */
	uint32_t priority;	/* relative priority of the job,
				 * explicitly set only for user root,
				 * 0 == held (don't initiate) */
	char *qos;		/* Quality of Service */
	char *resp_host;	/* NOTE: Set by slurmctld */
	char *req_nodes;	/* comma separated list of required nodes
				 * default NONE */
	uint16_t requeue;	/* enable or disable job requeue option */
	char *reservation;	/* name of reservation to use */
	char *script;		/* the actual job script, default NONE */
	uint16_t shared;	/* 1 if job can share nodes with other jobs,
				 * 0 if job needs exclusive access to the node,
				 * or NO_VAL to accept the system default.
				 * SHARED_FORCE to eliminate user control. */
	char **spank_job_env;	/* environment variables for job prolog/epilog
				 * scripts as set by SPANK plugins */
	uint32_t spank_job_env_size; /* element count in spank_env */
	uint16_t task_dist;	/* see enum task_dist_state */
	uint32_t time_limit;	/* maximum run time in minutes, default is
				 * partition limit */
	uint32_t user_id;	/* set only if different from current UID,
				 * can only be explicitly set by user root */
	uint16_t warn_signal;	/* signal to send when approaching end time */
	uint16_t warn_time;	/* time before end to send signal (seconds) */
	char *work_dir;		/* pathname of working directory */

	/* job constraints: */
	uint16_t job_min_cpus;    /* minimum # CPUs per node, default=0 */
	uint32_t job_min_memory;   /* minimum real memory per node OR
				    * real memory per CPU | MEM_PER_CPU,
				    * default=0 (no limit) */
	uint32_t job_min_tmp_disk; /* minimum tmp disk per node, default=0 */
	uint32_t num_procs;	/* total count of processors required,
				 * default=0 */
	uint32_t min_nodes;	/* minimum number of nodes required by job,
				 * default=0 */
	uint32_t max_nodes;	/* maximum number of nodes usable by job,
				 * default=0 */
	uint16_t min_sockets;	/* number of sockets per node required by job */
	uint16_t min_cores;	/* number of cores per cpu required by job */
	uint16_t min_threads;	/* number of threads per core required by job */
	uint16_t cpus_per_task;	/* number of processors required for each task */
	uint16_t ntasks_per_node;/* number of tasks to invoke on each node */
	uint16_t ntasks_per_socket;/* number of tasks to invoke on each socket */
	uint16_t ntasks_per_core;/* number of tasks to invoke on each core */

/*
 * The following parameters are only meaningful on a Blue Gene
 * system at present. Some will be of value on other system. Don't remove these
 * they are needed for LCRM and others that can't talk to the opaque data type
 * select_jobinfo.
 */
#ifdef HAVE_BG
	uint16_t geometry[SYSTEM_DIMENSIONS];	/* node count in various
				 * dimensions, e.g. X, Y, and Z */
#endif
	uint16_t conn_type;	/* see enum connection_type */
	uint16_t reboot;	/* force node reboot before startup */
	uint16_t rotate;	/* permit geometry rotation if set */
	char *blrtsimage;       /* BlrtsImage for block */
	char *linuximage;       /* LinuxImage for block */
	char *mloaderimage;     /* MloaderImage for block */
	char *ramdiskimage;     /* RamDiskImage for block */

/* End of Blue Gene specific values */

	select_jobinfo_t *select_jobinfo; /* opaque data type,
					  * SLURM internal use only */
	char *std_err;		/* pathname of stderr */
	char *std_in;		/* pathname of stdin */
	char *std_out;		/* pathname of stdout */
	char *wckey;            /* wckey for job */
} job_desc_msg_t;

typedef struct job_info {
	char *account;		/* charge to specified account */
	char    *alloc_node;	/* local node making resource alloc */
	uint32_t alloc_sid;	/* local sid making resource alloc */
	uint32_t assoc_id;	/* association id for job */
	uint16_t batch_flag;	/* 1 if batch: queued job with script */
	char *command;		/* command to be executed */
	char *comment;		/* arbitrary comment (used by Moab scheduler) */
	uint16_t contiguous;	/* 1 if job requires contiguous nodes */
	uint16_t cpus_per_task;	/* number of processors required for each task */
	char *dependency;	/* syncrhonize job execution with other jobs */
	time_t eligible_time;	/* time job is eligible for running */
	time_t end_time;	/* time of termination, actual or expected */
	char *exc_nodes;	/* comma separated list of excluded nodes */
	int *exc_node_inx;	/* excluded list index pairs into node_table:
				 * start_range_1, end_range_1,
				 * start_range_2, .., -1  */
	uint32_t exit_code;	/* exit code for job (status from wait call) */
	char *features;		/* comma separated list of required features */
	uint32_t group_id;	/* group job sumitted as */
	uint32_t job_id;	/* job ID */
	uint32_t job_min_memory;   /* minimum real memory per node, default=0 */
	uint16_t job_min_cpus;	   /* minimum # CPUs per node, default=0 */
	uint32_t job_min_tmp_disk; /* minimum tmp disk per node, default=0 */
	uint16_t job_state;	/* state of the job, see enum job_states */
	char *licenses;		/* licenses required by the job */
	uint32_t max_nodes;	/* maximum number of nodes usable by job */
	uint16_t min_cores;	/* minimum number of cores per cpu */
	uint16_t min_sockets;	/* minimum number of sockets per node */
	uint16_t min_threads;	/* minimum number of threads per core */
	char *name;		/* name of the job */
	char *network;		/* network specification */
	char *nodes;		/* list of nodes allocated to job */
	uint16_t nice;	  	/* requested priority change */
	int *node_inx;		/* list index pairs into node_table for *nodes:
				 * start_range_1, end_range_1,
				 * start_range_2, .., -1  */
	uint16_t ntasks_per_core;/* number of tasks to invoke on each core */
	uint16_t ntasks_per_node;/* number of tasks to invoke on each node */
	uint16_t ntasks_per_socket;/* number of tasks to invoke on each socket */

	uint32_t num_nodes;	/* minimum number of nodes required by job */
	uint32_t num_procs;	/* number of processors required by job */
	char *partition;	/* name of assigned partition */
	time_t pre_sus_time;	/* time job ran prior to last suspend */
	uint32_t priority;	/* relative priority of the job,
				 * 0=held, 1=required nodes DOWN/DRAINED */
	char *qos;		/* Quality of Service */
	char *req_nodes;	/* comma separated list of required nodes */
	int *req_node_inx;	/* required list index pairs into node_table:
				 * start_range_1, end_range_1,
				 * start_range_2, .., -1  */
	uint16_t requeue;       /* enable or disable job requeue option */
	uint16_t restart_cnt;	/* count of job restarts */
	char *resv_name;	/* reservation name */
	select_jobinfo_t *select_jobinfo; /* opaque data type,
				 * process using slurm_get_select_jobinfo() */
	job_resources_t *job_resrcs; /* opaque data type, job resources */
	uint16_t shared;	/* 1 if job can share nodes with other jobs */
	time_t start_time;	/* time execution begins, actual or expected */
	char *state_desc;	/* optional details for state_reason */
	uint16_t state_reason;	/* reason job still pending or failed, see
				 * slurm.h:enum job_state_reason */
	time_t submit_time;	/* time of job submission */
	time_t suspend_time;	/* time job last suspended or resumed */
	uint32_t time_limit;	/* maximum run time in minutes or INFINITE */
	uint32_t user_id;	/* user the job runs as */
	char *wckey;            /* wckey for job */
	char *work_dir;		/* pathname of working directory */
} job_info_t;

typedef struct job_info_msg {
	time_t last_update;	/* time of latest info */
	uint32_t record_count;	/* number of records */
	job_info_t *job_array;	/* the job records */
} job_info_msg_t;

typedef struct slurm_step_layout {
	uint32_t node_cnt;	/* node count */
	char *node_list;        /* list of nodes in step */
	uint16_t plane_size;	/* plane size when task_dist =
				 * SLURM_DIST_PLANE */
	/* Array of length "node_cnt". Each element of the array
	 * is the number of tasks assigned to the corresponding node */
	uint16_t *tasks;
	uint32_t task_cnt;	/* total number of tasks in the step */
	uint16_t task_dist;	/* see enum task_dist_state */
	/* Array (of length "node_cnt") of task ID arrays.  The length
	 * of each subarray is designated by the corresponding value in
	 * the tasks array. */
	uint32_t **tids;	/* host id => task id mapping */
} slurm_step_layout_t;

typedef struct slurm_step_io_fds {
	struct {
		int fd;
		uint32_t taskid;
		uint32_t nodeid;
	} in, out, err;
} slurm_step_io_fds_t;

#define SLURM_STEP_IO_FDS_INITIALIZER {{0, (uint32_t)-1, (uint32_t)-1},\
				   {1, (uint32_t)-1, (uint32_t)-1},\
				   {2, (uint32_t)-1, (uint32_t)-1}}

typedef struct launch_tasks_response_msg {
	uint32_t return_code;
	char    *node_name;
	uint32_t srun_node_id;
	uint32_t count_of_pids;
	uint32_t *local_pids;
	uint32_t *task_ids; /* array of length count_of_pids */
} launch_tasks_response_msg_t;

typedef struct task_ext_msg {
	uint32_t num_tasks;
	uint32_t *task_id_list;
	uint32_t return_code;
	uint32_t job_id;
	uint32_t step_id;
} task_exit_msg_t;

typedef struct srun_ping_msg {
	uint32_t job_id;	/* slurm job_id */
	uint32_t step_id;	/* step_id or NO_VAL */
} srun_ping_msg_t;

typedef struct srun_job_complete_msg {
	uint32_t job_id;        /* slurm job_id */
	uint32_t step_id;       /* step_id or NO_VAL */
} srun_job_complete_msg_t;

typedef struct srun_timeout_msg {
	uint32_t job_id;	/* slurm job_id */
	uint32_t step_id;	/* step_id or NO_VAL */
	time_t   timeout;	/* when job scheduled to be killed */
} srun_timeout_msg_t;

typedef struct srun_user_msg {
	uint32_t job_id;	/* slurm job_id */
	char *msg;		/* message to user's srun */
} srun_user_msg_t;

typedef struct srun_node_fail_msg {
	uint32_t job_id;	/* slurm job_id */
	char *nodelist;		/* name of failed node(s) */
	uint32_t step_id;	/* step_id or NO_VAL */
} srun_node_fail_msg_t;

typedef struct srun_step_missing_msg {
	uint32_t job_id;	/* slurm job_id */
	char *nodelist;		/* name of node(s) lacking this step */
	uint32_t step_id;	/* step_id or NO_VAL */
} srun_step_missing_msg_t;

typedef struct {
	uint16_t ckpt_interval;	/* checkpoint interval in minutes */
	uint32_t cpu_count;	/* number of required processors */
	uint16_t exclusive;	/* 1 if CPUs not shared with other steps */
	uint16_t immediate;	/* 1 if allocate to run or fail immediately,
				 * 0 if to be queued awaiting resources */
	uint32_t job_id;	/* job ID */
	uint32_t mem_per_cpu;	/* memory required per CPU (MB),
				 * use job limit if 0 */
	char *ckpt_dir;		/* directory to store checkpoint image files */
	char *name;		/* name of the job step */
	char *network;		/* network use spec */
	uint8_t no_kill;	/* 1 if no kill on node failure */
	uint32_t node_count;	/* number of required nodes */
	char *node_list;	/* list of required nodes */
	bool overcommit;	/* "true" to allow the allocation of more tasks
				 * to a node than available processors,
				 * "false" to accept at most one task per
				 * processor. "false" by default. */
	uint16_t plane_size;	/* plane size when task_dist =
				 * SLURM_DIST_PLANE */
	uint16_t relative;	/* first node to use of job's allocation */
	uint16_t resv_port_cnt;	/* reserve ports if set */
	uint32_t task_count;	/* number of tasks required */
	uint16_t task_dist;	/* see enum task_dist_state, default
				 * is SLURM_DIST_CYCLIC */
	uint32_t time_limit;	/* step time limit */
	uid_t uid;		/* user ID */
	uint16_t verbose_level; /* for extra logging decisions in step
				 * launch api */
} slurm_step_ctx_params_t;

typedef struct {
	uint32_t argc;
	char **argv;
	uint32_t envc;
	char **env;
	char *cwd;
	bool user_managed_io;
	uint32_t msg_timeout; /* timeout set for sending message */

	/* START - only used if user_managed_io is false */
	bool buffered_stdio;
	bool labelio;
	char *remote_output_filename;
	char *remote_error_filename;
	char *remote_input_filename;
	slurm_step_io_fds_t local_fds;
	/*  END  - only used if user_managed_io is false */

	uint32_t gid;
	bool multi_prog;
	uint32_t slurmd_debug;  /* remote slurmd debug level */
	bool parallel_debug;
	char *task_prolog;
	char *task_epilog;
	uint16_t cpu_bind_type;	/* use cpu_bind_type_t */
	char *cpu_bind;
	uint16_t mem_bind_type;	/* use mem_bind_type_t */
	char *mem_bind;

	uint16_t max_sockets;
	uint16_t max_cores;
	uint16_t max_threads;
	uint16_t cpus_per_task;
	uint16_t task_dist;
	bool preserve_env;

	char *mpi_plugin_name;
	uint8_t open_mode;
	uint16_t acctg_freq;
	bool pty;
	char *ckpt_dir;
	char *restart_dir;
	char **spank_job_env;	/* environment variables for job prolog/epilog
				 * scripts as set by SPANK plugins */
	uint32_t spank_job_env_size;	/* element count in spank_env */
} slurm_step_launch_params_t;

typedef struct {
	void (*task_start)(launch_tasks_response_msg_t *);
	void (*task_finish)(task_exit_msg_t *);
} slurm_step_launch_callbacks_t;

typedef struct {
	void (*ping)(srun_ping_msg_t *);
	void (*job_complete)(srun_job_complete_msg_t *);
	void (*timeout)(srun_timeout_msg_t *);
	void (*user_msg)(srun_user_msg_t *);
	void (*node_fail)(srun_node_fail_msg_t *);
} slurm_allocation_callbacks_t;

typedef struct {
	char *ckpt_dir;		/* path to store checkpoint image files */
	uint16_t ckpt_interval;	/* checkpoint interval in minutes */
	uint32_t job_id;	/* job ID */
	char *name;		/* name of job step */
	char *network;		/* network specs for job step */
	char *nodes;		/* list of nodes allocated to job_step */
	int *node_inx;		/* list index pairs into node_table for *nodes:
				 * start_range_1, end_range_1,
				 * start_range_2, .., -1  */
	uint32_t num_cpus;	/* how many cpus are being used by step */
	uint32_t num_tasks;	/* number of tasks */
	char *partition;	/* name of assigned partition */
	char *resv_ports;	/* ports allocated for MPI */
	time_t run_time;	/* net run time (factor out time suspended) */
	time_t start_time;	/* step start time */
	uint32_t step_id;	/* step ID */
	uint32_t time_limit;	/* step time limit */
	uint32_t user_id;	/* user the job runs as */
} job_step_info_t;

typedef struct job_step_info_response_msg {
	time_t last_update;		/* time of latest info */
	uint32_t job_step_count;	/* number of records */
	job_step_info_t *job_steps;	/* the job step records */
} job_step_info_response_msg_t;

typedef struct node_info {
	char *arch;		/* computer architecture */
	uint16_t cores;         /* number of cores per CPU */
	uint16_t cpus;		/* configured count of cpus running on
				 * the node */
	char *features;		/* arbitrary list of features for node */
	char *name;		/* node name */
	uint16_t node_state;	/* see enum node_states */
	char *os;		/* operating system currently running */
	uint32_t real_memory;	/* configured MB of real memory on the node */
	char *reason;		/* reason for node being DOWN or DRAINING */
	uint16_t sockets;       /* number of sockets per node */
	uint16_t threads;       /* number of threads per core */
	uint32_t tmp_disk;	/* configured MB of total disk in TMP_FS */
	uint32_t weight;	/* arbitrary priority of node for scheduling */
	select_nodeinfo_t *select_nodeinfo;  /* opaque data structure,
					     * use slurm_get_select_nodeinfo()
					     * to access conents */
} node_info_t;

typedef struct node_info_msg {
	time_t last_update;		/* time of latest info */
	uint32_t node_scaling;          /* the amount of nodes per
					   each record used for
					   systems like bluegene
					   where SLURM handles a
					   bluegene midplane as a
					   single SLURM node. */
	uint32_t record_count;		/* number of records */
	node_info_t *node_array;	/* the node records */
} node_info_msg_t;

typedef struct topo_info {
	uint16_t level;			/* level in hierarchy, leaf=0 */
	uint32_t link_speed;		/* link speed, arbitrary units */
	char *name;			/* switch name */
	char *nodes;			/* name if direct descendent nodes */
	char *switches;			/* name if direct descendent switches */
} topo_info_t;

typedef struct topo_info_response_msg {
	uint32_t record_count;		/* number of records */
	topo_info_t *topo_array;	/* the switch topology records */
} topo_info_response_msg_t;

typedef struct job_alloc_info_msg {
	uint32_t job_id;	/* job ID */
} job_alloc_info_msg_t;

typedef struct partition_info {
	char *allow_alloc_nodes;/* list names of allowed allocating nodes */
	char *allow_groups;	/* comma delimited list of groups,
				 * null indicates all */
	uint16_t default_part;	/* 1 if this is default partition */
	uint32_t default_time;	/* minutes, NO_VAL or INFINITE */
	uint16_t disable_root_jobs; /* 1 if user root jobs disabled */
	uint16_t hidden;	/* 1 if partition is hidden by default */
	uint32_t max_nodes;	/* per job or INFINITE */
	uint16_t max_share;	/* number of jobs to gang schedule */
	uint32_t max_time;	/* minutes or INFINITE */
	uint32_t min_nodes;	/* per job */
	char *name;		/* name of the partition */
	int *node_inx;		/* list index pairs into node_table:
				 * start_range_1, end_range_1,
				 * start_range_2, .., -1  */
	char *nodes;		/* list names of nodes in partition */
	uint16_t priority;	/* scheduling priority for jobs */
	uint16_t root_only;	/* 1 if allocate must come for user root */
	uint16_t state_up;	/* 1 if state is up, 0 if down */
	uint32_t total_cpus;	/* total number of cpus in the partition */
	uint32_t total_nodes;	/* total number of nodes in the partition */
} partition_info_t;

typedef struct delete_partition_msg {
	char *name;		/* name of partition to be delete */
} delete_part_msg_t;

typedef struct resource_allocation_response_msg {
	uint32_t job_id;	/* assigned job id */
	char *node_list;	/* assigned list of nodes */
	uint32_t num_cpu_groups;/* elements in below cpu arrays */
	uint16_t *cpus_per_node;/* cpus per node */
	uint32_t *cpu_count_reps;/* how many nodes have same cpu count */
	uint32_t node_cnt;	/* count of nodes */
	uint32_t error_code;	/* error code for warning message */
	select_jobinfo_t *select_jobinfo;	/* opaque data structure,
			* use slurm_get_select_jobinfo() to access conents */
} resource_allocation_response_msg_t;

typedef struct job_alloc_info_response_msg {
	uint32_t job_id;	/* assigned job id */
	char *node_list;	/* assigned list of nodes */
	uint32_t num_cpu_groups;/* elements in below cpu arrays */
	uint16_t *cpus_per_node;/* cpus per node */
	uint32_t *cpu_count_reps;/* how many nodes have same cpu count */
	uint32_t node_cnt;	/* count of nodes */
	slurm_addr *node_addr;	/* network addresses */
	uint32_t error_code;	/* error code for warning message */
	select_jobinfo_t *select_jobinfo;	/* opaque data structure,
			* use slurm_get_select_jobinfo() to access conents */
} job_alloc_info_response_msg_t;

typedef struct partition_info_msg {
	time_t last_update;	/* time of latest info */
	uint32_t record_count;	/* number of records */
	partition_info_t *partition_array; /* the partition records */
} partition_info_msg_t;


/* BLUEGENE specific information */

typedef struct {
	char *bg_block_id;
	char *blrtsimage;       /* BlrtsImage for this block */
	int *bp_inx;            /* list index pairs into node_table for *nodes:
				 * start_range_1, end_range_1,
				 * start_range_2, .., -1  */
	uint16_t conn_type;
	char *ionodes;
	int *ionode_inx;        /* list index pairs for ionodes in the
				 * node listed for *ionodes:
				 * start_range_1, end_range_1,
				 * start_range_2, .., -1  */
	uint32_t job_running;
	char *linuximage;       /* LinuxImage for this block */
	char *mloaderimage;     /* mloaderImage for this block */
	char *nodes;
	uint32_t node_cnt;
	uint16_t node_use;
	char *owner_name;
	char *ramdiskimage;     /* RamDiskImage for this block */
	uint16_t state;
} block_info_t;

typedef struct {
	block_info_t *block_array;
	time_t    last_update;
	uint32_t  record_count;
} block_info_msg_t;

typedef block_info_t update_block_msg_t;

/*
 * slurm_print_block_info_msg - output information about all Bluegene
 *	blocks based upon message as loaded using slurm_load_block
 * IN out - file to write to
 * IN info_ptr - block information message pointer
 * IN one_liner - print as a single line if true
 */
extern void slurm_print_block_info_msg PARAMS((
	FILE *out, block_info_msg_t *info_ptr, int one_liner));

/*
 * slurm_print_block_info - output information about a specific Bluegene
 *	block based upon message as loaded using slurm_load_block
 * IN out - file to write to
 * IN bg_info_ptr - an individual block information record pointer
 * IN one_liner - print as a single line if true
 */
extern void slurm_print_block_info PARAMS((
	FILE *out, block_info_t *bg_info_ptr, int one_liner));

/*
 * slurm_sprint_block_info - output information about a specific Bluegene
 *	block based upon message as loaded using slurm_load_block
 * IN bg_info_ptr - an individual partition information record pointer
 * IN one_liner - print as a single line if true
 * RET out - char * containing formatted output (must be freed after call)
 *           NULL is returned on failure.
 */
extern char *slurm_sprint_block_info PARAMS((
	block_info_t * bg_info_ptr, int one_liner));

/*
 * slurm_load_block_info - issue RPC to get slurm all node select plugin
 *      information if changed since update_time
 * IN update_time - time of current configuration data
 * IN block_info_msg_pptr - place to store a node select configuration
 *      pointer
 * RET 0 or a slurm error code
 * NOTE: free the response using slurm_free_block_info_msg
 */
extern int slurm_load_block_info PARAMS((
	time_t update_time,
	block_info_msg_t **block_info_msg_pptr));

/*
 * slurm_free_block_info_msg - free buffer returned by
 *	slurm_load_block
 * IN block_info_msg_pptr - data is freed and pointer is set to NULL
 * RET 0 or a slurm error code
 */
extern int slurm_free_block_info_msg PARAMS((
	block_info_msg_t **block_info_msg_pptr));

/* update state or remove block */
extern int slurm_update_block PARAMS((update_block_msg_t *block_msg));

void slurm_init_update_block_msg PARAMS((update_block_msg_t *update_block_msg));


/*********************************/

/*
 * Resource reservation data structures.
 * Create, show, modify and delete functions are required
 */
#define RESERVE_FLAG_MAINT	0x0001	/* Set MAINT flag */
#define RESERVE_FLAG_NO_MAINT	0x0002	/* Clear MAINT flag */
#define RESERVE_FLAG_DAILY	0x0004	/* Set DAILY flag */
#define RESERVE_FLAG_NO_DAILY	0x0008	/* Clear DAILY flag */
#define RESERVE_FLAG_WEEKLY	0x0010	/* Set WEEKLY flag */
#define RESERVE_FLAG_NO_WEEKLY	0x0020	/* Clear WEEKLY flag */
#define RESERVE_FLAG_IGN_JOBS	0x0040	/* Ignore running jobs */
#define RESERVE_FLAG_NO_IGN_JOB	0x0080	/* Clear ignore running jobs */
#define RESERVE_FLAG_OVERLAP	0x4000	/* Permit to overlap others */
#define RESERVE_FLAG_SPEC_NODES	0x8000	/* Contains specific nodes */

typedef struct reserve_info {
	char *accounts;		/* names of accounts permitted to use */
	time_t end_time;	/* end time of reservation */
	char *features;		/* required node features */
	uint16_t flags;		/* see RESERVE_FLAG_* above */
	char *licenses;		/* names of licenses to be reserved */
	char *name;		/* name of reservation */
	uint32_t node_cnt;	/* count of nodes required */
	int *node_inx;		/* list index pairs into node_table for *nodes:
				 * start_range_1, end_range_1,
				 * start_range_2, .., -1  */
	char *node_list;	/* list of reserved nodes or ALL */
	char *partition;	/* name of partition to be used */
	time_t start_time;	/* start time of reservation */
	char *users;		/* names of users permitted to use */
} reserve_info_t;

typedef struct reserve_info_msg {
	time_t last_update;	/* time of latest info */
	uint32_t record_count;	/* number of records */
	reserve_info_t *reservation_array; /* the reservation records */
} reserve_info_msg_t;

typedef struct resv_desc_msg {
	char *accounts;		/* names of accounts permitted to use */
	uint32_t duration;	/* duration of reservation in seconds */
	time_t end_time;	/* end time of reservation */
	char *features;		/* required node features */
	uint16_t flags;		/* see RESERVE_FLAG_* above */
	char *licenses;		/* names of licenses to be reserved */
	char *name;		/* name of reservation (optional on create) */
	uint32_t node_cnt;	/* count of nodes required */
	char *node_list;	/* list of reserved nodes or ALL */
	char *partition;	/* name of partition to be used */
	time_t start_time;	/* start time of reservation */
	char *users;		/* names of users permitted to use */
} resv_desc_msg_t;

typedef struct reserve_response_msg {
	char *name;		/* name of reservation */
} reserve_response_msg_t;

typedef struct reservation_name_msg {
	char *name;		/* name of reservation just created or
				 * to be delete */
} reservation_name_msg_t;


#define DEBUG_FLAG_SELECT_TYPE	0x00000001	/* SelectType plugin */
#define DEBUG_FLAG_STEPS	0x00000002	/* slurmctld steps */
#define DEBUG_FLAG_TRIGGERS	0x00000004	/* slurmctld triggers */
#define DEBUG_FLAG_CPU_BIND	0x00000008	/* CPU binding */
#define DEBUG_FLAG_WIKI		0x00000010	/* wiki communications */

#define PREEMPT_MODE_OFF	0x0000	/* disable job preemption */
#define PREEMPT_MODE_SUSPEND	0x0001	/* suspend jobs to preempt */
#define PREEMPT_MODE_REQUEUE	0x0002	/* requeue or kill jobs to preempt */
#define PREEMPT_MODE_CHECKPOINT	0x0003	/* checkpoint job to preempt,
					 * no automatic restart */
#define PREEMPT_MODE_CANCEL	0x0004	/* always cancel the job */
#define PREEMPT_MODE_GANG	0x8000	/* enable gang scheduling */

typedef struct slurm_ctl_conf {
	time_t last_update;	/* last update time of the build parameters */
	uint16_t accounting_storage_enforce; /* job requires valid association:
					 * user/account/partition/cluster */
	char *accounting_storage_backup_host;	/* accounting storage
						 * backup host */
	char *accounting_storage_host;	/* accounting storage host */
	char *accounting_storage_loc;	/* accounting storage (db table)
					 * location */
	char *accounting_storage_pass;	/* accounting storage
					 * password */
	uint32_t accounting_storage_port;/* node accountinging storage port */
	char *accounting_storage_type; /* accounting storage type */
	char *accounting_storage_user; /* accounting storage user */
	char *authtype;		/* authentication type */
	char *backup_addr;	/* comm path of slurmctld secondary server */
	char *backup_controller;/* name of slurmctld secondary server */
	uint16_t batch_start_timeout;	/* max secs for batch job to start */
	time_t boot_time;	/* time slurmctld last booted */
	uint16_t cache_groups;	/* cache /etc/groups to avoid initgroups(2) */
	char *checkpoint_type;	/* checkpoint plugin type */
	char *cluster_name;     /* general name of the entire cluster */
	uint16_t complete_wait;	/* seconds to wait for job completion before
				 * scheduling another job */
	char *control_addr;	/* comm path of slurmctld primary server */
	char *control_machine;	/* name of slurmctld primary server */
	char *crypto_type;	/* cryptographic signature plugin */
	uint32_t debug_flags;	/* see DEBUG_FLAG_* above for values */
	uint32_t def_mem_per_cpu; /* default MB memory per allocated CPU */
	uint16_t disable_root_jobs; /* if set then user root can't run jobs */
	uint16_t enforce_part_limits;	/* if set, reject job exceeding
					 * partition size and/or time limits */
	char *epilog;		/* pathname of job epilog */
	uint32_t epilog_msg_time;  /* usecs for slurmctld to process an
				 * epilog complete message */
	char *epilog_slurmctld;	/* pathname of job epilog run by slurmctld */
	uint16_t fast_schedule;	/* 1 to *not* check configurations by node
				 * (only check configuration file, faster) */
	uint32_t first_job_id;	/* first slurm generated job_id to assign */
	uint16_t get_env_timeout; /* timeout for srun --get-user-env option */
	uint16_t health_check_interval;	/* secs between health checks */
	char * health_check_program;	/* pathname of health check program */
	uint16_t inactive_limit;/* seconds of inactivity before a
				 * inactive resource allocation is released */
	uint16_t job_acct_gather_freq; /* poll frequency for job accounting
					* gather plugins */
	char *job_acct_gather_type; /* job accounting gather type */
	char *job_ckpt_dir;	/* directory saving job record checkpoint */
	char *job_comp_host;	/* job completion logging host */
	char *job_comp_loc;	/* job completion logging location */
	char *job_comp_pass;	/* job completion storage password */
	uint32_t job_comp_port;	/* job completion storage port */
	char *job_comp_type;	/* job completion storage type */
	char *job_comp_user;	/* job completion storage user */
	char *job_credential_private_key;	/* path to private key */
	char *job_credential_public_certificate;/* path to public certificate*/
	uint16_t job_file_append; /* if set, append to stdout/err file */
	uint16_t job_requeue;	/* If set, jobs get requeued on node failre */
	uint16_t kill_on_bad_exit; /* If set, the job will be
				 * terminated immediately when one of
				 * the processes is aborted or crashed */
	uint16_t kill_wait;	/* seconds between SIGXCPU to SIGKILL
				 * on job termination */
	char *licenses;		/* licenses available on this cluster */
	char *mail_prog;	/* pathname of mail program */
	uint16_t max_job_cnt;	/* maximum number of active jobs */
	uint32_t max_mem_per_cpu; /* maximum MB memory per allocated CPU */
	uint16_t max_tasks_per_node; /* maximum tasks per node */
	uint16_t min_job_age;	/* COMPLETED jobs over this age (secs)
				 * purged from in memory records */
	char *mpi_default;	/* Default version of MPI in use */
	char *mpi_params;	/* MPI parameters */
	uint16_t msg_timeout;	/* message timeout */
	uint32_t next_job_id;	/* next slurm generated job_id to assign */
	char *node_prefix;      /* prefix of nodes in partition, only set in
				   bluegene clusters NULL otherwise */
	uint16_t over_time_limit; /* job's time limit can be exceeded by this
				   * number of minutes before cancellation */
	char *plugindir;	/* pathname to plugins */
	char *plugstack;        /* pathname to plugin stack config
				 * file */
	uint16_t preempt_mode;	/* See PREEMPT_MODE_* above */
	char *preempt_type;	/* job preemption selection plugin */
	uint32_t priority_decay_hl; /* priority decay half life in
				     * seconds */
	uint32_t priority_calc_period; /* seconds between priority decay
					* calculation */
	uint16_t priority_favor_small; /* favor small jobs over large */
	uint32_t priority_max_age; /* time when not to add any more
				    * priority to a job if reached */
	uint16_t priority_reset_period; /* when to clear usage,
					 * see PRIORITY_RESET_* */
	char *priority_type;    /* priority type plugin */
	uint32_t priority_weight_age; /* weight for age factor */
	uint32_t priority_weight_fs; /* weight for Fairshare factor */
	uint32_t priority_weight_js; /* weight for Job Size factor */
	uint32_t priority_weight_part; /* weight for Partition factor */
	uint32_t priority_weight_qos; /* weight for QOS factor */
	uint16_t private_data;	/* block viewing of information,
				 * see PRIVATE_DATA_* */
	char *proctrack_type;	/* process tracking plugin type */
	char *prolog;		/* pathname of job prolog run by slurmd */
	char *prolog_slurmctld;	/* pathname of job prolog run by slurmctld */
	uint16_t propagate_prio_process; /* 1 if process priority should
					  * be propagated */
	char *propagate_rlimits;/* Propagate (all/specific) resource limits */
	char *propagate_rlimits_except;/* Propagate all rlimits except these */
	char *resume_program;	/* program to make nodes full power */
	uint16_t resume_rate;	/* nodes to make full power, per minute */
	uint16_t resume_timeout;/* time required in order to perform a node
				 * resume operation */
	uint16_t resv_over_run;	/* how long a running job can exceed
				 * reservation time */
	uint16_t ret2service;	/* 1 return DOWN node to service at
				 * registration */
	char *salloc_default_command; /* default salloc command */
	char *sched_params;	/* SchedulerParameters OR
				 * contents of scheduler plugin config file */
	uint16_t sched_time_slice;	/* gang scheduler slice time, secs */
	char *schedtype;	/* type of scheduler to use */
	uint16_t schedport;	/* port for scheduler connection */
	uint16_t schedrootfltr;	/* 1 if rootOnly partitions should be
				 * filtered from scheduling (if needed) */
	char *select_type;	/* type of node selector to use */
	void *select_conf_key_pairs; /* key-pair list which can be
				      * listed with slurm_print_key_pairs */
	uint16_t select_type_param; /* Parameters
				 * describing the select_type plugin */
	char *slurm_conf;	/* pathname of slurm config file */
	uint32_t slurm_user_id;	/* uid of slurm_user_name */
	char *slurm_user_name;	/* user that slurmctld runs as */
	uint32_t slurmd_user_id;/* uid of slurmd_user_name */
	char *slurmd_user_name;	/* user that slurmd runs as */
	uint16_t slurmctld_debug; /* slurmctld logging level */
	char *slurmctld_logfile;/* where slurmctld error log gets written */
	char *slurmctld_pidfile;/* where to put slurmctld pidfile         */
	uint32_t slurmctld_port;/* default communications port to slurmctld */
	uint16_t slurmctld_timeout;/* seconds that backup controller waits
				 * on non-responding primarly controller */
	uint16_t slurmd_debug;	/* slurmd logging level */
	char *slurmd_logfile;	/* where slurmd error log gets written */
	char *slurmd_pidfile;   /* where to put slurmd pidfile           */
	uint32_t slurmd_port;	/* default communications port to slurmd */
	char *slurmd_spooldir;	/* where slurmd put temporary state info */
	uint16_t slurmd_timeout;/* how long slurmctld waits for slurmd before
				 * considering node DOWN */
	char *srun_epilog;      /* srun epilog program */
	char *srun_prolog;      /* srun prolog program */
	char *state_save_location;/* pathname of slurmctld state save
				 * directory */
	char *suspend_exc_nodes;/* nodes to not make power saving */
	char *suspend_exc_parts;/* partitions to not make power saving */
	char *suspend_program;	/* program to make nodes power saving */
	uint16_t suspend_rate;	/* nodes to make power saving, per minute */
	uint32_t suspend_time;	/* node idle for this long before power save mode */
	uint16_t suspend_timeout;/* time required in order to perform a node
				 * suspend operation */
	char *switch_type;	/* switch or interconnect type */
	char *task_epilog;	/* pathname of task launch epilog */
	char *task_plugin;	/* task launch plugin */
	uint16_t task_plugin_param;	/* see CPU_BIND_* */
	char *task_prolog;	/* pathname of task launch prolog */
	char *tmp_fs;		/* pathname of temporary file system */
	char *topology_plugin;	/* network topology plugin */
	uint16_t track_wckey;    /* see if we are using wckey or not */
	uint16_t tree_width;    /* number of threads per node to span */
	char *unkillable_program; /* program run by the slurmstepd when
				   * processes in a job step are unkillable */
	uint16_t unkillable_timeout; /* time in seconds, after processes in a
				      * job step have been signalled, before
				      * they are considered "unkillable". */
	uint16_t use_pam;	/* enable/disable PAM support */
	char *version;		/* version of slurmctld */
	uint16_t wait_time;	/* default job --wait time */
	uint16_t z_16;		/* reserved for future use */
	uint32_t z_32;		/* reserved for future use */
	char *z_char;		/* reserved for future use */
} slurm_ctl_conf_t;

typedef struct slurmd_status_msg {
	time_t booted;			/* when daemon was started */
	time_t last_slurmctld_msg;	/* time of last slurmctld message */
	uint16_t slurmd_debug;		/* logging level */
	uint16_t actual_cpus;		/* actual logical processor count */
	uint16_t actual_sockets;	/* actual sockets count */
	uint16_t actual_cores;		/* actual core count */
	uint16_t actual_threads;	/* actual thread per core count */
	uint32_t actual_real_mem;	/* actual real memory in MB */
	uint32_t actual_tmp_disk;	/* actual temp disk space in MB */
	uint32_t pid;			/* process ID */
	char *hostname;			/* local hostname */
	char *slurmd_logfile;		/* slurmd log file location */
	char *step_list;		/* list of active job steps */
	char *version;			/* version running */
} slurmd_status_t;

typedef struct submit_response_msg {
	uint32_t job_id;	/* job ID */
	uint32_t step_id;	/* step ID */
	uint32_t error_code;	/* error code for warning message */
} submit_response_msg_t;

typedef struct slurm_update_node_msg {
	char *node_names;	/* comma separated list of required nodes */
	uint16_t node_state;	/* see enum node_states */
	char *reason;		/* reason for node being DOWN or DRAINING */
	char *features;		/* new feature for node */
	uint32_t weight;	/* new weight for node */
} update_node_msg_t;

typedef struct partition_info update_part_msg_t;

typedef struct job_sbcast_cred_msg {
	uint32_t      job_id;		/* assigned job id */
	slurm_addr   *node_addr;	/* network addresses */
	uint32_t      node_cnt;		/* count of nodes */
	char         *node_list;	/* assigned list of nodes */
	sbcast_cred_t *sbcast_cred;	/* opaque data structure */
} job_sbcast_cred_msg_t;

/* Opaque data type for slurm_step_ctx_* functions */
typedef struct slurm_step_ctx_struct slurm_step_ctx_t;

#define TRIGGER_RES_TYPE_JOB   1
#define TRIGGER_RES_TYPE_NODE  2
#define TRIGGER_TYPE_UP        0x0001
#define TRIGGER_TYPE_DOWN      0x0002
#define TRIGGER_TYPE_FAIL      0x0004
#define TRIGGER_TYPE_TIME      0x0008
#define TRIGGER_TYPE_FINI      0x0010
#define TRIGGER_TYPE_RECONFIG  0x0020
#define TRIGGER_TYPE_BLOCK_ERR 0x0040
#define TRIGGER_TYPE_IDLE      0x0080
#define TRIGGER_TYPE_DRAINED   0x0100

typedef struct trigger_info {
	uint32_t trig_id;	/* trigger ID */
	uint16_t res_type;	/* TRIGGER_RES_TYPE_* */
	char *   res_id;	/* resource ID */
	uint16_t trig_type;	/* TRIGGER_TYPE_* */
	uint16_t offset;	/* seconds from trigger, 0x8000 origin */
	uint32_t user_id;	/* user requesting trigger */
	char *   program;	/* program to execute */
} trigger_info_t;

typedef struct trigger_info_msg {
	uint32_t record_count;		/* number of records */
	trigger_info_t *trigger_array;	/* the trigger records */
} trigger_info_msg_t;

/*****************************************************************************\
 *	RESOURCE ALLOCATION FUNCTIONS
\*****************************************************************************/

/*
 * slurm_init_job_desc_msg - initialize job descriptor with
 *	default values
 * OUT job_desc_msg - user defined job descriptor
 */
extern void slurm_init_job_desc_msg PARAMS((job_desc_msg_t * job_desc_msg));

/*
 * slurm_allocate_resources - allocate resources for a job request
 *   If the requested resources are not immediately available, the slurmctld
 *   will send the job_alloc_resp_msg to the sepecified node and port.
 * IN job_desc_msg - description of resource allocation request
 * OUT job_alloc_resp_msg - response to request.  This only represents
 *   a job allocation if resources are immediately.  Otherwise it just contains
 *   the job id of the enqueued job request.
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 * NOTE: free the allocated using slurm_free_resource_allocation_response_msg
 */
extern int slurm_allocate_resources PARAMS((
	job_desc_msg_t * job_desc_msg ,
	resource_allocation_response_msg_t ** job_alloc_resp_msg));

/*
 * slurm_allocate_resources_blocking
 *	allocate resources for a job request.  This call will block until
 *	the allocation is granted, or the specified timeout limit is reached.
 * IN req - description of resource allocation request
 * IN timeout - amount of time, in seconds, to wait for a response before
 * 	giving up.
 *	A timeout of zero will wait indefinitely.
 * IN pending_callback - If the allocation cannot be granted immediately,
 *      the controller will put the job in the PENDING state.  If
 *      pending callback is not NULL, it will be called with the job_id
 *      of the pending job as the sole parameter.
 *
 * RET allocation structure on success, NULL on error set errno to
 *	indicate the error (errno will be ETIMEDOUT if the timeout is reached
 *      with no allocation granted)
 * NOTE: free the allocation structure using
 *	slurm_free_resource_allocation_response_msg
 */
extern resource_allocation_response_msg_t *
	slurm_allocate_resources_blocking PARAMS((
	const job_desc_msg_t *user_req, time_t timeout,
	void (*pending_callback)(uint32_t job_id)));

/*
 * slurm_free_resource_allocation_response_msg - free slurm resource
 *	allocation response message
 * IN msg - pointer to allocation response message
 * NOTE: buffer is loaded by slurm_allocate_resources
 */
extern void slurm_free_resource_allocation_response_msg PARAMS((
	resource_allocation_response_msg_t * msg));

/*
 * slurm_free_job_alloc_info_response_msg - free slurm resource
 *	allocation lookup message
 * IN msg - pointer to job allocation info response message
 * NOTE: buffer is loaded by slurm_allocation_lookup
 */
extern void slurm_free_job_alloc_info_response_msg PARAMS((
	job_alloc_info_response_msg_t * msg));

/*
 * slurm_allocation_lookup - retrieve info for an existing resource allocation
 * IN job_id - job allocation identifier
 * OUT resp - job allocation information
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 * NOTE: free "info" using slurm_free_job_alloc_info_response_msg
 */
extern int slurm_allocation_lookup PARAMS((
	uint32_t job_id, job_alloc_info_response_msg_t **info));

/*
 * slurm_allocation_lookup_lite - retrieve minor info for an existing
 *				  resource allocation
 * IN job_id - job allocation identifier
 * OUT resp - job allocation information
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 * NOTE: free "info" using slurm_free_job_alloc_info_response_msg
 */
extern int slurm_allocation_lookup_lite PARAMS((
	uint32_t job_id, resource_allocation_response_msg_t **info));

/*
 * slurm_read_hostfile - Read a SLURM hostfile specified by "filename".
 *	"filename" must contain a list of SLURM NodeNames, one per line.
 *	Reads up to "n" number of hostnames from the file. Returns a
 *	string representing a hostlist ranged string of the contents of
 *	the file.  This is a helper function, it does not contact any
 *	SLURM daemons.
 *
 * IN filename - name of SLURM Hostlist file to be read.
 * IN n - number of NodeNames required
 * RET - a string representing the hostlist.  Returns NULL if there are
 *	fewer than "n" hostnames in the file, or if an error occurs.
 *
 * NOTE: Returned string must be freed with free().
 */
extern char *slurm_read_hostfile PARAMS((char *filename, int n));

/*
 * slurm_allocation_msg_thr_create - startup a message handler talking
 * with the controller dealing with messages from the controller during an
 * allocation.
 * IN port - port we are listening for messages on from the controller
 * IN callbacks - callbacks for different types of messages
 * RET allocation_msg_thread_t * or NULL on failure
 */
extern allocation_msg_thread_t *slurm_allocation_msg_thr_create PARAMS(
	(uint16_t *port, const slurm_allocation_callbacks_t *callbacks));

/*
 * slurm_allocation_msg_thr_destroy - shutdown the message handler talking
 * with the controller dealing with messages from the controller during an
 * allocation.
 * IN msg_thr - allocation_msg_thread_t pointer allocated with
 *              slurm_allocation_msg_thr_create
 */
extern void slurm_allocation_msg_thr_destroy PARAMS(
	(allocation_msg_thread_t * msg_thr));
/*
 * slurm_submit_batch_job - issue RPC to submit a job for later execution
 * NOTE: free the response using slurm_free_submit_response_response_msg
 * IN job_desc_msg - description of batch job request
 * OUT slurm_alloc_msg - response to request
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 */
extern int slurm_submit_batch_job PARAMS((
	job_desc_msg_t * job_desc_msg,
	submit_response_msg_t ** slurm_alloc_msg));

/*
 * slurm_free_submit_response_response_msg - free slurm
 *	job submit response message
 * IN msg - pointer to job submit response message
 * NOTE: buffer is loaded by slurm_submit_batch_job
 */
extern void slurm_free_submit_response_response_msg PARAMS((
		submit_response_msg_t *msg));

/*
 * slurm_job_will_run - determine if a job would execute immediately if
 *	submitted now
 * IN job_desc_msg - description of resource allocation request
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 */
extern int slurm_job_will_run PARAMS((job_desc_msg_t * job_desc_msg));

/*
 * slurm_sbcast_lookup - retrieve info for an existing resource allocation
 *	including a credential needed for sbcast
 * IN jobid - job allocation identifier
 * OUT info - job allocation information including a credential for sbcast
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 * NOTE: free the "resp" using slurm_free_sbcast_cred_msg
 */
extern int slurm_sbcast_lookup PARAMS((uint32_t jobid,
				       job_sbcast_cred_msg_t **info));

extern void slurm_free_sbcast_cred_msg PARAMS((job_sbcast_cred_msg_t * msg));

/*****************************************************************************\
 *	JOB/STEP SIGNALING FUNCTIONS
\*****************************************************************************/

/*
 * slurm_kill_job - send the specified signal to all steps of an existing job
 * IN job_id     - the job's id
 * IN signal     - signal number
 * IN batch_flag - 1 to signal batch shell only, otherwise 0
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 */
extern int slurm_kill_job PARAMS((uint32_t job_id, uint16_t signal,
			uint16_t batch_flag));

/*
 * slurm_kill_job_step - send the specified signal to an existing job step
 * IN job_id  - the job's id
 * IN step_id - the job step's id
 * IN signal  - signal number
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 */
extern int slurm_kill_job_step PARAMS((uint32_t job_id, uint32_t step_id,
				       uint16_t signal));

/*
 * slurm_signal_job - send the specified signal to all steps of an existing job
 * IN job_id     - the job's id
 * IN signal     - signal number
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 */
extern int slurm_signal_job PARAMS((uint32_t job_id, uint16_t signal));

/*
 * slurm_signal_job_step - send the specified signal to an existing job step
 * IN job_id  - the job's id
 * IN step_id - the job step's id - use SLURM_BATCH_SCRIPT as the step_id
 *              to send a signal to a job's batch script
 * IN signal  - signal number
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 */
extern int slurm_signal_job_step PARAMS((uint32_t job_id, uint32_t step_id,
					 uint16_t signal));


/*****************************************************************************\
 *	JOB/STEP COMPLETION FUNCTIONS
\*****************************************************************************/

/*
 * slurm_complete_job - note the completion of a job and all of its steps
 * IN job_id - the job's id
 * IN job_return_code - the highest exit code of any task of the job
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 */
extern int slurm_complete_job PARAMS((uint32_t job_id,
	uint32_t job_return_code));

/*
 * slurm_terminate_job - terminates all steps of an existing job by sending
 * 	a REQUEST_TERMINATE_JOB rpc to all slurmd in the the job allocation,
 *      and then calls slurm_complete_job().
 * IN job_id     - the job's id
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 */
extern int slurm_terminate_job PARAMS((uint32_t job_id));

/*
 * slurm_terminate_job_step - terminates a job step by sending a
 * 	REQUEST_TERMINATE_TASKS rpc to all slurmd of a job step, and then
 *	calls slurm_complete_job_step() after verifying that all
 *	nodes in the job step no longer have running tasks from the job
 *	step.  (May take over 35 seconds to return.)
 * IN job_id  - the job's id
 * IN step_id - the job step's id - use SLURM_BATCH_SCRIPT as the step_id
 *              to terminate a job's batch script
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 */
extern int slurm_terminate_job_step PARAMS((
	uint32_t job_id, uint32_t step_id));

/*****************************************************************************\
 *	SLURM TASK SPAWNING FUNCTIONS
\*****************************************************************************/

/*
 * slurm_step_ctx_params_t_init - This initializes parameters
 *	in the structure that you will pass to slurm_step_ctx_create().
 *	This function will NOT allocate any new memory.
 * IN ptr - pointer to a structure allocated by the user.  The structure will
 *      be intialized.
 */
extern void slurm_step_ctx_params_t_init PARAMS((slurm_step_ctx_params_t *ptr));

/*
 * slurm_step_ctx_create - Create a job step and its context.
 * IN step_params - job step parameters
 * RET the step context or NULL on failure with slurm errno set
 * NOTE: Free allocated memory using slurm_step_ctx_destroy.
 */
extern slurm_step_ctx_t *slurm_step_ctx_create PARAMS((
	const slurm_step_ctx_params_t *step_params));

/*
 * slurm_step_ctx_create_no_alloc - Create a job step and its context without
 *                                  getting an allocation.
 * IN step_params - job step parameters
 * IN step_id     - since we are faking it give me the id to use
 * RET the step context or NULL on failure with slurm errno set
 * NOTE: Free allocated memory using slurm_step_ctx_destroy.
 */
extern slurm_step_ctx_t *
slurm_step_ctx_create_no_alloc PARAMS((
	const slurm_step_ctx_params_t *step_params, uint32_t step_id));

/*
 * slurm_step_ctx_get - get parameters from a job step context.
 * IN ctx - job step context generated by slurm_step_ctx_create
 * RET SLURM_SUCCESS or SLURM_ERROR (with slurm_errno set)
 */
extern int slurm_step_ctx_get PARAMS((slurm_step_ctx_t *ctx,
	int ctx_key, ...));

/*
 * slurm_jobinfo_ctx_get - get parameters from jobinfo context.
 * IN jobinfo - job information from context, returned by slurm_step_ctx_get()
 * IN data_type - type of data required, specific to the switch type
 * OUT data - the requested data type
 * RET SLURM_SUCCESS or SLURM_ERROR (with slurm_errno set)
 */
extern int slurm_jobinfo_ctx_get PARAMS((switch_jobinfo_t *jobinfo,
	int data_type, void *data));

/*
 * slurm_step_ctx_daemon_per_node_hack - Hack the step context
 *	to run a single process per node, regardless of the settings
 *	selected at slurm_step_ctx_create time.
 *
 *	This is primarily used on AIX by the slurm_ll_api in support of
 * 	poe.  The slurm_ll_api will want to launch a single pmd daemon
 *	on each node regardless of the number of tasks running on each
 *	node.
 * IN ctx - job step context generated by slurm_step_ctx_create
 * RET SLURM_SUCCESS or SLURM_ERROR (with slurm_errno set)
 */
extern int slurm_step_ctx_daemon_per_node_hack PARAMS((slurm_step_ctx_t *ctx));

/*
 * slurm_step_ctx_destroy - free allocated memory for a job step context.
 * IN ctx - job step context generated by slurm_step_ctx_create
 * RET SLURM_SUCCESS or SLURM_ERROR (with slurm_errno set)
 */
extern int slurm_step_ctx_destroy PARAMS((slurm_step_ctx_t *ctx));

/*
 * slurm_step_launch_params_t_init - initialize a user-allocated
 *      slurm_step_launch_params_t structure with default values.
 *	default values.  This function will NOT allocate any new memory.
 * IN ptr - pointer to a structure allocated by the use.  The structure will
 *      be intialized.
 */
extern void slurm_step_launch_params_t_init
	PARAMS((slurm_step_launch_params_t *ptr));

/*
 * slurm_step_launch - launch a parallel job step
 * IN ctx - job step context generated by slurm_step_ctx_create
 * IN params - job step parameters
 * IN callbacks - Identify functions to be called when various events occur
 * RET SLURM_SUCCESS or SLURM_ERROR (with errno set)
 */
extern int slurm_step_launch PARAMS((slurm_step_ctx_t *ctx,
	const slurm_step_launch_params_t *params,
	const slurm_step_launch_callbacks_t *callbacks));

/*
 * Block until all tasks have started.
 */
extern int slurm_step_launch_wait_start PARAMS((slurm_step_ctx_t *ctx));

/*
 * Block until all tasks have finished (or failed to start altogether).
 */
extern void slurm_step_launch_wait_finish PARAMS((slurm_step_ctx_t *ctx));

/*
 * Abort an in-progress launch, or terminate the fully launched job step.
 *
 * Can be called from a signal handler.
 */
extern void slurm_step_launch_abort PARAMS((slurm_step_ctx_t *ctx));

/*
 * Forward a signal to all those nodes with running tasks
 */
extern void slurm_step_launch_fwd_signal PARAMS((slurm_step_ctx_t *ctx,
	 int signo));

/*****************************************************************************\
 *	SLURM CONTROL CONFIGURATION READ/PRINT/UPDATE FUNCTIONS
\*****************************************************************************/

/*
 * slurm_api_version - Return a single number reflecting the SLURM API's
 *	version number. Use the macros SLURM_VERSION_NUM, SLURM_VERSION_MAJOR,
 *	SLURM_VERSION_MINOR, and SLURM_VERSION_MICRO to work with this value
 * RET API's version number
 */
extern long slurm_api_version PARAMS((void));

/*
 * slurm_load_ctl_conf - issue RPC to get slurm control configuration
 *	information if changed since update_time
 * IN update_time - time of current configuration data
 * IN slurm_ctl_conf_ptr - place to store slurm control configuration
 *	pointer
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 * NOTE: free the response using slurm_free_ctl_conf
 */
extern int slurm_load_ctl_conf PARAMS((
	time_t update_time,
	slurm_ctl_conf_t  **slurm_ctl_conf_ptr));

/*
 * slurm_free_ctl_conf - free slurm control information response message
 * IN msg - pointer to slurm control information response message
 * NOTE: buffer is loaded by slurm_load_ctl_conf
 */
extern void slurm_free_ctl_conf PARAMS((slurm_ctl_conf_t* slurm_ctl_conf_ptr));

/*
 * slurm_print_ctl_conf - output the contents of slurm control configuration
 *	message as loaded using slurm_load_ctl_conf
 * IN out - file to write to
 * IN slurm_ctl_conf_ptr - slurm control configuration pointer
 */
extern void slurm_print_ctl_conf PARAMS((
	FILE * out, slurm_ctl_conf_t* slurm_ctl_conf_ptr));

/*
 * slurm_ctl_conf_2_key_pairs - put the slurm_ctl_conf_t variables into
 *	a List of opaque data type config_key_pair_t
 * IN slurm_ctl_conf_ptr - slurm control configuration pointer
 * RET List of opaque data type config_key_pair_t
 */
extern void *slurm_ctl_conf_2_key_pairs PARAMS((
	slurm_ctl_conf_t* slurm_ctl_conf_ptr));

/*
 * slurm_load_slurmd_status - issue RPC to get the status of slurmd
 *	daemon on this machine
 * IN slurmd_status_ptr - place to store slurmd status information
 * RET 0 or -1 on error
 * NOTE: free the response using slurm_free_slurmd_status()
 */
extern int slurm_load_slurmd_status PARAMS((slurmd_status_t **slurmd_status_ptr));

/*
 * slurm_free_slurmd_status - free slurmd state information
 * IN msg - pointer to slurmd state information
 * NOTE: buffer is loaded by slurm_load_slurmd_status
 */
extern void slurm_free_slurmd_status PARAMS((
		slurmd_status_t* slurmd_status_ptr));

/*
 * slurm_print_slurmd_status - output the contents of slurmd status
 *	message as loaded using slurm_load_slurmd_status
 * IN out - file to write to
 * IN slurmd_status_ptr - slurmd status pointer
 */
void slurm_print_slurmd_status PARAMS((
		FILE* out, slurmd_status_t * slurmd_status_ptr));

/*
 * slurm_print_key_pairs - output the contents of key_pairs
 *	which is a list of opaque data type config_key_pair_t
 * IN out - file to write to
 * IN key_pairs - List contianing key pairs to be printed
 * IN title - title of key pair list
 */
void slurm_print_key_pairs PARAMS((
		FILE* out, void* key_pairs, char *title));

/*****************************************************************************\
 *	SLURM JOB RESOURCES READ/PRINT FUNCTIONS
\*****************************************************************************/

/*
 * slurm_job_cpus_allocated_on_node_id -
 *                        get the number of cpus allocated to a job
 *			  on a node by node id
 * IN job_resrcs_ptr	- pointer to job_resources structure
 * IN node_id		- zero-origin node id in allocation
 * RET number of CPUs allocated to job on this node or -1 on error
 */
extern int slurm_job_cpus_allocated_on_node_id PARAMS(
	(job_resources_t *job_resrcs_ptr, int node_id));

/*
 * slurm_job_cpus_allocated_on_node -
 *                        get the number of cpus allocated to a job
 *			  on a node by node name
 * IN job_resrcs_ptr	- pointer to job_resources structure
 * IN node_name		- name of node
 * RET number of CPUs allocated to job on this node or -1 on error
 */
extern int slurm_job_cpus_allocated_on_node PARAMS(
	(job_resources_t *job_resrcs_ptr, const char *node_name));

/*****************************************************************************\
 *	SLURM JOB CONTROL CONFIGURATION READ/PRINT/UPDATE FUNCTIONS
\*****************************************************************************/

/*
 * slurm_free_job_info_msg - free the job information response message
 * IN msg - pointer to job information response message
 * NOTE: buffer is loaded by slurm_load_jobs.
 */
extern void slurm_free_job_info_msg PARAMS((job_info_msg_t * job_buffer_ptr));

/*
 * slurm_get_end_time - get the expected end time for a given slurm job
 * IN jobid     - slurm job id
 * end_time_ptr - location in which to store scheduled end time for job
 * RET 0 or -1 on error
 */
extern int slurm_get_end_time PARAMS((uint32_t jobid, time_t *end_time_ptr));

/*
 * slurm_get_rem_time - get the expected time remaining for a given job
 * IN jobid     - slurm job id
 * RET remaining time in seconds or -1 on error
 */
extern long slurm_get_rem_time PARAMS((uint32_t jobid));

/*
 * slurm_job_node_ready - report if nodes are ready for job to execute now
 * IN job_id - slurm job id
 * RET: READY_* values defined above
 */
extern int slurm_job_node_ready(uint32_t job_id);

/*
 * slurm_load_job - issue RPC to get job information for one job ID
 * IN job_info_msg_pptr - place to store a job configuration pointer
 * IN job_id -  ID of job we want information about
 * IN show_flags - job filtering options
 * RET 0 or -1 on error
 * NOTE: free the response using slurm_free_job_info_msg
 */
extern int slurm_load_job PARAMS((job_info_msg_t **resp, uint32_t job_id,
	uint16_t show_flags));

/*
 * slurm_load_jobs - issue RPC to get slurm all job configuration
 *	information if changed since update_time
 * IN update_time - time of current configuration data
 * IN job_info_msg_pptr - place to store a job configuration pointer
 * IN show_flags - job filtering options
 * RET 0 or -1 on error
 * NOTE: free the response using slurm_free_job_info_msg
 */
extern int slurm_load_jobs PARAMS((
	time_t update_time, job_info_msg_t **job_info_msg_pptr,
	uint16_t show_flags));

/*
 * slurm_notify_job - send message to the job's stdout,
 *	usable only by user root
 * IN job_id - slurm job_id or 0 for all jobs
 * IN message - arbitrary message
 * RET 0 or -1 on error
 */
extern int slurm_notify_job PARAMS(( uint32_t job_id, char *message ));

/*
 * slurm_pid2jobid - issue RPC to get the slurm job_id given a process_id
 *	on this machine
 * IN job_pid - process_id of interest on this machine
 * OUT job_id_ptr - place to store a slurm job_id
 * RET 0 or -1 on error
 */
extern int slurm_pid2jobid PARAMS(( pid_t job_pid, uint32_t * job_id_ptr )) ;

/*
 * slurm_print_job_info - output information about a specific Slurm
 *	job based upon message as loaded using slurm_load_jobs
 * IN out - file to write to
 * IN job_ptr - an individual job information record pointer
 * IN one_liner - print as a single line if true
 */
extern void slurm_print_job_info PARAMS(( FILE*, job_info_t * job_ptr,
					  int one_liner ));

/*
 * slurm_print_job_info_msg - output information about all Slurm
 *	jobs based upon message as loaded using slurm_load_jobs
 * IN out - file to write to
 * IN job_info_msg_ptr - job information message pointer
 * IN one_liner - print as a single line if true
 */
extern void slurm_print_job_info_msg PARAMS((
	FILE * out, job_info_msg_t * job_info_msg_ptr, int one_liner ));

/*
 * slurm_sprint_job_info - output information about a specific Slurm
 *	job based upon message as loaded using slurm_load_jobs
 * IN job_ptr - an individual job information record pointer
 * IN one_liner - print as a single line if true
 * RET out - char * containing formatted output (must be freed after call)
 *           NULL is returned on failure.
 */
extern char *slurm_sprint_job_info PARAMS(( job_info_t * job_ptr,
					    int one_liner ));

/*
 * slurm_update_job - issue RPC to a job's configuration per request,
 *	only usable by user root or (for some parameters) the job's owner
 * IN job_msg - description of job updates
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 */
extern int slurm_update_job PARAMS(( job_desc_msg_t * job_msg )) ;

/*****************************************************************************\
 *	SLURM JOB STEP CONFIGURATION READ/PRINT/UPDATE FUNCTIONS
\*****************************************************************************/

/*
 * slurm_get_job_steps - issue RPC to get specific slurm job step
 *	configuration information if changed since update_time.
 *	a job_id value of NO_VAL implies all jobs, a step_id value of
 *	NO_VAL implies all steps
 * IN update_time - time of current configuration data
 * IN job_id - get information for specific job id, NO_VAL for all jobs
 * IN step_id - get information for specific job step id, NO_VAL for all
 *	job steps
 * IN step_response_pptr - place to store a step response pointer
 * IN show_flags - job step filtering options
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 * NOTE: free the response using slurm_free_job_step_info_response_msg
 */
extern int slurm_get_job_steps PARAMS((
	time_t update_time, uint32_t job_id, uint32_t step_id,
	job_step_info_response_msg_t **step_response_pptr,
	uint16_t show_flags));

/*
 * slurm_free_job_step_info_response_msg - free the job step
 *	information response message
 * IN msg - pointer to job step information response message
 * NOTE: buffer is loaded by slurm_get_job_steps.
 */
extern void slurm_free_job_step_info_response_msg PARAMS((
	job_step_info_response_msg_t * msg));

/*
 * slurm_print_job_step_info_msg - output information about all Slurm
 *	job steps based upon message as loaded using slurm_get_job_steps
 * IN out - file to write to
 * IN job_step_info_msg_ptr - job step information message pointer
 * IN one_liner - print as a single line if true
 */
extern void slurm_print_job_step_info_msg PARAMS((
	FILE * out, job_step_info_response_msg_t * job_step_info_msg_ptr,
	int one_liner ));

/*
 * slurm_print_job_step_info - output information about a specific Slurm
 *	job step based upon message as loaded using slurm_get_job_steps
 * IN out - file to write to
 * IN job_ptr - an individual job step information record pointer
 * IN one_liner - print as a single line if true
 */
extern void slurm_print_job_step_info PARAMS((
	FILE * out, job_step_info_t * step_ptr, int one_liner ));

/*
 * slurm_job_step_layout_get - get the slurm_step_layout_t structure for
 *      a particular job step
 *
 * IN job_id
 * IN step_id
 * RET pointer to a slurm_step_layout_t (free with
 *   slurm_free_step_layout) on success, and NULL on error.
 */
extern slurm_step_layout_t *slurm_job_step_layout_get PARAMS((uint32_t job_id,
							    uint32_t step_id));
/*
 * slurm_sprint_job_step_info - output information about a specific Slurm
 *	job step based upon message as loaded using slurm_get_job_steps
 * IN job_ptr - an individual job step information record pointer
 * IN one_liner - print as a single line if true
 * RET out - char * containing formatted output (must be freed after call)
 *           NULL is returned on failure.
 */
extern char *slurm_sprint_job_step_info PARAMS(( job_step_info_t * step_ptr,
						 int one_liner ));

void slurm_job_step_layout_free PARAMS((slurm_step_layout_t *layout));

/*****************************************************************************\
 *	SLURM NODE CONFIGURATION READ/PRINT/UPDATE FUNCTIONS
\*****************************************************************************/

/*
 * slurm_load_node - issue RPC to get slurm all node configuration information
 *	if changed since update_time
 * IN update_time - time of current configuration data
 * IN node_info_msg_pptr - place to store a node configuration pointer
 * IN show_flags - node filtering options
 * RET 0 or a slurm error code
 * NOTE: free the response using slurm_free_node_info_msg
 */
extern int slurm_load_node PARAMS((
	time_t update_time, node_info_msg_t **node_info_msg_pptr,
	uint16_t show_flags));

/*
 * slurm_free_node_info - free the node information response message
 * IN msg - pointer to node information response message
 * NOTE: buffer is loaded by slurm_load_node.
 */
extern void slurm_free_node_info_msg PARAMS((
	node_info_msg_t * node_buffer_ptr ));

/*
 * slurm_print_node_info_msg - output information about all Slurm nodes
 *	based upon message as loaded using slurm_load_node
 * IN out - file to write to
 * IN node_info_msg_ptr - node information message pointer
 * IN one_liner - print as a single line if true
 */
extern void slurm_print_node_info_msg PARAMS((
	FILE * out, node_info_msg_t * node_info_msg_ptr, int one_liner )) ;

/*
 * slurm_print_node_table - output information about a specific Slurm nodes
 *	based upon message as loaded using slurm_load_node
 * IN out - file to write to
 * IN node_ptr - an individual node information record pointer
 * IN node_scaling - number of nodes each node represents
 * IN one_liner - print as a single line if true
 */
extern void slurm_print_node_table PARAMS((
	FILE * out, node_info_t * node_ptr,
	int node_scaling, int one_liner ));

/*
 * slurm_sprint_node_table - output information about a specific Slurm nodes
 *	based upon message as loaded using slurm_load_node
 * IN node_ptr - an individual node information record pointer
 * IN one_liner - print as a single line if true
 * IN node_scaling - number of nodes each node represents
 * RET out - char * containing formatted output (must be freed after call)
 *           NULL is returned on failure.
 */
extern char *slurm_sprint_node_table PARAMS(( node_info_t * node_ptr,
					      int node_scaling,
					      int one_liner ));

/*
 * slurm_init_update_node_msg - initialize node update message
 * OUT update_node_msg - user defined node descriptor
 */
void slurm_init_update_node_msg (update_node_msg_t * update_node_msg);

/*
 * slurm_update_node - issue RPC to a node's configuration per request,
 *	only usable by user root
 * IN node_msg - description of node updates
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 */
extern int slurm_update_node PARAMS(( update_node_msg_t * node_msg ));


/*****************************************************************************\
 *	SLURM SWITCH TOPOLOGY CONFIGURATION READ/PRINT FUNCTIONS
\*****************************************************************************/

/*
 * slurm_load_topo - issue RPC to get slurm all switch topology configuration
 *	information
 * IN node_info_msg_pptr - place to store a node configuration pointer
 * RET 0 or a slurm error code
 * NOTE: free the response using slurm_free_topo_info_msg
 */
extern int slurm_load_topo PARAMS((
	topo_info_response_msg_t **topo_info_msg_pptr ));

/*
 * slurm_free_topo_info_msg - free the switch topology configuration
 *	information response message
 * IN msg - pointer to switch topology configuration response message
 * NOTE: buffer is loaded by slurm_load_topo.
 */
extern void slurm_free_topo_info_msg PARAMS(( topo_info_response_msg_t *msg ));

/*
 * slurm_print_topo_info_msg - output information about all switch topology
 *	configuration information based upon message as loaded using
 *	slurm_load_topo
 * IN out - file to write to
 * IN topo_info_msg_ptr - switch topology information message pointer
 * IN one_liner - print as a single line if not zero
 */
extern void slurm_print_topo_info_msg PARAMS((
	FILE * out, topo_info_response_msg_t *topo_info_msg_ptr, int one_liner )) ;

/*
 * slurm_print_topo_record - output information about a specific Slurm topology
 *	record based upon message as loaded using slurm_load_topo
 * IN out - file to write to
 * IN topo_ptr - an individual switch information record pointer
 * IN one_liner - print as a single line if not zero
 * RET out - char * containing formatted output (must be freed after call)
 *	   NULL is returned on failure.
 */
extern void slurm_print_topo_record PARAMS((FILE * out, topo_info_t *topo_ptr,
				    int one_liner ));

/*****************************************************************************\
 *	SLURM SELECT READ/PRINT/UPDATE FUNCTIONS
\*****************************************************************************/

/*
 * slurm_get_select_jobinfo - get data from a select job credential
 * IN jobinfo  - updated select job credential
 * IN data_type - type of data to enter into job credential
 * IN/OUT data - the data to enter into job credential
 * RET 0 or -1 on error
 */
extern int slurm_get_select_jobinfo PARAMS(
	(select_jobinfo_t *jobinfo, enum select_jobdata_type data_type,
	 void *data));

/*
 * slurm_get_select_nodeinfo - get data from a select node credential
 * IN nodeinfo  - updated select node credential
 * IN data_type - type of data to enter into node credential
 * IN state     - state of node query
 * IN/OUT data  - the data to enter into node credential
 * RET 0 or -1 on error
 */
extern int slurm_get_select_nodeinfo PARAMS(
	(select_nodeinfo_t *nodeinfo, enum select_nodedata_type data_type,
	 enum node_states state, void *data));

/*****************************************************************************\
 *	SLURM PARTITION CONFIGURATION READ/PRINT/UPDATE FUNCTIONS
\*****************************************************************************/

/*
 * slurm_init_part_desc_msg - initialize partition descriptor with
 *	default values
 * IN/OUT update_part_msg - user defined partition descriptor
 */
extern void slurm_init_part_desc_msg PARAMS((update_part_msg_t * update_part_msg ));

/*
 * slurm_load_partitions - issue RPC to get slurm all partition configuration
 *	information if changed since update_time
 * IN update_time - time of current configuration data
 * IN partition_info_msg_pptr - place to store a partition configuration
 *	pointer
 * IN show_flags - partitions filtering options
 * RET 0 or a slurm error code
 * NOTE: free the response using slurm_free_partition_info_msg
 */
extern int slurm_load_partitions PARAMS((
	time_t update_time, partition_info_msg_t **part_buffer_ptr,
	uint16_t show_flags));

/*
 * slurm_free_partition_info_msg - free the partition information
 *	response message
 * IN msg - pointer to partition information response message
 * NOTE: buffer is loaded by slurm_load_partitions
 */
extern void slurm_free_partition_info_msg PARAMS((
	partition_info_msg_t * part_info_ptr ));

/*
 * slurm_print_partition_info_msg - output information about all Slurm
 *	partitions based upon message as loaded using slurm_load_partitions
 * IN out - file to write to
 * IN part_info_ptr - partitions information message pointer
 * IN one_liner - print as a single line if true
 */
extern void slurm_print_partition_info_msg PARAMS((
	FILE * out, partition_info_msg_t * part_info_ptr, int one_liner ));

/*
 * slurm_print_partition_info - output information about a specific Slurm
 *	partition based upon message as loaded using slurm_load_partitions
 * IN out - file to write to
 * IN part_ptr - an individual partition information record pointer
 * IN one_liner - print as a single line if true
 */
extern void slurm_print_partition_info PARAMS((
	FILE *out , partition_info_t * part_ptr, int one_liner ));

/*
 * slurm_sprint_partition_info - output information about a specific Slurm
 *	partition based upon message as loaded using slurm_load_partitions
 * IN part_ptr - an individual partition information record pointer
 * IN one_liner - print as a single line if true
 * RET out - char * with formatted output (must be freed after call)
 *           NULL is returned on failure.
 */
extern char *slurm_sprint_partition_info PARAMS((
		partition_info_t * part_ptr, int one_liner ));

/*
 * slurm_create_partition - create a new partition, only usable by user root
 * IN part_msg - description of partition configuration
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 */
extern int slurm_create_partition PARAMS(( update_part_msg_t * part_msg ));

/*
 * slurm_update_partition - issue RPC to update a partition's configuration
 *	per request, only usable by user root
 * IN part_msg - description of partition updates
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 */
extern int slurm_update_partition PARAMS(( update_part_msg_t * part_msg ));

/*
 * slurm_delete_partition - issue RPC to delete a partition, only usable
 *	by user root
 * IN part_msg - description of partition to delete
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 */
extern int slurm_delete_partition PARAMS(( delete_part_msg_t * part_msg ));

/*****************************************************************************\
 *	SLURM RESERVATION CONFIGURATION READ/PRINT/UPDATE FUNCTIONS
\*****************************************************************************/

/*
 * slurm_init_resv_desc_msg - initialize reservation descriptor with
 *	default values
 * OUT job_desc_msg - user defined partition descriptor
 */
extern void slurm_init_resv_desc_msg PARAMS((
		resv_desc_msg_t * update_resv_msg ));
/*
 * slurm_create_reservation - create a new reservation, only usable by user root
 * IN resv_msg - description of reservation
 * RET name of reservation on success (caller must free the memory),
 *	otherwise return NULL and set errno to indicate the error
 */
extern char * slurm_create_reservation PARAMS((
		resv_desc_msg_t * resv_msg ));

/*
 * slurm_update_reservation - modify an existing reservation, only usable by
 *	user root
 * IN resv_msg - description of reservation
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 */
extern int slurm_update_reservation PARAMS((resv_desc_msg_t * resv_msg));

/*
 * slurm_delete_reservation - issue RPC to delete a reservation, only usable
 *	by user root
 * IN resv_msg - description of reservation to delete
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 */
extern int slurm_delete_reservation PARAMS((
		reservation_name_msg_t * resv_msg ));

/*
 * slurm_load_reservations - issue RPC to get all slurm reservation
 *	configuration information if changed since update_time
 * IN update_time - time of current configuration data
 * IN reserve_info_msg_pptr - place to store a reservation configuration
 *	pointer
 * RET 0 or a slurm error code
 * NOTE: free the response using slurm_free_reservation_info_msg
 */
extern int slurm_load_reservations PARAMS(( time_t update_time,
		reserve_info_msg_t **resp ));

/*
 * slurm_print_reservation_info_msg - output information about all Slurm
 *	reservations based upon message as loaded using slurm_load_reservation
 * IN out - file to write to
 * IN resv_info_ptr - reservation information message pointer
 * IN one_liner - print as a single line if true
 */
void slurm_print_reservation_info_msg PARAMS(( FILE* out,
		reserve_info_msg_t * resv_info_ptr, int one_liner ));

/*
 * slurm_print_reservation_info - output information about a specific Slurm
 *	reservation based upon message as loaded using slurm_load_reservation
 * IN out - file to write to
 * IN resv_ptr - an individual reservation information record pointer
 * IN one_liner - print as a single line if true
 */
void slurm_print_reservation_info PARAMS(( FILE* out,
		reserve_info_t * resv_ptr, int one_liner ));

/*
 * slurm_sprint_reservation_info - output information about a specific Slurm
 *	reservation based upon message as loaded using slurm_load_reservations
 * IN resv_ptr - an individual reservation information record pointer
 * IN one_liner - print as a single line if true
 * RET out - char * containing formatted output (must be freed after call)
 *           NULL is returned on failure.
 */
char *slurm_sprint_reservation_info PARAMS(( reserve_info_t * resv_ptr,
		int one_liner ));

/*
 * slurm_free_reservation_info_msg - free the reservation information
 *	response message
 * IN msg - pointer to reservation information response message
 * NOTE: buffer is loaded by slurm_load_reservation
 */
extern void slurm_free_reservation_info_msg PARAMS((
	reserve_info_msg_t * resv_info_ptr ));

/*****************************************************************************\
 *	SLURM PING/RECONFIGURE/SHUTDOWN FUNCTIONS
\*****************************************************************************/

/*
 * slurm_ping - issue RPC to have Slurm controller (slurmctld)
 * IN controller - 1==primary controller, 2==secondary controller
 * RET 0 or a slurm error code
 */
extern int slurm_ping PARAMS(( int primary ));

/*
 * slurm_reconfigure - issue RPC to have Slurm controller (slurmctld)
 *	reload its configuration file
 * RET 0 or a slurm error code
 */
extern int slurm_reconfigure PARAMS(( void ));

/*
 * slurm_shutdown - issue RPC to have Slurm controller (slurmctld)
 *	cease operations, both the primary and backup controller
 *	are shutdown.
 * IN options - 0: all slurm daemons are shutdown
 *              1: slurmctld generates a core file
 *              2: only the slurmctld is shutdown (no core file)
 * RET 0 or a slurm error code
 */
extern int slurm_shutdown PARAMS(( uint16_t options ));

/*
 * slurm_takeover - issue RPC to have Slurm backup controller (slurmctld)
 *	take over the primary controller.
 *
 * RET 0 or a slurm error code
 */
extern int slurm_takeover PARAMS(( void ));

/*
 * slurm_set_debug_level - issue RPC to set slurm controller debug level
 * IN debug_level - requested debug level
 * RET 0 on success, otherwise return -1 and set errno to indicate the error
 */
extern int slurm_set_debug_level PARAMS((uint32_t debug_level));


/*****************************************************************************\
 *      SLURM JOB SUSPEND FUNCTIONS
\*****************************************************************************/

/*
 * slurm_suspend - suspend execution of a job.
 * IN job_id  - job on which to perform operation
 * RET 0 or a slurm error code
 */
extern int slurm_suspend PARAMS(( uint32_t job_id ));

/*
 * slurm_resume - resume execution of a previously suspended job.
 * IN job_id  - job on which to perform operation
 * RET 0 or a slurm error code
 */
extern int slurm_resume PARAMS(( uint32_t job_id ));

/*
 * slurm_requeue - re-queue a batch job, if already running
 *	then terminate it first
 * RET 0 or a slurm error code
 */
extern int slurm_requeue PARAMS(( uint32_t job_id ));

/*****************************************************************************\
 *      SLURM JOB CHECKPOINT FUNCTIONS
\*****************************************************************************/

/*
 * slurm_checkpoint_able - determine if the specified job step can presently
 *	be checkpointed
 * IN job_id  - job on which to perform operation
 * IN step_id - job step on which to perform operation
 * OUT start_time - time at which checkpoint request was issued
 * RET 0 (can be checkpoined) or a slurm error code
 */
extern int slurm_checkpoint_able PARAMS(( uint32_t job_id, uint32_t step_id,
		time_t *start_time ));

/*
 * slurm_checkpoint_disable - disable checkpoint requests for some job step
 * IN job_id  - job on which to perform operation
 * IN step_id - job step on which to perform operation
 * RET 0 or a slurm error code
 */
extern int slurm_checkpoint_disable PARAMS(( uint32_t job_id,
		uint32_t step_id ));


/*
 * slurm_checkpoint_enable - enable checkpoint requests for some job step
 * IN job_id  - job on which to perform operation
 * IN step_id - job step on which to perform operation
 * RET 0 or a slurm error code
 */
extern int slurm_checkpoint_enable PARAMS(( uint32_t job_id,
					    uint32_t step_id ));

/*
 * slurm_checkpoint_create - initiate a checkpoint requests for some job step.
 *	the job will continue execution after the checkpoint operation completes
 * IN job_id  - job on which to perform operation
 * IN step_id - job step on which to perform operation
 * IN max_wait - maximum wait for operation to complete, in seconds
 * IN image_dir - directory to store image files
 * RET 0 or a slurm error code
 */
extern int slurm_checkpoint_create PARAMS(( uint32_t job_id,
					    uint32_t step_id,
					    uint16_t max_wait,
					    char *image_dir ));

/*
 * slurm_checkpoint_vacate - initiate a checkpoint requests for some job step.
 *	the job will terminate after the checkpoint operation completes
 * IN job_id  - job on which to perform operation
 * IN step_id - job step on which to perform operation
 * IN max_wait - maximum wait for operation to complete, in seconds
 * IN image_dir - directory to store image files
 * RET 0 or a slurm error code
 */
extern int slurm_checkpoint_vacate PARAMS(( uint32_t job_id,
					    uint32_t step_id,
					    uint16_t max_wait,
					    char *image_dir ));

/*
 * slurm_checkpoint_restart - restart execution of a checkpointed job step.
 * IN job_id  - job on which to perform operation
 * IN step_id - job step on which to perform operation
 * IN stick - stick to nodes previously running on
 * IN image_dir - directory to find checkpoint image files
 * RET 0 or a slurm error code
 */
extern int slurm_checkpoint_restart PARAMS(( uint32_t job_id,
					     uint32_t step_id,
					     uint16_t stick,
					     char *image_dir ));

/*
 * slurm_checkpoint_complete - note the completion of a job step's checkpoint
 *	operation.
 * IN job_id  - job on which to perform operation
 * IN step_id - job step on which to perform operation
 * IN begin_time - time at which checkpoint began
 * IN error_code - error code, highest value for all complete calls is preserved
 * IN error_msg - error message, preserved for highest error_code
 * RET 0 or a slurm error code
 */
extern int slurm_checkpoint_complete PARAMS(( uint32_t job_id,
					      uint32_t step_id,
					      time_t begin_time,
					      uint32_t error_code,
					      char *error_msg ));

/*
 * slurm_checkpoint_task_complete - note the completion of a task's checkpoint
 *	operation.
 * IN job_id  - job on which to perform operation
 * IN step_id - job step on which to perform operation
 * IN task_id - task which completed the operation
 * IN begin_time - time at which checkpoint began
 * IN error_code - error code, highest value for all complete calls is preserved
 * IN error_msg - error message, preserved for highest error_code
 * RET 0 or a slurm error code
 */
extern int slurm_checkpoint_task_complete PARAMS(( uint32_t job_id,
						   uint32_t step_id,
						   uint32_t task_id,
						   time_t begin_time,
						   uint32_t error_code,
						   char *error_msg ));

/*
 * slurm_checkpoint_error - gather error information for the last checkpoint
 *	operation for some job step
 * IN job_id  - job on which to perform operation
 * IN step_id - job step on which to perform operation
 * OUT error_code - error number associated with the last checkpoint operation,
 *	this value is dependent upon the checkpoint plugin used and may be
 *	completely unrelated to slurm error codes, the highest value for all
 *	complete calls is preserved
 * OUT error_msg - error message, preserved for highest error_code, value
 *	must be freed by the caller to prevent memory leak
 * RET 0 or a slurm error code
 */
extern int slurm_checkpoint_error PARAMS(( uint32_t job_id, uint32_t step_id,
					   uint32_t *error_code,
					   char **error_msg ));

/*
 * slurm_checkpoint_tasks - send checkpoint request to tasks of
 *     specified step
 * IN job_id: job ID of step
 * IN step_id: step ID of step
 * IN image_dir: location to store ckpt images. parameter to plugin.
 * IN max_wait: seconds to wait for the operation to complete
 * IN nodelist: nodes to send the request
 * RET: 0 on success, non-zero on failure with errno set
 */
extern int slurm_checkpoint_tasks PARAMS(( uint32_t job_id, uint16_t step_id,
					   time_t begin_time, char *image_dir,
					   uint16_t max_wait, char *nodelist));


/*****************************************************************************\
 *      SLURM HOSTLIST FUNCTIONS
\*****************************************************************************/

/* The hostlist opaque data type
 *
 * A hostlist is a list of hostnames optimized for a prefixXXXX style
 * naming convention, where XXXX  is a decimal, numeric suffix.
 */
#ifndef   __hostlist_t_defined
#  define __hostlist_t_defined
   typedef struct hostlist * hostlist_t;
#endif

/*
 * slurm_hostlist_create():
 *
 * Create a new hostlist from a string representation.
 *
 * The string representation (str) may contain one or more hostnames or
 * bracketed hostlists separated by either `,' or whitespace. A bracketed
 * hostlist is denoted by a common prefix followed by a list of numeric
 * ranges contained within brackets: e.g. "tux[0-5,12,20-25]"
 *
 * To support systems with 3-D topography, a rectangular prism may
 * be described using two three digit numbers separated by "x": e.g.
 * "bgl[123x456]". This selects all nodes between 1 and 4 inclusive
 * in the first dimension, between 2 and 5 in the second, and between
 * 3 and 6 in the third dimension for a total of 4*4*4=64 nodes
 *
 * Note: if this module is compiled with WANT_RECKLESS_HOSTRANGE_EXPANSION
 * defined, a much more loose interpretation of host ranges is used.
 * Reckless hostrange expansion allows all of the following (in addition to
 * bracketed hostlists):
 *
 *  o tux0-5,tux12,tux20-25
 *  o tux0-tux5,tux12,tux20-tux25
 *  o tux0-5,12,20-25
 *
 * If str is NULL, and empty hostlist is created and returned.
 *
 * If the create fails, hostlist_create() returns NULL.
 *
 * The returned hostlist must be freed with hostlist_destroy()
 *
 */
extern hostlist_t slurm_hostlist_create PARAMS(( const char *hostlist ));

/* slurm_hostlist_count():
 *
 * Return the number of hosts in hostlist hl.
 */
extern int slurm_hostlist_count PARAMS((hostlist_t hl));

/*
 * slurm_hostlist_destroy():
 *
 * Destroy a hostlist object. Frees all memory allocated to the hostlist.
 */
extern void slurm_hostlist_destroy PARAMS(( hostlist_t hl ));

/* slurm_hostlist_find():
 *
 * Searches hostlist hl for the first host matching hostname
 * and returns position in list if found.
 *
 * Returns -1 if host is not found.
 *
 */
extern int slurm_hostlist_find PARAMS((hostlist_t hl, const char *hostname));

/* slurm_hostlist_push():
 *
 * push a string representation of hostnames onto a hostlist.
 *
 * The hosts argument may take the same form as in slurm_hostlist_create()
 *
 * Returns the number of hostnames inserted into the list,
 * or 0 on failure.
 */
extern int slurm_hostlist_push PARAMS((hostlist_t hl, const char *hosts));

/* slurm_hostlist_push_host():
 *
 * Push a single host onto the hostlist hl.
 * This function is more efficient than slurm_hostlist_push() for a single
 * hostname, since the argument does not need to be checked for ranges.
 *
 * return value is 1 for success, 0 for failure.
 */
extern int slurm_hostlist_push_host PARAMS((hostlist_t hl, const char *host));

/* slurm_hostlist_ranged_string():
 *
 * Write the string representation of the hostlist hl into buf,
 * writing at most n chars. Returns the number of bytes written,
 * or -1 if truncation occurred.
 *
 * The result will be NULL terminated.
 *
 * slurm_hostlist_ranged_string() will write a bracketed hostlist representation
 * where possible.
 */
extern ssize_t slurm_hostlist_ranged_string PARAMS((hostlist_t hl,
						    size_t n, char *buf));

/*
 * slurm_hostlist_shift():
 *
 * Returns the string representation of the first host in the hostlist
 * or NULL if the hostlist is empty or there was an error allocating memory.
 * The host is removed from the hostlist.
 *
 * Note: Caller is responsible for freeing the returned memory.
 */
extern char * slurm_hostlist_shift PARAMS(( hostlist_t hl ));

/* slurm_hostlist_uniq():
 *
 * Sort the hostlist hl and remove duplicate entries.
 *
 */
extern void slurm_hostlist_uniq PARAMS((hostlist_t hl));

/*****************************************************************************\
 *      SLURM TRIGGER FUNCTIONS
\*****************************************************************************/

/*
 * slurm_set_trigger - Set an event trigger
 * RET 0 or a slurm error code
 */
extern int slurm_set_trigger PARAMS(( trigger_info_t * trigger_set ));

/*
 * slurm_clear_trigger - Clear (remove) an existing event trigger
 * RET 0 or a slurm error code
 */
extern int slurm_clear_trigger PARAMS(( trigger_info_t * trigger_clear ));

/*
 * slurm_get_triggers - Get all event trigger information
 * Use slurm_free_trigger_msg() to free the memory allocated by this function
 * RET 0 or a slurm error code
 */
extern int slurm_get_triggers PARAMS(( trigger_info_msg_t ** trigger_get ));

/*
 * slurm_free_trigger_msg - Free data structure returned by slurm_get_triggers()
 */
extern void slurm_free_trigger_msg PARAMS(( trigger_info_msg_t * trigger_free ));
END_C_DECLS

#endif
