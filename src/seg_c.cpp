#include <Arduino.h>
#include "seg_c.h"

static void reset_ports()
{
  DDRD = (DDRD & B00000011); // set all input except first two
  DDRB = (DDRD & B11111110); // set bit 0 to input
}

static void reset_portb()
{
  DDRB = (DDRD & B11111110); // set bit 0 to input
}

static void set_portd(int mode, int output)
{
  DDRD = (DDRD & B00000011) | mode;
  PORTD = (PORTD & B00000011) | output;
}

static void set_portb(int mode, int output)
{
  DDRB = (DDRB & B11111110) | mode;
  PORTB = (PORTB & B11111110) | (output & B00000001);
}

static void a1()
{
  set_portd(S2, 0);  // set s2 output low
  set_portb(S7, S7); // set s7 output high
}

static void b1()
{
  set_portd((S2 | S6), S6); // set s2 s6 output s2 low s6 high
  set_portb(0, 0);          // set s7 input
}

static void a4()
{
  set_portd((S2 | S1), S1); // set s2 s6 output s2 low s1 high
  set_portb(0, 0);          // set s7 input
}

static void b4()
{
  set_portd((S2 | S3), S3); // set s2 s6 output s2 low s3 high
  set_portb(0, 0);          // set s7 input
}

static void g6()
{
  set_portd(S3, 0);  // set s3 output low
  set_portb(S7, S7); // set s7 output high
}

static void f6()
{
  set_portd((S3 | S5), S5); // set s3 s5 output s3 low s5 high
  set_portb(0, 0);          // set s7 input
}

static void c6()
{
  set_portd((S3 | S6), S6); // set s3 s6 output s3 low s6 high
  set_portb(0, 0);          // set s7 input
}

static void b6()
{
  set_portd((S3 | S2), S2); // set s3 s2 output s3 low s2 high
  set_portb(0, 0);          // set s7 input
}

static void d6()
{
  set_portd((S3 | S4), S4); // set s3 s4 output s3 low s4 high
  set_portb(0, 0);          // set s7 input
}

static void a6()
{
  set_portd((S4 | S2), S2); // set s4 s2 output s4 low s2 high
  set_portb(0, 0);          // set s7 input
}

static void e6()
{
  set_portd((S4 | S1), S1); // set s4 s2 output s4 low s2 high
  set_portb(0, 0);          // set s7 input
}

static void c5()
{
  set_portd(S4, 0);  // set s4 output low
  set_portb(S7, S7); // set s7 output high
}

static void d5()
{
  set_portd((S4 | S5), S5); // set s4 s5 output s4 low s5 high
  set_portb(0, 0);          // set s7 input
}

static void f5()
{
  set_portd((S4 | S6), S6); // set s4 s6 output s4 low s6 high
  set_portb(0, 0);          // set s7 input
}

static void b5()
{
  set_portd((S4 | S3), S3); // set s4 s3 output s4 low s3 high
  set_portb(0, 0);          // set s7 input
}

static void a5()
{
  set_portd((S5 | S3), S3); // set s5 s3 output s5 low s3 high
  set_portb(0, 0);          // set s7 input
}

static void e5()
{
  set_portd((S5 | S2), S2); // set s5 s2 output s5 low s2 high
  set_portb(0, 0);          // set s7 input
}

static void g5()
{
  set_portd((S5 | S1), S1); // set s5 s1 output s5 low s1 high
  set_portb(0, 0);          // set s7 input
}

static void a3()
{
  set_portd((S6 | S5), S5); // set s6 s5 output s6 low s5 high
  set_portb(0, 0);          // set s7 input
}

static void e3()
{
  set_portd((S6 | S4), S4); // set s6 s4 output s6 low s4 high
  set_portb(0, 0);          // set s7 input
}

static void g3()
{
  set_portd((S6 | S3), S3); // set s6 s3 output s6 low s3 high
  set_portb(0, 0);          // set s7 input
}

static void c3()
{
  set_portd((S6 | S2), S2); // set s6 s2 output s6 low s2 high
  set_portb(0, 0);          // set s7 input
}

static void f3()
{
  set_portd((S6 | S1), S1); // set s6 s1 output s6 low s1 high
  set_portb(0, 0);          // set s7 input
}

static void d3()
{
  set_portd(S5, 0);  // set s6 s1 output s6 low s1 high
  set_portb(S7, S7); // set s7 input
}

