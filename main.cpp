/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Brayan Espinosa
 *
 * Created on 23 de marzo de 2017, 10:33 AM
 */

#include <cstdlib>
#include <iostream>
#include <glew.h>
#include <glfw3.h>
#include <glfw3native.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string.h>
#include <string>
#include <cstring>
#include <fstream>
#include <GL/glext.h>

using namespace std;

std::string loadFieldToString(const char* filePath){
    std::string fileData = "";
    std::ifstream stream(filePath,std::ios::in);
    
    if (stream.is_open()) {
        std::string line = "";
        
        while (getline(stream, line)) {
            fileData += "\n" + line;
        }
        
        stream.close();
    }
    return fileData;
} 

GLuint loadShaders(const char* vertShaderPath, const char* fragShaderPath){
    GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);

    std::string vertShaderSource = loadFieldToString(vertShaderPath);
    std::string fragShaderSource = loadFieldToString(fragShaderPath);
    
    const char* rawVertShaderSource = vertShaderSource.c_str();
    const char* rawFragShaderSource = fragShaderSource.c_str();
    
    glShaderSource(vertShader,1,&rawVertShaderSource,NULL);
    glShaderSource(fragShader,1,&rawFragShaderSource,NULL);
    
    glCompileShader(vertShader);
    glCompileShader(fragShader);
    
    GLuint program = glCreateProgram();
    glAttachShader(program, vertShader);
    glAttachShader(program, fragShader);
    glLinkProgram(program);

    return program;
}

void keyCallBack(GLFWwindow*window,int key,int scanCode, int action,int mods);

GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;

void drawCube(GLfloat centerPosX,GLfloat centerPosY, GLfloat centerPosZ,GLfloat edgeLength){
    GLfloat halfSideLenght = edgeLength * 0.5;
    GLfloat vertices[]= {
        //front face
        centerPosX -halfSideLenght, centerPosY + halfSideLenght, centerPosZ + halfSideLenght,
        centerPosX +halfSideLenght, centerPosY + halfSideLenght, centerPosZ + halfSideLenght,
        centerPosX +halfSideLenght, centerPosY - halfSideLenght, centerPosZ + halfSideLenght,
        centerPosX -halfSideLenght, centerPosY - halfSideLenght, centerPosZ + halfSideLenght,
        
        //back Face
        centerPosX -halfSideLenght, centerPosY + halfSideLenght, centerPosZ - halfSideLenght,
        centerPosX +halfSideLenght, centerPosY + halfSideLenght, centerPosZ - halfSideLenght,
        centerPosX +halfSideLenght, centerPosY - halfSideLenght, centerPosZ - halfSideLenght,
        centerPosX -halfSideLenght, centerPosY - halfSideLenght, centerPosZ - halfSideLenght,
        // left face
        centerPosX -halfSideLenght, centerPosY + halfSideLenght, centerPosZ + halfSideLenght,
        centerPosX -halfSideLenght, centerPosY + halfSideLenght, centerPosZ - halfSideLenght,
        centerPosX -halfSideLenght, centerPosY - halfSideLenght, centerPosZ - halfSideLenght,
        centerPosX -halfSideLenght, centerPosY - halfSideLenght, centerPosZ + halfSideLenght,
        // right  face
        centerPosX +halfSideLenght, centerPosY + halfSideLenght, centerPosZ + halfSideLenght,
        centerPosX +halfSideLenght, centerPosY + halfSideLenght, centerPosZ - halfSideLenght,
        centerPosX +halfSideLenght, centerPosY - halfSideLenght, centerPosZ - halfSideLenght,
        centerPosX +halfSideLenght, centerPosY - halfSideLenght, centerPosZ + halfSideLenght,
        //top face
        centerPosX -halfSideLenght, centerPosY + halfSideLenght, centerPosZ + halfSideLenght,
        centerPosX -halfSideLenght, centerPosY + halfSideLenght, centerPosZ - halfSideLenght,
        centerPosX +halfSideLenght, centerPosY + halfSideLenght, centerPosZ - halfSideLenght,
        centerPosX +halfSideLenght, centerPosY + halfSideLenght, centerPosZ + halfSideLenght,
        //bottom face
        centerPosX -halfSideLenght, centerPosY - halfSideLenght, centerPosZ + halfSideLenght,
        centerPosX -halfSideLenght, centerPosY - halfSideLenght, centerPosZ - halfSideLenght,
        centerPosX +halfSideLenght, centerPosY - halfSideLenght, centerPosZ - halfSideLenght,
        centerPosX +halfSideLenght, centerPosY - halfSideLenght, centerPosZ + halfSideLenght
    };
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
//    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glEnableClientState(GL_VERTEX_ARRAY);
     glVertexPointer(3,GL_FLOAT,0,vertices);
     glDrawArrays(GL_QUADS,0,24);
    glDisableClientState(GL_VERTEX_ARRAY);
   
}

