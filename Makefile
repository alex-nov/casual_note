CC=gcc
CFLAGS=-c -Wall
SOURCES=add_record.cpp  clear_note.cpp delete_note.cpp print_note.cpp search_notes.cpp show_records.cpp casual_note.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=casual_note

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.o