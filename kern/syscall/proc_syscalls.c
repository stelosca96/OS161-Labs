#include <types.h>
#include <kern/unistd.h>
#include <clock.h>
#include <copyinout.h>
#include <syscall.h>
#include <lib.h>
#include <proc.h>
#include <thread.h>
#include <addrspace.h>

void sys__exit(int status){
    struct addrspace *as = proc_getas();
    (void) status;
    as_destroy(as);
    thread_exit();
}