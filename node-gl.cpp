/*
 * node-gl.cpp
 *
 */

#include "node-gl.h"

void init(Handle<Object> target) {

	  Persistent<Context> currentContext = Persistent<Context>::New(Context::GetCurrent());
#ifdef BUILD_GLUT_BINDINGS
	  GlutFactory::glut_persistent_context = currentContext;
#endif
#ifdef BUILD_GLES_BINDINGS
	  GlesFactory::gles_persistent_context = currentContext;
#endif

	  //Append *this* as Gl static variable so we can do dot-this-dot-that stuff
#ifdef BUILD_GL_BINDINGS
	  GlFactory::self_ = Persistent<Object>::New(GlFactory::createGl()->NewInstance());
#endif
#ifdef BUILD_GLES_BINDINGS
	  GlesFactory::self_ = Persistent<Object>::New(GlesFactory::createGles()->NewInstance());
#endif

	  //Set global objects and functions.
#ifdef BUILD_GL_BINDINGS
	  target->Set(String::New("Gl"), GlFactory::self_);
#endif
#ifdef BUILD_GLES_BINDINGS
	  target->Set(String::New("Gles"), GlesFactory::self_);
#endif
#ifdef BUILD_GLU_BINDINGS
	  target->Set(String::New("Glu"), Persistent<Object>::New(createGlu()->NewInstance()));
#endif
#ifdef BUILD_GLUT_BINDINGS
	  target->Set(String::New("Glut"), Persistent<Object>::New(GlutFactory::createGlut()->NewInstance()));
#endif

}

NODE_MODULE(nodegl, init);

