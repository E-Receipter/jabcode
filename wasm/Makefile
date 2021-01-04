PREFIX 	=
CC 	= $(PREFIX)emcc
LCC = $(PREFIX)gcc
CFLAGS	= -O3

TARGET = build/jabcode.js

OBJECTS := $(patsubst ../src/jabcode/%.c,objects/%.o,$(wildcard ../src/jabcode/*.c))
LOBJECTS := $(patsubst ../src/jabcode/%.c,../src/jabcode/%.o,$(wildcard ../src/jabcode/*.c))
$(TARGET): $(OBJECTS)
	$(CC) -I../src/jabcode/ -I../src/jabcode/include $(CFLAGS) -s WASM_BIGINT -s WASM=1 -s "EXPORTED_FUNCTIONS=@exported.json" $(OBJECTS) bindings.c -o $@

$(OBJECTS): objects/%.o: ../src/jabcode/%.c
	$(CC) -c -I../src/jabcode/ -I../src/jabcode/include $(CFLAGS) $< -o $@

gcc-build:
	$(LCC) -I../src/jabcode/ -I../src/jabcode/include $(LOBJECTS) -ltiff -lpng16 -lz -lm bindings.c -o build/test.out

clean:
	rm -f $(TARGET) $(OBJECTS)
