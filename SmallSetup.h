
//Written by Christopher Andrews, Provided under MIT & GPL licences.
#if defined( __AVR__ ) && !defined( HEADER_SMALLSETUP )
	#define HEADER_SMALLSETUP
	#include "wiring.c"

	/*** init runs before constructors ***/
	__attribute__ ((naked)) __attribute__ ((section (".init5"))) void init();
	
	/*** USBAttach runs after constructors ***/
	#if defined( USBCON )
		__attribute__ ((naked)) __attribute__ ((section (".init7"))) void USBAttach();
		void USBAttach(){ USBDevice.attach(); }
	#endif	
	
	/*** setup runs after USBAttach to ensure Serial is active ***/
	__attribute__ ((naked)) __attribute__ ((section (".init8")))  void setup();

	/*** main() runs as normal, only contains runtime code ***/
	__attribute__ ((naked)) int main();
	
	#ifdef __AVR_ATtiny25__
		int main(){ return (({while( loop(), true );}),0x00); }
	#else
		int main(){ return (({while( ( serialEventRun ? serialEventRun() : ( void ) 0 ), loop(), true );}),0x00); }
	#endif
#endif
