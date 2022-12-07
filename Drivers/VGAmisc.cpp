#include "VGAmisc.h"
#include "osdtext.h"


SpriteCore ghost(get_sprite_addr(BRIDGE_BASE, V3_GHOST), 1024);
SpriteCore mario(get_sprite_addr(BRIDGE_BASE, V1_MOUSE), 4096);
SpriteCore megaone(get_sprite_addr(BRIDGE_BASE, V4_USER4), 4096);
SpriteCore megatwo(get_sprite_addr(BRIDGE_BASE, V5_USER5), 4096);
OsdCore osd(get_sprite_addr(BRIDGE_BASE, V2_OSD));
GpvCore gradient(get_sprite_addr(BRIDGE_BASE, V7_GRADIENT));


Vgamisc::Vgamisc()
{

}

void Vgamisc::clear_text()
{
	for(int i = 0; i<80; i++)
	{
		osd.wr_char(i,28,' ');
		sleep_ms(1);
	}
	for(int i = 0; i<80; i++)
	{
		osd.wr_char(i,29,' ');
		sleep_ms(1);
	}

}

void Vgamisc::stage_VGA(int stage)
{
	for(int i = 0; i<8; i++)
	{
		osd.wr_char(71+i,0,stageVGA[i]);
		sleep_ms(1);
	}
	char stagenumber = (char) (48+stage);
	sleep_ms(1);
	osd.wr_char(79,0,stagenumber);
}

void Vgamisc::display_start()
{
	clear_text();
	for(int i = 0; i<22; i++)
	{
		osd.wr_char(i,28,welcome[i]);
		sleep_ms(1);
	}
	for(int i =0; i<22; i++)
	{
		osd.wr_char(i,29,t1[i]);
		sleep_ms(1);
	}

}
void Vgamisc::display_resistor_knight()
{
	clear_text();
	for(int i = 0; i<10; i++)
	{
		osd.wr_char(i,28,txtone[i]);
		sleep_ms(1);
	}
	for(int i = 0; i<31; i++)
	{
		osd.wr_char(i,29,txttwo[i]);
		sleep_ms(1);
	}
}

void Vgamisc::clear_info()
{
	for(int i = 0; i < 80; i++)
	{
		osd.wr_char(i , 20, ' ');
		sleep_ms(1);
	}
	for(int i = 0; i < 80; i++)
	{
		osd.wr_char(i , 21, ' ');
		sleep_ms(1);
	}
	for(int i = 0; i < 80; i++)
	{
		osd.wr_char(i , 22, ' ');
		sleep_ms(1);
	}
	for(int i = 0; i < 80; i++)
	{
		osd.wr_char(i , 23, ' ');
		sleep_ms(1);
	}
	for(int i = 0; i < 80; i++)
	{
		osd.wr_char(i , 24, ' ');
		sleep_ms(1);
	}
	for(int i = 0; i < 80; i++)
	{
		osd.wr_char(i , 25, ' ');
		sleep_ms(1);
	}
	for(int i = 0; i < 80; i++)
	{
		osd.wr_char(i , 26, ' ');
		sleep_ms(1);
	}

}

