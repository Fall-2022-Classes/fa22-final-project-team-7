#include "chu_init.h"
#include "gpio_cores.h"
#include "vga_core.h"
#include "sseg_core.h"
#include "i2c_core.h"
#include "xadc_core.h"
#include <cmath>
#include "Combat.h"
#include "ps2_core.h"
#include "OLEDmisc.h"
#include "VGAmisc.h"
#include "gpio_cores.h"


GpiCore sw(get_slot_addr(BRIDGE_BASE, S3_SW));
FrameCore frame(FRAME_BASE);
SsegCore sseg(get_slot_addr(BRIDGE_BASE, S8_SSEG));
Ps2Core ps2(get_slot_addr(BRIDGE_BASE, S11_PS2));
XadcCore adc(get_slot_addr(BRIDGE_BASE, S5_XDAC));
Oledmisc OLED;
Vgamisc VGA;
Combat com;


int EnemyHP = 0;int PlayerCurrentHP = 0;int EnemyCurrentHP = 0;
int TotalPlayerDamage = 0;int TotalEnemyDamage = 0;
int EnemyDamageCalc = 0;int PlayerDamageCalc = 0;
char PlayerInput;int PlayerChoice;int enemyChoice;
int activity = 0;


int stage = 0;
int PlayerTotalHP = 36;


