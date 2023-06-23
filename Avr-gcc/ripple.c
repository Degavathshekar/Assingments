#include <avr/io.h>

int main(void)
{
    int a, b, d, e, f, g;

    DDRB |= (1 << PB5);
    TCCR0B |= 0b00000101;

    while (1)
    {
        a = 0b00000000;
        b = 0b00100000;

    lp1:
        a ^= b;
        PORTB = a;

        d = 0b01000000;
    delay:
    lp2:
        e = TIFR0;
        f = 0b00000001;
        g = e & f;

        if (g == 0)
        {
            goto delay;
        }
        else
        {
            TIFR0 = 0b00000001;
            --d;

            if (d == 0)
            {
                
                goto lp1;
            }
            else
            {
                goto lp2;
            }
        }
    }
    return 0;
}

