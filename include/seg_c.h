#ifndef __SEGGG__
#define __SEGGG__

#define S1 0b00000100
#define S2 0b00001000
#define S3 0b00010000
#define S4 0b00100000
#define S5 0b01000000
#define S6 0b10000000
#define S7 0b00000001

#define D_ALL 0b000000

void update_display(int* s_nums, int* t_nums, int* shape);
void send_six_digit_number_to_display(uint32_t number);
void update_right_numbers(uint8_t numbers);
void update_left_numbers(uint8_t numbers);
void clear_screen();
void init_screen_ISR();
void test_screen();
void update_shapes(uint8_t * numbers);
void keep_alive();

#endif