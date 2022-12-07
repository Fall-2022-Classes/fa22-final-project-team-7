#pragma once
class Combat
{
public:
    Combat();
    void PlayerAttack(int, int, int);
    void EnemyAttack(int, int);
    int getEnemyHP() const;
    int getPlayerHP() const;
private:
    int EnemyHealth;
    int PlayerHealth;
    int damage;
};
