#include "Unmanaged.h"

extern void CreateApplicationForm( void );

class cUnManged* unmanaged = NULL;

void cUnManged::EncryptStrings( void )
{
	::strcpy( szTitle,  STRING_UI_TITLE );
	::strcpy( szStatus, STRING_UI_STATUS );
	::strcpy( szGrpbx,  STRING_UI_GRPBX );
	::strcpy( szDev,    STRING_UI_DEVELOPER );
	::strcpy( szChkbx,  STRING_UI_SAVEMUSIC );
}

void cUnManged::DestroyAllStrings( void )
{
	::strcpy( szTitle,  "" );
	::strcpy( szStatus, "" );
	::strcpy( szGrpbx,  "" );
	::strcpy( szDev,    "" );
	::strcpy( szChkbx,  "" );
}

void cUnManged::DestroyInitStrings( void )
{
	::strcpy( szTitle,  "" );
	::strcpy( szStatus, "" );
	::strcpy( szGrpbx,  "" );
	::strcpy( szDev,    "" );
	::strcpy( szChkbx,  "" );
}

int GetUrlBufferLen( char* szBuffer, int iBufferLen )
{
	for( int i = 0; i < iBufferLen; i++ )
		 if( szBuffer[i]   == 'H'
		  && szBuffer[i+1] == 'T'
		  && szBuffer[i+2] == 'T'
		  && szBuffer[i+3] == 'P' )
			 return i - 1;
	
	return NULL;
}

int GetHostStart( char* szBuffer, int iBufflen )
{
	for( int i = 0; i < iBufflen; i++ )
		 if( szBuffer[i]   == 'H'
		  && szBuffer[i+1] == 'o'
		  && szBuffer[i+2] == 's'
		  && szBuffer[i+3] == 't'
		  && szBuffer[i+4] == ':' )
			 return i + 6;
	
	return NULL;
}

int GetHostEnd( char* szBuffer, int iBufflen )
{
	for( int i = 0; i < iBufflen; i++ )
		 if( szBuffer[i]   == '.'
		  && szBuffer[i+1] == 'c'
		  && szBuffer[i+2] == 'o'
		  && szBuffer[i+3] == 'm' )
			 return i + 3;
	
	return NULL;
}

int GetSongNameStart( char* szBuffer, int iBufferlen )
{
	for( int i = 0; i < iBufferlen; i++ )
		 if( szBuffer[i]   == 's'
		  && szBuffer[i+1] == 'o'
		  && szBuffer[i+2] == 'n'
		  && szBuffer[i+3] == 'g' 
		  && szBuffer[i+4] == 'T'
		  && szBuffer[i+5] == 'i'
		  && szBuffer[i+6] == 't'
		  && szBuffer[i+7] == 'l'
		  && szBuffer[i+8] == 'e' )
			 return i + 23;
	
	return NULL;
}

int GetSongNameEnd( char* szBuffer, int iBufferlen, int iStart )
{
	for( int i = iStart; i < iBufferlen - iStart; i++ )
		 if( szBuffer[i] == '<' )
			 return i + iStart;
	
	return NULL;
}

int GetAudioUrlStart( char* szBuffer, int iBufferlen )
{
	for( int i = 0; i < iBufferlen; i++ )
		 if( szBuffer[i]   == 'a'
		  && szBuffer[i+1] == 'u'
		  && szBuffer[i+2] == 'd'
		  && szBuffer[i+3] == 'i'
		  && szBuffer[i+4] == 'o'
		  && szBuffer[i+5] == 'U'
		  && szBuffer[i+6] == 'R'
		  && szBuffer[i+7] == 'L' )
		     return i + 22;

	return NULL;
}

//<member><name>songTitle</name><value>Sympathy For The Devil (Radio Remix) (remixed and re-edited by The Neptunes)</value></member>

typedef int( WINAPI* WSARecv_t )( SOCKET Socket, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesRecvd, LPDWORD lpFlags, LPWSAOVERLAPPED lpOverLapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine );
WSARecv_t pWSARecv;

