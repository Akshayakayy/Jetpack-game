#include "main.h"
#include "timer.h"
#include "ball.h"
#include "man.h"
#include "scene.h"
#include "objects.h"
#include "enemy.h"
#include "magnet.h"
#include "semic.h"
#include "water.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>

using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Ball ball1, ball2, ball3, ball4;
Man man;
Platform platform;
Coins coins[10];
Coinsb coinsb[3];
Wall wall;
Walldesign walldesign1, walldesign2;
Enemy enemy;
Enemy2 enemy2;
Boomerang boomerang;
Special special;
Magnet magnet;
Semic semic;
vector <Water> waters;
vector <Water> attacks;
vector <Jet> jets;
Dragon dragon;
Shield shield;

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;

Timer t60(1.0 / 60);
long int timevar = 0;

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    glm::vec3 eye ( 0,0,1);//5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    glm::vec3 target (0, 0, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up (0, 1, 0);

    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    wall.draw(VP);
    walldesign1.draw(VP);
    walldesign2.draw(VP);
    platform.draw(VP);

    magnet.draw(VP);

    for(int i = 0; i<10; ++i){
      coins[i].draw(VP);
    }

    for(int i = 0; i<3; ++i){
      coinsb[i].draw(VP);
    }

    enemy.draw(VP);

    ball1.draw(VP);
    ball2.draw(VP);

    enemy2.draw(VP);
    ball3.draw(VP);
    ball4.draw(VP);

    boomerang.draw(VP);
    semic.draw(VP);
    special.draw(VP);
    dragon.draw(VP);

    for(int i = 0; i<waters.size();i++){
      waters[i].draw(VP);
    }

    for(int i = 0; i<attacks.size();i++){
      attacks[i].draw(VP);
    }

    for(int i = 0; i<jets.size();i++){
      jets[i].draw(VP);
    }

    shield.draw(VP);
    man.draw(VP);

}
bool lineLine(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {

  // calculate the direction of the lines
  float uA = ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));
  float uB = ((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));

  // if uA and uB are between 0-1, lines are colliding
  if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {
    return true;
  }
  return false;
}
bool lineRect(float x1, float y1, float x2, float y2, float rx, float ry, float rw, float rh) {

  // check if the line has hit any of the rectangle's sides
  // uses the Line/Line function below
  bool left =   lineLine(x1,y1,x2,y2, rx,ry,rx, ry+rh);
  bool right =  lineLine(x1,y1,x2,y2, rx+rw,ry, rx+rw,ry+rh);
  bool top =    lineLine(x1,y1,x2,y2, rx,ry, rx+rw,ry);
  bool bottom = lineLine(x1,y1,x2,y2, rx,ry+rh, rx+rw,ry+rh);

  // if ANY of the above are true, the line
  // has hit the rectangle
  if (left || right || top || bottom) {
    return true;
  }
  return false;
}

double velocity = 0.0;
int semic_flag = 0;

//input function
void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int space = glfwGetKey(window, GLFW_KEY_SPACE);
    int wat = glfwGetKey(window, GLFW_KEY_W);

    if (semic_flag == 0){
    if (left && man.position.x > -3.8) {
        man.position.x -= 0.05;
    }
    else if (right && man.position.x < 2.57) {
        man.position.x += 0.05;
    }

    if (space && man.position.y < 2.55) {
      man.position.y += 0.04;
      velocity = 0.0;
      if (timevar%5==0) {
        Jet new_jet = Jet(man.position.x-0.04, man.position.y+1, COLOR_YELLOW);
        jets.push_back(new_jet);
      }

    }
    else if (man.position.y > -2.49) {
      man.position.y -= 0.04 + velocity;
      velocity += 0.0005;
    }

    if (wat && timevar%7==0) {
      Water new_water = Water(man.position.x+0.5, man.position.y+1, COLOR_LBLUE);
      waters.push_back(new_water);
    }
  }
}

//long int timervar = 0;
long long int score = 1;

int s = 1;

float boomy = 2.6;
float boomx;
int b = 1;

float spy;
float spx = 4.5;

int mag_flag = rand()%2;
int mag_orientation = 0; //1 means up, 0 means down

int dragvar = 0;
int dragf = 0;

int nokill = 0;
int faster = 1;
int fastervar = 0;
int shieldvar = 0;

char title[100];
long long int level=0;

