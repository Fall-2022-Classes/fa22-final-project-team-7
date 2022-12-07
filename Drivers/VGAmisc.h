#include "chu_init.h"
#include "vga_core.h"

class Vgamisc
{
public:
	Vgamisc();
	void clear_text();
	void stage_VGA(int stage);
	void display_start();
	void display_resistor_knight();
	void clear_info();
	void display_info(int PlayerCurrentHP, int EnemyCurrentHP );
	void clear_lose();
	void stage_one_win();
	void stage_one_lose();
	void stage_two_win();
	void stage_two_lose();
	void stage_three_win();
	void stage_three_lose();
	void boss2();
	void boss3();
	void init();
	void stage_zero_bypass();
	void stage_one_entrance();
	void stage_two_entrance();
	void stage_three_entrance();
	void stage_one_animation();
	void stage_two_animation();
	void stage_three_animation();
	void clear_text_combat();
	void display_player_damage_effective(int damage);
	void display_player_damage(int damage);
	void display_player_damage_effective2(int damage);
	void display_player_damage2(int damage);
	void display_player_damage_effective3(int damage);
	void display_player_damage3(int damage);
	void display_player_damage_effective4(int damage);
	void display_player_damage4(int damage);
	void display_enemy_damage1(int damage);
	void display_enemy_damage2(int damage);
	void display_enemy_damage3(int damage);
	void enemy_out_of_range(int choice);
	void orientation(int orientation);
	void gradient_rgb(int rgb);


};

