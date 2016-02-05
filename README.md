# pandora_injection_downloader_gui_cpp_cli
Pandora downloader
 
# Readme
This is a very old project that was released in 2011 to a closed community, is being mirrored here and will be updated eventually. All source code is for demonstrational and educational purposes only, it comes with no warranty, I do not advise that you use it.

This was mostly a test of microsofts new C++/CLI language, that was the only language to feature full 100% managed/unmanaged interoperability. It was fun to learn, but the syntax is very picky and too complex, which is likely why it never caught on and became a dead language. I was very happy at the time to be able to spawn a fully managed, Winforms GUI from inside of a DLL that is injected into another process, once inside, it deploys fully native hooks.

# Old note
In this project you will see a little bit of everything, API Hooking, Unmanaged C++ code, and Managed C++/CLI. It uses unmanaged code to hook the winsock function "send", and managed code to control the UI. "I used a unmanaged hook because it feels more native to me - pun intended". 

It compiles into a DLL that is designed to be injected into Firefox. It will automatically save's all songs played to "C:\Pandora" with the name "UnknownXX.mp4". I was never able to get the names working 100% obtaining them through hooking. However if you hook "WSARecv" they pass an XML document when you load the 1st song which contains three songs, and ALOT of data about them. I assume its 1 song that is being played, one song if you hit thumbs down, and another song if you hit thumbs up. This may not be entirely true. 



Requirements - Windows OS, dotNet 3.5 or higher, Visual Studio "Intended for MS Detours 2.1" 
Test system - Windows 7 x64 bit 
Injected into - Firefox 3.6 

Have fun, cheers..
