#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/Vector.h"



#include "ParticleCon.h"
#include "cinder/Camera.h"

#include "Resources.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using std::list;


class iTunesApp : public AppNative {
public:
    void prepareSettings( Settings *settings );
    void setup();
    void mouseDown( MouseEvent event );
    void update();
    void draw();
    
    ParticleCon	mParticleCon;
    ParticleCon	mParticleCon01;
    
    // CAMERA
    CameraPersp			mCam;
    Vec3f				mEye, mCenter, mUp;
    float				mCameraDistance;



};

void iTunesApp::prepareSettings( Settings *settings){
    settings->setWindowSize( 1920, 540 );
    settings->setFrameRate( 60.0f );
}

void iTunesApp::setup()
{
    //setFullScreen( true );
    
    gl::enableAlphaBlending(true);
    gl::enableAdditiveBlending();
    
    gl::enableDepthRead();
    gl::enableDepthWrite();
    
    
    // SETUP CAMERA
    mCameraDistance = 350.0f;
    mEye			= Vec3f( 0.0f, 0.0f, mCameraDistance );
    mCenter			= Vec3f::zero();
    mUp				= Vec3f::yAxis();
    mCam.setPerspective( 75.0f, getWindowAspectRatio(), 5.0f, 5000.0f );
    

    mParticleCon.addParticles( 1500 );
    mParticleCon01.addParticles(1500);
    

    
}

void iTunesApp::mouseDown( MouseEvent event )
{
    if (event.getY()) {
        mParticleCon.update(10);
        mParticleCon01.update(10);
    }
}

void iTunesApp::update()
{
    //camera view
    mEye	= Vec3f( 0.0f, 0.0f, 1.0f ) * 350.0 ;
    mCam.lookAt( mEye, mCenter, mUp );

    gl::setMatrices( mCam );
    

    
}

void iTunesApp::draw()
{
    gl::clear( Color( 0.0, 0.0, 0.0 ) );
    
    //gl::disableDepthRead();
    //gl::disableDepthWrite();
    {
        //glEnable( GL_TEXTURE_2D );
  
        gl::pushMatrices();
        gl::translate( Vec2f( -getWindowBounds().getWidth()/4,0));

        mParticleCon.draw();
        gl::popMatrices();
    
        gl::pushMatrices();
        gl::translate( Vec2f(getWindowBounds().getWidth()/4,0));//240,0) );
        mParticleCon01.draw();
        gl::popMatrices();
    
        //glDisable( GL_TEXTURE_2D );
    }
    //gl::enableDepthRead();
    //gl::enableDepthWrite();

    
    
    //cout << getAverageFps() <<endl;

}

CINDER_APP_NATIVE( iTunesApp, RendererGl )
