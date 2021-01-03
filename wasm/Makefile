PREFIX 	=
CC 	= $(PREFIX)emcc
CFLAGS	= -O3

TARGET = jabcode.js

OBJECTS := $(patsubst ../src/jabcode/%.c,%.o,$(wildcard ../src/jabcode/*.c))
$(TARGET): $(OBJECTS)
	$(CC) -I../src/jabcode/ -I../src/jabcode/include $(CFLAGS) -s WASM=1 -s "EXPORTED_FUNCTIONS=@exported.json" $(OBJECTS) -o $@

$(OBJECTS): %.o: ../src/jabcode/%.c
	$(CC) -c -I../src/jabcode/ -I../src/jabcode/include $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)
