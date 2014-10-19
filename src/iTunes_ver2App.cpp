#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class iTunes_ver2App : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void iTunes_ver2App::setup()
{
}

void iTunes_ver2App::mouseDown( MouseEvent event )
{
}

void iTunes_ver2App::update()
{
}

void iTunes_ver2App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( iTunes_ver2App, RendererGl )
