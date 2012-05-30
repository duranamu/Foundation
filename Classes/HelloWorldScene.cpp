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
#include "HelloWorldScene.h"
//import the library
#include <Foundation/Foundation.h>

using namespace cocos2d;

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::node();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HelloWorld *layer = HelloWorld::node();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    bool bRet = false;
    do 
    {

        CCLabelTTF* pLabel = CCLabelTTF::labelWithString("Hello World", "Thonburi", 64);
        CC_BREAK_IF(! pLabel);

        // Get window size and place the label upper. 
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        pLabel->setPosition(ccp(size.width / 2, size.height - 20));

        // Add the label to HelloWorld layer as a child layer.
        this->addChild(pLabel, 1);


        bRet = true;
    } while (0);


	NSSTR("Foundation"); // return an autorelease instance of NSString just like  @"Foundation"

	/*any convenient class constructor return an autorelese object managed by CCAutoreleasePool
	  alloc init copy return objects with retainCount 1,you need to release those objects manually
	*/

	NSInteger downloadTimes = 1000000;

	NSString* formatedString =
		NSString::stringWithFormat(NSSTR("Cocos %@ is opensource now , %d downloads will be Cocos acheived ")
		,NSSTR("Foundation"),downloadTimes);

	NSMutableString* mutableString = 
		NSMutableString::stringWithCapacity(30);
	mutableString->setString(formatedString);

	NSRange range;
	range.location = 0;
	range.length = formatedString->length();
	mutableString->replaceOccurrencesOfString_withString_options_range(
		NSSTR("Cocos"),NSSTR("Cocoa"),NSOrderedSame,range);

	mutableString->appendFormat(NSSTR("%@ %@ %@ are our develop team principle"),
		NSSTR("conforming to apple document"), NSSTR("and improving execution efficiency "),
		NSSTR("welcoming opensource community feedback"));

	NSLog(NSSTR("\" %@ \" is modified "), mutableString);

	/* for existing cocos2d-x code compliant
	   all the collection class are convinient wrapper of identical Cocos2d-x class
	   NSArray->ref =  CCArray
	   NSDictionary->ref = CCDictionary
	   NSSet->ref       = CCSet
	   so is  NSString
	   NSString->ref = CCString
	*/
	CCString* ccstring = mutableString->ref;
	
	/*
	 fast enumeration
	 any class conform to NSFastEnumeration Protocol obtains
	 fast enumeration 
	 NSArray NSMutableArray 
	 NSDictionary NSMutableDictionary
	 NSSet
	 NSDirectoryEnumerator
	*/

	NSDictionary* dict = NSDictionary::dictionaryWithObjectAndKeys(
		NSNumber::numberWithInteger(100),NSSTR("NumberWrapperForInteger"),
		NSNumber::numberWithDouble(12.34f),NSSTR("NumberWrapperForDouble"),
		NSNumber::numberWithBool(YES),NSSTR("NumberWrapperForBOOL"),
		nil);
	NSMutableArray* mutableArray = NSMutableArray::arrayWithCapacity(2);
	nfor(NSString* ,keyString , dict)
		mutableArray->addObject(keyString);
	nend

	nfor(NSString* ,keyString , dict)
		NSLog(keyString);
    nend

	// return value of CCFileUtils::fullPathFromRelativePath("")
   NSString* currentDirectoryPath =  NSFileManager::defaultManager()->currentDirectoryPath();
	
	NSDirectoryEnumerator* enumerator = NSFileManager::defaultManager()->enumeratorAtPath(
		currentDirectoryPath);

	nfor(NSString* , directoryEntry , enumerator)
		NSDictionary* attributes =  enumerator->fileAttributes();
		NSString* entryName =  (NSString*)attributes->objectForKey(NSFileEntry);
		if(attributes->objectForKey(NSFileType)->isEqual(NSFileTypeDirectory))
		{
			NSLog(NSSTR("%@ is a directory"),entryName);
		}else if (attributes->objectForKey(NSFileType)->isEqual(NSFileTypeRegular))
		{
			NSLog(NSSTR("%@ is a regular file"),entryName);
		}
	nend


	//JSON serializtion never easier 

	
    return bRet;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}