/*
 * 
 */

int main(int argc, char** argv) {
    std::cout << "hola mundo" << std::endl;
    cout<< "hola mundo";
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 700;
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello", NULL, NULL);
    glfwSetKeyCallback(window,keyCallBack);
    glfwSetInputMode(window,GLFW_STICKY_KEYS,1);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    glewExperimental = true;
    
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Glew faild to initialise");
        glfwTerminate();
        return -1;
    }

//    GLuint vaoID;
//    glGenVertexArrays(1,&vaoID);
//    glBindVertexArray(vaoID);
    
//    static const GLfloat ver[] = {
//        -1.0f,-1.0f,0.0f,
//        1.0f,-1.0f,0.0f,
//        0.0f,1.0f,0.0f
//    };
    
//    GLuint program = loadShaders("shader.vertshader", "shader.fragshader");
    
//    GLuint vboID;
//    glGenBuffers(1,&vboID);
//    glBindBuffer(GL_ARRAY_BUFFER, vboID);
//    glBufferData(GL_ARRAY_BUFFER,sizeof(ver),ver,GL_STATIC_DRAW);
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    /* Loop until the user closes the window */
    glViewport(0.0f,0.0f,SCREEN_WIDTH,SCREEN_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, SCREEN_WIDTH,0,SCREEN_HEIGHT,0,1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    GLfloat halfScreenWidth = SCREEN_WIDTH/2;
    GLfloat halfScreenHeight = SCREEN_HEIGHT/2;
    
    while (!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glEnableVertexAttribArray(0);
//        glBindBuffer(GL_ARRAY_BUFFER,vboID);
//        glVertexAttribPointer(0, 3 ,GL_FLOAT,GL_FALSE, 0 ,(void*)0);
        
        glPushMatrix();
        glTranslatef(halfScreenWidth,halfScreenHeight,-500);
        glRotatef(rotationX,1,0,0);
        glRotatef(rotationY,0,1,0);
        glTranslatef(-halfScreenWidth,-halfScreenHeight,500);
        
//        glUseProgram(program);
//        glRotatef(0.01f, 1.0f , 0.0f , 0.0f);
//        glRotatef(0.01f, 0.0f , 1.0f , 0.0f);
//        glRotatef(0.01f, 0.0f , 0.0f , 1.0f);

        glColor3f(1.0f, 0.0f, 0.0f);
        
        drawCube(halfScreenWidth, halfScreenHeight,-500, 200);
        
        glPopMatrix();
        
//        glDrawArrays(GL_TRIANGLES,0,3);
//        glBegin(GL_TRIANGLES);
//             
//        
//                glColor3f(1.0f, 0.0f, 0.0f);
//                glVertex3f(1.0f, 1.0f, 0.0f);
//
//                glColor3f(0.0f, 1.0f, 0.0f);
//                glVertex3f(1.0f, 1.0f, 5.0f);
//
//                // Left & Blue
//                glColor3f(0.0f, 0.0f, 1.0f);
//                glVertex3f(1.0f, 1.0f,-20.0f);
//        
//        
//            glColor3f(1.0f,0.0,0.0);
//            glVertex3f( -1000.0f, 0.0f, 0.0f);
//            glVertex3f( 1000.0f, 0.0f, 0.0f);
//            
//            glColor3f(0.0f,1.0f,0.0);
//            glVertex3f( 0.0f, -1000.0f, 0.0f);
//            glVertex3f( 0.0f, 1000.0f, 0.0f);
//            
//            glColor3f(0.0f,0.0,1.0f);
//            glVertex3f( 0.0f, 0.0f, -1000.0f);
//            glVertex3f( 0.0f, 0.0f, 1000.0f);
//            
//        glEnd();
//        glFlush();
//        
       
        /* Render here */
//        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void keyCallBack(GLFWwindow*window,int key,int scanCode, int action,int mods){
//    std::cout << key << std::endl;
    const GLfloat speedRotation = 10;
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch(key){
            case GLFW_KEY_UP:
                rotationX -= speedRotation;
                break;
            case GLFW_KEY_DOWN:
                rotationX += speedRotation;
                break;
            case GLFW_KEY_LEFT:
                rotationY -= speedRotation;
                break;
            case GLFW_KEY_RIGHT:
                rotationY += speedRotation;
                break;
        }
    }

}