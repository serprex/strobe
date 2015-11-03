#include <GL/glx.h>
#include <stdlib.h>
int main(int argc,char**argv){
	Display*dpy=XOpenDisplay(0);
	XVisualInfo*vi=glXChooseVisual(dpy,DefaultScreen(dpy),(int[]){GLX_RGBA,None});
	Window Wdo=XCreateWindow(dpy,RootWindow(dpy,vi->screen),0,0,1680,1050,0,vi->depth,InputOutput,vi->visual,CWColormap|CWEventMask,(XSetWindowAttributes[]){{.colormap=XCreateColormap(dpy,RootWindow(dpy,vi->screen),vi->visual,AllocNone)}});
	XMapWindow(dpy,Wdo);
	glXMakeCurrent(dpy,Wdo,glXCreateContext(dpy,vi,0,GL_TRUE));
	static const unsigned char col[][3]={{255,255,255},{0,0,0}};
	for(;;){
		glColor3ubv(col[rand()&1]);
		glRecti(-1,-1,1,1);
		glFinish();
	}
}