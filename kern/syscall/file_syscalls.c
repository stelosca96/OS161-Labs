#include <types.h>
#include <kern/unistd.h>
#include <clock.h>
#include <copyinout.h>
#include <syscall.h>
#include <lib.h>

ssize_t sys_read(int filehandle, void * buf, size_t size ){ 	
    switch (filehandle)
    {
    case STDIN_FILENO:
        for (unsigned int i=0; i<size; i++) {
            ((char *) buf)[i] = getch();
	    }
        return size;
    
    default:
        break;
    }
    return 0;
}

ssize_t sys_write(int filehandle, void * buf, size_t size ){ 
    switch (filehandle)
    {
    case STDOUT_FILENO:
        for (unsigned int i=0; i<size; i++) {
            putch(((char *) buf)[i]);
	    }
        return size;
    
    case STDERR_FILENO:
        for (unsigned int i=0; i<size; i++) {
            putch(((char *) buf)[i]);
	    }
        return size;
        break;
    default:
        break;
    }
    return 0;
}

