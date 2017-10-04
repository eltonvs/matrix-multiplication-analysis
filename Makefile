# DIRS
INCDIR = include
BINDIR = bin
SRCDIR = src
BUILDDIR = build
LIBDIR = lib
# TARGET
TARGET_SEQ = $(BINDIR)/mat_mult_seq
TARGET_CONC = $(BINDIR)/mat_mult_conc
# EXTENSIONS
SRCEXT = cpp
HEADEREXT = hpp
# COMPILER
CC = g++
# FOR CLEANING
RM = /bin/rm
# WARNING FLAG
WARN = -Wall
# PEDANTIC FLAG
PEDANTIC = -pedantic -ansi
# DEBUG FLAGS
DEBUG = -g
COMPRESS = -O3
# LINKING FLAGS
INCFLAG = -I $(INCDIR)
LFLAGS = $(DEBUG) $(WARN) $(PEDANTIC) $(INCFLAG) -lpthread
# COMPILATION FLAGS
CFLAGS = $(DEBUG) -c $(WARN) -std=c++11
# OBJS
OBJS_COMMON = $(BUILDDIR)/read_file.o $(BUILDDIR)/write_file.o
OBJS_SEQ = $(BUILDDIR)/main_seq.o $(BUILDDIR)/mat_mult_seq.o
OBJS_CONC = $(BUILDDIR)/main_conc.o $(BUILDDIR)/mat_mult_conc.o


# ----------------------
# ENTRIES
# ----------------------

all: $(TARGET_SEQ) $(TARGET_CONC)

$(TARGET_SEQ): $(OBJS_COMMON) $(OBJS_SEQ)
	@echo "Linking Sequential..."
	@echo " $(CC) $^ -o $(TARGET_SEQ) $(LFLAGS)"
	$(CC) $^ -o $(TARGET_SEQ) $(LFLAGS)

$(TARGET_CONC): $(OBJS_COMMON) $(OBJS_CONC)
	@echo "Linking Concurrent..."
	@echo " $(CC) $^ -o $(TARGET_CONC) $(LFLAGS)"
	$(CC) $^ -o $(TARGET_CONC) $(LFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INCFLAG) -o $@ $<"
	$(CC) $(CFLAGS) $(INCFLAG) -o $@ $<

# DUMMY ENTRIES
clean:
	@echo "Cleaning..."
	@echo " $(RM) $(OBJS_COMMON) $(OBJS_SEQ) $(OBJS_CONC) $(TARGET_SEQ) $(TARGET_CONC)"
	$(RM) $(OBJS_COMMON) $(OBJS_SEQ) $(OBJS_CONC) $(TARGET_SEQ) $(TARGET_CONC)

.PHONY: clean