void Vgamisc::display_info(int PlayerCurrentHP, int EnemyCurrentHP )
{
	int playernumone =  PlayerCurrentHP % 10;
	char playernumoneout = (char) (48+playernumone);
	int playernumten = PlayerCurrentHP / 10;
	char playernumtenout = (char) (48+playernumten);

	int enemynumone =  EnemyCurrentHP % 10;
	char enemynumoneout = (char) (48+enemynumone);
	int enemynumten = EnemyCurrentHP / 10;
	char enemynumtenout = (char) (48+enemynumten);


	for(int i = 0; i < 9; i++)
	{
		osd.wr_char(i , 20, t5[i]);
		sleep_ms(1);
	}
		sleep_ms(1);
		osd.wr_char(10,20,enemynumtenout);
		osd.wr_char(11,20,enemynumoneout);

	for(int i = 0; i < 10; i++)
	{
		osd.wr_char(i , 21, t6[i]);
		sleep_ms(1);
	}
	sleep_ms(1);
	osd.wr_char(11,21,playernumtenout);
	osd.wr_char(12,21,playernumoneout);

	for(int i = 0; i < 34; i++)
	{
		osd.wr_char(i , 22, t7[i]);
		sleep_ms(1);
	}
	for(int i = 0; i < 24; i++)
	{
		osd.wr_char(i , 23, t8[i]);
		sleep_ms(1);
	}
	for(int i = 0; i < 21; i++)
	{
		osd.wr_char(i , 24, t9[i]);
		sleep_ms(1);
	}
	for(int i = 0; i < 27; i++)
	{
		osd.wr_char(i , 25, t17[i]);
		sleep_ms(1);
	}
	for(int i = 0; i < 25; i++)
	{
		osd.wr_char(i , 26, t18[i]);
		sleep_ms(1);
	}

}

void Vgamisc::clear_lose()
{
	for(int i = 0; i < 80; i++)
	{
		osd.wr_char(i, 27, ' ');
		sleep_ms(1);
	}
}
void Vgamisc::stage_one_win()
{
	clear_text();
	for(int i = 0; i < 64; i++)
	{
		osd.wr_char(i, 28, t4[i]);
		sleep_ms(1);
	}

}
void Vgamisc::stage_one_lose()
{
	for(int i = 0; i < 59; i++)
	{
		osd.wr_char(i, 27, t3[i]);
		sleep_ms(1);
	}
}
void Vgamisc::stage_two_win()
{
	clear_text();
	for(int i = 0; i < 67; i++)
	{
		osd.wr_char(i, 28, t11[i]);
		sleep_ms(1);
	}

}
void Vgamisc::stage_two_lose()
{
	for(int i = 0; i < 61; i++)
	{
		osd.wr_char(i, 27, t10[i]);
		sleep_ms(1);
	}
}
void Vgamisc::stage_three_win()
{
	clear_text();
	for(int i = 0; i < 54; i++)
	{
		osd.wr_char(i, 27, t13[i]);
		sleep_ms(1);
	}
}
void Vgamisc::stage_three_lose()
{
	for(int i = 0; i < 52; i++)
	{
		osd.wr_char(i, 27, t12[i]);
		sleep_ms(1);
	}
}


void Vgamisc::boss2()
{
	for(int i = 0; i < 45; i++)
	{
		osd.wr_char(i, 29, t15[i]);
		sleep_ms(1);
	}
}

void Vgamisc::boss3()
{
	for(int i = 0; i < 37; i++)
	{
		osd.wr_char(i, 29, t16[i]);
		sleep_ms(1);
	}
}

void Vgamisc::init()
{
	osd.set_color(0xFFF, 0x001);
    clear_info();
    clear_lose();
    clear_text();
    mario.bypass(1);
    ghost.bypass(1);
    megaone.bypass(1);
    megatwo.bypass(1);
 	gradient.bypass(0);

}

