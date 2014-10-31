//
//  Particle.h
//  iTunes
//
//  Created by John Namu Choi on 10/13/14.
//
//

#pragma once
#include "cinder/Vector.h"
#include "cinder/Color.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include <vector>

#include <iostream>

class Particle {
public:
    Particle();
    Particle(float a1, float a2, float r);
    
    void update();
    void move( float forceVel );
    void draw();
    void drawline(ci::Vec3f preloc);
    
    ci::Vec3f pLoc;
    
    float theta1, theta2, theta1Vel, theta2Vel;
    
    float radius, radiusOriginal, radiusVel, radiusAcc;
    
    
    float test1, test2 , test3, test4;
    
    float colorRand;
    float randValue;
    
    cinder::gl::Texture myImage;
    
};