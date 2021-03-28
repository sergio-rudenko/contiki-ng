/* Includes ------------------------------------------------------------------*/
#include "lib/dbg-io/dbg.h"
#include "Core/Inc/usart.h"

/**
 * \brief Print a stream of bytes
 * \param seq A pointer to the stream
 * \param len The number of bytes to print
 * \return The number of printed bytes
 */
unsigned int dbg_send_bytes(const unsigned char *seq, unsigned int len)
{
    for(int i = 0; i < len; i++) 
    {
        dbg_putchar((int)seq[i]);
    }
    return len;
}

/**
 * \brief Print a character to debug output
 * \param c Character to print
 * \return Printed character
 */
int dbg_putchar(int c)
{
    //TODO
    return c;
}
