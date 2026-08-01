#define HAS_GPS 0
#undef GPS_RX_PIN
#undef GPS_TX_PIN

#define HAS_SCREEN 0

#define HAS_NEOPIXEL                         // Enable the use of neopixels
#define NEOPIXEL_COUNT 1                     // How many neopixels are connected
#define NEOPIXEL_DATA 48                     // gpio pin used to send data to the neopixels
#define NEOPIXEL_TYPE (NEO_GRB + NEO_KHZ800) // type of neopixels in use

#define BUTTON_PIN 0 // This is the BOOT button
#define BUTTON_NEED_PULLUP

#define USE_SX1262

#define LORA_MISO 3
#define LORA_SCK 5
#define LORA_MOSI 6
#define LORA_CS 7

#define LORA_RESET 8
#define LORA_DIO1 16

#ifdef USE_SX1262
#define SX126X_CS LORA_CS // FIXME - we really should define LORA_CS instead
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY 15
#define SX126X_RESET LORA_RESET
#define SX126X_TXEN RADIOLIB_NC  // module TXEN wired to DIO2, nc
#define SX126X_DIO2_AS_RF_SWITCH
#define SX126X_RXEN 4
#endif
