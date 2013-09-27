#include <iostream>
#include <fstream>
#include <string>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <Glut/glut.h>
#include <OpenGL/glext.h>
	//#include <OpenAL/al.h>
	//#include <OpenAL/alc.h>
	//#include <vorbis/vorbisfile.h>
	//#include "sound.h"
#include "vector.h"
#include "display.h"
#include "texture.h"
#include <time.h>
#include <unistd.h>
#include "game.h"

using namespace std;

//variables
game interface;
display disp(-10,10,-10,10);

//	Texture names
GLuint boarderTexture;



void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	disp.setOrthographicProjection();
	glLoadIdentity();
	
	//Functions to draw objects
	interface.drawBoarder(boarderTexture);
	
	
	glutSwapBuffers();
	
}

void processNormalKeys(unsigned char key, int x, int y) {
	
}

void processSpecialKeys(int key, int x, int y) {
	
}

void initVar(){
	
}

void startUp(){
	// set up initial variables
	initVar();
	
	//GL setup
	glEnable(GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor (0.0f, 0.0f, 0.0f, 1.0f);
	glShadeModel(GL_FLAT);
	
	//		Textures
	load_texture("test.png", &boarderTexture);
	//load_texture("tankGraphicC.png", &tankTexture);
	
	
	/*		Sound
	openal.init();
	openALSetup();
	snd_load_file("missleSound.ogg", sound);
	*/
}

int main (int argc, char **argv) {
	
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	srand(time(0));
		
	
	/*
	glutInitWindowPosition(1,1);
	glutInitWindowSize(800,800);
	glutCreateWindow("Tanks");
	*/
	
	//set up resolution
	glutGameModeString("1280x1024");
	// enter full screen
	if (glutGameModeGet(GLUT_GAME_MODE_POSSIBLE))
		glutEnterGameMode();
	else {
		printf("The select mode is not available\n");
		exit(1);
	}
	
	
	startUp();
		
	// register callbacks
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	
	// enter GLUT event processing loop
	glutMainLoop();

	return 1;
}