#ifndef _ENCRYPT_H_
#define _ENCRYPT_H_

#pragma once
#pragma managed( push, off )

template <int XORSTART, int BUFLEN, int XREFKILLER>
class XorStr
{
private: 
	XorStr();
public: 
	char s[ BUFLEN ];

	XorStr( const char * xs );

	~XorStr()
	{
		for ( int i = 0; i < BUFLEN; i++ ) s[ i ]=0; 
	}
};

template <int XORSTART, int BUFLEN, int XREFKILLER>
XorStr<XORSTART,BUFLEN,XREFKILLER>::XorStr( const char * xs )
{
	int xvalue = XORSTART;
	int i = 0;

	for ( ; i < ( BUFLEN - 1 ); i++ ) 
	{
		s[ i ] = xs[ i - XREFKILLER ] ^ xvalue;
		xvalue += 1;
		xvalue %= 256;
	}

	s[ BUFLEN - 1 ] = 0;
}

//Unmanaged Strings
#define STRING_WSARECV          /*WSARecv*/XorStr<0x3E,8,0x08857762>("\x69\x6C\x01\x13\x27\x20\x32"+0x08857762).s
#define STRING_SEND			    /*send*/						XorStr<0xA9,5,0x7E83516F>("\xDA\xCF\xC5\xC8"+0x7E83516F).s
#define STRING_WSOCK2		    /*Ws2_32.dll*/					XorStr<0xF6,11,0x6D604134>("\xA1\x84\xCA\xA6\xC9\xC9\xD2\x99\x92\x93"+0x6D604134).s
#define STRING_MSWSOCK		    /*mswsock.dll*/					XorStr<0x99,12,0x961EBD9C>("\xF4\xE9\xEC\xEF\xF2\xFD\xF4\x8E\xC5\xCE\xCF"+0x961EBD9C).s
#define STRING_HTTP			    /*http://*/						XorStr<0x80,8,0x4E6E57D9>("\xE8\xF5\xF6\xF3\xBE\xAA\xA9"+0x4E6E57D9).s
#define STRING_SSSS			    /*%s%s%s*/						XorStr<0x8E,7,0x7DD0A364>("\xAB\xFC\xB5\xE2\xB7\xE0"+0x7DD0A364).s
#define STRING_FAILEDTOGET	    /*Failed to get URL Length*/	XorStr<0xF0,25,0x46EF1A44>("\xB6\x90\x9B\x9F\x91\x91\xD6\x83\x97\xD9\x9D\x9E\x88\xDD\xAB\xAD\x4C\x21\x4E\x66\x6A\x62\x72\x6F"+0x46EF1A44).s
#define STRING_FAILEDTOGETHOST  /*Failed to get host*/			XorStr<0x9D,19,0xAC26389E>("\xDB\xFF\xF6\xCC\xC4\xC6\x83\xD0\xCA\x86\xC0\xCD\xDD\x8A\xC3\xC3\xDE\xDA"+0xAC26389E).s
#define STRING_GELLIN_RAPES_YOU /*This is not intended to be Released.*/XorStr<0x33,37,0x5670F225>("\x67\x5C\x5C\x45\x17\x51\x4A\x1A\x55\x53\x49\x1E\x56\x2E\x35\x27\x2D\x20\x20\x22\x67\x3C\x26\x6A\x29\x29\x6D\x1C\x2A\x3C\x34\x33\x20\x31\x31\x78"+0x5670F225).s
#define STRING_I_SEE_YOU		/*I See You*/					XorStr<0x81,10,0x7F1EA213>("\xC8\xA2\xD0\xE1\xE0\xA6\xDE\xE7\xFC"+0x7F1EA213).s



//UI Strings
#define STRING_UI_DEVELOPER		/*Developed By: Gellin*/XorStr<0xA4,21,0x38EB06FA>("\xE0\xC0\xD0\xC2\xC4\xC6\xDA\xCE\xC8\x8D\xEC\xD6\x8A\x91\xF5\xD6\xD8\xD9\xDF\xD9"+0x38EB06FA).s
#define STRING_UI_STATUS	    /*Waiting for Song*/XorStr<0x45,17,0xD3636E83>("\x12\x27\x2E\x3C\x20\x24\x2C\x6C\x2B\x21\x3D\x70\x02\x3D\x3D\x33"+0xD3636E83).s
#define STRING_UI_SAVEMUSIC		/*Save Music*/XorStr<0xCB,11,0x5F8A9402>("\x98\xAD\xBB\xAB\xEF\x9D\xA4\xA1\xBA\xB7"+0x5F8A9402).s
#define STRING_UI_TITLE			/*P4nD0r4 |3e10nG 2 us kee kee kee*/XorStr<0x9D,33,0x9A6F26F5>("\xCD\xAA\xF1\xE4\x91\xD0\x97\x84\xA5\x95\xC2\x99\x99\xC4\xEC\x8C\x9F\x8E\xDA\xC3\x91\xD9\xD6\xD1\x95\xDD\xD2\xDD\x99\xD1\xDE\xD9"+0x9A6F26F5).s
#define STRING_UI_GRPBX			/*Pandora Ripper*/XorStr<0xD4,15,0xE7B9AB8B>("\x84\xB4\xB8\xB3\xB7\xAB\xBB\xFB\x8E\xB4\xAE\xAF\x85\x93"+0xE7B9AB8B).s



#pragma managed( pop )
#endif