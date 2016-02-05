#ifndef _UNMANAGED_
#define _UNMANAGED_

#pragma once
#pragma managed( push, off ) 

#include "globals.h"

using namespace std;

class cUnManged
{
	public:
		cUnManged( void )
		{
			sGuiCreated = NULL;
			isFiletoDownload = FALSE;
		}

		void EncryptStrings( void );

		void DestroyAllStrings( void );

		void DestroyInitStrings( void );

		DWORD pad0[0x40000]; //1 MegaByte

		char szLocation[1024]; DWORD unk6[ 0x101 ];

		DWORD pad123[0x400000]; DWORD unk45[ 0x101 ];

		char szLocation2[1024]; DWORD unk532[ 0x333 ];

		DWORD pad2[0x40000]; //1 MegaByte

		char szSongName[10000]; DWORD unk324[ 0x123 ];

		DWORD pad1[0x40000]; //1 MegaByte

		bool isFiletoDownload; DWORD unk5[ 0xBEEF ];

		DWORD pad32[0x40000]; //1 MegaByte

		char szTitle[64]; DWORD unk0[ 0xBAD ];

		DWORD pad3[0x40000]; //1 MegaByte

		char szGrpbx[24]; DWORD unk1[ 0xD34D ];

		DWORD pad4[0x40000]; //1 MegaByte

		char szChkbx[24]; DWORD unk2[ 0x1337 ];

		DWORD pad5[0x40000]; //1 MegaByte

		char szDev[24];	  DWORD unk3[ 0x333 ];

		DWORD pad6[0x40000]; //1 MegaByte

		char szStatus[32];DWORD unk4[ 0x666 ];

		DWORD pad7[0x40000]; //1 MegaByte

		int sGuiCreated;

		ofstream File_Recv;

	private:
		
		
		
};

extern cUnManged* unmanaged;

#pragma managed( pop )

#endif