void Vgamisc::stage_zero_bypass()
{
    mario.bypass(1);
    ghost.bypass(1);
    megaone.bypass(1);
    megatwo.bypass(1);
}
void Vgamisc::stage_one_entrance()
{
	int x_mario, y_mario;
	ghost.move_xy(305,300);
	mario.move_xy(284,100);
	ghost.bypass(0);
	mario.bypass(0);
	x_mario = 284;
	y_mario = 0;
	for(int i = 0; i < 100; i++)
	{
		mario.move_xy(x_mario,y_mario);
		y_mario = y_mario + 1;
		sleep_ms(5);
	}


}
void Vgamisc::stage_two_entrance()
{
	int x_mega1, y_mega1;
	mario.bypass(1);
	ghost.move_xy(305,300);
	megaone.move_xy(284,100);
	ghost.bypass(0);
	megaone.bypass(0);
	x_mega1 = 284;
	y_mega1 = 0;
	for(int i = 0; i < 100; i++)
	{
		megaone.move_xy(x_mega1,y_mega1);
		y_mega1 = y_mega1 + 1;
		sleep_ms(5);
	}

}
void Vgamisc::stage_three_entrance()
{
	int x_mega2, y_mega2;
	mario.bypass(1);
	megaone.bypass(1);
	ghost.move_xy(305,300);
	megatwo.move_xy(284,100);
	ghost.bypass(0);
	megatwo.bypass(0);
	x_mega2 = 284;
	y_mega2 = 0;
	for(int i = 0; i < 100; i++)
	{
		megatwo.move_xy(x_mega2,y_mega2);
		y_mega2 = y_mega2 + 1;
		sleep_ms(5);
	}

}
void Vgamisc::stage_one_animation()
{
	int x_mario, y_mario, x_ghost, y_ghost;
		x_ghost = 305;
		y_ghost = 300;
		x_mario = 284;
		y_mario = 100;
		for(int i = 0; i < 95; i++)
		{
			mario.move_xy(x_mario,y_mario);
			ghost.move_xy(x_ghost,y_ghost);
			y_mario = y_mario + 1;
			y_ghost = y_ghost - 1;
			sleep_ms(5);
			if(i == 94)
			{
				ghost.bypass(1);
				mario.bypass(1);
				sleep_ms(100);
				ghost.bypass(0);
				mario.bypass(0);
				sleep_ms(20);
    			ghost.move_xy(305,300);
    			mario.move_xy(284,100);
			}
		}


}
void Vgamisc::stage_two_animation()
{
	int x_mega1, y_mega1, x_ghost2, y_ghost2;
		x_ghost2 = 305;
		y_ghost2 = 300;
		x_mega1 = 284;
		y_mega1 = 100;
		for(int i = 0; i < 85; i++)
		{
			megaone.move_xy(x_mega1,y_mega1);
			ghost.move_xy(x_ghost2,y_ghost2);
			y_mega1 = y_mega1 + 1;
			y_ghost2 = y_ghost2 - 1;
			sleep_ms(5);
			if(i == 84)
			{
				ghost.bypass(1);
				megaone.bypass(1);
				sleep_ms(100);
				ghost.bypass(0);
				megaone.bypass(0);
				sleep_ms(20);
  			ghost.move_xy(305,300);
  			megaone.move_xy(284,100);
			}
		}

}
void Vgamisc::stage_three_animation()
{
	int x_mega2, y_mega2, x_ghost3, y_ghost3;
		x_ghost3 = 305;
		y_ghost3 = 300;
		x_mega2 = 284;
		y_mega2 = 100;
		for(int i = 0; i < 85; i++)
		{
			megatwo.move_xy(x_mega2,y_mega2);
			ghost.move_xy(x_ghost3,y_ghost3);
			y_mega2 = y_mega2 + 1;
			y_ghost3 = y_ghost3 - 1;
			sleep_ms(5);
			if(i == 84)
			{
				ghost.bypass(1);
				megatwo.bypass(1);
				sleep_ms(100);
				ghost.bypass(0);
				megatwo.bypass(0);
				sleep_ms(20);
   			ghost.move_xy(305,300);
   			megatwo.move_xy(284,100);
			}
		}

}