int main()
{
    int id;
    id = ps2.init();
    //int lbtn, rbtn, xmov, ymov;
    char ch;
    int once_stage_zero = 1;
    int once_stage_one = 0;
    int once_stage_two = 0;
    int once_stage_three = 0;
    VGA.init();
    OLED.screen_init();
    OLED.screen_clear();



    while (1)
    {

    	VGA.orientation((sw.read() & 0xC000) >> 14);
    	VGA.gradient_rgb(sw.read());
    	if (stage == 0)
        {
    		VGA.stage_zero_bypass();
    		if(once_stage_zero == 1)
    		{
    			OLED.display_OLED(PlayerCurrentHP,stage);
    			VGA.stage_VGA(stage);
    			VGA.display_start();
    			uart.disp("Stage: ");
    			uart.disp(stage);
    			uart.disp("\r\n");
    			uart.disp("Welcome to FPGA Quest!\r\nType 1 to get started: ");
    		}
    		if (id == 1)
    		{
    			if (ps2.get_kb_ch(&ch))
    			{
    				if(ch == '1')
    				{
    					VGA.clear_lose();
    		            uart.disp("\r\nGood Luck! \r\n \r\nA Resistor Knight has appeared!\r\n");
    		            //cout << "\nGood Luck!\n\nA Resistor Knight has appeared!\n";
    		            once_stage_one = 1;
    		            stage = 1;
    		        }
    				else
    		        {
    		            uart.disp("Please press '1' to get started. \r\n");
    		            //cout << "Please type 1 to get started.\n";
    		            stage = 0;
    		        }
    		     }
    		}
    		once_stage_zero = 0;
        }

    	if (stage == 1)
        {
            EnemyHP = 40;
            PlayerCurrentHP = PlayerTotalHP - TotalPlayerDamage;
            EnemyCurrentHP = EnemyHP - TotalEnemyDamage;
            if (PlayerCurrentHP <= 0)
            {
            	uart.disp("\r\nYou have been defeated by the Resistor Knight, Game Over... \r\n");
                //cout << "\nYou have been defeated by the Resistor Knight, Game Over...\n";
                TotalPlayerDamage = 0;
                TotalEnemyDamage = 0;
                once_stage_zero = 1;
                PlayerCurrentHP = 0;
                VGA.clear_info();
                VGA.stage_one_lose();
                stage = 0;
            }
            else if (EnemyCurrentHP <= 0)
            {
        	    EnemyCurrentHP = 0;
        	    OLED.display_OLED(PlayerCurrentHP,stage);
        	    VGA.stage_VGA(stage);
        	    VGA.display_info(PlayerCurrentHP, EnemyCurrentHP);
        		sleep_ms(200);
            	uart.disp("\r\nYou have defeated the Resistor Knight, your HP will be restored!\r\n");
                //cout << "You have defeated the Resistor Knight, your HP will be restored!";
                TotalPlayerDamage = 0;
                TotalEnemyDamage = 0;
                once_stage_two = 1;
                VGA.stage_one_win();
                VGA.boss2();
                stage = 2;
            }
            else
            {
            	if((once_stage_one == 1) || activity == 1)
            	{
            		if(once_stage_one == 1)
            		{
            			OLED.display_OLED(PlayerCurrentHP,stage);
            			VGA.stage_VGA(stage);
            			VGA.display_info(PlayerCurrentHP, EnemyCurrentHP);
            			VGA.display_resistor_knight();
            			VGA.stage_one_entrance();
            		}

        			uart.disp(once_stage_one);
        			uart.disp("\r\n");
        			OLED.display_OLED(PlayerCurrentHP,stage);
        			VGA.stage_VGA(stage);
        			VGA.display_info(PlayerCurrentHP, EnemyCurrentHP);
            		uart.disp("Stage: ");
            		uart.disp(stage);
            		uart.disp("\r\n");
            		uart.disp("\nEnemy HP: ");
            		uart.disp(EnemyCurrentHP);
            		uart.disp("\r\n");
            		uart.disp("\nPlayer HP: ");
            		uart.disp(PlayerCurrentHP);
            		uart.disp("\r\n");
            		uart.disp("\r\nSelect a move from the list below.\r\n1.Voltage Drop\r\n2.Amp Drain\r\n3.Grounded Strike\r\n4.Inductive Charge\r\n\n");
            		activity = 0;
            	}

            	if (id == 1)
            	{
            		if (ps2.get_kb_ch(&ch))
            		{
            			if(ch == '1')
            	        {
            				VGA.stage_one_animation();
            				enemyChoice = rand() % 3 + 1;
            	            com.PlayerAttack(PlayerCurrentHP, 1, 0);
            	            com.EnemyAttack(EnemyCurrentHP, enemyChoice);
            	            TotalEnemyDamage = TotalEnemyDamage + com.getEnemyHP();
            	            TotalPlayerDamage = TotalPlayerDamage + com.getPlayerHP();
            	            activity = 1;
            	        }
            	        if(ch == '2')
            	        {
            	        	VGA.stage_one_animation();
            	        	enemyChoice = rand() % 3 + 1;
            	            com.PlayerAttack(PlayerCurrentHP, 2, 1);
            	            com.EnemyAttack(EnemyCurrentHP, enemyChoice);
            	            TotalEnemyDamage = TotalEnemyDamage + com.getEnemyHP();
            	            TotalPlayerDamage = TotalPlayerDamage + com.getPlayerHP();
            	            activity = 1;
            	        }
            	        if(ch == '3')
            	        {
            	        	VGA.stage_one_animation();
            	        	enemyChoice = rand() % 3 + 1;
            	            com.PlayerAttack(PlayerCurrentHP, 3, 1);
            	            com.EnemyAttack(EnemyCurrentHP, enemyChoice);
            	            TotalEnemyDamage = TotalEnemyDamage + com.getEnemyHP();
            	            TotalPlayerDamage = TotalPlayerDamage + com.getPlayerHP();
            	            activity = 1;
            	        }
            	        if(ch == '4')
            	        {
            	        	VGA.stage_one_animation();
            	        	enemyChoice = rand() % 3 + 1;
            	            com.PlayerAttack(PlayerCurrentHP, 4, 0);
            	            com.EnemyAttack(EnemyCurrentHP, enemyChoice);
            	            TotalEnemyDamage = TotalEnemyDamage + com.getEnemyHP();
            	            TotalPlayerDamage = TotalPlayerDamage + com.getPlayerHP();
            	            activity = 1;
            	        }
            	    }

                 }
            	 once_stage_one = 0;
            }
        }

        if (stage == 2)
        {
            EnemyHP = 30;
            PlayerCurrentHP = PlayerTotalHP - TotalPlayerDamage;
            EnemyCurrentHP = EnemyHP - TotalEnemyDamage;
            if (PlayerCurrentHP <= 0)
            {
            	uart.disp("\r\nYou have been defeated by the Capacitance Thief, Game Over...\r\n");
                TotalPlayerDamage = 0;
                TotalEnemyDamage = 0;
                once_stage_zero = 1;
                PlayerCurrentHP = 0;
                VGA.clear_info();
                VGA.stage_two_lose();
                stage = 0;
            }
            else if (EnemyCurrentHP <= 0)
            {
            	uart.disp("You have defeated the Capacitance Knight, your HP will be restored!\r\n");
                TotalPlayerDamage = 0;
                TotalEnemyDamage = 0;
                once_stage_three = 1;
                VGA.stage_two_win();
                VGA.boss3();
                stage = 3;
            }
            else
            {
            	if((once_stage_two == 1) || activity == 1)
            	{
            		if(once_stage_two == 1)
            		{
            			VGA.stage_two_entrance();
            		}

            		OLED.display_OLED(PlayerCurrentHP,stage);
            		VGA.stage_VGA(stage);
            		VGA.display_info(PlayerCurrentHP, EnemyCurrentHP);
            		uart.disp("Stage: ");
            		uart.disp(stage);
            		uart.disp("\r\n");
            		uart.disp("\nEnemy HP: ");
            		uart.disp(EnemyCurrentHP);
            		uart.disp("\r\n");
            		uart.disp("\nPlayer HP: ");
            		uart.disp(PlayerCurrentHP);
            		uart.disp("\r\n");
            		uart.disp("\r\nSelect a move from the list below.\r\n1.Voltage Drop\r\n2.Amp Drain\r\n3.Grounded Strike\r\n4.Inductive Charge\r\n\n");
            		activity = 0;
            	}

            	if (id == 1)
            	{
            		if (ps2.get_kb_ch(&ch))
            		{
            			if(ch == '1')
            			{
            				VGA.stage_two_animation();
            				enemyChoice = rand() % 3 + 1;
            				com.PlayerAttack(PlayerCurrentHP, 1, 1);
            				com.EnemyAttack(EnemyCurrentHP, enemyChoice);
            				TotalEnemyDamage = TotalEnemyDamage + com.getEnemyHP();
            				TotalPlayerDamage = TotalPlayerDamage + com.getPlayerHP();
            				activity = 1;
            			}
            			if(ch == '2')
            			{
            				VGA.stage_two_animation();
            				enemyChoice = rand() % 3 + 1;
            				com.PlayerAttack(PlayerCurrentHP, 2, 0);
            				com.EnemyAttack(EnemyCurrentHP, enemyChoice);
            				TotalEnemyDamage = TotalEnemyDamage + com.getEnemyHP();
            				TotalPlayerDamage = TotalPlayerDamage + com.getPlayerHP();
            				activity = 1;
            			}
            	        if(ch == '3')
            	        {
            	        	VGA.stage_two_animation();
            	        	enemyChoice = rand() % 3 + 1;
            	            com.PlayerAttack(PlayerCurrentHP, 3, 1);
            	            com.EnemyAttack(EnemyCurrentHP, enemyChoice);
            	            TotalEnemyDamage = TotalEnemyDamage + com.getEnemyHP();
            	            TotalPlayerDamage = TotalPlayerDamage + com.getPlayerHP();
            	            activity = 1;
            	        }
            	        if(ch == '4')
            	        {
            	        	VGA.stage_two_animation();
            	        	enemyChoice = rand() % 3 + 1;
            	            com.PlayerAttack(PlayerCurrentHP, 4, 0);
            	            com.EnemyAttack(EnemyCurrentHP, enemyChoice);
            	            TotalEnemyDamage = TotalEnemyDamage + com.getEnemyHP();
            	            TotalPlayerDamage = TotalPlayerDamage + com.getPlayerHP();
            	            activity = 1;
            	        }
            		}

            	}
                once_stage_two = 0;
            }
        }

        if (stage == 3)
        {
            EnemyHP = 60;
            PlayerCurrentHP = PlayerTotalHP - TotalPlayerDamage;
            EnemyCurrentHP = EnemyHP - TotalEnemyDamage;
            if (PlayerCurrentHP <= 0)
            {
            	uart.disp("\r\nYou have been defeated by the Amp Lord, Game Over...\r\n");
                TotalPlayerDamage = 0;
                TotalEnemyDamage = 0;
            	once_stage_zero = 1;
            	PlayerCurrentHP = 0;
            	VGA.clear_info();
            	VGA.stage_three_lose();
                stage = 0;
            }
            else if (EnemyCurrentHP <= 0)
            {
            	uart.disp("You have defeated the Amp Lord, and completed the game!\r\n");
                TotalPlayerDamage = 0;
                TotalEnemyDamage = 0;
            	once_stage_zero = 1;
            	VGA.clear_info();
            	PlayerCurrentHP = 0;
            	VGA.stage_three_win();
                stage = 0;
            }
            else
            {
            	if((once_stage_three == 1) || activity == 1)
            	{
            		if((once_stage_three == 1) || activity == 1)
                	{
                		if(once_stage_three == 1)
                		{
                			VGA.stage_three_entrance();
                		}
                	}
            		OLED.display_OLED(PlayerCurrentHP,stage);
            		VGA.stage_VGA(stage);
            		VGA.display_info(PlayerCurrentHP, EnemyCurrentHP);
            		uart.disp("Stage: ");
            		uart.disp(stage);
            		uart.disp("\r\n");
            		uart.disp("\nEnemy HP: ");
            		uart.disp(EnemyCurrentHP);
            		uart.disp("\r\n");
            		uart.disp("\nPlayer HP: ");
            		uart.disp(PlayerCurrentHP);
            		uart.disp("\r\n");
            		uart.disp("\r\nSelect a move from the list below.\r\n1.Voltage Drop\r\n2.Amp Drain\r\n3.Grounded Strike\r\n4.Inductive Charge\r\n\n");
            		activity = 0;
            	}
            	if (id == 1)
            	{
            		if (ps2.get_kb_ch(&ch))
            		{
            			if(ch == '1')
        	        	{
            				VGA.stage_three_animation();
        	                enemyChoice = rand() % 3 + 1;
        	                com.PlayerAttack(PlayerCurrentHP, 1, 0);
        	                com.EnemyAttack(EnemyCurrentHP, enemyChoice);
        	                TotalEnemyDamage = TotalEnemyDamage + com.getEnemyHP();
        	                TotalPlayerDamage = TotalPlayerDamage + com.getPlayerHP();
                            activity = 1;
        	        	 }
        	        	 if(ch == '2')
        	        	 {
        	        		 VGA.stage_three_animation();
        	                 enemyChoice = rand() % 3 + 1;
        	                 com.PlayerAttack(PlayerCurrentHP, 2, 0);
        	                 com.EnemyAttack(EnemyCurrentHP, enemyChoice);
        	                 TotalEnemyDamage = TotalEnemyDamage + com.getEnemyHP();
        	                 TotalPlayerDamage = TotalPlayerDamage + com.getPlayerHP();
        	                 activity = 1;
        	        	 }
             	        if(ch == '3')
             	        {
             	        	VGA.stage_three_animation();
             	        	enemyChoice = rand() % 3 + 1;
             	            com.PlayerAttack(PlayerCurrentHP, 3, 1);
             	            com.EnemyAttack(EnemyCurrentHP, enemyChoice);
             	            TotalEnemyDamage = TotalEnemyDamage + com.getEnemyHP();
             	            TotalPlayerDamage = TotalPlayerDamage + com.getPlayerHP();
             	            activity = 1;
             	        }
             	        if(ch == '4')
             	        {
             	        	VGA.stage_three_animation();
             	        	enemyChoice = rand() % 3 + 1;
             	            com.PlayerAttack(PlayerCurrentHP, 4, 1);
             	            com.EnemyAttack(EnemyCurrentHP, enemyChoice);
             	            TotalEnemyDamage = TotalEnemyDamage + com.getEnemyHP();
             	            TotalPlayerDamage = TotalPlayerDamage + com.getPlayerHP();
             	            activity = 1;
             	        }
        	         }
        	      }
                once_stage_three = 0;
            }
        }
    }
}

