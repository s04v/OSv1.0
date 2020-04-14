global io_load_eflags
global io_cli
global io_store_eflags





io_cli:
    cli
    ret

io_load_eflags:
    pushfd
    pop eax
    ret

io_store_eflags:
    mov eax, [esp+4]
    push eax
    popfd
    ret
