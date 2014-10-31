
#pragma once
#include "Particle.h"
#include "cinder/Perlin.h"
#include "cinder/Rand.h"
#include <stdio.h>



class ParticleCon {
public:
    ParticleCon();
    void update( float soundValue );
    void draw();
    void addParticles( int amt );
    void removeParticles( int amt );
    
    std::list<Particle>	mParticles;
    
    cinder::Rand generator_;
};