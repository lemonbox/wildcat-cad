/*******************************************************************************
* Copyright (c) 2007, 2008, CerroKai Development
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*     * Neither the name of CerroKai Development nor the
*       names of its contributors may be used to endorse or promote products
*       derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY CerroKai Development ``AS IS'' AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL CerroKai Development BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
********************************************************************************/


//Included Header Files
#include <Kernel/keymap.h>


/***********************************************~***************************************************/


void WCKeyMap::AddMapping(const WCKeyEvent &event, const WCUserMessage &message) {
	//Insert into the map
	this->_keyMap.insert( std::make_pair(event._key, std::make_pair(event, message) ) );
}


WCUserMessage WCKeyMap::MessageFromKeyEvent(const WCKeyEvent &event) {
	WCKeyEvent tmpEvent(' ');
	
	//Iterate through map and test all matching char
	std::multimap<char, std::pair<WCKeyEvent,WCUserMessage> >::iterator mapIter;
	mapIter = this->_keyMap.find(event._key);
	//If mapIter exists
	if (mapIter != this->_keyMap.end()) {
		//Test to see if the same
		tmpEvent = (*mapIter).second.first;
		if (tmpEvent == event ) 
			//Return the message
			return (*mapIter).second.second;
	}
	//No such key found
	return ""; 
}


/***********************************************~***************************************************/