int WINAPI hkWSARecv( SOCKET Socket, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesRecvd, LPDWORD lpFlags, LPWSAOVERLAPPED lpOverLapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine )
{
	_asm pushad;

	//Un coded album cover image.
	//if( strstr( lpBuffers->buf, "songExplorerUrl" ) )/* && strstr( lpBuffers->buf, "artRadio" )*/
	//{
		//::MessageBox( NULL, lpBuffers->buf, NULL, NULL );
		//  		int iNameStart = GetSongNameStart( szBuffer, iBufferLen );
		//  		int iNameEnd   = GetSongNameEnd( szBuffer, iBufferLen, iNameStart );
		//  
		//  		if( iNameStart && iNameEnd )
		//  		{
		//  			char szName[64];
		//  
		//  			for( int i = iNameStart; i < iNameEnd; i++ )
		//  				szName[i] = szBuffer[i];
		//  			
		//  			szName[iNameEnd] = '\0';
		//  
		//  			::MessageBox( NULL, szName, NULL, NULL );
		//  		}
	//}

  	if( strstr( lpBuffers->buf, "songTitle" )
	 /*&& strstr( lpBuffers->buf, "onTour" )*/) 
 	{
		//  	unmanaged->File_Recv.open( STRING_RECV_LOG, ios::app );
   		//int iNameStart = GetSongNameStart( lpBuffers->buf, lpBuffers->len );
   		//int iNameEnd   = GetSongNameEnd( lpBuffers->buf, lpBuffers->len, iNameStart );
   
   		//if( iNameStart && iNameEnd )
   		//{
		//	int iNameLen = iNameEnd - iNameStart;

		//	if( iNameLen )
		//	{
				//char szBuf[0x20000];

				//char szDebug[256];
				//sprintf( szDebug, "INamedLen %i INameEnd %i INameStart %i", iNameLen, iNameEnd, iNameStart );
				//::MessageBox( NULL, szDebug, NULL, NULL );
	 
   				//for( int i = iNameStart; i < iNameLen; i++ )
   				//	szBuf[i-iNameStart] = lpBuffers->buf[i];

   				//szBuf[iNameLen-1] = '\0';
				//szBuf[iNameLen] = '\0';

				//::sprintf( unmanaged->szSongName, "%s", szBuf );
				//::MessageBox( NULL, unmanaged->szSongName, NULL, NULL );
			//}
   		//}

		   	
		   	unsigned char *szTempBuffer = new unsigned char[ lpBuffers->len + 1 ];
		   	memcpy( szTempBuffer, lpBuffers->buf, lpBuffers->len );
		   
			szTempBuffer[lpBuffers->len] = '\0';
			szTempBuffer[lpBuffers->len-1] = '\0';

		   	char szString[128];
		   	sprintf( szString, "\n\n[RECV] Socket: %i Buffer Len: %i\n\n",
		   			 Socket, lpBuffers->len );
		   
		   	unmanaged->File_Recv << szString;
		   
// 		   	char szTempLogChar[4];
// 		   
// 		   	for( unsigned int i = 0; i < lpBuffers->len; i++ )
// 		   	{
// 		   		sprintf( szTempLogChar, "%02x ", lpBuffers->buf[i] );
// 		   		unmanaged->File_Recv.write( szTempLogChar, strlen( szTempLogChar ) );
// 		   	}
// 		   
		   	unmanaged->File_Recv.write( "\n\n", 2 );
		   
		   	char szAscii[2];
		   
		   	for( unsigned int i = 0; i < lpBuffers->len; i++ )
		   	{
		   		if( szTempBuffer[i] < 32 || szTempBuffer[i] > 127 )
		   			szTempBuffer[i] = '.'; 
		   
		   		sprintf( szAscii, "%c", szTempBuffer[i] );
		   		unmanaged->File_Recv.write( szAscii, 1 );
		   	}
		   
		   	unmanaged->File_Recv.write( "\n", 1 );

		//::MessageBox( NULL, lpBuffers->buf, NULL, NULL );
	}

	//if( strstr( lpBuffers->buf, "songTitle" ) )
	//	::MessageBox( NULL, lpBuffers->buf, NULL, NULL );

// 	//Audio url method 2
// 	if( strstr( lpBuffers->buf, "audioURL" ) )
// 	{
// 	   	int iAudioUrlStart = GetAudioUrlStart( lpBuffers->buf, lpBuffers->len );
// 	   	int iAudioUrlEnd   = GetSongNameEnd( lpBuffers->buf, lpBuffers->len, iAudioUrlStart );
// 	   
// 	   	if( iAudioUrlStart && iAudioUrlEnd )
// 	   	{
// 	 		int iNameLen = iAudioUrlEnd - iAudioUrlStart;
// 	 
// 	   		char szAudioURL[2048];
// 	 
// 	   		for( int i = iAudioUrlStart; i < iNameLen; i++ )
// 	   			 szAudioURL[i-iAudioUrlStart] = lpBuffers->buf[i];
// 	   			
// 	   		szAudioURL[iNameLen-1] = '\0';
// 
// 			unmanaged->szLocation2[iNameLen-1] = '\0';
// 
// 			strcpy( unmanaged->szLocation2, szAudioURL );
// 			::MessageBox( NULL, unmanaged->szLocation2, NULL, NULL );
// 	   	}
// 	}

	_asm popad;

	return pWSARecv( Socket, lpBuffers, dwBufferCount, lpNumberOfBytesRecvd, lpFlags, lpOverLapped, lpCompletionRoutine );
}


