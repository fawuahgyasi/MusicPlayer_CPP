LIB_PATH		= lib
LIB_NAME_RELEASE	= libfmodex.dylib
LIB_NAME_LOGGING	= libfmodexL.dylib
ARCH			= -arch x86_64

release: main.o PlayerFMOD.o Playlist.o
	g++ -O3 ${ARCH} -o example main.o PlayerFMOD.o Playlist.o ${LIB_PATH}/${LIB_NAME_RELEASE}
	install_name_tool -change ./${LIB_NAME_RELEASE} ${LIB_PATH}/${LIB_NAME_RELEASE} example

debug: main.o PlayerFMOD.o Playlist.o
	g++ -O0 ${ARCH} -g -o example main.cpp ${LIB_PATH}/${LIB_NAME_LOGGING}
	install_name_tool -change ./${LIB_NAME_LOGGING} ${LIB_PATH}/${LIB_NAME_LOGGING} example

main.o:
	g++ -O3 ${ARCH} -c main.cpp


PlayerFMOD.o: PlayerFMOD.h
	g++ -O3 ${ARCH} -c PlayerFMOD.cpp

Playlist.o: Playlist.h
	g++ -O3 ${ARCH} -c Playlist.cpp


clean:
	rm -f example *.o
