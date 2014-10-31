#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "cinder/Vector.h"
#include "ParticleCon.h"

using namespace ci;
using std::list;


ParticleCon::ParticleCon(){};

void ParticleCon::update( float value ){

    for( list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
        float num = (generator_.nextGaussian()+2.0f);
        p->move( value*num );

    }

}

void ParticleCon::draw(){
    
    // DRAW PARTICLE
    for( list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); p++ ){
        p->update();
        p->draw();
        p->drawline(ci::Vec3f::zero());
    }
}

void ParticleCon::addParticles( int amt ){
    
    for(int i=0; i<amt ; i++){
        float a1 = Rand::randFloat( 2.0f * M_PI );
        float a2 = Rand::randFloat( 2.0f * M_PI );
        float r = 100.0f;
        
        mParticles.push_back( Particle(a1, a2, r) );
    }

}


void ParticleCon::removeParticles( int amt ){
    
}