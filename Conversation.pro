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
    observer.cxx \
    observable.cxx \
    playingstate.cxx \
    entityfactory.cxx \
    entity.cxx \
    character.cxx \
    drawable.cxx \
    transformable.cxx \
    mixer.cxx \
    vectorreader.cxx \
    preloadingstate.cxx \
    mainmenustate.cxx \
    fontmanager.cxx \
    mapreader.cxx \
    text.cxx

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
    observer.hxx \
    observable.hxx \
    playingstate.hxx \
    entityfactory.hxx \
    entity.hxx \
    character.hxx \
    drawable.hxx \
    transformable.hxx \
    mixer.hxx \
    vectorreader.hxx \
    preloadingstate.hxx \
    mainmenustate.hxx \
    fontmanager.hxx \
    mapreader.hxx \
    text.hxx

LIBS += -L/usr/include/SFML -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
LIBS += -L/usr/include/jsoncpp -ljsoncpp

OTHER_FILES += \
    singleton.inc \
    README.md \
    TODO.txt
