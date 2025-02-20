@all: ./builddir/main.exe

./builddir/main.exe: ./builddir src/*.c src/**/*.c include/**/*.h
	ninja -C ./builddir

./builddir: meson.build
	meson setup builddir --reconfigure

test: ./builddir/main.exe
	ninja -C ./builddir test

clean:
	rm -rf builddir
	rm *.png
	rm *.sig

run: ./builddir/main.exe
	./builddir/main.exe
