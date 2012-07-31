TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += \
    Game/conversation.cxx \
    main.cxx \
    Game/context.cxx \
    Game/state.cxx \
    Core/singleton.cxx \
    Core/window.cxx \
    Core/settings.cxx \
    log.cxx \
    Core/reader.cxx \
    Game/introstate.cxx \
    Core/observer.cxx \
    Core/observable.cxx \
    Game/playingstate.cxx \
    Core/entityfactory.cxx \
    Entities/entity.cxx \
    Entities/character.cxx \
    Core/mixer.cxx \
    Core/vectorreader.cxx \
    Game/preloadingstate.cxx \
    Game/mainmenustate.cxx \
    Core/fontmanager.cxx \
    Core/mapreader.cxx \
    UI/text.cxx \
    UI/widget.cxx \
    UI/container.cxx \
    UI/label.cxx \
    UI/textbutton.cxx \
    UI/button.cxx \
    UI/layout.cxx \
    Core/event.cxx \
    Core/eventpump.cxx

HEADERS += \
    Game/conversation.hxx \
    Game/context.hxx \
    Game/state.hxx \
    Core/singleton.hxx \
    Core/window.hxx \
    Core/settings.hxx \
    log.hxx \
    Core/reader.hxx \
    Game/introstate.hxx \
    Core/observer.hxx \
    Core/observable.hxx \
    Game/playingstate.hxx \
    Core/entityfactory.hxx \
    Entities/entity.hxx \
    Entities/character.hxx \
    Core/mixer.hxx \
    Core/vectorreader.hxx \
    Game/preloadingstate.hxx \
    Game/mainmenustate.hxx \
    Core/fontmanager.hxx \
    Core/mapreader.hxx \
    UI/text.hxx \
    UI/widget.hxx \
    UI/container.hxx \
    UI/label.hxx \
    UI/textbutton.hxx \
    UI/button.hxx \
    UI/label.hxx \
    UI/layout.hxx \
    Core/event.hxx \
    Core/eventpump.hxx

LIBS += -L/usr/include/SFML -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
LIBS += -L/usr/include/jsoncpp -ljsoncpp

OTHER_FILES += \
    Core/singleton.inc