static void b3()
{
  set_portd((S5 | S6), S6); // set s5 s6 output s5 low s6 high
  set_portb(0, 0);          // set s7 input
}

static void a2()
{
  set_portd(S6, S6); // set s6 output s6 high
  set_portb(S7, 0);  // set s7 output low
}

static void b2()
{
  set_portd(S6, 0);  // set s6 output s6 low
  set_portb(S7, S7); // set s7 output high
}

static void e2()
{
  set_portd(S5, S5); // set s5 output s5 high
  set_portb(S7, 0);  // set s7 output low
}

static void g2()
{
  set_portd(S4, S4); // set s4 output s4 high
  set_portb(S7, 0);  // set s7 output low
}

static void c2()
{
  set_portd(S3, S3); // set s3 output s3 high
  set_portb(S7, 0);  // set s7 output low
}

static void f2()
{
  set_portd(S2, S2); // set s2 output s2 high
  set_portb(S7, 0);  // set s7 output low
}

static void d2()
{
  set_portd(S1, S1); // set s2 output s2 high
  set_portb(S7, 0);  // set s7 output low
}

static void red_bat()
{
  set_portd((S3 | S1), S1); // set s1 s3 output s3 low s1 high
  set_portb(0, 0);          // set s7 input
}

static void green_bat()
{
  set_portd((S1 | S5), S5); // set s1 s5 output s1 low s5 high
  set_portb(0, 0);          // set s7 input
}

static void green_liq()
{
  set_portd((S2 | S4), S4); // set s2 s4 output s2 low s4 high
  set_portb(0, 0);          // set s7 input
}

static void red_liq()
{
  set_portd((S5 | S4), S4); // set s4 s5 output s5 low s4 high
  set_portb(0, 0);          // set s7 input
}

static void l_percentage()
{
  set_portd((S2 | S5), S5); // set s2 s5 output s2 low s5 high
  set_portb(0, 0);          // set s7 input
}

static void r_percentage()
{
  set_portd((S1 | S6), S6); // set s1 s6 output s1 low s6 high
  set_portb(0, 0);          // set s7 input
}

static void (*seg6[7])() = {a6, b6, c6, d6, e6, g6, f6};
static void (*seg5[7])() = {a5, b5, c5, d5, e5, g5, f5};
static void (*seg4[2])() = {a4, b4};
static void (*seg3[7])() = {a3, b3, c3, d3, e3, g3, f3};
static void (*seg2[7])() = {a2, b2, c2, d2, e2, g2, f2};
static void (*seg1[2])() = {a1, b1};

static void (**seven_segs[4])() = {seg2, seg3, seg5, seg6};
static void (**two_segs[2])() = {seg1, seg4};

static const int8_t numbers[11][7] = {{0, -1, 2, 3, 4, 5, 6},        // 0
                                      {-1, -1, -1, -1, 4, 5, -1},    // 1
                                      {0, 1, 2, -1, 4, -1, 6},       // 2
                                      {0, 1, 2, -1, 4, 5, -1},       // 3
                                      {1, 3, 4, 5, -1, -1, -1},      // 4
                                      {0, 1, 2, 3, 5, -1, -1},       // 5
                                      {0, 1, 2, 3, 5, 6, -1},        // 6
                                      {0, 4, 5, -1, -1, -1, -1},     // 7
                                      {0, 1, 2, 3, 4, 5, 6},         // 8
                                      {0, 1, 2, 3, 4, 5, -1},        // 9
                                      {-1, -1, -1, -1, -1, -1, -1}}; // 10 -blank-

static const int8_t two_numbers[11][7] = {{-1,-1}, //0
                                          {0,1}};  //1
                                 
static void (*shapes[6])() = {red_bat, green_bat, red_liq, green_liq, l_percentage, r_percentage};

static uint8_t g_s_nums[4] = {10,10,10,10};
static uint8_t g_t_nums[2] = {0,0};
static uint8_t g_shapes[6] = {0,0,0,0,0,0};

