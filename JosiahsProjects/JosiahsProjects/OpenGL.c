//
//  openGL.c
//  JosiahsProjects
//
//  Created by Justin Oliver on 8/24/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include "OpenGL.h"
#include <stdio.h>

// The OpenGL libraries, make sure to include the GLUT and OpenGL frameworks
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

// This is just an example using basic glut functionality.
// If you want specific Apple functionality, look up AGL

void init() // Called before main loop to set up the program
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
}

// Displays the score
void drawStrokeText(char* string, float scale)
{
    char *c;
    
    glScalef(scale,scale,scale);
    for (c=string; *c != '\0'; c++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
    }
}

// Called at the start of the program, after a glutPostRedisplay() and during idle
// to display a frame
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    /*
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0, 0.0, -10.0);
    glVertex3f(1.0, 0.0, -10.0);
    glVertex3f(0.0, 1.0, -10.0);
    glEnd();
    */
    
    // Display the score
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 500.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //gluLookAt(2, 1, 2, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glScalef(.005,.005,.005);
    //glRotatef(20, 0, 1, 0);
    //glRotatef(30, 0, 0, 1);
    //glRotatef(5, 1, 0, 0);
    //glTranslatef(-300, 0, 0);
    
    glColor3f(1,1,1);
    drawStrokeText("12345", 1.0);
    
    glutSwapBuffers();
}

// Called every time a window is resized to resize the projection matrix
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.1, 0.1, -(float)(h)/(10.0* (float)(w)), (float)(h)/(10.0*(float)(w)), 0.5, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// KEYBAORD PRESSED TUTORIAL
void keyPressed (unsigned char key, int x, int y)
{
    if(key == 'a')
    { // If they ‘a’ key was pressed
        // Perform action associated with the ‘a’ key
        printf("The 'a' key was pressed!\n");
    }
}

int openGLInit(int argc, char **argv)
{
    glutInit(&argc, argv); // Initializes glut
    
    // Sets up a double buffer with RGBA components and a depth component
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    
    // Sets the window size to 512*512 square pixels
    glutInitWindowSize(512, 512);
    
    // Sets the window position to the upper left
    glutInitWindowPosition(0, 0);
    
    // Creates a window using internal glut functionality
    glutCreateWindow("Hello!");
    
    // passes reshape and display functions to the OpenGL machine for callback
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    
    // Tell GLUT to use the method "keyPressed" for key presses
    glutKeyboardFunc(keyPressed);
    
    init();
    
    // Starts the program.
    glutMainLoop();
    return 0;
}