void tick_elements() {
    //timervar += 1;
    if (fastervar != 0){
      fastervar --;
    }
    else{
      faster = 1;
      nokill = 0;
      shieldvar = 0;
    }

    if(shieldvar == 1){
      shield.position.x = man.position.x;
      shield.position.y = man.position.y;
    }
    else{
      shield.position.x = 100;
    }

    timevar += 1;
    walldesign1.tick(-0.02*faster,0);
    walldesign2.tick(-0.02*faster,0);

    ball1.tick(-0.02*faster,0);
    ball2.tick(-0.02*faster,0);
    enemy.tick(-0.02*faster,0);

    magnet.tick(-0.02*faster,0);

    enemy2.tick(-0.02*faster,s*0.02);
    ball3.tick(-0.02*faster,s*0.02);
    ball4.tick(-0.02*faster,s*0.02);

    semic.tick(-0.008*faster,0);
    if(semic.position.x < -5){
      semic.position.x = 20;
      //semic.position.y = -1 + rand()%2;
    }

    if(man.position.y > dragon.position.y){
      dragvar = 1;
    }
    else{
      dragvar = -1;
    }
    dragon.tick(0.0*faster,dragvar*0.015);

    if(timevar%1000 == 0 && dragf==0){
      dragon.position.x = 2;
      dragf = 1;
    }
    else if(timevar%1700 == 0 && dragf==1){
      dragon.position.x = 100;
      timevar = 0;
      dragf = 0;
    }
    if(dragf == 1){
      if (timevar%120==0) {
        Water new_attack = Water(dragon.position.x-0.5, dragon.position.y+0.9, COLOR_WHITE);
        attacks.push_back(new_attack);
        //printf("um\n");
      }
    }

    for(int i=0;i<attacks.size();i++){
      attacks[i].position.x -= 0.04;
      //attacks[i].position.y -= 0.1;
    }

    for(int i=0;i<attacks.size();i++){
      if(attacks[i].position.x < -4.5){
          attacks.erase(attacks.begin() + i);
      }
    }

    boomx = 4*(boomy-0.5)*(boomy-0.5)-3;
    boomerang.position.x = boomx;
    boomerang.position.y = boomy;
    boomerang.rotation -= b*0.2;

    boomy -= b*0.007;

    if(boomx < -3){
      b = -1;
    }
    else if(boomx > 4.5){
      b = 1;
    }

    if(boomy < -5){
      boomy = 10;
    }

    spy = 2-((spx-5)*(spx-5)/25);
    special.position.x = spx;
    special.position.y = spy;

    spx -= 0.03;

    if(special.position.x < -5){
      spx = 57;
    }
    else if(abs(special.position.x-man.position.x-0.55) < 0.3 && abs(special.position.y-man.position.y-0.65) < 0.35){
      spx = rand()%9+57;
      score += 100;
      nokill = 1;
      faster = 3.5;
      fastervar = 500;
      shieldvar = 1;
      //printf("%lld\n",score );
    }

    for(int i=0;i<waters.size();i++){
      waters[i].position.x += 0.1;
      waters[i].position.y = (-(waters[i].position.x-man.position.x)*(waters[i].position.x-man.position.x))/10 + man.position.y+1;

      if(lineRect(ball1.position.x, ball1.position.y, ball2.position.x, ball2.position.y, waters[i].position.x, waters[i].position.y, -0.3, -0.3)){
        ball1.position.x = rand()%3+8;
        ball1.position.y = rand()%3;
        ball2.position.x = rand()%2+6;
        ball2.position.y = rand()%3;
        enemy.update(ball1.position.x, ball1.position.y, ball2.position.x, ball2.position.y, COLOR_YELLOW);
      }
    }

    for(int i=0;i<waters.size();i++){
      if(waters[i].position.x > 4.5){
          waters.erase(waters.begin() + i);
      }
    }

    for(int i=0;i<jets.size();i++){
      jets[i].position.y -= 0.1;
      //waters[i].position.y =
    }

    for(int i=0;i<jets.size();i++){
      if(jets[i].position.y < -1.8){
          jets.erase(jets.begin() + i);
      }
    }


    for(int i = 0; i<10; ++i){
      coins[i].tick(-0.02*faster,0);
      if(coins[i].position.x < -5){
        coins[i].position.x = rand()%9+4;
        coins[i].position.y = rand()%5-1;
      }
      else if(abs(coins[i].position.x-man.position.x-0.55) < 0.3 && abs(coins[i].position.y-man.position.y-0.65) < 0.35){
        coins[i].position.x = rand()%9+7;
        coins[i].position.y = rand()%5-1;
        score += 50;
        //printf("%lld\n",score );
      }
    }

    for(int i = 0; i<3; ++i){
      coinsb[i].tick(-0.02*faster,0);
      if(coinsb[i].position.x < -5){
        coinsb[i].position.x = rand()%9+15;
        coinsb[i].position.y = rand()%5-1;
      }
      else if(abs(coinsb[i].position.x-man.position.x-0.55) < 0.3 && abs(coinsb[i].position.y-man.position.y-0.65) < 0.35){
        coinsb[i].position.x = rand()%9+10;
        coinsb[i].position.y = rand()%5-1;
        score += 150;
        //printf("%lld\n",score );
      }
    }

    if (ball1.position.x < -5){
      ball1.position.x = rand()%3+8;
      ball1.position.y = rand()%3;
      ball2.position.x = rand()%2+6;
      ball2.position.y = rand()%3;
      enemy.update(ball1.position.x, ball1.position.y, ball2.position.x, ball2.position.y, COLOR_YELLOW);
    }

    if (ball3.position.x < -5){
      ball3.position.x = rand()%3+25;
      ball3.position.y = rand()%3;
      ball4.position.x = rand()%2+23;
      ball4.position.y = ball3.position.y;
      enemy2.update(ball3.position.x, ball3.position.y, ball4.position.x, ball4.position.y, COLOR_RED);
    }

    if (ball3.position.y > 3.5 || ball4.position.y > 3.5){
      s = -1;
    }
    else if (ball3.position.y < -2 || ball4.position.y < -2){
      s = 1;
    }

    if (nokill == 0 && timevar%7==0){
    if(lineRect(ball1.position.x, ball1.position.y, ball2.position.x, ball2.position.y, man.position.x, man.position.y, -0.68, -0.68)){
      score -= 5;
      // printf("%lld\n",score );
    }
    if(lineRect(ball3.position.x, ball3.position.y, ball4.position.x, ball4.position.y, man.position.x, man.position.y, -0.68, -0.68)){
      score -= 10;
      // printf("%lld\n",score );
    }

    if(abs(boomerang.position.x-man.position.x-0.55) < 0.3 && abs(boomerang.position.y-man.position.y-0.65) < 0.35){
      boomerang.position.x = rand()%9+10;
      boomerang.position.y = rand()%5-1;
      score -= 25;
      // printf("%lld\n",score );
    }
    }

    if (nokill == 0){
      for(int i = 0; i<attacks.size(); ++i){
        if(abs(attacks[i].position.x-man.position.x-0.55) < 0.3 && abs(attacks[i].position.y-man.position.y-0.65) < 0.35){
          attacks[i].position.x = rand()%9+10;
          attacks[i].position.y = rand()%5-1;
          score -= 50;
          // printf("%lld\n",score );
        }
      }
    }

    if (man.position.x < semic.position.x-0.7 && man.position.x+0.67 > semic.position.x-0.7 && man.position.y+0.5 < semic.position.y && man.position.y+0.8 > semic.position.y){
      semic_flag = 1;
      nokill = 1;
    }

    if (semic_flag == 0){
    if (magnet.position.x < -6){
      magnet.position.x = rand()%15+25;
      mag_flag = rand()%2;

      if (mag_flag == 1){
        magnet.position.y = -3.2;
        if (mag_orientation = 1){
          magnet.rotation = 180;
        }
      }
      else {
        magnet.position.y = 3.5;
        if (mag_orientation = 0){
          magnet.rotation = 180;
        }
      }
    }

    if (magnet.position.x > -4.2 && magnet.position.x < 4){
      if (magnet.position.x < man.position.x){
        man.position.x += -0.03;
      }
      else{
        man.position.x += 0.03;
      }

      if (magnet.position.y < man.position.y){
        if(man.position.y > -1.7){
          man.position.y += -0.03;
        }
      }
      else if (magnet.position.y > man.position.y){
        man.position.y += 0.05 + velocity;
      }
    }
  }
  else {
    man.position.x += 0.007;
    man.position.y = ((man.position.x+0.5-semic.position.x)*(man.position.x+0.5-semic.position.x)-0.8);

    if (man.position.x < semic.position.x+0.7 && man.position.x+0.67 > semic.position.x+0.7 && man.position.y+0.2 < semic.position.y && man.position.y+0.5 > semic.position.y){
      semic_flag = 0;
      nokill = 0;
    }
  }

  if(score%999 == 0){
    level += 1;
  }
  sprintf(title, "LEVEL: %lld; SCORE: %lld", level, score);
  glfwSetWindowTitle(window, title);
    //camera_rotation_angle += 1;
}


