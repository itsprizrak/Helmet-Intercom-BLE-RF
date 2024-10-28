#include "AudioTools.h"
#include "BluetoothA2DPSink.h"

// Initialize I2S configuration
I2SStream i2s;
BluetoothA2DPSink a2dp_sink(i2s);

void setup() {
    Serial.begin(115200);
    
    // Set I2S configuration for MAX98357A
    auto config = i2s.defaultConfig(TX_MODE);  // Transmit mode
    config.sample_rate = 44100;  // Standard audio sample rate
    config.bits_per_sample = 16;  // Standard bit depth
    config.pin_bck = 26;  // BCLK pin
    config.pin_ws = 25;   // LRC/WS pin
    config.pin_data = 22; // DIN pin
    i2s.begin(config);  // Initialize I2S with this configuration
    
    // Start Bluetooth A2DP Sink
    a2dp_sink.start("PRIZTECH");  // Bluetooth name
}

void loop() {
    // Empty loop
}
