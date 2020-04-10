#include "main.h"

#ifndef OBJECT_H
#define OBJECT_H


class Coins {
public:
    Coins() {}
    Coins(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(double,double);
    double speed;
private:
    VAO *object;
};

class Coinsb {
public:
    Coinsb() {}
    Coinsb(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(double,double);
    double speed;
private:
    VAO *object;
};

class Special {
public:
    Special() {}
    Special(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(double,double);
    double speed;
private:
    VAO *object;
};

class Shield {
public:
    Shield() {}
    Shield(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(double,double);
    double speed;
private:
    VAO *object;
};


#endif // OBJECT_H