/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    platform    = Platform(-4,-4,COLOR_BLACK);
    wall        = Wall(-4,-2.5,COLOR_WALL);
    walldesign1 = Walldesign(-2,-2.5,COLOR_WALLDESIGN);
    walldesign2 = Walldesign(2.5,-2.5,COLOR_WALLDESIGN);
    ball1       = Ball(5, 3, COLOR_GREY);
    ball2       = Ball(2, 1, COLOR_GREY);
    man         = Man(-2,-2.5,COLOR_BACKGROUND);
    enemy       = Enemy(5, 3, 2, 1, COLOR_YELLOW);
    enemy2      = Enemy2(10, 0, 7, 0, COLOR_RED);
    ball3       = Ball(10, 0, COLOR_DGREY);
    ball4       = Ball(7, 0, COLOR_DGREY);
    boomerang   = Boomerang(4.5, 2.6, COLOR_BOOM);
    special     = Special(1, 1, COLOR_GREEN);
    magnet      = Magnet(0, 3.5, COLOR_MAG);
    semic       = Semic(0, 0, 0.7, COLOR_BLACK);
    dragon      = Dragon(100, 0, COLOR_RED);
    shield      = Shield(100, 0, COLOR_WHITE);

    for(int i = 0; i<10; ++i){
      coins[i] = Coins(rand()%9-3,rand()%5-1,COLOR_ORANGE);
    }

    for(int i = 0; i<3; ++i){
      coinsb[i] = Coinsb(rand()%9-3,rand()%5-1,COLOR_PURPLE);
    }


    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 600;
    int height = 600;

    window = initGLFW(width, height);

    initGL (window, width, height);
    int collided=0;

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
        }
        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}
