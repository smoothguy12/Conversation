TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += \
    conversation.cxx \
    main.cxx \
    context.cxx \
    state.cxx \
    singleton.cxx \
    window.cxx \
    settings.cxx \
    log.cxx \
    reader.cxx \
    introstate.cxx \
    playstate.cxx \
    observer.cxx \
    observable.cxx

HEADERS += \
    conversation.hxx \
    context.hxx \
    state.hxx \
    singleton.hxx \
    window.hxx \
    settings.hxx \
    log.hxx \
    reader.hxx \
    introstate.hxx \
    playstate.hxx \
    observer.hxx \
    observable.hxx

LIBS += -L/usr/include/SFML -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
LIBS += -L/usr/include/jsoncpp -ljsoncpp

OTHER_FILES += \
    singleton.inc \
    README.md \
    TODO.txt