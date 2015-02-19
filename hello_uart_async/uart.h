int uart_putchar(char c, FILE *stream);
int uart_getchar(FILE *stream);

void uart_init(void);

struct rx_ring;
struct tx_ring;

/* http://www.ermicro.com/blog/?p=325 */

extern FILE uart_output;
extern FILE uart_input;