typedef int( WINAPI* Send_t )( SOCKET Socket, char* szBuffer, int iBufferLen, int iFlags );
Send_t pSend;

int WINAPI hkSend( SOCKET Socket, char* szBuffer, int iBufferLen, int iFlags )
{
	_asm pushad;

	if( szBuffer[0]  == 'G' 
	 && szBuffer[1]  == 'E' 
	 && szBuffer[2]  == 'T'
	 && szBuffer[3]  == 0x20
	 && szBuffer[4]  == '/'
	 && szBuffer[5]  == 'a' 
	 && szBuffer[6]  == 'c'
	 && szBuffer[7]  == 'c'
	 && szBuffer[8]  == 'e'
	 && szBuffer[9]  == 's' 
	 && szBuffer[10] == 's'
	 && szBuffer[11] == '/' )
	{
		char szPath[512];

		int iPathLen = GetUrlBufferLen( szBuffer, iBufferLen );

		if( iPathLen )
		{
			for( int i = 4; i < iPathLen; i++ )
				 szPath[i-4] = szBuffer[i];

			szPath[iPathLen - 4] = '\0';

			int iHostStart = GetHostStart( szBuffer, iBufferLen );
			int iHostEnd   = GetHostEnd( szBuffer, iBufferLen );

			if( iHostStart && iHostEnd )
			{
				char szHost[64];

				for( int i = iHostStart; i <= iHostEnd; i++ )
					 szHost[i-iHostStart] = szBuffer[i];

				sprintf( unmanaged->szLocation, STRING_SSSS, STRING_HTTP, szHost, szPath );
				unmanaged->isFiletoDownload = TRUE;
				//::MessageBox( NULL, unmanaged->szLocation, NULL, NULL );
			}
#ifdef _DEBUG11_
			else
				::MessageBox( NULL, STRING_FAILEDTOGETHOST, NULL, NULL );
#endif
		}
#ifdef _DEBUG11_
		else
			::MessageBox( NULL, STRING_FAILEDTOGET, NULL, NULL );
#endif
	}
	
	_asm popad;

	return pSend( Socket, szBuffer, iBufferLen, iFlags );
}

DWORD WINAPI dwMain( LPVOID lpArg )
{
	unmanaged = new cUnManged();

	if( unmanaged )
	{
		while( !GetModuleHandle( STRING_WSOCK2 )
			|| unmanaged->sGuiCreated == 0 )
			   Sleep( 25 );

		HMODULE Wsock = NULL;
		Wsock = GetModuleHandle( STRING_WSOCK2 );

		if( !Wsock )
			Wsock = LoadLibrary( STRING_WSOCK2 ); 

		if( Wsock )
		{
			DWORD dwSend = NULL, dwWSARecv = NULL;
			dwSend    = (DWORD)GetProcAddress( Wsock, STRING_SEND ); 
			dwWSARecv = (DWORD)GetProcAddress( Wsock, STRING_WSARECV );

			unmanaged->File_Recv.open( "C:\\FUCK.txt", ios::app );
			
			if( dwSend )
				pSend = (Send_t)DetourFunction( (PBYTE)dwSend, (PBYTE)hkSend );
#ifdef _DEBUG11_
			else
				::MessageBox( NULL, "Failed to get address of function [send]", NULL, NULL );
#endif
			if( dwWSARecv )
				pWSARecv = (WSARecv_t)DetourFunction( (PBYTE)dwWSARecv, (PBYTE)hkWSARecv );
#ifdef _DEBUG11_
			else
				::MessageBox( NULL, "Failed to get address of function [wsarecv]", NULL, NULL );
#endif
		}
#ifdef _DEBUG11_
		else
			::MessageBox( NULL, "Failed to find module Ws2_32.dll", NULL, NULL );
#endif
	}
#ifdef _DEBUG11_
	else
		::MessageBox( NULL, "There was a problem creating the class", NULL, NULL );
#endif

	return 0;
}

BOOL WINAPI DllMain( HMODULE hDll, DWORD dwReason, LPVOID lpReserved )
{
	if( dwReason == DLL_PROCESS_ATTACH )
	{
		::MessageBox( NULL, STRING_GELLIN_RAPES_YOU, STRING_I_SEE_YOU, NULL );
		CreateThread( NULL, NULL, (LPTHREAD_START_ROUTINE)CreateApplicationForm, NULL, NULL, NULL );
		CreateThread( NULL, NULL, dwMain, NULL, NULL, NULL );
	}
	else if( dwReason == DLL_PROCESS_DETACH )
	{
		delete[] unmanaged;
	}

	return TRUE;
}