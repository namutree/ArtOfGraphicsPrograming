
#include "Particle.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/app/AppNative.h"
#include "Resources.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using std::vector;


Particle::Particle(){}

Particle::Particle(float a1, float a2, float r){
    
    theta1 = a1;
    theta2 = a2;
    radius = r;
    radiusOriginal = r;
    
    radiusVel =0.0f;
    radiusAcc =0.0f;
    
    theta1Vel=0.0f;
    theta2Vel=0.0f;

    myImage = gl::Texture( loadImage( loadResource( "whitecircle.png")));
    
    colorRand = Rand::randFloat(5);
    
    randValue =Rand::randFloat(1.0f);
    

   
    
}

void Particle::update(){
    
    
    test1 = test2;
    test2 = sin(cinder::app::getElapsedSeconds()/2);
    
    test3 = test4;
    test4 = cos(cinder::app::getElapsedSeconds()/3);
    
    theta1Vel += test2 - test1;
    theta2Vel += test4 - test3;
    
    radius += radiusVel;
    radiusVel += radiusAcc;
    
    theta1 += theta1Vel;
    theta2 += theta2Vel;
    
    if (radius > radiusOriginal) {
        radiusAcc = - abs(radius - radiusOriginal) * 0.3;
    } else if (radius < radiusOriginal) {
        radiusAcc = abs(radius - radiusOriginal) * 0.3;
    }
    
    if (abs(radius - radiusOriginal) <1 && abs(radiusVel) <1) {
        radiusVel = 0;
        radiusAcc = 0;
        radius = radiusOriginal;
    }
    
    radiusVel *= 0.72;
    theta1Vel *= 0.4;
    theta2Vel *= 0.4;
    

    while (theta1>M_PI*2.0f) {
        theta1 -= M_PI*2.0f;
    }
    while (theta2>M_PI*2.0f) {
        theta2 -= M_PI*2.0f;
    }
    
    pLoc = ci::Vec3f( cosf(theta1)*cosf(theta2), sinf(theta1), cosf(theta1)*sinf(theta2))*radius;

}

void Particle::drawline(ci::Vec3f preloc){
    glColor4f(0.5, 0.5, 0.5, 0.15);
    gl::drawLine(pLoc, preloc);
}

void Particle::move( float forceVel){
    radiusVel += forceVel;
}

void Particle::draw()
{
    if (colorRand <1)       glColor4f(77.0f/255.0f,   255.0f/255.0f, 17.0f/255.0f,0.5f);
    else if (colorRand <2)  glColor4f(146.0f/255.0f,  232.0f/255.0f, 15.0f/255.0f,0.5f);
    else if (colorRand <3)  glColor4f(244.0f/255.0f,  255.0f/255.0f, 29.0f/255.0f, 0.5f);
    else if (colorRand <4)  glColor4f(232.0f/255.0f,  213.0f/255.0f, 15.0f/255.0f,0.5f);
    else                    glColor4f(255.0f/255.0f,  210.0f/255.0f, 17.0f/255.0f,0.5f);
    
    gl::pushMatrices();
    gl::translate(pLoc);

    // png image
    glEnable( GL_TEXTURE_2D );
    gl::draw(myImage,ci::Vec2f::zero());
    glDisable( GL_TEXTURE_2D );
    
    //gl::drawSphere(ci::Vec3f::zero(), 5.0f);
    
    // enable this to see the cube
//    if (randValue<0.3f)         gl::drawStrokedCube(ci::Vec3f::zero(), ci::Vec3f(3,3,3));
//    else if (randValue<0.6f)    gl::drawCube(ci::Vec3f::zero(), ci::Vec3f(4,4,4));
//    else                        gl::drawStrokedCube(ci::Vec3f::zero(), ci::Vec3f(2,2,2));
    gl::popMatrices();
    
    
   
}