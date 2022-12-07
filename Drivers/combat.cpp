#include <cmath>
#include "Combat.h"
#include "chu_init.h"
#include "VGAmisc.h"


int EnemyHealth;
int PlayerHealth;
int damage;

Combat::Combat()
{
}


Vgamisc OSD;

void Combat::PlayerAttack(int CurrentEnemyHP, int choice, int weak)
{
    if (choice == 1)
    {
        if (weak == 1)
        {
            damage = 1.5 * ((rand() % 4 + 1) + 3);
            OSD.display_player_damage_effective(damage);
            uart.disp("\r\n");
            uart.disp("Player used Voltage Drop! You dealt ");
            uart.disp(damage);
            uart.disp(" damage!\r\n It was super effective!\r\n");
            //cout << "\n" << Name << " used " << AtkName1 << "! You dealt " << damage << " damage!\nIt was supereffective!\n";
        }
        else if (weak == 0)
        {
            damage = (rand() % 4 + 1) + 3;
            OSD.display_player_damage(damage);
            uart.disp("\r\n");
            uart.disp("Player used Voltage Drop! You dealt ");
            uart.disp(damage);
            uart.disp(" damage!\r\n");
            //cout << "\n" << Name << " used " << AtkName1 << "! You dealt " << damage << " damage!\n";
        }
        EnemyHealth = damage;
        getEnemyHP();
    }
    if (choice == 2)
    {
        if (weak == 1)
        {
            damage = 1.5 * ((rand() % 6 + 1) + 2);
            OSD.display_player_damage_effective2(damage);
            uart.disp("\r\n");
            uart.disp("Player used Amp Drain! You dealt ");
            uart.disp(damage);
            uart.disp(" damage!\r\n It was super effective!\r\n");
            //cout << "\n" << Name << " used " << AtkName1 << "! You dealt " << damage << " damage!\nIt was supereffective!\n";
        }
        else if (weak == 0)
        {
            damage = (rand() % 6 + 1) + 2;
            OSD.display_player_damage2(damage);
            uart.disp("\r\n");
            uart.disp("Player used Amp Drain! You dealt ");
            uart.disp(damage);
            uart.disp(" damage!\r\n");
            //cout << "\n" << Name << " used " << AtkName1 << "! You dealt " << damage << " damage!\n";
        }
        //cout << "\n" << Name << " used " << AtkName2 << "! You dealt " << damage << " damage!\n";
        EnemyHealth = damage;
        getEnemyHP();
    }
    if (choice == 3)
        {
            if (weak == 1)
            {
                damage = 1.5 * ((rand()% 4 + 1) + 4);
                OSD.display_player_damage_effective3(damage);
                uart.disp("\r\n");
                uart.disp("Player used Grounded Strike! You dealt ");
                uart.disp(damage);
                uart.disp(" damage!\r\n It was super effective!\r\n");
                //cout << "\n" << Name << " used " << AtkName1 << "! You dealt " << damage << " damage!\nIt was supereffective!\n";
            }
            else if (weak == 0)
            {
                damage = (rand() % 4 + 1) + 4;
                OSD.display_player_damage3(damage);
                uart.disp("\r\n");
                uart.disp("Player used Grounded Strike! You dealt ");
                uart.disp(damage);
                uart.disp(" damage!\r\n");
                //cout << "\n" << Name << " used " << AtkName1 << "! You dealt " << damage << " damage!\n";
            }
            EnemyHealth = damage;
            getEnemyHP();
        }
        if (choice == 4)
        {
            if (weak == 1)
            {
                damage = 1.5 * (rand() % 10 + 1);
                OSD.display_player_damage_effective4(damage);
                uart.disp("\r\n");
                uart.disp("Player used Inductive Charge! You dealt ");
                uart.disp(damage);
                uart.disp(" damage!\r\n It was super effective!\r\n");
                //cout << "\n" << Name << " used " << AtkName1 << "! You dealt " << damage << " damage!\nIt was supereffective!\n";
            }
            else if (weak == 0)
            {
                damage = rand() % 10 + 1;
                OSD.display_player_damage4(damage);
                uart.disp("\r\n");
                uart.disp("Player used Inductive Charge! You dealt ");
                uart.disp(damage);
                uart.disp(" damage!\r\n");
                //cout << "\n" << Name << " used " << AtkName1 << "! You dealt " << damage << " damage!\n";
            }
            //cout << "\n" << Name << " used " << AtkName2 << "! You dealt " << damage << " damage!\n";
            EnemyHealth = damage;
            getEnemyHP();
        }
//    else if (choice > 3)
//    {
//
//    	uart.disp("\r\nPlayer Choice Out of Range, fix this. Choice Value: ");
//    	uart.disp(choice);
//    	uart.disp("\r\n");
//        //cout << "\nPlayer Choice Out of Range, fix this. Choice Value: " << choice << "\n";
//    }
}

void Combat::EnemyAttack(int CurrentPlayerHP, int choice)
{
    //string EAtkName1 = "Enemy Move #1";
    //string EAtkName2 = "Enemy Move #2";
    //string EAtkName3 = "Enemy Move #3";
    if (choice == 1)
    {
        damage = rand() % 6 + 1;
        OSD.display_enemy_damage1(damage);
        uart.disp("\r\n");
        uart.disp("Enemy used Enemy Move #1! You took ");
        uart.disp(damage);
        uart.disp(" damage!\r\n");
        //cout << "\n" << Name << " used " << EAtkName1 << "! You took " << damage << " damage!\n";
        PlayerHealth = damage;
        getPlayerHP();
    }
    if (choice == 2)
    {
        damage = rand() % 2 + 3;
        OSD.display_enemy_damage2(damage);
        uart.disp("\r\n");
        uart.disp("Enemy used Enemy Move #2! You took ");
        uart.disp(damage);
        uart.disp(" damage!\r\n");
        //cout << Name << " used " << EAtkName2 << "! You took " << damage << " damage!\n";
        PlayerHealth = damage;
        getPlayerHP();
    }
    if (choice == 3)
    {
        damage = rand() % 3 + 4;
        OSD.display_enemy_damage3(damage);
        uart.disp("\r\n");
        uart.disp("Enemy used Enemy Move #3! You took ");
        uart.disp(damage);
        uart.disp(" damage!\r\n");
        //cout << "\n" << Name << " used " << EAtkName2 << "! You took " << damage << " damage!\n";
        PlayerHealth = damage;
        getPlayerHP();
    }
    else if(choice > 3)
    {
    	OSD.enemy_out_of_range(choice);
    	uart.disp("\r\nEnemy Choice Out of Range, fix this. Choice Value: ");
    	uart.disp(choice);
    	uart.disp("\r\n");
        //cout << "Enemy Choice Out of Range, fix this. Choice Value: " << choice << "\n";
    }
}

int Combat::getEnemyHP()  const
{
    return EnemyHealth;
}
int Combat::getPlayerHP()  const
{
    return PlayerHealth;
}
