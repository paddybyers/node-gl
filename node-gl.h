/*
 * v8-gl.h
 */

#ifndef NODEGL_H_
#define NODEGL_H_

#include <string>
#include <v8-debug.h>

#include "utils.h"
#ifdef BUILD_GL_BINDINGS
#include "glbindings/glbind.h"
#endif
#ifdef BUILD_GLES_BINDINGS
#include "glesbindings/glesbind.h"
#endif
#ifdef BUILD_GLU_BINDINGS
#include "glubindings/glubind.h"
#endif
#ifdef BUILD_GLUT_BINDINGS
#include "glutbindings/glutbind.h"
#endif

#include <node.h>

v8::Handle<v8::Value> Load(const v8::Arguments& args);
v8::Handle<v8::Value> Unload(const v8::Arguments& args);

extern "C" NODE_EXTERN void init(v8::Handle<v8::Object> target);

#endif /* NODEGL_H_ */
