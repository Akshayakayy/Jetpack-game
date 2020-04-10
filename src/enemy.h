#include "main.h"

#ifndef ENEMY_H
#define ENEMY_H


class Enemy {
public:
    Enemy() {}
    Enemy(float x, float y, float a, float b, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(double,double);
    double speed;
    void update(float x, float y, float a, float b, color_t color);
private:
    VAO *object;
};

class Enemy2 {
public:
    Enemy2() {}
    Enemy2(float x, float y, float a, float b, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(double,double);
    double speed;
    void update(float x, float y, float a, float b, color_t color);
private:
    VAO *object;
};

class Boomerang {
public:
    Boomerang() {}
    Boomerang(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(double,double);
    double speed;
private:
    VAO *object;
};

class Dragon {
public:
    Dragon() {}
    Dragon(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(double,double);
    double speed;
    void update(float x, float y, float a, float b, color_t color);
private:
    VAO *object;
};

#endif // ENEMY_H
