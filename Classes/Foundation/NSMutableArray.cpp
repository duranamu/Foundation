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
#include <Foundation/NSMutableArray.h>
#include <Foundation/NSException.h>
#define super NSArray
NSMutableArray*
	NSMutableArray::arrayWithCapacity(NSUInteger capacity)
{
	NSMutableArray* mem =  new NSMutableArray(capacity);
	if(!mem )
	{
		CC_SAFE_DELETE(mem);
	}
	return mem;
}
NSMutableArray::NSMutableArray(NSUInteger num)
{
	ref = CCArray::arrayWithCapacity(num);
}

void
	NSMutableArray::exchangeObjectAtIndex_withObjectAtIndex(NSUInteger idx1 ,NSUInteger idx2)
{
	ref->exchangeObjectAtIndex(idx1,idx2);
}
void
	NSMutableArray::replaceObjectAtIndex_withObject(NSUInteger index , NSObject* anObject)
{
	if(anObject!= nil)
	{
	  throw NSException::exceptionWithName_reason_userInfo(
		NSSTR("Panic"),NSInvalidArgumentException,nil);
	  return ;
	}
	
	if( index >=  ref->count())
	{
		 throw NSException::exceptionWithName_reason_userInfo(
		NSSTR("Panic"),NSRangeException,nil);
		 return;
	}

	ref->addObject(anObject);
	ref->exchangeObject(anObject,ref->objectAtIndex(index));
	ref->removeLastObject();
	
}
BOOL
	NSMutableArray::removeObject(NSObject* obj)
{
		if(ref->containsObject(obj))
		{ 
			ref->removeObject(obj); 
			return YES;
		}else{ 
			return NO;
		}
}
void
	NSMutableArray::removeLastObject()
{
	self->ref->removeLastObject();
}
void
	NSMutableArray::dealloc()
{
	//if(self->m_bManaged == false)
	//{
	//	ref->removeAllObjects();
	//	ref->release();
	//	ref = nil;
	//}
}
NSMutableArray*
	NSMutableArray::initWithCapacity(NSUInteger capacity)
{
	return self;
}
NSMutableArray*
	NSMutableArray::alloc()
{
	NSArray* newInstance ;
	if(newInstance = super::alloc())
	{

	}
	return (NSMutableArray*)newInstance;
}
void
	NSMutableArray::insertObject_atIndex(NSObject* anObject ,NSUInteger index)
{
	ref->insertObject(anObject ,index);
}