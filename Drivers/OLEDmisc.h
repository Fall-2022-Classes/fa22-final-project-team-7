#include "spi_core.h"
#include "OLED_GPO.h"
#include "chu_init.h"

class Oledmisc
{
public:
	Oledmisc();
	void screen_init();
	void screen_terminate();
	void display_on();
	void display_off();
	void set_cursor(uint8_t x, uint8_t y);
	void screen_clear();
	void screen_fill();
	void print_char(char ch, uint8_t x_cord, uint8_t y_cord);
	void display_OLED(int PlayerCurrentHP, int stage);
};