void update_display(uint8_t* s_nums, uint8_t* t_nums, uint8_t* shape)
{
  if(s_nums != NULL)
  {
    for (int i = 0; i < 7; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        if (numbers[s_nums[j]][i] != -1)
        {
          seven_segs[j][numbers[s_nums[j]][i]]();
          delayMicroseconds(8);
          reset_ports();
        }
      }
    }
  }

  if(t_nums != NULL)
  {
    for (int i = 0; i < 2; i++)
    {
      for (int j = 0; j < 2; j++)
      {
        if (two_numbers[t_nums[j]][i] != -1)
        {
          two_segs[j][two_numbers[t_nums[j]][i]]();
          delayMicroseconds(8);
          reset_ports();
        }
      }
    }
  }

  if(shape != NULL)
  {
    for(int i = 0; i < 6; i++)
    {
      if (shape[i] == 1)
      {
        shapes[i]();
        delayMicroseconds(8);
        reset_ports();
      }    
    }
  }
}

void send_six_digit_number_to_display(uint32_t number)
{
  int two_seg[2] = {10,10};
  int seven_seg[4] = {10,10,10,10};
  for (int i = 5; i >= 0; i--) {
    if(i == 3 || i == 0) // for hundreds
    {
      two_seg[i/3] = ((number%10 == 1) ? 1 : 0) ;
      number /=10;
    }
    else
    {
      if(i == 1 || i == 2) // 
      {
        seven_seg[i-1] =  number%10;
        number /=10;
      }
      else
      {
        seven_seg[i-2] =  number%10;
        number /=10;
      }
    }
  }
  update_display(seven_seg,two_seg,NULL);
}

void update_right_numbers(uint8_t numbers)
{
  g_t_nums[1] = (((numbers/100) % 10) ? 1 : 0);
  g_s_nums[2] = (numbers/10) % 10;
  g_s_nums[3] = numbers % 10;
  update_display(g_s_nums,g_t_nums,NULL);
}

void update_left_numbers(uint8_t numbers)
{
  g_t_nums[0] = (((numbers/100) % 10) ? 1 : 0);
  g_s_nums[0] = (numbers/10) % 10;
  g_s_nums[1] = numbers % 10;
  update_display(g_s_nums,g_t_nums,NULL);
}

void update_shapes(uint8_t * numbers)
{
  g_shapes[0] = numbers[0];
  g_shapes[1] = numbers[1];
  g_shapes[2] = numbers[2];
  g_shapes[3] = numbers[3];
  g_shapes[4] = numbers[4];
  g_shapes[5] = numbers[5];
  update_display(NULL,NULL,g_shapes);
}

void keep_alive()
{
  update_display(g_s_nums,g_t_nums,g_shapes);
}

void clear_screen()
{
  int i; 
  for( i = 0; i < 4; i++)
  {
    g_s_nums[i] = 10;
  }

  for(i = 0; i < 2; i++)
  {
    g_t_nums[i] = 0;
  }

  for(i = 0; i < 6; i++)
  {
    g_shapes[i] = 0;
  }
}

void init_screen_ISR()
{
  DDRB |= (1 << 5);         // set Arduino pin 13 as output
  TCCR0A |= (1 << WGM01);   // Set the Timer Mode to CTC
  OCR0A = 0xFE;             // Set the value that we want to count to (249)
  TIMSK0 |= (1 << OCIE0A);   //Set the ISR COMPA vect
  sei();                      //enable global interrupts
  TCCR0B = (1 << CS02);    // set prescaler to 256 and start the timer
}

ISR(TIMER2_COMPA_vect){  // timer2 compare match interrupt
  update_display(g_s_nums,g_t_nums,NULL);
}

void test_screen()
{
  a1();
  delay(500);
  b1();
  delay(500);
  a4();
  delay(500);
  b4();
  delay(500);
  a6();
  delay(500);
  b6();
  delay(500);
  c6();
  delay(500);
  d6();
  delay(500);
  e6();
  delay(500);
  f6();
  delay(500);
  g6();
  delay(500);
  a5();
  delay(500);
  b5();
  delay(500);
  c5();
  delay(500);
  d5();
  delay(500);
  e5();
  delay(500);
  f5();
  delay(500);
  g5();
  delay(500);
  a3();
  delay(500);
  b3();
  delay(500);
  c3();
  delay(500);
  d3();
  delay(500);
  e3();
  delay(500);
  f3();
  delay(500);
  g3();
  delay(500);
  a2();
  delay(500);
  b2();
  delay(500);
  c2();
  delay(500);
  d2();
  delay(500);
  e2();
  delay(500);
  f2();
  delay(500);
  g2();
  delay(500);
  red_bat();
  delay(500);
  green_bat();
  delay(500);
  red_liq();
  delay(500);
  green_liq();
  delay(500);
  l_percentage();
  delay(500);
  r_percentage();
  delay(500);
}