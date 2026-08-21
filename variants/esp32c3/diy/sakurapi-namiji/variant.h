#define HAS_SCREEN (0)

// AHT20 sensor
#define WIRE_INTERFACES_COUNT (1)
#define I2C_SDA (2)
#define I2C_SCL (0)
// I2C is a bit finicky, don't scan too much???
#define I2C_NO_RESCAN (1)

// VIN ADC
#define BATTERY_PIN (1)
#define ADC_CHANNEL ADC_CHANNEL_1
// #define ADC_MULTIPLIER 5.52

// GPS
#define NO_GPS 1
// #define GPS_RX_PIN (3)
// #define GPS_TX_PIN (4)

// LoRa
// SX1262: 170M or 900M; SX1268: 400M
// #define USE_SX1262
#define USE_SX1268

#define LORA_DIO0 RADIOLIB_NC
#define LORA_RESET (10)
#define LORA_DIO1 (20)
#define LORA_BUSY (21)
#define LORA_RXEN (5)
#define LORA_SCK (6)
#define LORA_MISO (9)
#define LORA_MOSI (8)
#define LORA_CS (7)

#define SX126X_CS LORA_CS
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY LORA_BUSY
#define SX126X_RESET LORA_RESET
#define SX126X_RXEN LORA_RXEN

#define SX126X_DIO2_AS_RF_SWITCH

#ifdef EBYTE_E22
// TCXO VCC not exposed
#define LORA_DIO3
#define TCXO_OPTIONAL
#define SX126X_DIO3_TCXO_VOLTAGE (2.2)
#endif


// NOTE: src/configuration.h#L145, refer to datasheet
#ifdef EBYTE_E22_400M33S
#define TX_GAIN_LORA 12
#define SX126X_MAX_POWER 21
#endif
