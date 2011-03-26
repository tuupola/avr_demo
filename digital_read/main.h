static int uart_putchar(char c, FILE *stream);
static int uart_getchar(FILE *stream);

static void init_uart(void);
static void init(void);

static FILE output = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
static FILE input = FDEV_SETUP_STREAM(NULL, uart_getchar, _FDEV_SETUP_READ );