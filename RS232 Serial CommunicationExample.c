// RS232 serial communication example www.github.com/muhammedfurkan

#include <16f877.h>


#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD

#use delay (clock=400000000)


#define use_port_b_lcd TRUE
#include <lcd.c>

#use rs232 (baud=9600, xmit=pin_C6, rcv=pin_C7, parity=N, stop=1);

char keyboard[80]

#int_rda

void serial_communication_interrupt()
{
    disable_interrupts(int_rda);
    output_high(pin_c);
    gets(keyboard);
    printf("\n\rTyped text: %s\n",keyboard);
    printf(lcd_putc,"\f%s",keyboard);

    output_low(pin_c5);
    printf("\n\renter text on the keyboard and press enter=");

}


void main()
{
    setup_psp(PSP_DISABLED);
    setup_timer_1(T1_DISABLED);
    setup_timer_2(T2_DISABLED,0,1);
    setup_CCP1(CCP_OFF);
    setup_CCP2(CCP_OFF);

    output_low(pin_c5);
    lcd_init();

    printf("\r******************** Hello *****************");

    printf("\n\rthe information you enter from the keyboard will appear on the LCD screen");

    printf("\n\renter text on the keyboard and press enter=");

    enable_interrupts(GLOBAL);

    while(1)
    {
        enable_interrupts(int_rda)
    }
}
