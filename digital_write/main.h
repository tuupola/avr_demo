int digital_read(int input_register, int pin);
void digital_write(volatile int *data_port, int pin, int value);
static void init(void);
