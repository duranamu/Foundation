Foundation
==========

Foundation of Apple Cocoa Programming Enviroment port to C++ with Cocos2d-x

welcome discussion and contribution

E-mail:duranamu@126.com

Build Note:

	1,Add ./Classes  to your project compiler search directory

	2,if you want to take advantage of Grand Centeral Dispatch
	   ,find the libdispatch for your target platform and 
	   add libdispatch headers directory to your compiler search
	   directory ,and put the static or dynamic library to your 
	   compiler library path.

	   if you won't bother what is GCD , comment out 
	   <Foundation/NSOperation.h> and delete NSOperation.h 
	   and NSOperation.cpp, the Foundation library will just work
	   fine 

	3  AppDelegate.h  AppDelegate.cpp can be removed 

	4  HelloWorldScene.cpp HelloWorldScene.h are illustration for 
	   the library usage ,for more detail please goto Apple Online 
	   iOS Developer Document 
