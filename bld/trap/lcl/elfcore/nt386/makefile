#pmake: lcl core os_nt cpu_386 trap x86
#
# Create the generic ELF core trap file
#
host_cpu = 386
host_os  = nt

target_cpu = x86
target_os  = nt

srv     = lcl
name    = elf
which   = TRAP
reg_dll = 1

extra_cppflags = -DELFCORE

extra_objs = &
        elfcore.obj &
        core_fbsd.obj &
        core_nto.obj &
        coremisc.obj &
        supp.obj &
        core.obj

inc_dirs   = -I"$(trap_dir)/lcl/elfcore/h"

!include $(trap_dir)/lcl/lcl.mif
!include $(trap_dir)/master.mif
