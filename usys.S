#include "syscall.h"
#include "traps.h"
#define SYSCALL(name) \
  .globl name; \
  name: \
    movl $SYS_ ## name, %eax; \
    int $T_SYSCALL; \
    ret

#define SYSCALLR(name) \
  .globl name; \
  name: \
    movl $SYS_ ## name, %eax; \
    add $4, %esp;  \
    mov (%esp), %edx; \
    sub $4, %esp; \
    int $T_SYSCALL; \
    ret
SYSCALL(fork)
SYSCALL(exit)
SYSCALL(wait)
SYSCALL(pipe)
SYSCALL(read)
SYSCALL(write)
SYSCALL(close)
SYSCALL(kill)
SYSCALL(exec)
SYSCALL(open)
SYSCALL(mknod)
SYSCALL(unlink)
SYSCALL(fstat)
SYSCALL(link)
SYSCALL(mkdir)
SYSCALL(chdir)
SYSCALL(dup)
SYSCALL(getpid)
SYSCALL(sbrk)
SYSCALL(sleep)
SYSCALL(uptime)
SYSCALL(trace_syscalls)
SYSCALL(process_start_time)
SYSCALL(calculate_BPS)
SYSCALL(set_sleep)
SYSCALL(date)
SYSCALL(get_ancestors)
SYSCALL(get_descendants)
SYSCALL(fill_date)
SYSCALL(reentrantTest) 