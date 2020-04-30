        .arch msp430g2553
        .p2align 1,0
    
        .text 
jt:     
        .word default;
        .word case1;
        .word case2;
        .word case3; 
        .word case4; 
        
        .global state_advance
        
state_advance:
        
        ;; range check on selector (switch_state_changed)
        mov.b #5, r13
        mov.b &switch_state_changed, r12
        cmp.b r12, r13
        jnc default
        add r12, r12
        mov jt(r12), r0 ; jmp jt[s]
        
        ;; switch table options
        ;; same order as in source code
        
default:
        
case1:  ; will toggle red light only alongside song 1 being played, see switches.c
        call #toggle_red
        jmp end
case2:  ; will toggle green light only alongside song 2 being played, see switches.c
        call #toggle_green
        jmp end
case3:  ; will toggle both the green and red lights, alongside song 3 being played, see switches.c
        call #toggle_both
        JMP end
case4:  ; will toggle both lights off, alongside song 4 being played, see switches.c
        call #toggle_both_off
        jmp end
        
end:    
        ret
