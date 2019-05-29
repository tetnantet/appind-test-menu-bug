###

EXE              = appind-test-menu-bug
PKG_CONFIG_LIST  = gtk+-2.0
PKG_CONFIG_LIST += appindicator-0.1

###

CFLAGS  += $(shell pkg-config --cflags $(PKG_CONFIG_LIST))
LDFLAGS += $(shell pkg-config --libs $(PKG_CONFIG_LIST))

CFLAGS  += -Wall
CFLAGS  += -I.
CFLAGS  += -DGTK_DISABLE_DEPRECATED
CFLAGS  += -DLOGO_PNG=\"$(shell pwd)/logo.png\"

SRC  = $(shell ls |grep "\.c$$")
OBJS = $(SRC:%.c=%.o)

RM = rm -f

all : $(EXE)

$(EXE) : $(OBJS)
	@echo "	*** Linking $@"
	$(CC) $^ $(LDFLAGS) -o $@

%.o : %.c
	@echo "	*** Compiling $<"
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJS) $(EXE)

.PHONY : all clean
