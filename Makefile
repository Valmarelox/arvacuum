BUILD := build
TARGET := arduino:avr:uno

$(BUILD)/sketch.ino.with_bootloader.bin:
	arduino-cli compile --fqbn $(TARGET) --output-dir $(BUILD) .


.PHONY: run
run: $(BUILD)/sketch.ino.with_bootloader.bin
	arduino-cli upload --port /dev/ttyUSB0 --fqbn $(TARGET) .
