
//Written by Christopher Andrews, Provided under MIT & GPL licences.
#if defined( __AVR__ ) && !defined( HEADER_SMALLSETUP )
	#define HEADER_SMALLSETUP
	
	#if ARDUINO >= 157
		inline void yield( void ){ return; }
	#endif
	
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
	
	#if defined( __AVR_ATtiny24__ ) || defined( __AVR_ATtiny25__ ) || \
		defined( __AVR_ATtiny44__ ) || defined( __AVR_ATtiny45__ ) || \
		defined( __AVR_ATtiny85__ ) || defined( __AVR_ATtiny85__ ) || \
		defined( __AVR_ATtiny167__ ) || defined( __AVR_ATtiny861__ ) || \
		defined( __AVR_ATtiny2313__ ) || defined( __AVR_ATtiny4313__ )
		int main(){ return (({while( loop(), true );}),0x00); }
	#else
		int main(){ return (({while( ( serialEventRun ? serialEventRun() : ( void ) 0 ), loop(), true );}),0x00); }
	#endif
#endif
