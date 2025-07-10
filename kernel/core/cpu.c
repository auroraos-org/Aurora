#include "cpu.h"

struct registers {
    u32 eax, ebx, ecx, edx;
    u32 esi, edi, esp, ebp;
    u32 eip, eflags;
    u32 cs, ds, es, fs, gs, ss;
    u32 cr0, cr2, cr3, cr4;
};

void get_regs(struct registers *regs) {
    // general
    __asm__ (
        "movl %%eax, %0\n\t"
        "movl %%ebx, %1\n\t"
        "movl %%ecx, %2\n\t"
        "movl %%edx, %3\n\t"
        "movl %%esi, %4\n\t"
        "movl %%edi, %5\n\t"
        "movl %%esp, %6\n\t"
        "movl %%ebp, %7\n\t"
        : "=m"(regs->eax), "=m"(regs->ebx), "=m"(regs->ecx), "=m"(regs->edx),
          "=m"(regs->esi), "=m"(regs->edi), "=m"(regs->esp), "=m"(regs->ebp)
        :
        : "memory"
    );
    
    // segment
    __asm__ (
        "movw %%cs, %0\n\t"
        "movw %%ds, %1\n\t"
        "movw %%es, %2\n\t"
        "movw %%fs, %3\n\t"
        "movw %%gs, %4\n\t"
        "movw %%ss, %5\n\t"
        : "=m"(regs->cs), "=m"(regs->ds), "=m"(regs->es),
          "=m"(regs->fs), "=m"(regs->gs), "=m"(regs->ss)
        :
        : "memory"
    );
    
    // flags
    __asm__ (
        "pushfl\n\t"
        "popl %0\n\t"
        : "=m"(regs->eflags)
        :
        : "memory"
    );
    
    // control... Maybe not what if this is an user process - ehh who cares.
    __asm__ (
        "movl %%cr0, %%eax\n\t"
        "movl %%eax, %0\n\t"
        : "=m"(regs->cr0)
        :
        : "eax", "memory"
    );
    
    __asm__ (
        "movl %%cr2, %%eax\n\t"
        "movl %%eax, %0\n\t"
        : "=m"(regs->cr2)
        :
        : "eax", "memory"
    );
    
    __asm__ (
        "movl %%cr3, %%eax\n\t"
        "movl %%eax, %0\n\t"
        : "=m"(regs->cr3)
        :
        : "eax", "memory"
    );
    
    __asm__  (
        "movl %%cr4, %%eax\n\t"
        "movl %%eax, %0\n\t"
        : "=m"(regs->cr4)
        :
        : "eax", "memory"
    );
    

    regs->eip = 0; //TODO: Capture EIP.
}

void register_dump() {
    struct registers regs;
    get_regs(&regs);
    
    log_print("CPU REGISTER DUMP:\n");
    log_print("General Purpose Registers:\n");
    log_print("EAX: 0x"); log_print_hex(regs.eax);
    log_print(" EBX: 0x"); log_print_hex(regs.ebx);
    log_print(" ECX: 0x"); log_print_hex(regs.ecx);
    log_print(" EDX: 0x"); log_print_hex(regs.edx);
    log_print("\n");
    
    log_print("ESI: 0x"); log_print_hex(regs.esi);
    log_print(" EDI: 0x"); log_print_hex(regs.edi);
    log_print(" ESP: 0x"); log_print_hex(regs.esp);
    log_print(" EBP: 0x"); log_print_hex(regs.ebp);
    log_print("\n");
    

    log_print("CS: 0x"); log_print_hex(regs.cs);
    log_print(" DS: 0x"); log_print_hex(regs.ds);
    log_print(" ES: 0x"); log_print_hex(regs.es);
    log_print(" FS: 0x"); log_print_hex(regs.fs);
    log_print(" GS: 0x"); log_print_hex(regs.gs);
    log_print(" SS: 0x"); log_print_hex(regs.ss);
    log_print("\n");
    
    log_print("CR0: 0x"); log_print_hex(regs.cr0);
    log_print(" CR2: 0x"); log_print_hex(regs.cr2);
    log_print(" CR3: 0x"); log_print_hex(regs.cr3);
    log_print(" CR4: 0x"); log_print_hex(regs.cr4);
    log_print("\n");
    
    log_print("EFLAGS: 0x"); log_print_hex(regs.eflags);
    log_print("\n");
