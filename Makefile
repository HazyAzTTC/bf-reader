IFLAG = -I include

CC = gcc
CFLAGS = $(IFLAG) -Wall -Werror -Wextra
RFLAGS = $(IFLAG) -Wno-unused-result -O1
DFLAGS = $(CFLAGS) -g3

SDIR = src
_SOURCES = main.c error.c core.c complex_inputs.c debug_treating.c esthetical.c file_utils.c
SOURCES = $(patsubst %,$(SDIR)/%,$(_SOURCES))

ODIR = obj
_OBJECTS = $(_SOURCES:.c=.o)
_DOBJECTS = $(_SOURCES:.c=.do)
_ROBJECTS = $(_SOURCES:.c=.ro)
OBJECTS = $(patsubst %,$(ODIR)/%,$(_OBJECTS))
DOBJECTS = $(patsubst %,$(ODIR)/%,$(_DOBJECTS))
ROBJECTS = $(patsubst %,$(ODIR)/%,$(_ROBJECTS))

TARGET = bin/test.build
DTARGET = bin/test.debug.build
RELEASE = bf-reader
INSTALL = /home/${USER}/.local/bin/bf-reader



.PHONY: all debug release install clean fclean rclean dclean dfclean rfclean iclean aclean re dre rre ire

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "\n\033[1;34mSuccessfully created a test build in ./bin\033[0m!\n"

$(ODIR)/%.o: $(SDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo created $@!

debug: $(DTARGET)

$(DTARGET): $(DOBJECTS)
	@$(CC) $(DFLAGS) -o $(DTARGET) $(DOBJECTS)
	@echo "\n\033[1;34mSuccessfully created a debug build in ./bin\033[0m!\n"

$(ODIR)/%.do: $(SDIR)/%.c
	@$(CC) $(DFLAGS) -c $< -o $@
	@echo created $@!

release: $(RELEASE)

$(RELEASE): $(ROBJECTS)
	@if test -f bin/.old/$(RELEASE).old; then rm -f bin/.old/$(RELEASE).old; fi
	@if test -f bin/$(RELEASE); then mv bin/$(RELEASE) bin/.old/$(RELEASE).old; fi
	@$(CC) $(RFLAGS) -o bin/$(RELEASE) $(ROBJECTS)
	@echo "\033[1;32m/!\\ MADE A RELEASE /!\\ \033[0m\n"

$(ODIR)/%.ro: $(SDIR)/%.c
	@$(CC) $(RFLAGS) -c $< -o $@
	@echo created $@!

install: $(INSTALL)

$(INSTALL): $(RELEASE)
	@cp -f bin/$(RELEASE) $(INSTALL)
	@echo "\033[1;31m/!\\ CREATED A COPY IN .LOCAL/BIN /!\\ \033[0m\n"




clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(TARGET)




dclean:
	@rm -f $(DOBJECTS)

dfclean: dclean
	@rm -f $(DTARGET)




rclean:
	@rm -f $(ROBJECTS)

rfclean: rclean
	@rm -f bin/$(RELEASE)
	@if test -f bin/.old/$(RELEASE).old; then rm -f bin/.old$(RELEASE).old; fi



iclean: rfclean
	@rm -f $(INSTALL)



aclean: iclean fclean dfclean



re: fclean all

dre: dclean debug

rre: rfclean release

ire: iclean install
