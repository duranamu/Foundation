/****************************************************************************
	             Foundation  OpenSource  Project
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#pragma once
#include <Foundation/Cocos2DX_framework.h>
#include <Foundation/NSObject.h>
#include <Foundation/NSString.h>
#include <Foundation/NSMutableDictionary.h>
FOUNDATION_EXPORT NSString * const NSGenericException;
FOUNDATION_EXPORT NSString * const NSInvalidArgumentException;
FOUNDATION_EXPORT NSString * const NSRangeException;

FOUNDATION_EXPORT NSString * const NSInternalInconsistencyException;
FOUNDATION_EXPORT NSString * const NSMallocException;

FOUNDATION_EXPORT NSString * const NSParseErrorException;
FOUNDATION_EXPORT NSString * const NSInconsistentArchiveException;

NS_INTERFACE(NSException,NSObject)
	NSException* 
		initWithName_reason_userInfo(NSString*,NSString*,NSMutableDictionary*);
	static NSException* 
		exceptionWithName_reason_userInfo(NSString*,NSString*,NSMutableDictionary*);
	NSString* name();
	NSString* reason();
	NSMutableDictionary* userInfo();
	protected:
		NSString* _name;
		NSString* _reason;
		NSMutableDictionary* _useeInfo;
NS_END