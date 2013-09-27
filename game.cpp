#include "game.h"


void game::drawBoarder(GLuint texture) {
	
	glLoadIdentity();

	glEnable(GL_TEXTURE_2D);
	glBindTexture (GL_TEXTURE_2D, texture);
	
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(-10, -10);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(-10, 10);
		glTexCoord2f(1.0f, 1.0f); glVertex2f(10, 10);
		glTexCoord2f(1.0f, 0.0f); glVertex2f(10, -10);
	glEnd();
	
	glDisable(GL_TEXTURE_2D);
	
}