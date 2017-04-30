// This file implements the window functionality in an ugly way.
// don't use it as an example for your own code.

#include "window.hpp"
#include <iostream>

/* This is where all the input to a window goes to */
LRESULT CALLBACK WndProc(
   HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam
) {
	switch(Message) {
		
		/* trap the WM_CLOSE => tell the window to close */
		case WM_CLOSE: {
			DestroyWindow(hwnd);
			break;
		}
		
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

void winloop(){
   for(;;){ 
   MSG Msg; 
	   BOOL r = PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE );
      if( r == -1 ){
         // exit( 0 );
      } else if( r > 0) {
		   TranslateMessage(&Msg); /* Translate key codes to chars if present */
		   DispatchMessage(&Msg); /* Send it to WndProc */
	   }   
   }   
}

// derived by trial-and-error :(
#define X_MARGIN 20
#define Y_MARGIN 42

window::window( int x_size, int y_size, int scale ):
   x_size( x_size ), y_size( y_size), scale( scale )
{
   
   volatile HINSTANCE hInstance;
   WNDCLASSEX wc; /* A properties struct of our window */
   HWND hwnd; 

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		  = sizeof(WNDCLASSEX);
	wc.lpfnWndProc = WndProc; /* where we will send messages to */
	wc.hInstance	  = hInstance;
	wc.hCursor		  = LoadCursor(NULL, IDC_ARROW);
	
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); 
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&wc)) {
		MessageBox( 
          NULL, 
         "Window Registration Failed!",
         "Error!",
         MB_ICONEXCLAMATION|MB_OK 
      );
		for(;;);
	}

	hwnd = CreateWindowEx(
	    WS_EX_CLIENTEDGE,
		"WindowClass",
		"LCD Window",
		WS_VISIBLE | WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		scale * x_size + X_MARGIN, /* width */
		scale * y_size + Y_MARGIN, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox( 
          NULL, 
         "Window Creation Failed!",
         "Error!",
         MB_ICONEXCLAMATION|MB_OK 
      );
		for(;;);
	}
	
   hdc = GetDC(hwnd);
   
   atexit ( winloop );
}

void print_pixel( HDC hdc, int x, int y, int scale, int color ){
   //std::cout<< __LINE__ << " " << x << ":" << y << "\n";
   for( int dx = 0; dx < scale; dx++ ){
      for( int dy = 0; dy < scale; dy++ ){
         SetPixel( hdc, scale * x + dx, scale * y + dy, color );
      }
   }   
}

void window::clear(){
   return;
   for( int x = 0; x < 128; ++x )   {
      for( int y = 0; y < 64; ++y ){
         print_pixel( hdc, x, y, scale, RGB( 0xFF, 0xFF, 0xFF ) );
      }
   }
}

void window::draw( int x, int y ){
   print_pixel( hdc, x, y, scale, RGB( 0x00, 0x00, 0x00 ) );
}