void Vgamisc::clear_text_combat()
{
	for(int i = 0; i<200; i++)
	{
		osd.wr_char(i,28,' ');
	}
	for(int i = 0; i<200; i++)
	{
		osd.wr_char(i,29,' ');
	}

}

 void Vgamisc::display_player_damage_effective(int damage)
{
	 clear_text_combat();
	 char vga_damage_ones;
	 char vga_damage_tens;
	 vga_damage_ones = (char) ((damage % 10) + 48);
	 vga_damage_tens = (char) ((damage / 10) + 48);
	 for(int i = 0; i < 35; i++)
	 {
		 osd.wr_char(i,28,txt1[i]);
	 }
	 osd.wr_char(36,28,vga_damage_tens);
	 osd.wr_char(37,28,vga_damage_ones);

	 for(int i = 0; i < 7; i++)
	 {
		 osd.wr_char(i+39,28, txt2[i]);
	 }
	 for(int i = 0; i < 23; i++)
	 {
		 osd.wr_char(i+47,28, txt3[i]);
	 }
}

 void Vgamisc::display_player_damage(int damage)
{
	 clear_text_combat();
	 char vga_damage_ones;
	 char vga_damage_tens;
	 vga_damage_ones = (char) ((damage % 10) + 48);
	 vga_damage_tens = (char) ((damage / 10) + 48);

	 for(int i = 0; i < 35; i++)
	 {
		 osd.wr_char(i,28,txt1[i]);
	 }

	 osd.wr_char(36,28,vga_damage_tens);
	 osd.wr_char(37,28,vga_damage_ones);

	 for(int i = 0; i < 7; i++)
	 {
		 osd.wr_char(i+39,28, txt2[i]);
	 }
}


 void Vgamisc::display_player_damage_effective2(int damage)
{
	 clear_text_combat();
	 char vga_damage_ones;
	 char vga_damage_tens;
	 vga_damage_ones = (char) ((damage % 10) + 48);
	 vga_damage_tens = (char) ((damage / 10) + 48);
	 for(int i = 0; i < 32; i++)
	 {
		 osd.wr_char(i,28,txt4[i]);
	 }

	 osd.wr_char(33,28,vga_damage_tens);
	 osd.wr_char(34,28,vga_damage_ones);

	 for(int i = 0; i < 7; i++)
	 {
		 osd.wr_char(i+36,28, txt2[i]);
	 }
	 for(int i = 0; i < 23; i++)
	 {
		 osd.wr_char(i+44,28, txt3[i]);
	 }
}

 void Vgamisc::display_player_damage2(int damage)
{
	 clear_text_combat();
	 char vga_damage_ones;
	 char vga_damage_tens;
	 vga_damage_ones = (char) ((damage % 10) + 48);
	 vga_damage_tens = (char) ((damage / 10) + 48);

	 for(int i = 0; i < 32; i++)
	 {
		 osd.wr_char(i,28,txt4[i]);
	 }

	 osd.wr_char(33,28,vga_damage_tens);
	 osd.wr_char(34,28,vga_damage_ones);

	 for(int i = 0; i < 7; i++)
	 {
		 osd.wr_char(i+36,28, txt2[i]);
	 }
}
 void Vgamisc::display_player_damage3(int damage)
{
	 clear_text_combat();
	 char vga_damage_ones;
	 char vga_damage_tens;
	 vga_damage_ones = (char) ((damage % 10) + 48);
	 vga_damage_tens = (char) ((damage / 10) + 48);

	 for(int i = 0; i < 38; i++)
	 {
		 osd.wr_char(i,28,txt5[i]);
	 }

	 osd.wr_char(39,28,vga_damage_tens);
	 osd.wr_char(40,28,vga_damage_ones);

	 for(int i = 0; i < 7; i++)
	 {
		 osd.wr_char(i+42,28, txt2[i]);
	 }
}


 void Vgamisc::display_player_damage_effective3(int damage)
{
	 clear_text_combat();
	 char vga_damage_ones;
	 char vga_damage_tens;
	 vga_damage_ones = (char) ((damage % 10) + 48);
	 vga_damage_tens = (char) ((damage / 10) + 48);
	 for(int i = 0; i < 38; i++)
	 {
		 osd.wr_char(i,28,txt5[i]);
	 }

	 osd.wr_char(39,28,vga_damage_tens);
	 osd.wr_char(40,28,vga_damage_ones);

	 for(int i = 0; i < 7; i++)
	 {
		 osd.wr_char(i+42,28, txt2[i]);
	 }
	 for(int i = 0; i < 23; i++)
	 {
		 osd.wr_char(i+50,28, txt3[i]);
	 }
}

 void Vgamisc::display_player_damage_effective4(int damage)
{
	 clear_text_combat();
	 char vga_damage_ones;
	 char vga_damage_tens;
	 vga_damage_ones = (char) ((damage % 10) + 48);
	 vga_damage_tens = (char) ((damage / 10) + 48);
	 for(int i = 0; i < 39; i++)
	 {
		 osd.wr_char(i,28,txt11[i]);
	 }

	 osd.wr_char(40,28,vga_damage_tens);
	 osd.wr_char(41,28,vga_damage_ones);

	 for(int i = 0; i < 7; i++)
	 {
		 osd.wr_char(i+43,28, txt2[i]);
	 }
	 for(int i = 0; i < 23; i++)
	 {
		 osd.wr_char(i+51,28, txt3[i]);
	 }
}
 void Vgamisc::display_player_damage4(int damage)
{
	 clear_text_combat();
	 char vga_damage_ones;
	 char vga_damage_tens;
	 vga_damage_ones = (char) ((damage % 10) + 48);
	 vga_damage_tens = (char) ((damage / 10) + 48);

	 for(int i = 0; i < 39; i++)
	 {
		 osd.wr_char(i,28,txt11[i]);
	 }

	 osd.wr_char(40,28,vga_damage_tens);
	 osd.wr_char(41,28,vga_damage_ones);

	 for(int i = 0; i < 7; i++)
	 {
		 osd.wr_char(i+43,28, txt2[i]);
	 }
}


 void Vgamisc::display_enemy_damage1(int damage)
{
	 char vga_damage_ones;
	 char vga_damage_tens;
	 vga_damage_ones = (char) ((damage % 10) + 48);
	 vga_damage_tens = (char) ((damage / 10) + 48);

	 for(int i = 0; i < 34; i++)
	 {
		 osd.wr_char(i,29,txt7[i]);
	 }

	 osd.wr_char(35,29,vga_damage_tens);
	 osd.wr_char(36,29,vga_damage_ones);

	 for(int i = 0; i < 7; i++)
	 {
		 osd.wr_char(i+38,29, txt2[i]);
	 }
}

 void Vgamisc::display_enemy_damage2(int damage)
{
	 char vga_damage_ones;
	 char vga_damage_tens;
	 vga_damage_ones = (char) ((damage % 10) + 48);
	 vga_damage_tens = (char) ((damage / 10) + 48);

	 for(int i = 0; i < 34; i++)
	 {
		 osd.wr_char(i,29,txt8[i]);
	 }

	 osd.wr_char(35,29,vga_damage_tens);
	 osd.wr_char(36,29,vga_damage_ones);

	 for(int i = 0; i < 7; i++)
	 {
		 osd.wr_char(i+38,29, txt2[i]);
	 }
}
 void Vgamisc::display_enemy_damage3(int damage)
{
	 char vga_damage_ones;
	 char vga_damage_tens;
	 vga_damage_ones = (char) ((damage % 10) + 48);
	 vga_damage_tens = (char) ((damage / 10) + 48);

	 for(int i = 0; i < 34; i++)
	 {
		 osd.wr_char(i,29,txt10[i]);
	 }

	 osd.wr_char(35,29,vga_damage_tens);
	 osd.wr_char(36,29,vga_damage_ones);

	 for(int i = 0; i < 7; i++)
	 {
		 osd.wr_char(i+38,29, txt2[i]);
	 }
}
 void Vgamisc::enemy_out_of_range(int choice)
 {
	 char vga_choice;
	 vga_choice = (char) (choice + 48);
	 for(int i = 0; i < 50; i++)
	 {
		 osd.wr_char(i,29, txt9[i]);
	 }
	 	 osd.wr_char(51,29,vga_choice);
 }
 void Vgamisc::orientation(int orientation)
{
 	gradient.wr_mem(2, orientation);
}

void Vgamisc::gradient_rgb(int rgb)
{
	gradient.wr_mem(1, rgb);
}


