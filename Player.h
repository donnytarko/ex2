#ifndef EX2_Player_H
#define EX2_Player_H

class Player {
    private:
    const char* m_name; 
    int m_level, m_force, m_maxHP, m_hp, m_coins;

    public:
    Player(const char* name, int maxHP = 100, int force = 5);
    ~Player();
    void printInfo() const;
    void levelUp();
    int getLevel() const;
    void buff(int forceIncrease);
    void heal(int additionalHP);
    void damage(int damageTaken);
    bool isKnockedOut() const;
    void addCoins(int additionalCoins);
    bool pay(int paymentAmount);
    int getAttackStrength() const;
};

#endif //EX2_Player_H