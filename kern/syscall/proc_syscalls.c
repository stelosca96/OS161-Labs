#include <types.h>
#include <kern/unistd.h>
#include <clock.h>
#include <copyinout.h>
#include <syscall.h>
#include <lib.h>
#include <proc.h>
#include <thread.h>
#include <addrspace.h>
#include <current.h>
#include "synch.h"

void sys__exit(int status){
    (void) status;
    
    #if OPT_PROC_WAIT
	struct proc *proc = curproc;
	struct thread *thread = curthread;
    proc->exit_code = status;
    proc_remthread(thread);
    V(proc->p_sem);
    #else
    struct addrspace *as = proc_getas();
    as_destroy(as);
	#endif

    thread_exit();
}