BUILD := build
TARGET := arduino:avr:uno
CFLAGS += -Wall -Werror -Wextra

$(BUILD)/sketch.ino.with_bootloader.bin:
	arduino-cli compile --build-property build.extra_flags='$(CFLAGS)' --fqbn $(TARGET) --output-dir $(BUILD) .


.PHONY: run
run: $(BUILD)/sketch.ino.with_bootloader.bin
	arduino-cli upload --port /dev/ttyUSB0 --fqbn $(TARGET) .
